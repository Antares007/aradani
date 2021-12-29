#include "arsi.h"
#include "queue.h"
#include <stdio.h>
#define MAX_QUEUE_PAPERS 1024

// clang-format off
int   (*print)(const char*, ...);
I(0, 
printf, print,         import);

typedef struct { QUEUE q; Q_t α; p_t *σ; p_t ο[12]; } queue_paper_t;
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
  //σ[1].Q = α, σ[2].q = ρ;
  QUEUE_REMOVE(q);
  queue_paper_t *p = QUEUE_DATA(q, queue_paper_t, q);
  p->q[0] = 0;
  p_t *pσ = p->σ, *pο = pσ[0].v;
  Q_t pα = p->α;
  q_t pρ = pσ[2].q;
  tablelookup[pα](pο, p->ο);
  pο[pα - 1].c(pο, pα - 1, pρ, pσ);
}
N(os_queue) {
  R(Q_t, wc);
  R(p_t *, nσ);
  static unsigned short qpno = 0;
  qpno++, qpno %= 1024;
  if (queue_papers[qpno].q[0])
    return C(2);
  queue_papers[qpno].σ = nσ;
  queue_papers[qpno].α = wc;
  tablelookup[wc](queue_papers[qpno].ο, &ο[α -= wc]);
  QUEUE_INSERT_TAIL(&temp_queue, &queue_papers[qpno].q);
  C(1);
}

N(ray_not) { print("ray_not σ:%p α:%lu ρ:%ld\n", σ, α, ρ); }
N(ray_and) { os_next(T()); }
N(ray_or ) { print("ray_or  σ:%p α:%lu ρ:%ld\n", σ, α, ρ); }
N(seven  ) { print("seven\n");A2(7, 7) C(1); }

// requrcive defined OarS;
p_t ο[512];
p_t *s_pith;
static void init_pith() {
  p_t *σ = s_pith = ο + sizeof(ο) / sizeof(*ο) - 4;
  q_t α = 0, ρ = 0;
  σ[--ρ].v = ray_not;
  σ[--ρ].v = ray_and;
  σ[--ρ].v = ray_or;
  ο[α++].v = seven;
  σ[0].v = ο;
  σ[1].Q = α;
  σ[2].q = ρ;
  σ[3].v = σ;
}
static void init_queue();
void init() { init_queue(); init_pith(); }

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
