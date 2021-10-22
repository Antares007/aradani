#include "aradani.h"
#include "mmap.h"
#include "os_expimp.h"
#include "queue.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
  N(os_შემდეგი){}
    N(os_წერტილი){}
      N(os_აგულგული){}
/*
 *      ρ  σ        οα
 *      OANρlrqq lrαx
 * */
N(one) { A(1) C(, 1); }
N(add) {
  R(long, r);
  R(long, l);
  A(l + r) C(, 1);
}
N(two) { A5(one, one, da, add, da) O; }
N(seven) { A5(one, two, da, add, da) O; }
N(wordump);
N(an_gadasvla) { C(, 0); }
N(da_gadasvla) { C(, 1); }
N(ara_gadasvla) { C(, 2); }

N(run) {
  // if (argc < 2)
  //  printf("%s filenameToRun\n", argv[0]);
  // unsigned long size;
  // n_t arsi = mapfile(argc < 2 ? "src/arsi00.arsi" : argv[1], &size);
  //*(void **)((char *)arsi + size - 10) = ღრმაარსი;
  // A2(arsi, არსი) O;
}
N(new_oars) {
  R(Q_t, ws);
  R(Q_t, wc);
  Noars(ο[--α].c, ο[--α].c, ο[--α].c, wc, ws, n);
  A(nσ) C(, 1);
}
N(free_oars) {
  R(p_t *, nσ);
  free(nσ[0].v);
  C(, 1);
}
typedef struct {
  QUEUE q;
  Q_t α;
  p_t *σ;
  p_t ο[32];
} queue_paper_t;
queue_paper_t queue_papers[1024];
QUEUE main_queue;
void init_queue() {
  QUEUE_INIT(&main_queue);
  for (Q_t i = 0; i < sizeof(queue_papers) / sizeof(*queue_papers); i++)
    queue_papers[i].q[0] = 0;
}
Q_t next_queue_paper() {
  static Q_t last = 0;
  Q_t i = last + 1;
  for (; i < sizeof(queue_papers) / sizeof(*queue_papers); i++)
    if (queue_papers[i].q[0] == 0)
      return last = i, i;
  for (i = 1; i < last; i++)
    if (queue_papers[i].q[0] == 0)
      return last = i, i;
  return 0;
}
N(queue) {
  R(Q_t, wc);
  R(p_t *, nσ);
  Q_t qpno;
  if ((qpno = next_queue_paper()) == 0)
    C(, 2);
  queue_papers[qpno].σ = nσ;
  queue_papers[qpno].α = 0;
  while (queue_papers[qpno].α < wc)
    queue_papers[qpno].ο[queue_papers[qpno].α++].v = ο[--α].v;
  QUEUE_INSERT_TAIL((QUEUE *)&σ[3], &queue_papers[qpno].q);
  C(, 1);
}
N(next) {
  σ[1].Q = α;
  QUEUE *q;
  if ((QUEUE *)&σ[3] != (q = QUEUE_NEXT((QUEUE *)&σ[3]))) {
    QUEUE *qn;
    if ((QUEUE *)&σ[3] != (qn = QUEUE_NEXT(q))) {
      QUEUE_PREV(qn) = QUEUE_PREV(&main_queue);
      QUEUE_PREV_NEXT(&main_queue) = qn;
      QUEUE_PREV(&main_queue) = QUEUE_PREV((QUEUE *)&σ[3]);
      QUEUE_PREV_NEXT((QUEUE *)&σ[3]) = &main_queue;
    }
    QUEUE_INIT((QUEUE *)&σ[3]);
    queue_paper_t *p = QUEUE_DATA(q, queue_paper_t, q);
    p->q[0] = 0;
    p_t *pσ = p->σ, *pο = pσ[0].v;
    Q_t pα = pσ[1].Q;
    q_t pρ = pσ[2].q;
    while (p->α)
      pο[pα++].v = p->ο[--p->α].v;
    pο[pα - 1].c(pο, pα - 1, pρ, pσ);
  } else if (&main_queue != (q = QUEUE_NEXT(&main_queue))) {
    QUEUE_REMOVE(q);
    queue_paper_t *p = QUEUE_DATA(q, queue_paper_t, q);
    p->q[0] = 0;
    p_t *pσ = p->σ, *pο = pσ[0].v;
    Q_t pα = pσ[1].Q;
    q_t pρ = pσ[2].q;
    while (p->α)
      pο[pα++].v = p->ο[--p->α].v;
    pο[pα - 1].c(pο, pα - 1, pρ, pσ);
  } else
    printf("end\n");
}
N(r0) {
  R(p_t *, oσ);
  printf("r0\n");
  A7(σ, da_gadasvla, oσ, 2, queue, next, da) O;
}
N(r1) {
  R(p_t *, oσ);
  printf("r1\n");
  A7(σ, da_gadasvla, oσ, 2, queue, next, da) O;
}
N(r2) { printf("r2\n"); }
N(mr) { A6(r0, r1, r2, 64, 0, new_oars) O; }
N(a0) {
  printf("a0\n");
  next(T());
}
N(a1) {
  R(p_t *, oσ);
  printf("a1\n");
  A7(σ, da_gadasvla, oσ, 2, queue, next, da) O;
}
N(a2) { printf("a2\n"); }
N(ma) { A6(a0, a1, a2, 64, 0, new_oars) O; }
N(cb) { A7(ma, an_gadasvla, mr, daa, 2, queue, daa) O; }
static N(os_არა) { printf("os_არა\n"); }
static N(os_და) {
  printf("os_და\n");
  next(T());
}
static N(os_ან) {
  printf("os_ან\n");
  next(T());
}
int main(int argc, char **argv) {
  init_queue();
  Noars(os_ან, os_და, os_არა, 512, 3, );
  cb(T());
}
