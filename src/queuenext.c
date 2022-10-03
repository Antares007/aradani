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
static N(δ0) {
  QUEUE *q = QUEUE_NEXT(&temp_queue);
  QUEUE_PREV(q) = QUEUE_PREV(&main_queue);
  QUEUE_PREV_NEXT(&temp_queue) = &main_queue;
  QUEUE_PREV_NEXT(&main_queue) = q;
  QUEUE_PREV(&main_queue) = QUEUE_PREV(&temp_queue);
  QUEUE_INIT(&temp_queue);
  C(1);
}
static void δn(OANT) {
  RN(Q_t, wc);
  p_t *p = qp[i];
  i = (i + 1) % QPS;
  τ -= wc;
  p[wc + 2].Q = wc;
  QUEUE_INSERT_HEAD(&temp_queue, (QUEUE *)&p[wc]);
  for (Q_t i = 0; i < wc; i++)
    p[i].v = ν[τ + i].v;
  O;
}
static N(δ1) { A(1) δn(T); }
static N(δ2) { A(2) δn(T); }
static N(δ3) { A(3) δn(T); }
static N(δ4) { A(4) δn(T); }
static N(δ5) { A(5) δn(T); }
static N(δ6) { A(6) δn(T); }
static N(δ7) { A(7) δn(T); }
static N(δ8) { A(8) δn(T); }
static N(δ9) { A(9) δn(T); }
static N(δ10) { A(10) δn(T); }
static N(δ11) { A(11) δn(T); }
static N(δ12) { A(12) δn(T); }
static N(δ13) { A(13) δn(T); }
static N(δ14) { A(14) δn(T); }
static N(δ15) { A(15) δn(T); }
static N(δ16) { A(16) δn(T); }
static N(δ17) { A(17) δn(T); }
static N(δ18) { A(18) δn(T); }
static N(δ19) { A(19) δn(T); }
static N(δ20) { A(20) δn(T); }
static N(δ21) { A(21) δn(T); }
static N(δ22) { A(22) δn(T); }
static N(δ23) { A(23) δn(T); }
static N(δ24) { A(24) δn(T); }
static N(δ25) { A(25) δn(T); }
static N(δ26) { A(26) δn(T); }
static N(δ27) { A(27) δn(T); }
static N(δ28) { A(28) δn(T); }
static N(δ29) { A(29) δn(T); }
static N(δ30) { A(30) δn(T); }
static N(δ31) { A(31) δn(T); }
n_t δ[32] = {
    δ0,  δ1,  δ2,  δ3,  δ4,  δ5,  δ6,  δ7,  δ8,  δ9,  δ10,
    δ11, δ12, δ13, δ14, δ15, δ16, δ17, δ18, δ19, δ20, δ21,
    δ22, δ23, δ24, δ25, δ26, δ27, δ28, δ29, δ30, δ31,
};
