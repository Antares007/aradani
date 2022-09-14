#include "oars.h"
#include "oars_logn.h"
#include <stdio.h>

void Got(OARS);
void God(OARS);
void Gor(OARS);

N(seven) { A(7) C(1); }
N(add) {
  q_t r = R.q;
  q_t l = R.q;
  A(l + r) C(1);
}

void da(OARS);
extern n_t Τ[01000];
N(CountTo14) { A5(seven, seven, da, add, da) O; }

// clang-format off
N(TestAraDaNi) {
  A12(God, Τ[0],
      Got, Got, Τ[0100],
      God, God, Τ[0010],
      Gor, Gor, Τ[0001], Τ[0333]) O;
}
// clang-format on
N(ray_not) {}
N(ray_and) { printf("%lu\n", σ[--α].q); }
N(ray_oor) {}
N(Setup) {
  ο[--ρ].v = ray_not;
  ο[--ρ].v = ray_and;
  ο[--ρ].v = ray_oor;
  CountTo14(T);
}
int main() {
  p_t ο[0x1000];
  Q_t α = 0;
  p_t σ[0x1000];
  Q_t ρ = sizeof(σ) / sizeof(*σ);
  Setup(T);
  return 0;
}
