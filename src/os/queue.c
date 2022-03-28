#include "queue.h"
#include "../gotgod.h"
#include "../oars.h"
#include "pith_coords.h"
#include <stdlib.h>
N(nar);
N(os_soll_n);
N(os_soll);
N(os_queue_soll) {
  R(p_t*, oο);
  R(p_t*, sοll);
  if(sοll[-2].Q < (sοll[-1].Q + 4)) return C(2);
  QUEUE_INSERT_TAIL((QUEUE *)&ο[Ψ], (QUEUE *)&sοll[sοll[-1].Q + 0]);
  sοll[sοll[-1].Q + 2].Q = sοll[-1].Q;
  sοll[sοll[-1].Q + 3].v = oο;
  C(1);
}
N(os_queue_n) {
  R(Q_t, wc);
  R(p_t*, oο);
  Α(wc, os_soll_n, oο, os_queue_soll, 020, nar) O;
}
N(os_queue) {
  R(p_t*, oο);
  Α(os_soll, oο, os_queue_soll, 020, nar) O;
}
