#include "oars.h"
#include "oars_logn.h"
#include <stdio.h>

void got(OARS);
void god(OARS);
void gor(OARS);

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
N(three) { A2(3, god); }
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
// clang-format off
N(Main) {
  Q_t rayn = 9, a = α;
  A10(one, 5, god, three, da, da4, add, da, &rayn, setray);
  α = a;
  A3(got, &rayn, setray); printf("rayn: %lu\n", rayn); α = a;
  A3(god, &rayn, setray); printf("rayn: %lu\n", rayn); α = a;
  A3(gor, &rayn, setray); printf("rayn: %lu\n", rayn);
}
N(Setup) {
  --ρ;
  ο[ρ - σ * 2].v = ray_not;
  ο[ρ - σ * 1].v = ray_and;
  ο[ρ - σ * 0].v = ray_oor;
  Main(T);
}
int main() {
  p_t ο[4096];
  Q_t α = 0, ρ = sizeof(ο) / sizeof(*ο), σ = ρ / 4;
  Setup(T);
  return 0;
}
