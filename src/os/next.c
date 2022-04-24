#include "../gotgod.h"
#include "../oars.h"
#include "pith_coords.h"
#include "queue.h"
#include <stdlib.h>

void page_free(void *);
void nar(OARS);
void os_soll_n(OARS);
void os_soll(OARS);
static Q_t qlen(QUEUE *h);

QUEUE temp_queue;
N(os_queue_soll) {
  R(p_t *, oο);
  R(p_t *, sοll);
  QUEUE_INSERT_TAIL(&temp_queue, (QUEUE *)&sοll[Ψ]);
  sοll[Φ].p = oο;
  printf("queued: ο%02lx, σ%02lx\n", FFF(oο), FFF(sοll) );
  C(1);
}
QUEUE main_queue;
N(os_next) {
  if (α) {
    return (printf("Señor, we are dropping data! "
                   "α:%lu "
                   "temp_queue:%lu "
                   "main_queue:%lu\n",
                   α, qlen(&temp_queue), qlen(&main_queue)),
            (void)0);
  }
  QUEUE *q;
  if (&temp_queue != (q = QUEUE_NEXT(&temp_queue))) {
    QUEUE_PREV(q) = QUEUE_PREV(&main_queue);
    QUEUE_PREV_NEXT(&temp_queue) = &main_queue;
    QUEUE_PREV_NEXT(&main_queue) = q;
    QUEUE_PREV(&main_queue) = QUEUE_PREV(&temp_queue);
    QUEUE_INIT(&temp_queue);
  }
  if (&main_queue == (q = QUEUE_NEXT(&main_queue)))
    return (printf("The End!\n"), (void)0);
  QUEUE_REMOVE(q);
  page_free(σ);
  p_t *nσ = ((p_t *)q) + 5, *nο = nσ[Φ].p;
  nσ[Φ].p = 0;
  printf("next: ο%02lx, σ%02lx\n", FFF(nο), FFF(nσ) );
  dot(nο, nσ[Ǎ].Q, nσ[Σ].Q, nσ);
}
N(os_queue_n) {
  R(Q_t, wc);
  R(p_t *, oο);
  Α(wc, os_soll_n, oο, os_queue_soll, 020, nar) O;
}
N(os_queue) {
  R(p_t *, oο);
  Α(os_soll, oο, os_queue_soll, 020, nar) O;
}
static Q_t qlen(QUEUE *h) {
  QUEUE *q;
  Q_t c = 0;
  for ((q) = QUEUE_NEXT(h); (q) != (h); (q) = QUEUE_NEXT(q))
    c++;
  return c;
}
void os_queue_init() {
  QUEUE_INIT(&temp_queue);
  QUEUE_INIT(&main_queue);
}
