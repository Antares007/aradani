#include "oant.h"
#include "oant_logn.h"
#include <stdio.h>

N(seven) { A(7) C(1); }
N(add) {
  q_t r = R.q;
  q_t l = R.q;
  A(l + r) C(1);
}

void da(OANT);
N(CountTo14) { A5(seven, seven, da, add, da) O; }

void Got(OANT);
void God(OANT);
void Gor(OANT);
extern n_t ψ[01000];
// clang-format off
N(TestAraDaNi) {
  A13(7,   God, ψ[0],
      Got, Got, ψ[0100],
      God, God, ψ[0010],
      Gor, Gor, ψ[0001], ψ[0333]) O;
}
// clang-format on
N(ray_not) {}
N(ray_and) { printf("%lu\n", ν[--τ].q); }
N(ray_oor) {}
int main() {
  p_t ω[0x1000];
  Q_t α = sizeof(ω) / sizeof(*ω);
  p_t ν[0x1000];
  Q_t τ = 0;
  ω[--α].v = ray_not;
  ω[--α].v = ray_and;
  ω[--α].v = ray_oor;
  TestAraDaNi(T);
  CountTo14(T);
  return 0;
}
