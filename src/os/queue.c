#include "queue.h"
#include "../oars.h"
#include <stdlib.h>
void nar(OARS);
void os_soll_n(OARS);
void os_soll(OARS);
p_t *soll_alloc();
N(os_queue_soll) {
  R(p_t *, oο);
  R(p_t *, sοll);
  QUEUE_INSERT_TAIL((QUEUE *)&ο[Ψ], (QUEUE *)&sοll[Ψ]);
  sοll[Φ].p = oο;
  C(1);
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
