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
S_RAY(2, free(ο))
S_RAY(1, append_to_φψ((QUEUE*)&ο[Φ].p[Ψ], (QUEUE*)&ο[Ψ]))
S_RAY(0, append_to_φψ((QUEUE*)&ο[Φ].p[Ψ], (QUEUE*)&ο[Ψ]))
N(os_new_pith) {
  R(Q_t,              nρ);
  p_t *nο           = malloc(nρ * sizeof(void *));
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
  R(const char*,      name);
  nο[Ν].cs          = name;
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
Narg6(os_new_psn) ( 
  ray_not,   n_t,          
  ray_and,   n_t,          
  ray_oor,   n_t,          
  oο,        p_t *,        
  nρ,        Q_t,          
  name,      const char *)(oο, 0, name, ray_oor, ray_and, ray_not, nρ, os_new_pith)

N(os_new_n) { R(const char*, n);  Α(ο[Φ].p, 512,  n,  os_new_psn) O; }
N(os_new  ) {                     Α(ο[Φ].p, 512, "n", os_new_psn) O; }
