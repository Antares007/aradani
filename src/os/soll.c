// TODO: rename soll to sigma
#include "../gotgod.h"
#include "../oars.h"
#include "pith_coords.h"
#include "queue.h"
#include <stdlib.h>
p_t *page_alloc();
void page_free(p_t *);
void nar(OARS);
static void append_to_parent_queue(QUEUE *mq, QUEUE *pq) {
  QUEUE *q;
  if (mq != (q = QUEUE_NEXT(mq)))
    QUEUE_PREV(q) = QUEUE_PREV(pq), QUEUE_PREV_NEXT(mq) = pq,
    QUEUE_PREV_NEXT(pq) = q, QUEUE_PREV(pq) = QUEUE_PREV(mq), QUEUE_INIT(mq);
}
#define S_RAY(RAY, PRE)                                                        \
  static N(s##RAY) {                                                           \
    if ((σ[ρ + 3].Q = !σ[ρ + 3].Q))                                            \
      ο[RAY].c(T());                                                           \
    else {                                                                     \
      p_t *φο = ο[Φ].p;                                                        \
      PRE;                                                                     \
      φο[RAY].c(φο, α, ρ, σ);                                                  \
    }                                                                          \
  }
S_RAY(2, page_free(ο))
S_RAY(1, append_to_parent_queue((QUEUE*)&ο[Ψ], (QUEUE*)&ο[Φ].p[Ψ]))
S_RAY(0, append_to_parent_queue((QUEUE*)&ο[Ψ], (QUEUE*)&ο[Φ].p[Ψ]))
p_t *soll_alloc() {
  p_t *sοll = page_alloc();
  sοll += 5;
  sοll[Ǎ].Q = sοll[Φ].Q = 0;
  sοll[Σ].Q = 503;
  sοll[503+3].Q = 0;
  sοll[503+2].c = s2;
  sοll[503+1].c = s1;
  sοll[503+0].c = s0;
  return sοll;
}
N(os_soll_n) {
  R(Q_t, wc);
  if (α < wc)
    return C(2);
  p_t *sοll = soll_alloc();
  if (sοll == 0)
    return C(2);
  α -= sοll[Ǎ].Q = wc;
  for (Q_t i = 0; i < wc; i++)
    sοll[i].v = σ[α + i].v;
  Α(sοll) C(1);
}
N(os_soll) {
  Q_t a = α;
  A(a) os_soll_n(T());
}
N(os_unsoll) {
  R(p_t *, sοll);
  if (σ[Σ].Q < (α + sοll[Ǎ].Q))
    return C(2);
  for (Q_t i = 0; i < sοll[Ǎ].Q; i++)
    σ[α + i].v = sοll[i].v;
  α += sοll[Ǎ].Q, C(1);
}
N(os_soll_dup) {
  R(p_t *, sοll);
  p_t *dsοll = soll_alloc();
  dsοll[Ǎ].Q = sοll[Ǎ].Q;
  for (Q_t i = 0; i < sοll[Ǎ].Q; i++)
    dsοll[i].v = sοll[i].v;
  Α(sοll, dsοll) C(1);
}
N(os_soll_free) {
  R(p_t *, sοll);
  page_free(sοll), C(1);
}
N(os_unsoll_free) {
  R(p_t *, sοll);
  Α(sοll, os_unsoll, sοll, os_soll_free, 020, nar) O;
}
N(os_unsoll_apply) {
  R(p_t *, sοll);
  Α(sοll, os_unsoll, dot, 010, nar) O;
}
N(os_unsoll_free_apply) {
  R(p_t *, sοll);
  Α(sοll, os_unsoll_free, dot, 010, nar) O;
}
