#include "arsi.h"
#include "gotgod.h"
// clang-format off
IBS(                L)IN(L,
nar,                L)IN(L,
os_co,              L)IN(L,
os_co_psn,          L)IN(L,
os_new_psn,         L)IN(L,
os_queue,           L)IN(L,

and,                L)IN(L,
and2,               L)IN(L,
not,                L)IN(L,
or,           imports);
// clang-format on
void init() {}

NP(pgot) { C(2); }
NP(pgod) { C(1); }
NP(pgor) { C(0); }
NP(cgot) { C(2); }
NP(cgod) { C(1); }
NP(cgor) { C(0); }
NP(rotate3) {
  R(void *, c);
  R(void *, b);
  R(void *, a);
  Α(b, c, a) C(1);
}
NP(tο) { A(ο) C(1); }
NP(mprod) {
  Α(got,
    tο, pgod, rotate3, and2, os_queue, and,
    tο, pgor, rotate3, and2, os_queue, and,
    0166, ο, 512, "prod", os_co_psn) O;
}
NP(mcons) {
  Α(got,
    tο, cgod, rotate3, and2, os_queue, and,
    tο, cgod, rotate3, and2, os_queue, and,
    0166, ο, 512, "cons", os_co_psn) O;
}
NP(მთავარი) { Α(0, mcons, gor, mprod, and2, os_queue, and) O; }

// clang-format off
EN(tail, 
მთავარი,      exports);
