#include "oars.h"
N(ada_not) {
  ρ += 3;
  Q_t oc = ο[ρ++].Q, ac = ο[ρ++].Q, nc = ο[ρ++].Q, f = nc != 0;
  while (nc)
    ο[α++].v = ο[ρ++].v, nc--;
  ρ += ac + oc;
  f ? O : C(2);
}
N(ada_and) {
  ρ += 3;
  Q_t oc = ο[ρ++].Q, ac = ο[ρ++].Q, nc = ο[ρ++].Q, f = ac != 0;
  ρ += nc;
  while (ac)
    ο[α++].v = ο[ρ++].v, ac--;
  ρ += oc;
  f ? O : C(1);
}
N(ada_oor) {
  ρ += 3;
  Q_t oc = ο[ρ++].Q, ac = ο[ρ++].Q, nc = ο[ρ++].Q, f = oc != 0;
  ρ += nc + ac;
  while (oc)
    ο[α++].v = ο[ρ++].v, oc--;
  f ? O : C(0);
}
N(ada) {
  Q_t j = ο[--α].Q, nc = ((j & 0700) >> 6), ac = ((j & 0070) >> 3),
      oc = ((j & 0007) >> 0), tc = nc + ac + oc;
  while (tc)
    ο[--ρ].v = ο[--α].v, tc--;
  ο[--ρ].Q = nc, ο[--ρ].Q = ac, ο[--ρ].Q = oc, ο[--ρ].c = ada_not,
  ο[--ρ].c = ada_and, ο[--ρ].c = ada_oor, O;
}
