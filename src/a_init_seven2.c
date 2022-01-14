#include "arsi.h"

// clang-format off
IF(0,
printf, print,                L, int, const char*, ...)IN(L,
and,                          L)IB(L);

N(seven) {
  print("seven2\n");
  A7(7, 7, 7, 7, 7, 7, 7) C(1);
}

N(init) {
  print("init2\n");
  A2(seven, and) C(1);
}

EB(tail);
