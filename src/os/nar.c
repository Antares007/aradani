#include "../oars.h"

#define DESTRUCTJ                                                              \
  nc = ((j & 0700) >> 6), ac = ((j & 0070) >> 3), oc = ((j & 0007) >> 0)
#define DESTRUCT                                                               \
  ρ += 3;                                                                      \
  Q_t j = ο[ρ++].Q, DESTRUCTJ
N(nar_not) {
  DESTRUCT, f = nc;
  while (nc)
    nc--, σ[α++].v = ο[ρ++].v;
  ρ += ac + oc;
  f ? O : C(2);
}
N(nar_and) {
  DESTRUCT, f = ac;
  ρ += nc;
  while (ac)
    ac--, σ[α++].v = ο[ρ++].v;
  ρ += oc;
  f ? O : C(1);
}
N(nar_oor) {
  DESTRUCT, f = oc;
  ρ += nc + ac;
  while (oc)
    oc--, σ[α++].v = ο[ρ++].v;
  f ? O : C(0);
}

N(nar) {
  Q_t j = σ[--α].Q, DESTRUCTJ, tc = nc + ac + oc;
  while (tc)
    tc--, ο[--ρ].v = σ[--α].v;
  ο[--ρ].Q = j;
  ο[--ρ].c = nar_not, ο[--ρ].c = nar_and, ο[--ρ].c = nar_oor;
  O;
}
#undef DESTRUCT
#undef DESTRUCTJ
