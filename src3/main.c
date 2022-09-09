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
void da4(OARS);
N(Main) { A8(one, 7, god, god, da, da4, add, da); }
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
