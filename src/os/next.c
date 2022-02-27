#include "../gotgod.h"
#include "../oars.h"
#include "pith_coords.h"
#include "queue.h"

N(os_next) {
  QUEUE *q;
  if ((QUEUE *)&ο[Ψ] == (q = QUEUE_NEXT((QUEUE *)&ο[Ψ])))
    return C(2);
  // if (ρ < ο[Ρ].Q) {
  //   A(god) QUEUE_INSERT_TAIL((QUEUE *)&ο[Ψ], (QUEUE *)&σ[α + 0]);
  //   σ[α + 2].Q = α;
  //   σ[α + 3].v = ο;
  //   σ[α + 4].Q = ρ;
  // } else
  σ[0].Q = 0;

  QUEUE_REMOVE(q);
  p_t *nσ = ((p_t *)q);
  Q_t nα = nσ[2].Q;
  p_t *nο = nσ[3].p;
  Q_t nρ = nσ[4].Q;
  nσ -= nα;
  dot(nσ, nα, nο, nρ);
}
