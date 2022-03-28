#include "../gotgod.h"
#include "../oars.h"
#include "pith_coords.h"
#include "queue.h"
#include <stdlib.h>

static Q_t qlen(QUEUE *h) {
  QUEUE *q;
  Q_t c = 0;
  for ((q) = QUEUE_NEXT(h); (q) != (h); (q) = QUEUE_NEXT(q))
    c++;
  return c;
}

void page_free(void *);

N(os_next) {
  if (α)
    return (printf("Señor, we are dropping data! α:%lu ψ:%lu\n", α,
                   qlen((QUEUE *)&ο[Ψ])),
            C(2));
  QUEUE *q;
  if ((QUEUE *)&ο[Ψ] == (q = QUEUE_NEXT((QUEUE *)&ο[Ψ])))
    return C(2);
  QUEUE_REMOVE(q);
  page_free(σ);
  p_t *nσ = ((p_t *)q);
  Q_t nα = nσ[2].Q;
  p_t *nο = nσ[3].p;
  nσ -= nα;
  Q_t nρ = nο[Ρ].Q;
  dot(nσ, nα, nο, nρ);
}
