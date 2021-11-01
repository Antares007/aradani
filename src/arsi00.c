#include "arsi.h"
// clang-format off
IN(gor,
os_next, import);
// clang-format on

N(s2) { A(7) C(1); }
N(mmain) { A(9) C(1); }

// clang-format off
E(Tail,
"m2",       mmain, L)E(L,
"M",        mmain, export);
// clang-format on
