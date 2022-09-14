#include "arsi.h"
// clang-format off
                    IN(Gor,
nar2,             L)IN(L,
nar3,             L)IO(L,
on_draw,          L)IO(L,
on_init,          L)IO(L,
on_stdin,         L)IO(L,
on_tick,    imports);
// clang-format on

N(on_tick) { inner_on_tick(T); }
N(on_stdin) { inner_on_stdin(T); }
N(on_init) { inner_on_init(T); }
N(on_draw) { inner_on_draw(T); }

// clang-format off
                    EN(Tail,
on_draw,          L)EN(L,
on_init,          L)EN(L,
on_stdin,         L)EN(L,
on_tick,    exports);
