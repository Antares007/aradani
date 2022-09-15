#include "../oars.h"

void page_free(p_t *);
N(nar);

static N(cb) {
  R(Q_t , ray);
  R(Q_t , oρ);
  R(p_t*, oο);
  R(p_t*, oσ);
  for(Q_t i = 0; i < α; i++)
    oσ[oσ[Ǎ].Q + i].v = σ[i].v;
  oσ[Ǎ].Q += α;
  page_free(σ - 5);
  oσ[oρ + ray].c(oο, oσ[Ǎ].Q, oρ, oσ);
}
static N(call_n_n) {
  R(p_t*, oο);
  R(p_t*, oσ);
  σ[Ǎ].Q = α;

  oσ[oσ[Ǎ].Q++].p = σ;
  oσ[oσ[Ǎ].Q++].p = ο;
  oσ[oσ[Ǎ].Q++].Q = ρ;
  oσ[oσ[Ǎ].Q++].Q = 2;
  oσ[oσ[Ǎ].Q++].c = cb;

  oσ[oσ[Ǎ].Q++].p = σ;
  oσ[oσ[Ǎ].Q++].p = ο;
  oσ[oσ[Ǎ].Q++].Q = ρ;
  oσ[oσ[Ǎ].Q++].Q = 1;
  oσ[oσ[Ǎ].Q++].c = cb;

  oσ[oσ[Ǎ].Q++].p = σ;
  oσ[oσ[Ǎ].Q++].p = ο;
  oσ[oσ[Ǎ].Q++].Q = ρ;
  oσ[oσ[Ǎ].Q++].Q = 0;
  oσ[oσ[Ǎ].Q++].c = cb;

  oσ[oσ[Ǎ].Q++].Q = 0555;
  nar(oο, oσ[Ǎ].Q, oσ[Σ].Q, oσ);
}
N(os_soll_n);
N(os_call_n) {
  R(Q_t , wc);
  R(p_t*, oο);
  Α(wc, os_soll_n, oο, call_n_n, 020, nar) O;
}

