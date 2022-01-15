#include "arsi.h"
// clang-format off
IF(iε,
printf, print,                L, int, const char*, ...)IN(L,
and,                          L)IN(L,
and2,                         L)IB(L);

N(seven) {
  print("seven\n");
  A7(7, 7, 7, 7, 7, 7, 7) C(1);
}

N(init) {
  print("init\n");
  A2(seven, and) C(1);
}

EB(tail);
