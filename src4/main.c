#include "oars.h"
#include "oars_logn.h"
#include <stdio.h>

void Got(OARS);
void God(OARS);
void Gor(OARS);

N(one) { A(7) C(1); }
N(add) {
  q_t r = R.q;
  q_t l = R.q;
  A(l + r) C(1);
}
N(ray_not) {}
N(ray_and) { printf("%lu\n", ο[--α].q); }
N(ray_oor) {}
void da(OARS);
void da2(OARS);
void da4(OARS);
void ara2da2an2(OARS);
N(three) { A2(3, God); }
N(setray_ara) {
  RN(Q_t *, rayp);
  *rayp = 2, C(*rayp);
}
N(setray_da) {
  RN(Q_t *, rayp);
  *rayp = 1, C(*rayp);
}
N(setray_an) {
  RN(Q_t *, rayp);
  *rayp = 0, C(*rayp);
}
N(setray) {
  RN(Q_t *, rayp);
  A7(rayp, setray_ara, rayp, setray_da, rayp, setray_an, ara2da2an2);
}
void aradaan(OARS);
void ara3da3an3(OARS);
void an(OARS);
void ara(OARS);
// clang-format off
N(Main) {
  A11(Got,
      Got, Got, ara,
      God, God, da,
      Gor, Gor, an, ara3da3an3);
  // A10(Gor, one, da, one, da,  add, da, 1, add, da2);
}
N(Setup) {
  ο[--ρ].v = ray_not;
  ο[--ρ].v = ray_and;
  ο[--ρ].v = ray_oor;
  Main(T);
}
int main() {
  p_t ο[4096];
  Q_t α = 0, ρ = sizeof(ο) / sizeof(*ο), σ = ρ / 4;
  Setup(T);
  return 0;
}
