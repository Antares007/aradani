#include "arsi.h"
#include "raylibfun.h"
#include "stdiofun.h"
rayfun_t *ρ;
stdiofun_t *σ;
n_t *ψ;
n_t *δ, Got, God;
// clang-format off
                   I(Gor,
"God", God,      L)I(L,
"Got", Got,      L)I(L,
"δ", δ,          L)I(L,
"ρ", ρ,          L)I(L,
"σ", σ,          L)I(L,
"ψ", ψ,          ι);
// clang-format on

N(on_tick2) { A(God) O; }
N(_c      ) { A(5) C(1); }
N(one) { σ->printf("1\n"), C(0); }
N(on_draw) { σ->printf("5\n"), A(7) C(1); }
N(show) {
  A17(
    δ[0],
      δ[0],
        one, God, ψ[0001],
      δ[3],
    δ[5],
      δ[0],
        God, God, ψ[0010],
      δ[3],
        Got, God, ψ[0100],
      δ[3],
    δ[9]
  ) O;
}
  // const int screenWidth = 800;
  // const int screenHeight = 450;
  // InitWindow(screenWidth, screenHeight, "GUI Example!");
  // SetTargetFPS(0);
  // while (!WindowShouldClose()) {
  //   BeginDrawing();
  //   ClearBackground(RAYWHITE);
  //  DrawText("aba mamao!", 240, 140, 20, GRAY);
  //  EndDrawing();
  // }

N(term) { C(1); }

N(_a) { A2("b", term) O; }
N(_b) { A2("a", term) O; }

// clang-format off
                          EN(ζ,
on_draw,                L)EN(L,
show,                   L)EN(L,
_c,                     L)EN(L,
_b,                     L)EN(L,
_a,                     ε);
