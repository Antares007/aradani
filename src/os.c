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
  A(nσ) C(, 1);
}
N(os_delete) {
  R(p_t *, nσ);
  free(nσ[0].v);
  C(, 1);
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
Q_t next_queue_paper() {
  static Q_t last = 0;
  Q_t i = last + 1;
  for (; i < sizeof(queue_papers) / sizeof(*queue_papers); i++)
    // TODO: try replace if with assert here
    if (queue_papers[i].q[0] == 0)
      return last = i, i;
  for (i = 1; i < last; i++)
    // TODO: try replace if with assert here
    if (queue_papers[i].q[0] == 0)
      return last = i, i;
  return 0;
}
N(os_queue) { // TODO: reorder args
  R(Q_t, wc);
  R(p_t *, nσ);
  Q_t qpno;
  if ((qpno = next_queue_paper()) == 0)
    C(, 2);
  queue_papers[qpno].σ = nσ;
  queue_papers[qpno].α = 0;
  // TODO: use table lookup here
  while (queue_papers[qpno].α < wc)
    queue_papers[qpno].ο[queue_papers[qpno].α++].v = ο[--α].v;
  QUEUE_INSERT_TAIL((QUEUE *)&σ[3], &queue_papers[qpno].q);
  C(, 1);
}
// TODO: hide implementation details! as an including c file?
// TODO: simplify lookup function signature type
typedef Q_t (*amocere_t)(p_t *, p_t *, Q_t, Q_t);
static Q_t amocere0(p_t *pο, p_t *ο, Q_t pα, Q_t α) { return pα; }
static Q_t amocere1(p_t *pο, p_t *ο, Q_t pα, Q_t α) {
  pο[pα++].v = ο[--α].v;
  return pα;
}
static Q_t amocere2(p_t *pο, p_t *ο, Q_t pα, Q_t α) {
  pο[pα++].v = ο[--α].v;
  pο[pα++].v = ο[--α].v;
  return pα;
}
static Q_t amocere3(p_t *pο, p_t *ο, Q_t pα, Q_t α) {
  pο[pα++].v = ο[--α].v;
  pο[pα++].v = ο[--α].v;
  pο[pα++].v = ο[--α].v;
  return pα;
}
static Q_t amocere4(p_t *pο, p_t *ο, Q_t pα, Q_t α) {
  pο[pα++].v = ο[--α].v;
  pο[pα++].v = ο[--α].v;
  pο[pα++].v = ο[--α].v;
  pο[pα++].v = ο[--α].v;
  return pα;
}
static Q_t amocere5(p_t *pο, p_t *ο, Q_t pα, Q_t α) {
  pο[pα++].v = ο[--α].v;
  pο[pα++].v = ο[--α].v;
  pο[pα++].v = ο[--α].v;
  pο[pα++].v = ο[--α].v;
  pο[pα++].v = ο[--α].v;
  return pα;
}
static Q_t amocere6(p_t *pο, p_t *ο, Q_t pα, Q_t α) {
  pο[pα++].v = ο[--α].v;
  pο[pα++].v = ο[--α].v;
  pο[pα++].v = ο[--α].v;
  pο[pα++].v = ο[--α].v;
  pο[pα++].v = ο[--α].v;
  pο[pα++].v = ο[--α].v;
  return pα;
}
N(os_next) {
  // TODO: assert α zero
  σ[1].Q = α;
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
  Q_t pα = pσ[1].Q;
  q_t pρ = pσ[2].q;
  // TODO: restrict params. add asserts required
  static amocere_t tablelookup[7] = {amocere0, amocere1, amocere2, amocere3,
                                     amocere4, amocere5, amocere6};
  pα = tablelookup[p->α](pο, p->ο, pα, p->α);
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
N(ang) { C(, 0); }
N(dag) { C(, 1); }
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
