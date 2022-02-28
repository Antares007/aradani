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
#define SR(RAY, OFF, PRE)                                                      \
  S(s##RAY) {                                                                  \
    Q_t wc = ο[ρ + 3 + RAY].Q;                                                 \
    if (wc && (ο[ρ + 6].Q = !ο[ρ + 6].Q)) {                                    \
      for (Q_t i = 0; i < wc; i++)                                             \
        σ[α++].v = ο[ρ + i + 7 + OFF].v;                                       \
      O;                                                                       \
    } else {                                                                   \
      PRE;                                                                     \
      ο[Φ].p[ο[Φ].p[Ρ].Q + RAY].c(σ, α, ο[Φ].p, ο[Φ].p[Ρ].Q);                  \
    }                                                                          \
  }
SR(2, 0, )
SR(1, ο[ρ + 3].Q, append_to_parent_queue((QUEUE*)&ο[Ψ], (QUEUE*)&ο[Φ].p[Ψ]))
SR(0, ο[ρ + 3].Q + ο[ρ + 4].Q, append_to_parent_queue((QUEUE*)&ο[Ψ], (QUEUE*)&ο[Φ].p[Ψ]))
N(os_new_psnj) {
  Q_t j = σ[--α].Q,           //
      nc = ((j & 0700) >> 6), //
      ac = ((j & 0070) >> 3), //
      oc = ((j & 0007) >> 0), //
      tc = nc + ac + oc;
  R(const char *, name);
  R(Q_t,          nρ);
  R(p_t *,        oο);

  p_t *nο         = malloc(nρ * sizeof(void *));
  nο[Σ].Q         = nρ; 

  while (tc)
    nο[--nρ].c    = σ[--α].c, --tc;
  nο[--nρ].Q      = 0;
  nο[--nρ].Q      = nc;
  nο[--nρ].Q      = ac;
  nο[--nρ].Q      = oc;
  nο[--nρ].c      = s2;
  nο[--nρ].c      = s1;
  nο[--nρ].c      = s0;

  nο[Φ].p         = oο;
  nο[Ρ].Q         = nρ;
  nο[Ν].cs        = name;
  QUEUE_INIT((QUEUE *)&nο[Ψ]);

  A(nο) C(1);
}
N(os_new_j) { R(Q_t, j); Α(ο[Φ].p, 512, "os_new_j", j, os_new_psnj) O; }

N(os_new) { Α(ο[Φ].p, 512, "os_new", 0111, os_new_psnj) O; }
