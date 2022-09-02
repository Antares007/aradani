#include "oars.h"
#include <stdio.h>
#define LOG printf("α:%lu ρ:%lu %s\n", α, ρ, __FUNCTION__)

N(got);
N(god);
N(gor);

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
N(and2) {
  ρ--;
  ο[ρ - σ * 0].v = gor;
  ο[ρ - σ * 1].v = ο[--α].v;
  ο[ρ - σ * 2].v = got;
  ο[α - 1].c(ο, α - 1, ρ, σ);
}
N(ray_not) { LOG; }
N(ray_and) {
  LOG;
  printf("%lu\n", ο[--α].q);
}
N(ray_oor) { LOG; }
N(da1);
N(da2);
N(da4);
int main() {
  p_t ο[4096];
  Q_t α = 0, ρ = sizeof(ο) / sizeof(*ο), σ = ρ / 4;
  --ρ;
  ο[ρ - σ * 2].v = ray_not;
  ο[ρ - σ * 1].v = ray_and;
  ο[ρ - σ * 0].v = ray_oor;
  A8(one, 8, god, god, da1, da4, add, da1) O;
  return 0;
}
