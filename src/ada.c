// clang-format off
#include "oars.h"
typedef void (*fun_t)();
static fun_t mc21_lookup[22];
N(init_mc21);
N(init_ada) { A2(mc21_lookup, init_mc21) O; }
N(ada_not) {
  ρ += 3;
  Q_t oc = ο[ρ++].Q, ac = ο[ρ++].Q, nc = ο[ρ++].Q, f = nc != 0;
  while (nc) ο[α++].v = ο[ρ++].v, nc--;
  ρ += ac + oc;
  f ? O : C(2);
}
N(ada_and) {
  ρ += 3;
  Q_t oc = ο[ρ++].Q, ac = ο[ρ++].Q, nc = ο[ρ++].Q, f = ac != 0;
  ρ += nc;
  while (ac) ο[α++].v = ο[ρ++].v, ac--;
  ρ += oc;
  f ? O : C(1);
}
N(ada_oor) {
  ρ += 3;
  Q_t oc = ο[ρ++].Q, ac = ο[ρ++].Q, nc = ο[ρ++].Q, f = oc != 0;
  ρ += nc + ac;
  while (oc) ο[α++].v = ο[ρ++].v, oc--;
  f ? O : C(0);
}
N(ada) {
  Q_t j = ο[--α].Q, nc = ((j & 0700) >> 6), ac = ((j & 0070) >> 3), oc = ((j & 0007) >> 0), tc = nc + ac + oc;
  void **t = &ο[ρ-=tc].v; void **s = &ο[α-=tc].v;
  ο[--ρ].Q = nc, ο[--ρ].Q = ac, ο[--ρ].Q = oc, ο[--ρ].c = ada_not, ο[--ρ].c = ada_and, ο[--ρ].c = ada_oor, mc21_lookup[tc](ο, α, ρ, t, s);
}
