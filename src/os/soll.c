#include "../oars.h"
#include <stdlib.h>
N(nar);
N(os_unsoll) {
  R(p_t *, sοll);
  Q_t wc = sοll[-1].Q;
  for (Q_t i = 0; i < wc; i++)
    σ[α + i].v = sοll[i].v;
  α += wc, C(1);
}
N(os_soll_n) {
  R(Q_t, wc);
  p_t *sοll = malloc(sizeof(p_t) * (wc + 1));
  sοll += 1, α -= sοll[-1].Q = wc;
  for (Q_t i = 0; i < wc; i++)
    sοll[i].v = σ[α + i].v;
  Α(sοll) C(1);
}
NP(os_soll) {
  q_t wc = α;
  Α(wc, os_soll_n) O;
}
N(os_soll_dup) {
  R(p_t *, sοll);
  p_t *ns = malloc((sοll[-1].Q + 1) * sizeof(void *));
  ns += 1, ns[-1].Q = sοll[-1].Q;
  for (Q_t i = 0; i < sοll[-1].Q; i++)
    ns[i].v = sοll[i].v;
  Α(sοll, ns) C(1);
}
N(os_soll_free) {
  R(p_t *, sοll);
  free(sοll - 1), C(1);
}
NP(os_unsoll_free) {
  R(p_t *, sοll);
  Α(sοll, os_unsoll, sοll, os_soll_free, 020, nar) O;
}
static N(dot) { O; }
N(os_unsoll_apply) {
  R(p_t *, sοll);
  Α(sοll, os_unsoll, dot, 010, nar) O;
}
N(os_unsoll_free_apply) {
  R(p_t *, sοll);
  Α(sοll, os_unsoll_free, dot, 010, nar) O;
}

N(os_unroll) {
  R(p_t *, sοll);
  Q_t wc = sοll[-1].Q;
  ρ -= wc;
  for (Q_t i = 0; i < wc; i++)
    ο[ρ + i].v = sοll[i].v;
  C(1);
}
N(os_roll_n) {
  R(Q_t, wc);
  p_t *sοll = malloc(sizeof(p_t) * (wc + 1));
  sοll += 1;
  for (Q_t i = 0; i < wc; i++)
    sοll[i].v = ο[ρ + i].v;
  ρ += sοll[-1].Q = wc;
  A(sοll) C(1);
}
