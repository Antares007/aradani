#include "oant.h"
#include "oant_logn.h"
#include "queue.h"
#include <stdio.h>
#define QPS 64

static QUEUE main_queue;
static QUEUE temp_queue;
static p_t qp[QPS][32];
static Q_t i = 0;
void queue_init() {
  QUEUE_INIT(&temp_queue);
  QUEUE_INIT(&main_queue);
}
N(next) {
  QUEUE *q;
  if (&main_queue == (q = QUEUE_NEXT(&main_queue)))
    return (printf("The End!\n"), (void)0);
  QUEUE_REMOVE(q);
  p_t *p = (p_t *)q;
  Q_t wc = p[2].Q;
  p -= wc;
  for (Q_t i = 0; i < wc; i++)
    ν[τ + i].v = p[i].v;
  τ += wc;
  O;
}
static N(ο0) {
  QUEUE *q = QUEUE_NEXT(&temp_queue);
  QUEUE_PREV(q) = QUEUE_PREV(&main_queue);
  QUEUE_PREV_NEXT(&temp_queue) = &main_queue;
  QUEUE_PREV_NEXT(&main_queue) = q;
  QUEUE_PREV(&main_queue) = QUEUE_PREV(&temp_queue);
  QUEUE_INIT(&temp_queue);
  C(1);
}
static N(οn) {
  RN(Q_t, wc);
  p_t *p = qp[i];
  i = (i + 1) % QPS;
  τ -= wc;
  p[wc + 2].Q = wc;
  QUEUE_INSERT_TAIL(&temp_queue, (QUEUE *)&p[wc]);
  for (Q_t i = 0; i < wc; i++)
    p[i].v = ν[τ + i].v;
  O;
}
static N(ο1) { A(1) οn(T); }
static N(ο2) { A(2) οn(T); }
static N(ο3) { A(3) οn(T); }
static N(ο4) { A(4) οn(T); }
static N(ο5) { A(5) οn(T); }
static N(ο6) { A(6) οn(T); }
static N(ο7) { A(7) οn(T); }
static N(ο8) { A(8) οn(T); }
static N(ο9) { A(9) οn(T); }
static N(ο10) { A(10) οn(T); }
static N(ο11) { A(11) οn(T); }
static N(ο12) { A(12) οn(T); }
static N(ο13) { A(13) οn(T); }
static N(ο14) { A(14) οn(T); }
static N(ο15) { A(15) οn(T); }
static N(ο16) { A(16) οn(T); }
static N(ο17) { A(17) οn(T); }
static N(ο18) { A(18) οn(T); }
static N(ο19) { A(19) οn(T); }
static N(ο20) { A(20) οn(T); }
static N(ο21) { A(21) οn(T); }
static N(ο22) { A(22) οn(T); }
static N(ο23) { A(23) οn(T); }
static N(ο24) { A(24) οn(T); }
static N(ο25) { A(25) οn(T); }
static N(ο26) { A(26) οn(T); }
static N(ο27) { A(27) οn(T); }
static N(ο28) { A(28) οn(T); }
static N(ο29) { A(29) οn(T); }
static N(ο30) { A(30) οn(T); }
static N(ο31) { A(31) οn(T); }
n_t ο[32] = {
    ο0,  ο1,  ο2,  ο3,  ο4,  ο5,  ο6,  ο7,  ο8,  ο9,  ο10,
    ο11, ο12, ο13, ο14, ο15, ο16, ο17, ο18, ο19, ο20, ο21,
    ο22, ο23, ο24, ο25, ο26, ο27, ο28, ο29, ο30, ο31,
};
