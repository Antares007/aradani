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

No(os_next)(
  if (α) {
    if (σ[-3].p == 0)
      printf("Señor, we are dropping data! α:%lu ψ:%lu\n", α, qlen(ο[Ψ].v));
    else {
      printf("ret\n");
      // p_t *nσ = σ[-3].p;
      //σ[-3].p = 0;
      ////nσ[-2];
      //Α(1) O;
    }
  } else {
    QUEUE *q;
    if ((QUEUE*)&ο[Ψ] == (q = QUEUE_NEXT((QUEUE *)&ο[Ψ])))
      return (printf("The End!\n"), (void)0);
    QUEUE_REMOVE(q);
    page_free(σ);
    p_t *nσ = ((p_t *)q) + 5, *nο = nσ[Φ].p;
    nσ[Φ].p = 0;
    dot(nο, nσ[Ǎ].Q, nσ[Σ].Q, nσ);
  }
)
