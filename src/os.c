#include "aradani.h"
#include "mmap.h"
#include "os_epoll.h"
#include "queue.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

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

Nd(os_new) {
  R(Q_t, ws);
  R(Q_t, wc);
  OarS(n, ο[--α].c, ο[--α].c, ο[--α].c, wc, ws);
  A(nσ) C(1);
}

Nd(os_delete) {
  R(p_t *, nσ);
  free(nσ[0].v);
  C(1);
}
static void memcopy1(p_t *, p_t *);
static void memcopy2(p_t *, p_t *);
static void memcopy3(p_t *, p_t *);
static void memcopy4(p_t *, p_t *);
static void memcopy5(p_t *, p_t *);
static void memcopy6(p_t *, p_t *);
static void memcopy7(p_t *, p_t *);
N(os_queue) {
  R(Q_t, wc);
  R(p_t *, nσ);
  static unsigned short qpno = 0;
  qpno++, qpno %= 1024;
  assert(queue_papers[qpno].q[0] == 0);
  queue_papers[qpno].σ = nσ;
  queue_papers[qpno].α = 0;
  static memcopy_t tablelookup[8] = {0,        memcopy1, memcopy2, memcopy3,
                                     memcopy4, memcopy5, memcopy6, memcopy7};
  tablelookup[wc](queue_papers[qpno].ο, &ο[α -= (queue_papers[qpno].α = wc)]);
  QUEUE_INSERT_TAIL(&temp_queue, &queue_papers[qpno].q);
  C(1);
}
N(os_next) {
  assert(α == 0);
  QUEUE *q;
  if (&temp_queue != (q = QUEUE_NEXT(&temp_queue))) {
    QUEUE_PREV(q) = QUEUE_PREV(&main_queue);
    QUEUE_PREV_NEXT(&temp_queue) = &main_queue;
    QUEUE_PREV_NEXT(&main_queue) = q;
    QUEUE_PREV(&main_queue) = QUEUE_PREV(&temp_queue);
    QUEUE_INIT(&temp_queue);
  }
  if (&main_queue == (q = QUEUE_NEXT(&main_queue))) {
    // TODO: epoll when listeners are registered
    //int ret = epoll_wait(epoll_fd, events, MAX_EVENT_NUMBER, -1);
    //if (ret < 0) {
    //  printf("epoll failure!\n");
    //} else {
    //}
  } else {
    // TODO: wait 0
    QUEUE_REMOVE(q);
    queue_paper_t *p = QUEUE_DATA(q, queue_paper_t, q);
    p->q[0] = 0;
    p_t *pσ = p->σ, *pο = pσ[0].v;
    Q_t pα = p->α;
    q_t pρ = pσ[2].q;
    static memcopy_t tablelookup[8] = {0,        memcopy1, memcopy2, memcopy3,
                                       memcopy4, memcopy5, memcopy6, memcopy7};
    tablelookup[pα](pο, p->ο);
    pο[pα - 1].c(pο, pα - 1, pρ, pσ);
  }
}
static Nd(os_არა) {}
N(wordump);
N(αzero) { α = 0, C(1); }
static Nd(os_და) {
  if (α)
    A5(wordump, αzero, da, os_next, da) O;
  else
    os_next(T());
}
static Nd(os_ან) { os_next(T()); }
#include "os_exports.h"
N(stab) { --α, A(os_exports) C(1); }
N(nn) {
  R(n_t, export);
  R(n_t, addd);
  R(char *, name);
  printf("N %s %p\n", name, addd);
  A3(export, nn, da) O;
}
int cmp(const char *s1, const char *s2);
N(run) {
  R(n_t, export);
  R(n_t, addd);
  R(char *, name);
  R(char *, mame);
  printf("N %s %p\n", name, addd);
  if (cmp(mame, name) == 0) {
    A(addd) O;
  } else {
    A4(mame, export, run, da) O;
  }
}
N(os_impexp);
N(example_cicle);
static void os_queue_init() {
  QUEUE_INIT(&main_queue);
  QUEUE_INIT(&temp_queue);
  for (Q_t i = 0; i < MAX_QUEUE_PAPERS; i++)
    queue_papers[i].q[0] = 0;
}

int main(int argc, char **argv) {
  os_queue_init();
  os_epoll_init();
  OarS(, os_ან, os_და, os_არა, 0x1000, 0);
  if (argc < 2)
    printf("%s filenameToRun\n", argv[0]);
  else
    printf("%s\n", argv[1]);
  unsigned long size;
  n_t arsi = mapfile(argc < 2 ? "src/arsi00.arsi" : argv[1], &size);
  *(void **)((char *)arsi + size - 10) = stab;
  A6("მთავარი", os_impexp, arsi, run, da, daa) O;
  α = 0, example_cicle(T());
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
