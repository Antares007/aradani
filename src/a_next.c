#include "arsi.h"
#include "queue.h"
#include <stdio.h>

// clang-format off
IF(iε, 
printf, print,         L, int, const char*, ...)p_t *oο;I(L,
"ο", oο,          import);

#define MAX_QUEUE_PAPERS 1024
typedef struct {
  QUEUE q;
  Q_t word_count;
  p_t *targetο, ntextspace[12];
} queue_paper_t;

typedef void (*memcopy_t)(p_t *, p_t *);
static queue_paper_t queue_papers[MAX_QUEUE_PAPERS];
static QUEUE main_queue, temp_queue;
static memcopy_t tablelookup[8];

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
  QUEUE_REMOVE(q);
  queue_paper_t *p = QUEUE_DATA(q, queue_paper_t, q);
  p->q[0] = 0;
  p_t *pο = p->targetο;
  tablelookup[p->word_count](&pο[pο[1].Q], p->ntextspace);
  Q_t pα = pο[1].Q + p->word_count - 1;
  ο[001].Q = α;
  pο[pα].c(pο, pα, pο[2].Q);
}
N(os_queue) {
  R(Q_t, word_count);
  R(p_t *, targetο);
  static unsigned short qpno = 0;
  qpno++, qpno %= 1024;
  if (queue_papers[qpno].q[0]) return C(2);
  queue_papers[qpno].targetο = targetο;
  queue_papers[qpno].word_count = word_count;
  tablelookup[word_count](queue_papers[qpno].ntextspace, &ο[α -= word_count]);
  QUEUE_INSERT_TAIL(&temp_queue, &queue_papers[qpno].q);
  C(1);
}

EN(tail,
os_next,                                     L)EN(L,
os_queue,                                    L)p_t bο[512];E(L,
"ο", bο,                                export)

N(cont_fathers_not_ray) { p_t *pο = ο[0].v; pο[pο[2].Q + 2].c(pο, pο[1].Q, pο[2].Q); }
N(cont_fathers_and_ray) { p_t *pο = ο[0].v; pο[pο[2].Q + 1].c(pο, pο[1].Q, pο[2].Q); }
N(cont_fathers_oor_ray) { p_t *pο = ο[0].v; pο[pο[2].Q + 0].c(pο, pο[1].Q, pο[2].Q); }
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

static void memcopy0(p_t *pο, p_t *ο) {
}
static void memcopy1(p_t *pο, p_t *ο) {
  pο[0].v = ο[0].v;
}
static void memcopy2(p_t *pο, p_t *ο) {
  pο[0].v = ο[0].v;
  pο[1].v = ο[1].v;
}
static void memcopy3(p_t *pο, p_t *ο) {
  pο[0].v = ο[0].v;
  pο[1].v = ο[1].v;
  pο[2].v = ο[2].v;
}
static void memcopy4(p_t *pο, p_t *ο) {
  pο[0].v = ο[0].v;
  pο[1].v = ο[1].v;
  pο[2].v = ο[2].v;
  pο[3].v = ο[3].v;
}
static void memcopy5(p_t *pο, p_t *ο) {
  pο[0].v = ο[0].v;
  pο[1].v = ο[1].v;
  pο[2].v = ο[2].v;
  pο[3].v = ο[3].v;
  pο[4].v = ο[4].v;
}
static void memcopy6(p_t *pο, p_t *ο) {
  pο[0].v = ο[0].v;
  pο[1].v = ο[1].v;
  pο[2].v = ο[2].v;
  pο[3].v = ο[3].v;
  pο[4].v = ο[4].v;
  pο[5].v = ο[5].v;
}
static void memcopy7(p_t *pο, p_t *ο) {
  pο[0].v = ο[0].v;
  pο[1].v = ο[1].v;
  pο[2].v = ο[2].v;
  pο[3].v = ο[3].v;
  pο[4].v = ο[4].v;
  pο[5].v = ο[5].v;
  pο[6].v = ο[6].v;
}
static void init_queue() {
  QUEUE_INIT(&main_queue);
  QUEUE_INIT(&temp_queue);
  tablelookup[0] = memcopy0;
  tablelookup[1] = memcopy1;
  tablelookup[2] = memcopy2;
  tablelookup[3] = memcopy3;
  tablelookup[4] = memcopy4;
  tablelookup[5] = memcopy5;
  tablelookup[6] = memcopy6;
  tablelookup[7] = memcopy7;
  for (Q_t i = 0; i < MAX_QUEUE_PAPERS; i++)
    queue_papers[i].q[0] = 0;
}
N(init) { init_pith(), init_queue(), C(1); }
