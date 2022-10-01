#include "arsi_ie.h"
#include "oant.h"
#include "oant_logn.h"
#include <stdio.h>

void Got(OANT);
void God(OANT);
void Gor(OANT);
void map_pith(OANT);
extern n_t ψ[01000];
extern n_t ο[32];
extern void *raylibfun[];
extern void *stdiofun[];
// clang-format off
                                    E(Got,
"God", God,                       L)E(L,
"Gor", Gor,                       L)E(L,
"Got", Got,                       L)E(L,
"raylibfun", &raylibfun,          L)E(L,
"stdiofun", &stdiofun,            L)E(L,
"ο", &ο,                          L)E(L,
"ψ", &ψ,                    exports);
// clang-format on

N(root) { A1(exports) C(1); }

N(ls_exports) {
  RN(const char *, fname);
  RN(n_t, exp);
  RN(n_t, nar);
  (void)nar;
  RN(const char *, name);
  printf("%s:%s\n", fname, name);
  A3(exp, ls_exports, ψ[010]) O;
}
N(run_epoll) {
  τ -= 1;
  RN(n_t, export);
  RN(n_t, nar);
  RN(const char *, name);
  if (name[0] == '_')
    printf(">>> %s %lu\n", name, τ), A3(export, run_epoll, ψ[010]) O;
  else
    nar(T);
}
N(run_bark) { A5(map_pith, ψ[0], ψ[010], run_epoll, ψ[010]) O; }
#include "raylib.h"

void queue_init();
void next(OANT);
// clang-format off
N(ray_not) {}
N(ray_and) { if (τ) printf("%lu\n", ν[τ - 1].q); else printf("\n"); α -= 3, next(T); }
N(ray_oor) {}
int main() {
  queue_init();
  p_t ω[0x1000];
  Q_t α = sizeof(ω) / sizeof(*ω);
  p_t ν[0x1000];
  Q_t τ = 0;
  ω[--α].v = ray_not;
  ω[--α].v = ray_and;
  ω[--α].v = ray_oor;
  A3(
    "src/a_show.pith",  root, run_bark
//    "src/a_pith2.pith",  root, run_bark, ψ[030]
  ) O;
  // const int screenWidth = 800;
  // const int screenHeight = 450;
  // InitWindow(screenWidth, screenHeight, "GUI Example!");
  // SetTargetFPS(0);
  // while (!WindowShouldClose()) {
  //   BeginDrawing();
  //   ClearBackground(RAYWHITE);
  //  DrawText("Sopo kargi gogoa", 240, 140, 20, GRAY);
  //  EndDrawing();
  //}
  return 0;
}
