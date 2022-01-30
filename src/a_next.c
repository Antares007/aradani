#include "arsi.h"
#include "queue.h"
#include <stdio.h>

// clang-format off
IN(iε,
os_init_pith,           L)IF(L, 
printf, print,          L, int, const char*, ...)IN(L,
init_mc21,              L)IN(L,
ada,              imports);
// clang-format on

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
static N(notthend) { print("NOT The End!\n"); };
static N(oorthend) { print("OR  The End!\n"); };
static NP(init_queue) {
  QUEUE_INIT(&main_queue);
  QUEUE_INIT(&temp_queue);
  for (Q_t i = 0; i < MAX_QUEUE_PAPERS; i++)
    queue_papers[i].q[0] = 0;
  C(1);
}
NP(init) {
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

// clang-format off
EN(tail,
os_queue,            L)EN(L,
σ,             exports);
