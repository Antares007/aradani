#include "arsi.h"
#include "raylibfun.h"
#include "stdiofun.h"
rayfun_t *ρ;
stdiofun_t *σ;
n_t Got, God;
// clang-format off
                   I(Gor,
"God", God,      L)I(L,
"Got", Got,      L)I(L,
"ρ", ρ,          L)I(L,
"σ", σ,          ι);
// clang-format on
N(InitWindow) {
  const int screenWidth = 800;
  const int screenHeight = 450;
  ρ->InitWindow(screenWidth, screenHeight, "GUI Example!");
  ρ->SetTargetFPS(0);
  C(1);
}
N(WindowShouldNotClose) { C(!ρ->WindowShouldClose()); }
N(BeginDrawing) { ρ->BeginDrawing(); ρ->ClearBackground(RAYWHITE); C(1); }
N(EndDrawing) { ρ->EndDrawing(); C(1); }
N(Draw) { ρ->DrawText("aba mamao!", 240, 140, 44, GRAY); C(1); }
N(loop) {
  A11(                                            δ[0],
      WindowShouldNotClose, BeginDrawing, ψ[010], δ[3],
      Draw,                                       δ[1],
      EndDrawing,                                 δ[1],
      loop,                                       δ[1]) O;
}
N(xxx) {
  A3(InitWindow, loop, ψ[010]) O;
}
N(counter) {
  //(
  //  Δ.draw,
  //    Δ.draw,
  //    "+",
  //    Δ.text,
  //  Δ.button,
  //    Δ.draw,
  //    "-",
  //    Δ.text,
  //  Δ.button,
  //  "0",
  //  Δ.text,

  //  Σ.aba
  //) O;
}
N(treeasnumbers) {
  A17(
    δ[0],
      δ[0],
        God, God, ψ[0001],
      δ[3],
    δ[5],
      δ[0],
        God, God, ψ[0010],
      δ[3],
        Got, treeasnumbers, ψ[0100],
      δ[3],
    δ[9]
  ) O;
}
N(prn) { RN(Q_t, n); for(Q_t i = 0; i < n; i++) σ->printf(" "); σ->printf("%lu\n", n); C(1); }
N(tree) {
  RN(Q_t, n);
  if(n>10) return C(1);
  A13(              δ[0],
      n+1, prn,     δ[2],
      n+2, prn,     δ[2],
      n+1, tree,    δ[2],
      n+4, prn,     δ[2]
  ) O;
}
N(show) { A2(0, tree) O; }
// clang-format off
            EN(ζ,
show,     ε);
