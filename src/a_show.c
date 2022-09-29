#include "arsi.h"
#include "raylibfun.h"
#include "stdiofun.h"
rayfun_t r;
stdiofun_t *s;
// clang-format off
                          IN(Gor,
God,                    L)IN(L,
Got,                    L)I(L,
"raylibfun", r,         L)I(L,
"stdiofun", s,    imports);
// clang-format on

N(on_tick2) { A(God) O; }
N(_c      ) { A(5) C(1); }
N(on_draw ) { 
  s->printf("soplikuna\n");
  s->puts("kargi gogoa\n");
  A(7) C(1);
}

N(term) { C(1); }

N(_a) { A2("b", term) O; }
N(_b) { A2("a", term) O; }

// clang-format off
                          EN(tail,
on_draw,                L)EN(L,
_c,                     L)EN(L,
_b,                     L)EN(L,
_a,               exports);
