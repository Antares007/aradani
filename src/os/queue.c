#include "queue.h"
#include "../gotgod.h"
#include "../oars.h"
#include "pith_coords.h"
#include <stdlib.h>

N(os_queue_n) {
  R(Q_t, wc);
  R(p_t *, nο);
  p_t *nσ;
  Q_t nα = wc;
  nσ = malloc(0x1000);
  α -= wc;
  while (wc)
    wc--, nσ[wc].v = σ[α + wc].v;
  QUEUE_INSERT_TAIL((QUEUE *)&ο[Ψ], (QUEUE *)&nσ[nα + 0]);
  nσ[nα + 2].Q = nα;
  nσ[nα + 3].v = nο;
  nσ[nα + 4].Q = nο[Ρ].Q;
  C(1);
}
N(os_queue) {
  Q_t a = α - 1;
  A2(a, os_queue_n) O;
}
