#include "../oars.h"
#include "queue.h"
#include <stdlib.h>

#define RAY_ALG(Index)                                                         \
  S(ray_al_##Index) { ρ += 6, ο[ρ - 3 + Index].c(T()); }
#define Co(o, r) (o)[(o)[1].Q + r].c(σ, α, (o), (o)[1].Q)

RAY_ALG(2)
RAY_ALG(1)
RAY_ALG(0)
S(ray_gof_not) {
  p_t *pο = ο[0].p;
  free(ο);
  Co(pο, 2);
}
static void append_to_parent_queue(p_t *ο) {
  QUEUE *q;
  QUEUE *t = (QUEUE *)&ο[2];
  QUEUE *m = (QUEUE *)&ο[0].p[2];
  if (t != (q = QUEUE_NEXT(t))) {
    QUEUE_PREV(q) = QUEUE_PREV(m);
    QUEUE_PREV_NEXT(t) = m;
    QUEUE_PREV_NEXT(m) = q;
    QUEUE_PREV(m) = QUEUE_PREV(t);
    QUEUE_INIT(t);
  }
}
S(ray_gof_and) { append_to_parent_queue(ο), Co(ο[0].p, 1); }
S(ray_gof_oor) { append_to_parent_queue(ο), Co(ο[0].p, 0); }

N(os_new) {
  Q_t nρ = 512;
  p_t *nο = malloc(nρ * sizeof(void *));

  nο[--nρ].c = ray_gof_not, nο[--nρ].c = ray_gof_and, nο[--nρ].c = ray_gof_oor;
  nο[--nρ].c = σ[--α].c, nο[--nρ].c = σ[--α].c, nο[--nρ].c = σ[--α].c;
  nο[--nρ].c = ray_al_2, nο[--nρ].c = ray_al_1, nο[--nρ].c = ray_al_0;

  nο[0].v = ο, nο[1].Q = nρ;
  QUEUE_INIT((QUEUE *)&nο[2]);

  A(nο) C(1);
}
