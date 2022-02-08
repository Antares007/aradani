#include "../gotgod.h"
#include "../oars.h"
#include "queue.h"
#include <stdio.h>
NP(os_next) {
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
