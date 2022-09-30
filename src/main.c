#include "arsi_ie.h"
#include "oant.h"
#include "oant_logn.h"
#include <stdio.h>

void Got(OANT);
void God(OANT);
void Gor(OANT);
void map_pith(OANT);
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
N(ray_and) { printf("%lu\n", ν[--τ].q); }
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
  τ -= 1;
  RN(n_t, export);
  RN(n_t, nar);
  RN(const char *, name);
  if (name[0] == '_')
    printf(">>> %s %lu\n", name, τ), A3(export, run_epoll, Τ[010]) O;
  else
    nar(T);
}
N(run_bark) { A5(map_pith, Τ[0], Τ[010], run_epoll, Τ[010]) O; }
// Ο
//Ν Τ
// Α
// Otar
// Nino
// Nika
// Nargo
// Tina
// Andria
// Achiko
#define QPSize 64
p_t qp[QPSize][32];
W_t qw = 0, qr = 0;
N(unroll1) {
  p_t *p = qp[qr];
  qr = (qr + 1) % QPSize;
  ν[τ + 0].v = p[1 + 0].v;
  τ += 1;
  O;
}
N(queue1) {
  p_t *p = qp[qw];
  qw = (qw + 1) % QPSize;
  p[0].v = unroll1;
  τ -= 1;
  p[1 + 0].v = ν[τ + 0].v;
  O;
}
N(next) { qp[qr][0].c(T); }

#include "raylib.h"
N(pint_qps) {
  printf("%d %d\n", qw ,qr);
  O;
}
int main() {
  p_t ο[0x1000];
  Q_t α = sizeof(ο) / sizeof(*ο);
  p_t ν[0x1000];
  Q_t τ = 0;
  ο[--α].v = ray_not;
  ο[--α].v = ray_and;
  ο[--α].v = ray_oor;
  A5(next, pint_qps, Gor, queue1, pint_qps) O;
  //A7(
  //  "src/a_show.pith",  root, run_bark,
  //  "src/a_pith2.pith",  root, run_bark, Τ[030]
  //) O;
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
