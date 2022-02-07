#include "gotgod.h"
#include "oars.h"
#include "queue.h"
#include <stdlib.h>

#define MAXΣ 1024

static p_t σtable[MAXΣ][512];
static p_t *getσ() {
  static Q_t last = 0;
  Q_t i;
  for (i = last + 1; i < MAXΣ; i++)
    if (!σtable[i][0].Q)
      return last = i, σtable[i];
  for (i = 1; i < last; i++)
    if (!σtable[i][0].Q)
      return last = i, σtable[i];
  return 0;
}
#define RAY_ALG(Index)                                                         \
  S(ray_al_##Index) { ρ += 6, ο[ρ - 3 + Index].c(T()); }
RAY_ALG(2)
RAY_ALG(1)
RAY_ALG(0)

#define Co(o, r) (o)[(o)[1].Q + r].c(σ, α, (o), (o)[1].Q)

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
N(os_queue) {
  R(p_t *, oο);
  p_t *nσ;
  Q_t nα = α;
  if (ρ < ο[1].Q) {
    nσ = getσ();
    if (!nσ)
      return C(2);
    while (α)
      α--, nσ[α].v = σ[α].v;
  } else {
    nσ = σ;
    static p_t emptyσ[1];
    σ = emptyσ, α = 0;
  }
  QUEUE_INSERT_TAIL((QUEUE *)&ο[2], (QUEUE *)&nσ[nα + 0]);
  nσ[nα + 2].Q = nα;
  nσ[nα + 3].v = oο;
  C(1);
}
N(os_next) {
  QUEUE *q;
  QUEUE *main_queue = (QUEUE *)&ο[2];
  if (main_queue == (q = QUEUE_NEXT(main_queue)))
    return C(2);
  σ[0].Q = 0;
  QUEUE_REMOVE(q);
  p_t *nσ = ((p_t *)q);
  Q_t  nα = nσ[2].Q;
  p_t *oο = nσ[3].p;
  nσ -= nα;
  dot(nσ, nα, oο, oο[1].Q);
}
void init_queue() {
  for (Q_t i = 0; i < MAXΣ; i++)
    σtable[i][0].Q = 0;
}
