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
N(U){C(1);} N(V){C(1);} N(W){C(1);} N(X){C(1);} N(Y){C(1);} N(Z){C(1);}
                  EN(Got,
God,            L)EN(L,
Gor,            L)EN(L,
Got,            L)EN(L,
U,              L)EN(L,
V,              L)EN(L,
W,              L)EN(L,
X,              L)EN(L,
Y,              L)EN(L,
Z,        exports);
// clang-format on

N(root) { α--, A1(exports) C(1); }

N(ray_not) {}
N(ray_and) { printf("%lu\n", σ[--α].q); }
N(ray_oor) {}

N(ls_exports) {
  RN(const char *, fname);
  RN(n_t, exp);
  RN(n_t, nar);
  RN(const char *, name);
  printf("%s:%s %p %p\n", fname, name, nar, exp);
  A3(exp, ls_exports, Τ[010]) O;
}

int main() {
  p_t ο[0x1000];
  Q_t α = 0;
  p_t σ[0x1000];
  Q_t ρ = sizeof(σ) / sizeof(*σ);
  ο[--ρ].v = ray_not;
  ο[--ρ].v = ray_and;
  ο[--ρ].v = ray_oor;
  A7("src/a_pith2.pith", root, load_pith, Τ[0], Τ[010], ls_exports, Τ[010]) O;
  return 0;
}
