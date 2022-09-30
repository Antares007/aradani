#include "arsi_ie.h"
#include "oars.h"
#include "oars_logn.h"
#include <stdio.h>

void Got(OARS);
void God(OARS);
void Gor(OARS);
void map_pith(OARS);
extern n_t Τ[];
extern void *raylibfun[];
extern void *stdiofun[];
// clang-format off
                                    EN(Got,
God,                              L)EN(L,
Gor,                              L)EN(L,
Got,                              L)E(L,
"raylibfun", &raylibfun,          L)E(L,
"stdiofun", &stdiofun,      exports);
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
  if (name[0] == '_')
    printf(">>> %s %lu\n", name, α), A3(export, run_epoll, Τ[010]) O;
  else
    nar(T);
}
N(run_bark) { A5(map_pith, Τ[0], Τ[010], run_epoll, Τ[010]) O; }

#include "raylib.h"

p_t qp[3][5];
W_t qw = 0, qr = 0;
N(queue) {
  qp[qw][4].v = 0;
  qw = (qw + 1) % sizeof(qp) / sizeof(*qp);
  ρ[--σ].v = ο[--α].v;
}
N(next) {}

int main() {
  printf("%lu\n", sizeof(qp) / sizeof(*qp));
  return 0;
  p_t ο[0x1000];
  Q_t α = 0;
  p_t σ[0x1000];
  Q_t ρ = sizeof(σ) / sizeof(*σ);
  ο[--ρ].v = ray_not;
  ο[--ρ].v = ray_and;
  ο[--ρ].v = ray_oor;
  A7("src/a_show.pith", root, run_bark, "src/a_pith2.pith", root, run_bark,
     Τ[030])
  O;

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
