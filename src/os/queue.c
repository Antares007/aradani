#include "queue.h"
#include "../gotgod.h"
#include "../oars.h"
#include "pith_coords.h"
#include <stdlib.h>

N(os_queue) {
  R(p_t *, nο);
  p_t *nσ;
  Q_t nα = α;
  if (ρ < ο[Ρ].Q) {
    nσ = malloc(0x1000);
    while (α)
      α--, nσ[α].v = σ[α].v;
  } else {
    nσ = σ;
    σ = 0;
    α = 0;
  }
  QUEUE_INSERT_TAIL((QUEUE *)&ο[Ψ], (QUEUE *)&nσ[nα + 0]);
  nσ[nα + 2].Q = nα;
  nσ[nα + 3].v = nο;
  nσ[nα + 4].Q = nο[Ρ].Q;
  C(1);
}
