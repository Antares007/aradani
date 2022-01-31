#include "gorgodandgot.h"
#include "oars.h"
// clang-format off
typedef void (*fun_t)();
static fun_t mc21_lookup[22];
static fun_t ada_not_jun[2];
static fun_t ada_and_jun[2];
static fun_t ada_oor_jun[2];

static N(ada_not) {
  ρ += 3;
  Q_t oc = ο[ρ++].Q, ac = ο[ρ++].Q, nc = ο[ρ++].Q;
  void **t = &σ[α].v, **s = &ο[ρ].v;
  α += nc, ρ += nc + ac + oc;
  ada_not_jun[nc != 0](T(), t, s, nc);
}
static N(ada_and) {
  ρ += 3;
  Q_t oc = ο[ρ++].Q, ac = ο[ρ++].Q, nc = ο[ρ++].Q;
  ρ += nc;
  void **t = &σ[α].v, **s = &ο[ρ].v;
  α += ac, ρ += ac + oc;
  ada_and_jun[ac != 0](T(), t, s, ac);
}
static N(ada_oor) {
  ρ += 3;
  Q_t oc = ο[ρ++].Q, ac = ο[ρ++].Q, nc = ο[ρ++].Q;
  ρ += nc + ac;
  void **t = &σ[α].v, **s = &ο[ρ].v;
  α += oc, ρ += oc;
  ada_oor_jun[oc != 0](T(), t, s, oc);
}
N(ada) {
  Q_t j = σ[--α].Q,
      nc = ((j & 0700) >> 6),
      ac = ((j & 0070) >> 3),
      oc = ((j & 0007) >> 0),
      tc = nc + ac + oc;
  void **t = &ο[ρ -= tc].v, **s = &σ[α -= tc].v;
  ο[--ρ].Q = nc, ο[--ρ].Q = ac, ο[--ρ].Q = oc,
  ο[--ρ].c = ada_not, ο[--ρ].c = ada_and, ο[--ρ].c = ada_oor,
  mc21_lookup[tc](T(), dot, t, s);
}
static void
ada_not_mc(OARS, void **t, void **s, Q_t wc) { mc21_lookup[wc](T(), dot, t, s); };
static void
ada_and_mc(OARS, void **t, void **s, Q_t wc) { mc21_lookup[wc](T(), dot, t, s); };
static void
ada_oor_mc(OARS, void **t, void **s, Q_t wc) { mc21_lookup[wc](T(), dot, t, s); };
void init_mc21(void**);
void init_ada() {
  ada_not_jun[0] = got, ada_not_jun[1] = ada_not_mc;
  ada_and_jun[0] = god, ada_and_jun[1] = ada_and_mc;
  ada_oor_jun[0] = gor, ada_oor_jun[1] = ada_oor_mc;
  init_mc21((void*)mc21_lookup);
}
