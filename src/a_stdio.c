#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
dot,                L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
os_new,             L)IN(L,
os_queue,           L)IN(L,
os_queue_n,         L)IN(L,
os_soll_n,          L)IN(L,

and,                L)IN(L,
and2,               L)IN(L,
and3,               L)IN(L,
and4or,             L)IN(L,
and5or5,            L)IN(L,
andor,              L)IN(L,
andor2,             L)IN(L,

forward,            L)IN(L,
greet,              L)IN(L,
greet_b,            L)IN(L,
reject,             L)IN(L,

mk_stdin,           L)IN(L,
mk_stdout,    imports)
SarP(init)(god)

#define οn_end_soll(ο)  ο[0x7].p 
#define οn_data_soll(ο) ο[0x8].p
#define οproducer(ο)    ο[0x9].p
#define οconsumer(ο)    ο[0xa].p
#define οtransformer(ο) ο[0xb].p   

N(pipe   ) { R(p_t*, cο); R(p_t*, pο); οproducer(cο) = pο; A(pο) C(1); } // fix it
Sar(set_consumer)(god)
Sar(mk_trans_pith)(god)
Sar(set_trans_pith)(god)
Sar(is_alfa_zero)(god)
SarP(trans_oor)(
  set_consumer, mk_trans_pith, and,
               set_trans_pith, and,
   οproducer(ο), οtransformer(ο), greet, and3)

SarP(trans_and)(
  is_alfa_zero,
    god,
    οproducer(ο), forward, andor2)

S(is_equal) { R(void *, r); R(void *, l); C(l == r); }
SarP(trans_not_n)(
  οconsumer(ο), is_equal,
    οproducer(ο), οtransformer(ο), reject,
    got, and4or)
SarP(trans_not)(
  is_alfa_zero,
    got,
    trans_not_n, andor)

SarP(mk_trans )(trans_not, trans_and, trans_oor, os_new)
SP(trans_set) {
  R(p_t *, ns);
  R(p_t *, as);
  R(p_t *, tο);
  οn_end_soll(ο) = ns;
  οn_data_soll(ο) = as;
  οproducer(ο) = 0;
  οconsumer(ο) = 0;
  οtransformer(ο) = 0;
  A(tο) C(1);
}
N(trans) {
  R(p_t *, ns);
  R(p_t *, as);
  Α(mk_trans, as, ns, trans_set, and3) O;
}
NarP(on_data)(god)
NarP(on_end)(god)
Nar(example)(
  mk_stdin,
      mk_stdout, and,
      greet, and);

EN(tail,
example,      exports)
