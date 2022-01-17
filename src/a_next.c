#include "arsi.h"
#include "queue.h"
#include <stdio.h>
#define MAX_QUEUE_PAPERS 1024

// clang-format off
IF(iε, 
printf, print,         import, int, const char*, ...);
// clang-format on

typedef struct { QUEUE q; Q_t wc; p_t *targetο; p_t ntext[12]; } queue_paper_t;
typedef struct { p_t *ο; Q_t α, ρ, σ; QUEUE q; } oars_t;

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
  Q_t pα = pο[1].Q + p->wc;
  q_t pρ = pο[2].Q;
  tablelookup[pα](&pο[pο[1].Q], p->ntext);
  pο[pα - 1].c(pο, pα - 1, pρ);
}
N(os_queue) {
  R(Q_t, wc);
  R(p_t *, oο);
  static unsigned short qpno = 0;
  qpno++, qpno %= 1024;
  if (queue_papers[qpno].q[0])
    return C(2);
  queue_papers[qpno].targetο = oο;
  queue_papers[qpno].wc = wc;
  tablelookup[wc](queue_papers[qpno].ntext, &ο[α -= wc]);
  QUEUE_INSERT_TAIL(&temp_queue, &queue_papers[qpno].q);
  C(1);
}

N(ray_not) { print("ray_not ο:%p α:%lu ρ:%ld\n", ο, α, ρ); }
N(ray_and) { os_next(T()); }
N(ray_or) { print("ray_or  ο:%p α:%lu ρ:%ld\n", ο, α, ρ); }
N(seven) {
  print("seven\n");
  A2(7, 7) C(1);
}

// requrcive defined OarS;
p_t ο[512];
p_t *s_pith;
static void init_pith() {
  q_t α = 4, ρ = 0;
  ο[--ρ].v = ray_not;
  ο[--ρ].v = ray_and;
  ο[--ρ].v = ray_or;
  ο[0].v = ο;
  ο[1].Q = α;
  ο[2].Q = ρ;
  ο[3].Q = sizeof(ο) / sizeof(*ο);
  ο[α++].v = seven;
}
static void init_queue();
N(init) {
  (void)init_pith, (void)init_queue;
  C(1);
}

// clang-format off
EN(tail,
os_next,                                     L)EN(L,
os_queue,                                    L)EN(L,
s_pith,                                 export)

static void memcopy1(p_t *pο, p_t *ο) { pο[0].v = ο[0].v; }
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
