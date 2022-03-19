#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
dot,                L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
os_ls,              L)IN(L,
os_new_n,           L)IN(L,
os_queue,           L)IN(L,
os_seed,            L)IN(L,
os_wordump,         L)IN(L,
//
and,                L)IN(L,
and2,               L)IN(L,
and2or,             L)IN(L,
and3or,             L)IN(L,
and4,               L)IN(L,
andor,              L)IN(L,
andor3,             L)IN(L,
or,                 L)IN(L,
or3,          imports) //


SarP(pgot)(got)
SarP(pgod)(god)
SarP(pgor)(gor)

#define ET(Tail, Name, Head) SarP(Name##_stab)(god) E(Tail, #Name, Name##_stab, Head)
#define EE(Tail, Name, Head) E(Tail, #Name, Name, Head)
S(drop1) {
  α -= 1; C(1);
}
SP(import_n) {
  R(const char*, in);
  R(n_t, e);
  R(n_t, a);
  R(const char*, en);
  if (cmp(in, en)) Α(e, in, import_n, and2) O;
  else             A(a) C(1);
}
SP(import) {
  R(const char*, n);
  R(n_t, e);
  Α(e, n, import_n, and2) O;
}
E(got, "0",              0,L)E(L,
"0",                     0,L)E(L,
"printf",            print,L)E(L,
"god",                pgod,L)E(L,
"gor",                pgor,L)E(L,
"got",                pgot,
                           L)ET(L,
l_free,                    L)E(L,
"l_setnoblock", drop1,     L)ET(L,
l_write,                   L)EE(L,
os_new_n,                  L)ET(L,
os_queue,                  
                           L)EE(L,
and,                       L)EE(L,
and2,                      L)EE(L,
and2or,                    L)EE(L,
and3or,                    L)EE(L,
andor,                     L)EE(L,
andor3,                    L)EE(L,
or,                        L)EE(L,
or3,                       
                           L)ET(L, //
q_for_each,                L)ET(L,
q_push,                    L)ET(L,
q_shift,                   L)ET(L,
q_soll_free,               L)ET(L,
q_soll_remove,             L)ET(L,
q_unshift,                 L)ET(L, //
epoll_ctl_add_out,         L)ET(L,
epoll_ctl_del_out,         L)ET(L,
epoll_ctl_mod_out,         L)ET(L, //
is_alfa_zero,              L)ET(L,
match,              exports2)

static n_t arsi;

S(set) {
  R(n_t*, a);
  R(n_t , v);
  *a = v, C(1);
}
SarP(init)("src/a_stdout.tarsi", exports2, os_seed, &arsi, set, and2)
S(test) {
  R(n_t, j);
}
SarP(მთავარი_n)(
  arsi, "mk_stdout", import,
  dot, and,
  os_wordump, and)
SarP(მთავარი)(მთავარი_n, ο, os_queue)

// clang-format off
EN(tail,
მთავარი,      exports)
