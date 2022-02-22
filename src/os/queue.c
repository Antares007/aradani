#include "queue.h"
#include "../gotgod.h"
#include "../oars.h"
#include "pith_coords.h"
#define MAXΣ 1024

static p_t σtable[MAXΣ][512];

static p_t *getσ() {
  static W_t c = 0;
  p_t *σ = σtable[c++ % MAXΣ];
  return σ[0].Q ? getσ() : σ;
}

N(os_queue) {
  R(p_t *, oο);
  p_t *nσ;
  Q_t nα = α;
  if (ρ < ο[Ρ].Q) {
    nσ = getσ();
    while (α)
      α--, nσ[α].v = σ[α].v;
  } else {
    nσ = σ;
    static p_t emptyσ[1];
    σ = emptyσ, α = 0;
  }
  QUEUE_INSERT_TAIL((QUEUE *)&ο[Ψ], (QUEUE *)&nσ[nα + 0]);
  nσ[nα + 2].Q = nα;
  nσ[nα + 3].v = oο;
  C(1);
}

void os_queue_init() {
  for (Q_t i = 0; i < MAXΣ; i++)
    σtable[i][0].Q = 0;
}
