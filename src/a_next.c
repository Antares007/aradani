#include "arsi.h"
#include "queue.h"
#include <stdio.h>

// clang-format off
IF(iε, 
printf, print,         L, int, const char*, ...)p_t *oο;IN(L,
init_mc21,             L)IN(L,
and,                   L)I(L,
"ο", oο,          import);
// clang-format on

#define MAX_QUEUE_PAPERS 1024
typedef struct {
  QUEUE q;
  Q_t word_count;
  p_t *targetο, ntextspace[12];
} queue_paper_t;

typedef void (*fun_t)();
static fun_t mc21_lookup[22];
static queue_paper_t queue_papers[MAX_QUEUE_PAPERS];
static QUEUE main_queue, temp_queue;

static N(dot) { O; }
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
  ο[001].Q = α;
  QUEUE_REMOVE(q);
  queue_paper_t *p = QUEUE_DATA(q, queue_paper_t, q);
  p->q[0] = 0;
  p_t *pο = p->targetο;
  void **t = &pο[pο[1].Q].v, **s = &p->ntextspace[0].v;
  mc21_lookup[p->word_count](pο, pο[1].Q + p->word_count, pο[2].Q, dot, t, s);
}
N(os_queue) {
  R(Q_t, word_count);
  R(p_t *, targetο);
  static unsigned short qpno = 0;
  qpno++, qpno %= 1024;
  if (queue_papers[qpno].q[0])
    return C(2);
  queue_papers[qpno].targetο = targetο;
  queue_papers[qpno].word_count = word_count;
  QUEUE_INSERT_TAIL(&temp_queue, &queue_papers[qpno].q);
  void **t = &queue_papers[qpno].ntextspace[0].v, **s = &ο[α -= word_count].v;
  mc21_lookup[word_count](ο, α, ρ, god, t, s);
}

// clang-format off
EN(tail,
os_next,                                     L)EN(L,
os_queue,                                    L)p_t bο[512];E(L,
"ο", bο,                                export)
// clang-format on

N(cont_fathers_not_ray) {
  p_t *pο = ο[0].v;
  pο[pο[2].Q + 2].c(pο, pο[1].Q, pο[2].Q);
}
N(cont_fathers_and_ray) {
  p_t *pο = ο[0].v;
  pο[pο[2].Q + 1].c(pο, pο[1].Q, pο[2].Q);
}
N(cont_fathers_oor_ray) {
  p_t *pο = ο[0].v;
  pο[pο[2].Q + 0].c(pο, pο[1].Q, pο[2].Q);
}
N(ray_cb_not) { ρ += 6, ο[ρ - 1].c(T()); }
N(ray_cb_and) { ρ += 6, ο[ρ - 2].c(T()); }
N(ray_cb_oor) { ρ += 6, ο[ρ - 3].c(T()); }

static void init_pith() {
  Q_t bα = 0, bρ = sizeof(bο) / sizeof(*bο);

  bο[--bρ].v = cont_fathers_not_ray;
  bο[--bρ].v = cont_fathers_and_ray;
  bο[--bρ].v = cont_fathers_oor_ray;

  bο[--bρ].v = cont_fathers_not_ray;
  bο[--bρ].v = os_next;
  bο[--bρ].v = cont_fathers_oor_ray;

  bο[--bρ].v = ray_cb_not;
  bο[--bρ].v = ray_cb_and;
  bο[--bρ].v = ray_cb_oor;

  bο[bα++].v = oο;
  bο[bα++].Q = 0001;
  bο[bα++].Q = bρ;
  bο[bα++].v = god;

  bο[0001].Q = bα;
}
static void init_queue() {
  QUEUE_INIT(&main_queue);
  QUEUE_INIT(&temp_queue);
  for (Q_t i = 0; i < MAX_QUEUE_PAPERS; i++)
    queue_papers[i].q[0] = 0;
}
N(init) { init_pith(), init_queue(), A2(mc21_lookup, init_mc21) O; }
