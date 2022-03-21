#include "../oars.h"
#include <stdlib.h>

N(os_unroll) {
  R(p_t *, rso);
  Q_t wc = rso[-1].Q;
  ρ -= wc;
  for (Q_t i = 0; i < wc; i++)
    ο[ρ + i].v = rso[i].v;
  C(1);
}
N(os_unsoll) {
  R(p_t *, rso);
  Q_t wc = rso[-1].Q;
  for (Q_t i = 0; i < wc; i++)
    σ[α + i].v = rso[i].v;
  α += wc, C(1);
}
N(os_roll_n) {
  R(Q_t, wc);
  p_t *rso = malloc(sizeof(p_t) * (wc + 1));
  rso += 1;
  for (Q_t i = 0; i < wc; i++)
    rso[i].v = ο[ρ + i].v;
  ρ += rso[-1].Q = wc;
  A(rso) C(1);
}
N(nar);
#include "../gotgod.h"
#define SOLL                                                                   \
  R(Q_t, wc);                                                                  \
  p_t *rso = malloc(sizeof(p_t) * (wc + 1));                                   \
  rso += 1, α -= rso[-1].Q = wc;                                               \
  for (Q_t i = 0; i < wc; i++)                                                 \
    rso[i].v = σ[α + i].v;
N(os_soll_a) {
  SOLL;
  A3(rso, god, 020) nar(T());
}
N(os_soll_n) {
  SOLL;
  A(rso) C(1);
}
N(os_soll_free) {
  R(p_t *, rso);
  free(rso - 1), C(1);
}
