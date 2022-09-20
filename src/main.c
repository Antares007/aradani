#include "arsi_ie.h"
#include "oars.h"
#include "oars_logn.h"
#include <stdio.h>

void Got(OARS);
void God(OARS);
void Gor(OARS);
void load_pith(OARS);
extern n_t Τ[01000];

// clang-format off
                  EN(Got,
God,            L)EN(L,
Gor,            L)EN(L,
Got,      exports);
// clang-format on

N(root) { α--, A1(exports) C(1); }

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
  α -= 2;
  RN(n_t, nar);
  α -= 1;
  nar(T);
}

int main() {
  p_t ο[0x1000];
  Q_t α = 0;
  p_t σ[0x1000];
  Q_t ρ = sizeof(σ) / sizeof(*σ);
  ο[--ρ].v = ray_not;
  ο[--ρ].v = ray_and;
  ο[--ρ].v = ray_oor;
  A7("src/a_show.pith", root, load_pith, Τ[0], Τ[010], run_epoll, Τ[010]) O;
  return 0;
}
