#include "../oars.h"
#include <stdlib.h>

N1(os_unsoll)(sοll,  p_t*)(
  Q_t wc = sοll[-1].Q;
  for (Q_t i = 0; i < wc; i++)
    σ[α + i].v = sοll[i].v;
  α += wc, C(1);
)
N(nar);
N1(os_soll_n)(wc, Q_t)(
  p_t *sοll = malloc(sizeof(p_t) * (wc + 1));                                  \
  sοll += 1, α -= sοll[-1].Q = wc;                                             \
  for (Q_t i = 0; i < wc; i++)                                                 \
    sοll[i].v = σ[α + i].v;
  Α(sοll) C(1);
)
No(os_soll)(
  Q_t wc = α;
  Α(wc, os_soll_n) C(1);
)
N1(os_soll_free)(sοll, p_t *)(
  free(sοll - 1), C(1);
)
Narg1(os_unsoll_free)(sοll, p_t *)(
  sοll, os_unsoll, sοll, os_soll_free, 020, nar
)
#include "../gotgod.h"
Narg1(os_unsoll_apply)(sοll, p_t *)(
  sοll, os_unsoll, dot, 010, nar
)
Narg1(os_unsoll_free_apply)(sοll, p_t *)(
  sοll, os_unsoll_free, dot, 010, nar
)

N1(os_unroll)(sοll,  p_t*)(
  Q_t wc = sοll[-1].Q;
  ρ -= wc;
  for (Q_t i = 0; i < wc; i++)
    ο[ρ + i].v = sοll[i].v;
  C(1);
)
N1(os_roll_n)(wc,  Q_t)(
  p_t *sοll = malloc(sizeof(p_t) * (wc + 1));
  sοll += 1;
  for (Q_t i = 0; i < wc; i++)
    sοll[i].v = ο[ρ + i].v;
  ρ += sοll[-1].Q = wc;
  A(sοll) C(1);
)
