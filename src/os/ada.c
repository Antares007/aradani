#include "../oars.h"

S(ada_not) {
  ρ += 3;
  Q_t oc = ο[ρ++].Q, ac = ο[ρ++].Q, nc = ο[ρ++].Q, f = nc;
  while (nc)
    nc--, σ[α++].v = ο[ρ++].v;
  ρ += ac + oc;
  f ? O : C(2);
}
S(ada_and) {
  ρ += 3;
  Q_t oc = ο[ρ++].Q, ac = ο[ρ++].Q, nc = ο[ρ++].Q, f = ac;
  ρ += nc;
  while (ac)
    ac--, σ[α++].v = ο[ρ++].v;
  ρ += oc;
  f ? O : C(1);
}
S(ada_oor) {
  ρ += 3;
  Q_t oc = ο[ρ++].Q, ac = ο[ρ++].Q, nc = ο[ρ++].Q, f = oc;
  ρ += nc + ac;
  while (oc)
    oc--, σ[α++].v = ο[ρ++].v;
  f ? O : C(0);
}

N(ada) {
  Q_t j = σ[--α].Q,           //
      nc = ((j & 0700) >> 6), //
      ac = ((j & 0070) >> 3), //
      oc = ((j & 0007) >> 0), //
      tc = nc + ac + oc;
  while (tc)
    tc--, ο[--ρ].v = σ[--α].v;
  ο[--ρ].Q = nc, ο[--ρ].Q = ac, ο[--ρ].Q = oc;
  ο[--ρ].c = ada_not, ο[--ρ].c = ada_and, ο[--ρ].c = ada_oor;
  O;
}
