#include "arsi.h"

// clang-format off
IN(0,
and,              L)IB(L);

N(seven) { A7(7, 7, 7, 7, 7, 7, 7) C(1); }

N(init) { A2(seven, and) C(1); }

EB(tail);
