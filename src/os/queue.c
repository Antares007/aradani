#include "../oars.h"
#include "../gotgod.h"
#include "queue.h"

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

void init_queue() {
  for (Q_t i = 0; i < MAXΣ; i++)
    σtable[i][0].Q = 0;
}
