// TODO: rename soll to sigma
#include "../gotgod.h"
#include "../oars.h"
#include "pith_coords.h"
#include "queue.h"
#include <stdlib.h>
void page_init();
p_t *page_alloc();
void page_free(p_t *);
N(nar);
N(os_next);
static NP(soll_not) {}
static N(soll_and) { os_next(T()); }
static NP(soll_oor) {}

void os_soll_init() { page_init(); }
p_t *os_soll_alloc() {
  p_t *sοll = page_alloc();
  if (sοll == 0)
    return sοll;
  sοll += 5;
  sοll[Ǎ].Q = sοll[Φ].Q = 0;
  sοll[Σ].Q = 504;
  sοll[506].c = soll_not;
  sοll[505].c = soll_and;
  sοll[504].c = soll_oor;
  return sοll;
}
N(os_soll_n) {
  R(Q_t, wc);
  if (α < wc)
    return C(2);
  p_t *sοll = os_soll_alloc();
  if (sοll == 0)
    return C(2);
  α -= sοll[Ǎ].Q = wc;
  for (Q_t i = 0; i < wc; i++)
    sοll[i].v = σ[α + i].v;
  sοll[Φ].p = ο;
  Α(sοll) C(1);
}
N(os_roll) {
  R(n_t, next);
  p_t *sοll = os_soll_alloc();
  if (sοll == 0) return C(2);
  Q_t wc = ο[Σ].Q - ρ;
  if (wc > sοll[Σ].Q) return C(2);
  for (Q_t i = 0; i < wc; i++)
    sοll[i].v = σ[ρ + i].v;
  ρ += sοll[Ǎ].Q = wc;
  sοll[Φ].p = ο;
  Α(sοll, next) O;
}
N(os_soll) {
  Q_t a = α;
  A(a) os_soll_n(T());
}
N(os_unsoll) {
  R(p_t *, sοll);
  if (σ[Σ].Q < (α + sοll[Ǎ].Q))
    return C(2);
  for (Q_t i = 0; i < sοll[Ǎ].Q; i++)
    σ[α + i].v = sοll[i].v;
  α += sοll[Ǎ].Q, C(1);
}
N(os_unroll) {
  R(p_t *, sοll);
  if (α < (ρ - sοll[Ǎ].Q))
    return C(2);
  ρ -= sοll[Ǎ].Q;
  for (Q_t i = 0; i < sοll[Ǎ].Q; i++)
    σ[ρ + i].v = sοll[i].v;
  C(1);
}
N(os_soll_dup) {
  R(p_t *, sοll);
  p_t *dsοll = os_soll_alloc();
  dsοll[Ǎ].Q = sοll[Ǎ].Q;
  for (Q_t i = 0; i < sοll[Ǎ].Q; i++)
    dsοll[i].v = sοll[i].v;
  Α(sοll, dsοll) C(1);
}
N(os_soll_free) {
  R(p_t *, sοll);
  page_free(sοll - 5), C(1);
}
N(os_unsoll_free) {
  R(p_t *, sοll);
  Α(sοll, os_unsoll, sοll, os_soll_free, 020, nar) O;
}
N(os_unsoll_apply) {
  R(p_t *, sοll);
  Α(sοll, os_unsoll, dot, 010, nar) O;
}
N(os_unsoll_free_apply) {
  R(p_t *, sοll);
  Α(sοll, os_unsoll_free, dot, 010, nar) O;
}
