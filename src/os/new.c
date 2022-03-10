#include "../oars.h"
#include "pith_coords.h"
#include "queue.h"
#include <stdlib.h>
// clang-format off
static void append_to_parent_queue(QUEUE* my_q, QUEUE* parent_q) {
  QUEUE *q;
  if (my_q != (q = QUEUE_NEXT(my_q)))
    QUEUE_PREV(q) = QUEUE_PREV(parent_q), QUEUE_PREV_NEXT(my_q) = parent_q,
    QUEUE_PREV_NEXT(parent_q) = q, QUEUE_PREV(parent_q) = QUEUE_PREV(my_q),
    QUEUE_INIT(my_q);
}
#define SSR(RAY, PRE)                                                          \
  S(ss##RAY) {                                                                 \
    if ((ο[ρ + 7].Q = !ο[ρ + 7].Q))                                            \
      ο[ρ + 3 + RAY].c(T());                                                   \
    else {                                                                     \
      PRE;                                                                     \
      ο[Φ].p[ο[Φ].p[Ρ].Q + RAY].c(σ, α, ο[Φ].p, ο[Φ].p[Ρ].Q);                  \
    }                                                                          \
  }
SSR(2, )
SSR(1, append_to_parent_queue((QUEUE*)&ο[Ψ], (QUEUE*)&ο[Φ].p[Ψ]))
SSR(0, append_to_parent_queue((QUEUE*)&ο[Ψ], (QUEUE*)&ο[Φ].p[Ψ]))
NP(os_new_psn) { 
  R(const char *, name);
  R(Q_t,          nρ);
  R(p_t *,        oο);

  p_t *nο         = malloc(nρ * sizeof(void *));
  nο[Σ].Q         = nρ; 

  nο[--nρ].Q      = 0;
  nρ             -= 4;
  α              -= 3;
  nο[nρ+2].c      = σ[α+0].c;
  nο[nρ+1].c      = σ[α+1].c;
  nο[nρ+0].c      = σ[α+2].c;
  nο[--nρ].c      = ss2;
  nο[--nρ].c      = ss1;
  nο[--nρ].c      = ss0;

  nο[Φ].p         = oο;
  nο[Ρ].Q         = nρ;
  nο[Ν].cs        = name;
  QUEUE_INIT((QUEUE *)&nο[Ψ]);

  A(nο) C(1);
}
N(os_new_n) { R(const char*, n);  Α(ο[Φ].p, 512,  n,  os_new_psn) O; }
N(os_new  ) {                     Α(ο[Φ].p, 512, "n", os_new_psn) O; }
