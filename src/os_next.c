#include "queue.h"
#include "import_export.h"
#include <stdio.h>

#define MAX_QUEUE_PAPERS 1024
typedef struct {
  QUEUE q;
  Q_t word_count;
  p_t *σ, ntextspace[12];
} queue_paper_t;

typedef void (*fun_t)();
static fun_t mc21_lookup[22];
static queue_paper_t queue_papers[MAX_QUEUE_PAPERS];
static QUEUE main_queue, temp_queue;
static p_t σ[512];

N(os_next) {
  QUEUE *q;
  if (&temp_queue != (q = QUEUE_NEXT(&temp_queue))) {
    QUEUE_PREV(q) = QUEUE_PREV(&main_queue);
    QUEUE_PREV_NEXT(&temp_queue) = &main_queue;
    QUEUE_PREV_NEXT(&main_queue) = q;
    QUEUE_PREV(&main_queue) = QUEUE_PREV(&temp_queue);
    QUEUE_INIT(&temp_queue);
  }
  if (&main_queue == (q = QUEUE_NEXT(&main_queue)))
    return C(0);
  ο[-1].p[1].Q = α;
  QUEUE_REMOVE(q);
  queue_paper_t *p = QUEUE_DATA(q, queue_paper_t, q);
  p->q[0] = 0;
  p_t *σ = p->σ;
  void **t = &σ[0].p[σ[1].Q].v, **s = &p->ntextspace[0].v;
  mc21_lookup[p->word_count](σ[0].p, σ[1].Q + p->word_count, σ[2].Q, dot, t, s);
}
static N(notthend) { printf("NOT The End!\n"); };
static N(oorthend) { printf("OR  The End!\n"); };
static NP(init_queue) {
  QUEUE_INIT(&main_queue);
  QUEUE_INIT(&temp_queue);
  for (Q_t i = 0; i < MAX_QUEUE_PAPERS; i++)
    queue_papers[i].q[0] = 0;
  C(1);
}
N(init_mc21);
N(ada);
N(os_init_pith);
NP(init_next) {
  A15(notthend, os_next, oorthend, sizeof(σ) / sizeof(*σ) - 5, 0, σ, σ,
      os_init_pith, mc21_lookup, init_mc21, 020, ada, init_queue, 010, ada)
  O;
}
N(os_queue) {
  R(Q_t, word_count);
  R(p_t *, σ);
  static unsigned short qpno = 0;
  qpno++, qpno %= 1024;
  if (queue_papers[qpno].q[0])
    return C(2);
  queue_papers[qpno].σ = σ;
  queue_papers[qpno].word_count = word_count;
  QUEUE_INSERT_TAIL(&temp_queue, &queue_papers[qpno].q);
  void **t = &queue_papers[qpno].ntextspace[0].v, **s = &ο[α -= word_count].v;
  mc21_lookup[word_count](ο, α, ρ, god, t, s);
}

N(exports_raylib);

#undef L
#define L CAT(exports_next, __LINE__)

// clang-format off
EN(exports_raylib,
init_mc21,                 L)EN(L,
ada,                       L)EN(L,
os_queue,                  L)EN(L,
σ,              exports_next)
// clang-format on
