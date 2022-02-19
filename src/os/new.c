#include "../oars.h"
#include "queue.h"
#include <stdlib.h>

#define RAY_ALG(Index)                                                         \
  S(ray_al_##Index) { ρ += 6, ο[ρ - 3 + Index].c(T()); }
#define Co(o, r) (o)[(o)[1].Q + r].c(σ, α, (o), (o)[1].Q)

RAY_ALG(2)
RAY_ALG(1)
RAY_ALG(0)
S(rgof_not) {
  p_t *pο = ο[0].p;
  free(ο);
  Co(pο, 2);
}
static void append_to_parent_queue(p_t *ο) {
  QUEUE *q;
  QUEUE *my_q = (QUEUE *)&ο[2];
  QUEUE *parent_q = (QUEUE *)&ο[0].p[2];
  if (my_q != (q = QUEUE_NEXT(my_q)))
    QUEUE_PREV(q) = QUEUE_PREV(parent_q), QUEUE_PREV_NEXT(my_q) = parent_q,
    QUEUE_PREV_NEXT(parent_q) = q, QUEUE_PREV(parent_q) = QUEUE_PREV(my_q),
    QUEUE_INIT(my_q);
}
S(rgof_and) { append_to_parent_queue(ο), Co(ο[0].p, 1); }
S(rgof_oor) { append_to_parent_queue(ο), Co(ο[0].p, 0); }
N(os_new_psn) {
  R(const char *, name);
  R(Q_t, nρ);
  R(p_t *, oο);
  p_t *nο = malloc(nρ * sizeof(void *));

  nο[--nρ].c = rgof_not, nο[--nρ].c = rgof_and, nο[--nρ].c = rgof_oor;
  nο[--nρ].c = σ[--α].c, nο[--nρ].c = σ[--α].c, nο[--nρ].c = σ[--α].c;
  nο[--nρ].c = ray_al_2, nο[--nρ].c = ray_al_1, nο[--nρ].c = ray_al_0;

  nο[0].p = oο, nο[1].Q = nρ, QUEUE_INIT((QUEUE *)&nο[2]),
  nο[4].v = (void *)name;

  A(nο) C(1);
}
N(os_new) { A4(ο[0].p, 512, "os_new", os_new_psn) O; }
N(nar_not);
N(nar_and);
N(nar_oor);
N(os_co_psn) {
  R(const char *, name);
  R(Q_t, nρ);
  R(p_t *, oο);
  R(Q_t, j);
  Q_t nc = ((j & 0700) >> 6), //
      ac = ((j & 0070) >> 3), //
      oc = ((j & 0007) >> 0), //
      tc = nc + ac + oc;
  p_t *nο = malloc(nρ * sizeof(void *));
  nο[--nρ].c = rgof_not, nο[--nρ].c = rgof_and, nο[--nρ].c = rgof_oor;

  while (tc)
    tc--, nο[--nρ].v = σ[--α].v;

  nο[--nρ].Q = nc, nο[--nρ].Q = ac, nο[--nρ].Q = oc;
  nο[--nρ].c = nar_not, nο[--nρ].c = nar_and, nο[--nρ].c = nar_oor;

  nο[0].p = oο, nο[1].Q = nρ, QUEUE_INIT((QUEUE *)&nο[2]),
  nο[4].v = (void *)name;

  A(nο) C(1);
}
N(os_co) { Α(ο[0].p, 512, "os_co", os_co_psn) O; }
