#include "../oars.h"
#include "pith_coords.h"
#include "queue.h"
#include <stdlib.h>
// clang-format off
static void append_to_φψ(QUEUE *pq, QUEUE *mq) {
  QUEUE *q;
  if (mq != (q = QUEUE_NEXT(mq)))
    QUEUE_PREV(q) = QUEUE_PREV(pq), QUEUE_PREV_NEXT(mq) = pq,
    QUEUE_PREV_NEXT(pq) = q, QUEUE_PREV(pq) = QUEUE_PREV(mq), QUEUE_INIT(mq);
}
#define S_RAY(RAY, PRE)                                                        \
  S(s##RAY) {                                                                  \
    if ((ο[ρ + 6].Q = !ο[ρ + 6].Q))                                            \
      ο[ρ + 3 + RAY].c(T());                                                   \
    else {                                                                     \
      p_t *φο = ο[Φ].p;                                                        \
      PRE;                                                                     \
      φο[φο[Ρ].Q + RAY].c(σ, α, φο, φο[Ρ].Q);                                  \
    }                                                                          \
  }
static char ids[0x1000] = {0};
S_RAY(2, (ids[ο[Ι].Q] = 0, free(ο)))
S_RAY(1, append_to_φψ((QUEUE*)&ο[Φ].p[Ψ], (QUEUE*)&ο[Ψ]))
S_RAY(0, append_to_φψ((QUEUE*)&ο[Φ].p[Ψ], (QUEUE*)&ο[Ψ]))
static q_t id_next() {
  for(q_t i = 1; i < sizeof(ids) / sizeof(*ids); i++)
    if (ids[i] == 0)
      return ids[i] = 1, i;
  return -1;
}
N(os_new_pith) {
  R(Q_t,              nρ);
  Q_t id            = id_next();
  if (id  < 0) return C(2);
  p_t *nο           = malloc(nρ * sizeof(void *));
  if (nο == 0) return ids[id] = 0, C(2);
  nο[Σ].Q           = nρ; 
  nο[--nρ].Q        = 0;
  R(n_t,              ray_not);
  R(n_t,              ray_and);
  R(n_t,              ray_oor);
  nο[--nρ].c        = ray_not;
  nο[--nρ].c        = ray_and;
  nο[--nρ].c        = ray_oor;
  nο[--nρ].c        = s2;
  nο[--nρ].c        = s1;
  nο[--nρ].c        = s0;
  nο[Ρ].Q           = nρ;
  nο[Ι].Q           = id;
  nο[Ψ+0].p         = &nο[Ψ];
  nο[Ψ+1].p         = &nο[Ψ];
  R(Q_t,              wc);
  while(wc) {
    R(void*,          v);
    nο[--wc + 7].v  = v;
  }
  R(p_t *,            oο);
  nο[Φ].p           = oο;
  A(nο) C(1);
}
Narg5(os_new_ps)( 
  ray_not,   n_t,          
  ray_and,   n_t,          
  ray_oor,   n_t,          
  oο,        p_t *,        
  nρ,        Q_t)(
  oο, 0, ray_oor, ray_and, ray_not, nρ, os_new_pith
)
Nargo(os_new   )(
  ο[Φ].p, 512, os_new_ps
)
