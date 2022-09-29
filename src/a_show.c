#include "arsi.h"
// clang-format off
                      IN(Gor,
God,                L)IN(L,
Got,          imports);
// clang-format on

N(on_tick2) { A(God) O; }
N(on_init) { A(5) C(1); }
N(on_draw) { C(1); }

N(term) { C(1); }

N(_a) { A2("b", term) O; }
N(_b) { A2("a", term) O; }

// clang-format off
                      EN(tail,
on_draw,            L)EN(L,
on_init,            L)EN(L,
_a,                 L)EN(L,
_b,           exports);
