#include "oars.h"
#include <stdio.h>

N(got) { C(2); }
N(god) { C(1); }
N(gor) { C(0); }

N(one) { A(7) C(1); }
N(add) {
  q_t r = R.q;
  q_t l = R.q;
  A(l + r) C(1);
}
N(and) {
  ρ--;
  ο[ρ - σ * 0].v = gor;
  ο[ρ - σ * 1].v = ο[--α].v;
  ο[ρ - σ * 2].v = got;
  ο[α - 1].c(ο, α - 1, ρ, σ);
}
N(ray_not) { printf("NOT\n"); }
N(ray_and) { printf("AND %lu\n", ο[--α].q); }
N(ray_oor) { printf("OOR\n"); }
int main() {
  p_t ο[4096];
  Q_t α = 0, ρ = sizeof(ο) / sizeof(*ο), σ = ρ / 4;
  --ρ;
  ο[ρ - σ * 2].v = ray_not;
  ο[ρ - σ * 1].v = ray_and;
  ο[ρ - σ * 0].v = ray_oor;
  A5(one, one, and, add, and) O;
  return 0;
}
