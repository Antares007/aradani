#include "arsi.h"
// clang-format off
                    IN(Gor,
God,              L)IN(L,
Got,        imports);
// clang-format on

N(on_tick2) { A(God) O; }
N(_on_tick) { A(7) C(1); }
N(_on_stdin) { C(1); }
N(on_init) { A(5) C(1); }
N(on_draw) { C(1); }

// clang-format off
                    EN(tail,
on_draw,          L)EN(L,
on_init,          L)EN(L,
_on_stdin,        L)EN(L,
_on_tick,   exports);
