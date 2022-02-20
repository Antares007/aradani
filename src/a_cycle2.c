#include "arsi.h"
#include "gotgod.h"
// clang-format off
IBS(                L)IN(L,
nar,                L)IN(L,
os_create,          L)IN(L,
os_create_psn,      L)IN(L,
os_new_psn,         L)IN(L,
os_queue,           L)IN(L,

and,                L)IN(L,
and2,               L)IN(L,
not,                L)IN(L,
or,           imports);
// clang-format on
void init() {}

N(pgot) { C(2); }
N(pgod) { C(1); }
N(pgor) { C(0); }
N(cgot) { C(2); }
N(cgod) { C(1); }
N(cgor) { C(0); }
N(sgot) { C(2); }
N(sgod) { C(1); }
N(sgor) { C(0); }
N(rotate3) {
  R(void *, c);
  R(void *, b);
  R(void *, a);
  Α(b, c, a) C(1);
}
NP(p_and_log){};
NP(c_and_log){};
N(to) { Α(ο) C(1); }
N(tp) {
  R(void *, a);
  R(Q_t, c);
  if (c % 100000000 == 0)
    p_and_log(T());
  Α(c + 1, a, ο) C(1);
}
N(tc) {
  R(void *, a);
  R(Q_t, c);
  if (c % 100000000 == 1)
    c_and_log(T());
  Α(c + 1, a, ο) C(1);
}
N(mprod) {
  Α(got,
    tp, pgod, rotate3, and2, os_queue, and,
    to, pgor, rotate3, and2, os_queue, and,
    0166, ο, 512, "prod", os_create_psn)
  O;
}
N(mcons) {
  Α(got,
    tc, cgod, rotate3, and2, os_queue, and,
    to, cgod, rotate3, and2, os_queue, and,
    0166, ο, 512, "cons", os_create_psn)
  O;
}
N(მთავარი) { Α(0, mcons, sgor, mprod, and2, os_queue, and) O; }
// clang-format off
EN(tail, 
მთავარი,      exports);
