#include "arsi_ie.h"
#include "oars.h"
#include "oars_logn.h"
#include <stdio.h>

void Got(OARS);
void God(OARS);
void Gor(OARS);
void map_pith(OARS);
extern n_t Τ[];
extern void *raylib_fun[];

// clang-format off
                    EN(Got,
God,              L)EN(L,
Gor,              L)EN(L,
Got,              L)EN(L,
raylib_fun, exports);
// clang-format on

N(root) { A1(exports) C(1); }

N(ray_not) {}
N(ray_and) { printf("%lu\n", σ[--α].q); }
N(ray_oor) {}

N(ls_exports) {
  RN(const char *, fname);
  RN(n_t, exp);
  RN(n_t, nar);
  (void)nar;
  RN(const char *, name);
  printf("%s:%s\n", fname, name);
  A3(exp, ls_exports, Τ[010]) O;
}
N(run_epoll) {
  α -= 1;
  RN(n_t, export);
  RN(n_t, nar);
  RN(const char *, name);
  if (name[0] == '_') {
    printf(">%s %lu\n", name, α);
    A3(export, run_epoll, Τ[010]) O;
  } else
    nar(T);
}
N(run_pith) {
  A5(map_pith, Τ[0], Τ[010], run_epoll, Τ[010]) O;
}
#include "raylib.h"
int main() {
  p_t ο[0x1000];
  Q_t α = 0;
  p_t σ[0x1000];
  Q_t ρ = sizeof(σ) / sizeof(*σ);
  ο[--ρ].v = ray_not;
  ο[--ρ].v = ray_and;
  ο[--ρ].v = ray_oor;
  A3("src/a_show.pith", root, run_pith) O;

  const int screenWidth = 800;
  const int screenHeight = 450;
  InitWindow(screenWidth, screenHeight, "GUI Example!");
  SetTargetFPS(0);
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawText("PLACE MOUSE OVER INPUT BOX!", 240, 140, 20, GRAY);

    EndDrawing();
  }
  return 0;
}
