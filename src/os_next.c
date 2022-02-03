#include "import_export.h"
#include "gorgodandgot.h"
#include "queue.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXΣ 1024
static p_t σtable[MAXΣ][512];
static QUEUE main_queue, temp_queue;
static p_t emptyσ[1];
static p_t *getσ();
N(os_queue) {
  R(p_t *, oο);
  p_t *nσ;
  Q_t nα = α;
  if (ρ < ο[1].Q) {
    nσ = getσ();
    while (α)
      α--, nσ[α].v = σ[α].v;
  } else {
    nσ = σ;
    σ = emptyσ, α = 0;
  }
  nσ[nα + 0].v = nσ;
  nσ[nα + 1].Q = nα;
  nσ[nα + 2].v = oο;
  QUEUE_INSERT_TAIL(&temp_queue, (QUEUE *)&nσ[nα + 3]);
  C(1);
}
N(os_next) {
  QUEUE *q;
  if (&temp_queue != (q = QUEUE_NEXT(&temp_queue))) {
    QUEUE_PREV(q) = QUEUE_PREV(&main_queue);
    QUEUE_PREV_NEXT(&temp_queue) = &main_queue;
    QUEUE_PREV_NEXT(&main_queue) = q;
    QUEUE_PREV(&main_queue) = QUEUE_PREV(&temp_queue);
    QUEUE_INIT(&temp_queue);
  }
  if (&main_queue == (q = QUEUE_NEXT(&main_queue)))
    return C(0);
  σ[0].Q = 0;
  QUEUE_REMOVE(q);
  p_t *b = ((p_t *)q);
  p_t *nσ = b[-3].p;
  Q_t nα = b[-2].Q;
  p_t *oο = b[-1].p;
  dot(nσ, nα, oο, oο[1].Q);
}
#define RAY_GOF(Name, Index)                                                   \
  static N(ray_gof_##Name) {                                                   \
    p_t *pο = ο[0].p;                                                          \
    Q_t pρ = pο[1].Q;                                                          \
    pο[pρ + (Index)].c(σ, α, pο, pρ);                                          \
  }
#define RAY_ALG(Name, Index)                                                   \
  static N(ray_alg_##Name) { ρ += 6, ο[ρ - 3 + Index].c(T()); }
RAY_GOF(not, 2)
RAY_GOF(and, 1)
RAY_GOF(oor, 0)
RAY_ALG(not, 2)
RAY_ALG(and, 1)
RAY_ALG(oor, 0)
NP(os_new) {
  Q_t nρ = 512;
  p_t *nο = malloc(nρ * sizeof(void *));

  nο[--nρ].c = ray_gof_not, nο[--nρ].c = ray_gof_and, nο[--nρ].c = ray_gof_oor;
  nο[--nρ].c = σ[--α].c, nο[--nρ].c = σ[--α].c, nο[--nρ].c = σ[--α].c;
  nο[--nρ].c = ray_alg_not, nο[--nρ].c = ray_alg_and, nο[--nρ].c = ray_alg_oor;

  nο[0].v = ο, nο[1].Q = nρ;

  A(nο) C(1);
}
NP(os_delete) {
  R(p_t *, oσ);
  free(oσ);
  C(1);
}
void init_os_next() {
  QUEUE_INIT(&main_queue);
  QUEUE_INIT(&temp_queue);
  for (Q_t i = 0; i < MAXΣ; i++)
    σtable[i][0].Q = 0;
}
static p_t *getσ() {
  static Q_t last = 0;
  Q_t i;
  for (i = last + 1; i < MAXΣ; i++)
    if (!σtable[i][0].Q)
      return last = i, σtable[i];
  for (i = 1; i < last; i++)
    if (!σtable[i][0].Q)
      return last = i, σtable[i];
  assert(0);
}
