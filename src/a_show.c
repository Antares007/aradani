#include "arsi.h"
#include "raylibfun.h"
#include "stdiofun.h"
rayfun_t *ρ;
stdiofun_t *σ;
n_t *ψ;
n_t *ο, Got, God;
// clang-format off
                          I(Gor,
"God", God,             L)I(L,
"Got", Got,             L)I(L,
"ο", ο,                 L)I(L,
"ρ", ρ,                 L)I(L,
"σ", σ,                 L)I(L,
"ψ", ψ,           imports);
// clang-format on

N(on_tick2) { A(God) O; }
N(_c      ) { A(5) C(1); }
N(one) { σ->printf("1\n"), C(0); }
N(on_draw) { σ->printf("5\n"), A(7) C(1); }
N(show1) {
  A17(
    ο[0],
      ο[0],
        one, God, ψ[0001],
      ο[3],
    ο[5],
      ο[0],
        God, God, ψ[0010],
      ο[3],
        Got, God, ψ[0100],
      ο[3],
    ο[9]
  ) O;
}
  // const int screenWidth = 800;
  // const int screenHeight = 450;
  // InitWindow(screenWidth, screenHeight, "GUI Example!");
  // SetTargetFPS(0);
  // while (!WindowShouldClose()) {
  //   BeginDrawing();
  //   ClearBackground(RAYWHITE);
  //  DrawText("Sopo kargi gogoa", 240, 140, 20, GRAY);
  //  EndDrawing();
  // }

N(term) { C(1); }

N(_a) { A2("b", term) O; }
N(_b) { A2("a", term) O; }

// clang-format off
                          EN(tail,
on_draw,                L)EN(L,
show1,                  L)EN(L,
_c,                     L)EN(L,
_b,                     L)EN(L,
_a,               exports);
