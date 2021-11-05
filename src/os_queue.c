#include "os_queue.h"
#include "os_epoll.h"
#include "queue.h"
#include <assert.h>
#include <stdio.h>

#define MAX_QUEUE_PAPERS 1024

typedef struct {
  QUEUE q;
  Q_t α;
  p_t *σ;
  p_t ο[12];
} queue_paper_t;
typedef void (*memcopy_t)(p_t *, p_t *);

queue_paper_t queue_papers[MAX_QUEUE_PAPERS];
QUEUE main_queue, temp_queue;
static memcopy_t tablelookup[8];
static N(got) { C(0); }
N(os_queue) {
  R(Q_t, wc);
  R(p_t *, nσ);
  static unsigned short qpno = 0;
  qpno++, qpno %= 1024;
  assert(queue_papers[qpno].q[0] == 0);
  queue_papers[qpno].σ = nσ;
  queue_papers[qpno].α = wc;
  tablelookup[wc](queue_papers[qpno].ο, &ο[α -= wc]);
  QUEUE_INSERT_TAIL(&temp_queue, &queue_papers[qpno].q);
  //  os_epoll_wait(0);
  C(1);
}
// epollisdamushaveba =
//
//
// rigisgadartva shemdegi_rigis_furceli da
// got sheasrule anda
//
static N(rigisgadartva) {
  QUEUE *q;
  // TODO: move temp_queue on oars. to stop/start execution fo word.
  if (&temp_queue != (q = QUEUE_NEXT(&temp_queue))) {
    QUEUE_PREV(q) = QUEUE_PREV(&main_queue);
    QUEUE_PREV_NEXT(&temp_queue) = &main_queue;
    QUEUE_PREV_NEXT(&main_queue) = q;
    QUEUE_PREV(&main_queue) = QUEUE_PREV(&temp_queue);
    QUEUE_INIT(&temp_queue);
  }
  C(1);
}
static N(shemdegi_rigis_furceli) {
  QUEUE *q;
  if (&main_queue == (q = QUEUE_NEXT(&main_queue))) {
    // if (os_epoll_sockets()) {
    //  os_epoll_wait(-1);
    //} else {
    printf("The end!\n");
    C(0);
    //}
  } else
    A(q) C(1);
}
#include "aradani.h"
static N(sheasrule) {
  R(QUEUE *, q);
  QUEUE_REMOVE(q);
  queue_paper_t *p = QUEUE_DATA(q, queue_paper_t, q);
  p->q[0] = 0;
  p_t *pσ = p->σ, *pο = pσ[0].v;
  Q_t pα = p->α;
  q_t pρ = pσ[2].q;
  tablelookup[pα](pο, p->ο);
  pο[pα - 1].c(pο, pα - 1, pρ, pσ);
}
N(os_next) {
  A6(rigisgadartva, shemdegi_rigis_furceli, da, got, sheasrule, anda) O;
}
N(os_next0) {
  assert(α == 0);
  QUEUE *q;
  // TODO: move temp_queue on oars. to stop/start execution fo word.
  if (&temp_queue != (q = QUEUE_NEXT(&temp_queue))) {
    QUEUE_PREV(q) = QUEUE_PREV(&main_queue);
    QUEUE_PREV_NEXT(&temp_queue) = &main_queue;
    QUEUE_PREV_NEXT(&main_queue) = q;
    QUEUE_PREV(&main_queue) = QUEUE_PREV(&temp_queue);
    QUEUE_INIT(&temp_queue);
  }
  if (&main_queue == (q = QUEUE_NEXT(&main_queue))) {
    // if (os_epoll_sockets()) {
    //  os_epoll_wait(-1);
    //} else {
    printf("The end!\n");
    return;
    //}
  }
  QUEUE_REMOVE(q);
  queue_paper_t *p = QUEUE_DATA(q, queue_paper_t, q);
  p->q[0] = 0;
  p_t *pσ = p->σ, *pο = pσ[0].v;
  Q_t pα = p->α;
  q_t pρ = pσ[2].q;
  tablelookup[pα](pο, p->ο);
  pο[pα - 1].c(pο, pα - 1, pρ, pσ);
}

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
void os_queue_init() {
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
