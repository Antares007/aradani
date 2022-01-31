#include "import_export.h"
#include "queue.h"
#include <assert.h>
#include <stdio.h>

#define MAXΣ 1024
static p_t σtable[MAXΣ][512];
static QUEUE main_queue, temp_queue;
static p_t emptyσ[1];
static p_t *getσ();
N(os_queue) {
  R(p_t *, oο);
  p_t *nσ;
  Q_t nα = α;
  if (ο[1].Q == ρ) {
    nσ = σ;
    σ = emptyσ, α = 0;
  } else {
    nσ = getσ();
    while (α)
      α--, nσ[α].v = σ[α].v;
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
  σ[0].Q  = 0;
  QUEUE_REMOVE(q);
  p_t *b = ((p_t *)q);
  p_t *nσ = b[-3].p;
  Q_t  nα = b[-2].Q;
  p_t *oο = b[-1].p;
  dot(nσ, nα, oο, oο[1].Q);
}
void init_os_next() {
  QUEUE_INIT(&main_queue);
  QUEUE_INIT(&temp_queue);
  for (Q_t i = 0; i < MAXΣ; i++) σtable[i][0].Q = 0;
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

N(exports_raylib);
// clang-format off
// EN(exports_raylib,
// init_mc21,                 L)EN(L,
// ada,                       L)EN(L,
// os_queue,                  L)EN(L,
// σ,              exports_next);
// clang-format on
