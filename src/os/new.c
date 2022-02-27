#include "../oars.h"
#include "pith_coords.h"
#include "queue.h"
#include <stdlib.h>
// clang-format off
N(os_new_wpsn) {
  R(Q_t,          wc);
  R(const char *, name);
  R(Q_t,          nρ);
  R(p_t *,        oο);

  p_t *nο         = malloc(nρ * sizeof(void *));

  nο[Σ].Q         = nρ; 

  while (wc)
    nο[--nρ].c    = σ[--α].c, --wc;

  nο[Φ].p         = oο;
  nο[Ρ].Q         = nρ;
  nο[Ν].cs        = name;
  QUEUE_INIT((QUEUE *)&nο[Ψ]);

  A(nο) C(1);
}
N(os_new_psn) {
  Α(3, os_new_wpsn) O;
}
static void append_to_parent_queue(QUEUE* my_q, QUEUE* parent_q) {
  QUEUE *q;
  if (my_q != (q = QUEUE_NEXT(my_q)))
    QUEUE_PREV(q) = QUEUE_PREV(parent_q), QUEUE_PREV_NEXT(my_q) = parent_q,
    QUEUE_PREV_NEXT(parent_q) = q, QUEUE_PREV(parent_q) = QUEUE_PREV(my_q),
    QUEUE_INIT(my_q);
}
#define SR(RAY, AND)                                                            \
  S(s##RAY) {printf("RAY: %d oc: %lu\n", RAY, (ο[ρ + 3].Q = !ο[ρ + 3].Q));      \
    if (ο[ρ + 3].Q) ο[ρ + 4 + RAY].c(T());                                      \
    else { AND; ο[Φ].p[ο[Φ].p[Ρ].Q + RAY].c(σ, α, ο[Φ].p, ο[Φ].p[Ρ].Q); }       \
  }

SR(2,)
SR(1, append_to_parent_queue((QUEUE*)&ο[Ψ], (QUEUE*)&ο[Φ].p[Ψ]))
SR(0, append_to_parent_queue((QUEUE*)&ο[Ψ], (QUEUE*)&ο[Φ].p[Ψ]))

N(os_new) {
  R(n_t, r2);
  R(n_t, r1);
  R(n_t, r0);
  Α(s0, s1, s2, 0, r0, r1, r2, ο[Φ].p, 512, "os_new", 7, os_new_wpsn) O;
}
