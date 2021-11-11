#include "arsi.h"
// clang-format off
IN(gor,
an,                           L)IN(L,
ara,                          L)IN(L,
arada,                        L)IN(L,
os_next,                      L)IN(L,
wordump,                 import);
// clang-format on

N(s2) { A(7) C(1); }
N(mmain) { A(9) C(1); }

// clang-format off
E(Tail,
"aaaaa",    mmain,            L)E(L,
"მთავარი",  mmain,       export);
