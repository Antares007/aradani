#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
os_new_psn,         L)IN(L,
os_next,            L)IN(L,
os_queue_n,         L)IN(L,
//
and,                L)IN(L,
and2,         imports)

SarP(init)(god)

Sar(pand0)(os_next)
Sar(pnot0)(got)
Sar(poor0)(gor)
Sar(pand1)(god)
Sar(pnot1)(got)
Sar(poor1)(gor)

S(mp0) { R(p_t*, oο); Α(pnot0, pand0, poor0, oο, 512, "0", os_new_psn) O; }
S(mp1) { R(p_t*, oο); Α(pnot1, pand1, poor1, oο, 512, "1", os_new_psn) O; }

N(sgod) {
  R(Q_t, c);
  if(c > 100000000) C(1);
  else Α(c + 1, sgod, ο, 2, os_queue_n) O;
}

Nar(example)(0, sgod, ο, mp0, mp1, and, 2, os_queue_n, and2);

// clang-format off
EN(tail,
example,      exports)
