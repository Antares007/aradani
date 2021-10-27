#include "aradani.h"
#include "mmap.h"
#include "os_expimp.h"
#include "queue.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
N(os_new) {
  R(Q_t, ws);
  R(Q_t, wc);
  Noars(n, ο[--α].c, ο[--α].c, ο[--α].c, wc, ws);
  A(nσ) C(1);
}
N(os_delete) {
  R(p_t *, nσ);
  free(nσ[0].v);
  C(1);
}
typedef struct {
  QUEUE q;
  Q_t α;
  p_t *σ;
  p_t ο[12];
} queue_paper_t;
queue_paper_t queue_papers[1024];
QUEUE main_queue;
void init_queue() {
  QUEUE_INIT(&main_queue);
  for (Q_t i = 0; i < sizeof(queue_papers) / sizeof(*queue_papers); i++)
    queue_papers[i].q[0] = 0;
}
// TODO: hide implementation details! as an including c file?
typedef void (*memcopy_t)(p_t *, p_t *);
static void memcopy0(p_t *pο, p_t *ο) {}
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
N(os_queue) { // TODO: reorder args
  R(Q_t, wc);
  R(p_t *, nσ);
  static unsigned short qpno = 0;
  qpno++, qpno %= 1024;
  assert(queue_papers[qpno].q[0] == 0);
  queue_papers[qpno].σ = nσ;
  queue_papers[qpno].α = 0;
  static memcopy_t tablelookup[7] = {memcopy0, memcopy1, memcopy2, memcopy3,
                                     memcopy4, memcopy5, memcopy6};
  tablelookup[wc](queue_papers[qpno].ο, &ο[α -= (queue_papers[qpno].α = wc)]);
  QUEUE_INSERT_TAIL((QUEUE *)&σ[3], &queue_papers[qpno].q);
  C(1);
}
N(os_next) {
  assert(α == 0);
  QUEUE *q;
  if ((QUEUE *)&σ[3] == (q = QUEUE_NEXT((QUEUE *)&σ[3]))) {
    if (&main_queue == (q = QUEUE_NEXT(&main_queue)))
      return (printf("the end!\n"), (void)0);
    else
      QUEUE_REMOVE(q);
  } else {
    QUEUE *qn;
    if ((QUEUE *)&σ[3] != (qn = QUEUE_NEXT(q))) {
      QUEUE_PREV(qn) = QUEUE_PREV(&main_queue);
      QUEUE_PREV_NEXT(&main_queue) = qn;
      QUEUE_PREV(&main_queue) = QUEUE_PREV((QUEUE *)&σ[3]);
      QUEUE_PREV_NEXT((QUEUE *)&σ[3]) = &main_queue;
    }
    QUEUE_INIT((QUEUE *)&σ[3]);
  }
  queue_paper_t *p = QUEUE_DATA(q, queue_paper_t, q);
  p->q[0] = 0;
  p_t *pσ = p->σ, *pο = pσ[0].v;
  Q_t pα = p->α;
  q_t pρ = pσ[2].q;
  // TODO: restrict params. add asserts required
  static memcopy_t tablelookup[7] = {memcopy0, memcopy1, memcopy2, memcopy3,
                                     memcopy4, memcopy5, memcopy6};
  tablelookup[pα](pο, p->ο);
  pο[pα - 1].c(pο, pα - 1, pρ, pσ);
}
static N(os_არა) { printf("os_არა\n"); }
// TODO: remove os_next calls by extending meaning of dOt
static N(os_და) {
  printf("os_და\n");
  os_next(T());
}
static N(os_ან) {
  printf("os_ან\n");
  os_next(T());
}
N(ang) { C(0); }
N(dag) { C(1); }
N(so0) {
  R(p_t *, oσ);
  printf("so0\n");
  A7(σ, ang, oσ, 3, os_queue, os_next, da) O;
}
N(so1) {
  R(p_t *, oσ);
  R(Q_t, c);
  if (c % 100000000 == 0)
    printf("so1 %ld\n", c);
  A8(c + 1, σ, dag, oσ, 3, os_queue, os_next, da) O;
}
N(so2) { printf("so2\n"); }
N(so) { A6(so0, so1, so2, 64, 0, os_new) O; }
N(si0) {
  R(p_t *, oσ);
  printf("si0\n");
  A7(σ, dag, oσ, 3, os_queue, os_next, da) O;
}
N(si1) {
  R(p_t *, oσ);
  R(Q_t, c);
  if (c % 100000000 == 1)
    printf("si1 %ld\n", c);
  A8(c + 1, σ, dag, oσ, 3, os_queue, os_next, da) O;
}
N(si2) { printf("si2\n"); }
N(si) { A6(si0, si1, si2, 64, 0, os_new) O; }
int main(int argc, char **argv) {
  init_queue();
  Noars(, os_ან, os_და, os_არა, 0x1000, 0);
  printf("aa\n");
  A8(0, si, ang, so, daa, 3, os_queue, დაა) O;
  // if (argc < 2)
  //  printf("%s filenameToRun\n", argv[0]);
  // unsigned long size;
  // n_t arsi = mapfile(argc < 2 ? "src/arsi00.arsi" : argv[1], &size);
  //*(void **)((char *)arsi + size - 10) = ღრმაარსი;
  // A2(arsi, არსი) O;
}
