#include "../oars.h"
#include "pith_coords.h"
#include "queue.h"
#include <stdlib.h>
// clang-format off
static void append_to_parent_queue(QUEUE* pq, QUEUE* mq) {
  QUEUE *q;
  if (mq != (q = QUEUE_NEXT(mq)))
    QUEUE_PREV(q) = QUEUE_PREV(pq), QUEUE_PREV_NEXT(mq) = pq,
    QUEUE_PREV_NEXT(pq) = q, QUEUE_PREV(pq) = QUEUE_PREV(mq),
    QUEUE_INIT(mq);
}
#define S_RAY(RAY, PRE)                                                        \
  S(s##RAY) {                                                                  \
    if ((ο[ρ + 6].Q = !ο[ρ + 6].Q))                                            \
      ο[ρ + 3 + RAY].c(T());                                                   \
    else {                                                                     \
      PRE;                                                                     \
      ο[Φ].p[ο[Φ].p[Ρ].Q + RAY].c(σ, α, ο[Φ].p, ο[Φ].p[Ρ].Q);                  \
    }                                                                          \
  }
S_RAY(2, )
S_RAY(1, append_to_parent_queue((QUEUE*)&ο[Φ].p[Ψ], (QUEUE*)&ο[Ψ]))
S_RAY(0, append_to_parent_queue((QUEUE*)&ο[Φ].p[Ψ], (QUEUE*)&ο[Ψ]))
N(os_new_psn) { 
  R(const char *, name);
  R(Q_t,          nρ);
  R(p_t *,        oο);

  p_t *nο         = malloc(nρ * sizeof(void *));
  nο[Σ].Q         = nρ; 

  nο[--nρ].Q      = 0;
  α              -= 3;
  nο[--nρ].c      = σ[α+0].c;
  nο[--nρ].c      = σ[α+1].c;
  nο[--nρ].c      = σ[α+2].c;
  nο[--nρ].c      = s2;
  nο[--nρ].c      = s1;
  nο[--nρ].c      = s0;

  nο[Φ].p         = oο;
  nο[Ρ].Q         = nρ;
  nο[Ν].cs        = name;
  QUEUE_INIT((QUEUE *)&nο[Ψ]);

  A(nο) C(1);
}
N(os_new_n) { R(const char*, n);  Α(ο[Φ].p, 512,  n,  os_new_psn) O; }
N(os_new  ) {                     Α(ο[Φ].p, 512, "n", os_new_psn) O; }
