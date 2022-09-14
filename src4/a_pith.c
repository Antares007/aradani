#include "arsi.h"
// clang-format off
                    IN(Gor,
God,              L)IN(L,
Got,        imports);
// clang-format on

N(on_tick ) { C(1); }
N(on_stdin) { C(1); }
N(on_init ) { C(1); }
N(on_draw ) { C(1); }

// clang-format off
                    EN(Tail,
on_draw,          L)EN(L,
on_init,          L)EN(L,
on_stdin,         L)EN(L,
on_tick,    exports);
