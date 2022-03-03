#include "queue.h"
#include "../gotgod.h"
#include "../oars.h"
#include "pith_coords.h"
#include <stdlib.h>

N(os_next) {
  QUEUE *q;
  if ((QUEUE *)&ο[Ψ] == (q = QUEUE_NEXT((QUEUE *)&ο[Ψ])))
    return C(2);

  QUEUE_REMOVE(q);
  if (σ) free(σ);

  p_t *nσ = ((p_t *)q);
  Q_t nα = nσ[2].Q;
  p_t *nο = nσ[3].p;
  Q_t nρ = nσ[4].Q;
  nσ -= nα;
  dot(nσ, nα, nο, nρ);
}
