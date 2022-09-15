#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
debugger,           L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
l_free,             L)IN(L,
l_malloc,           L)IN(L,
os_new_ps,          L)IN(L,
os_queue,           L)IN(L,
os_wordump,         L)IN(L, //
and,                L)IN(L,
and2,               L)IN(L,
and3,               L)IN(L,
and4,               L)IN(L,
andor,        imports);
#include "os/queue.h"
S(queue_insert_tail) {
  R(QUEUE *, qσ);
  QUEUE *h = (QUEUE*)&ο[7];
  QUEUE_INSERT_TAIL(h, qσ), C(1);
}
S(queue_insert_head) {
  R(QUEUE *, qσ);
  QUEUE *h = (QUEUE*)&ο[7];
  QUEUE_INSERT_HEAD(h, qσ), C(1);
}
S(roll_out) {
  R(p_t *, qσ);
  qσ[2].Q = α;
  while (α)
    --α, qσ[α + 3].v = σ[α].v;
  Α(qσ) C(1);
}
S(roll_in) {
  R(p_t *, qσ);
  Q_t qα = qσ[2].Q;
  for (Q_t i = 0; i < qα; i++)
    σ[α + i].v = qσ[i + 3].v;
  α += qα, C(1);
}
S(q_remove) {
  R(QUEUE *, q);
  QUEUE_REMOVE(q), A2(q, l_free) O;
}
S(roll_in_and_free) {
  R(QUEUE *, q);
  QUEUE *h = (QUEUE*)&ο[7];
  if (q == h)
    return C(0);
  A5(q, roll_in, q, q_remove, and2) O;
}
S(q_push) {
  Q_t β = α + 3;
  Α(β * sizeof(void *), l_malloc, roll_out, and, queue_insert_tail, and) O;
}
S(q_unshift) {
  Q_t β = α + 3;
  Α(β * sizeof(void *), l_malloc, roll_out, and, queue_insert_head, and) O;
}
S(q_pop) {
  QUEUE *h = (QUEUE*)&ο[7];
  QUEUE *q = QUEUE_PREV(h);
  Α(q, roll_in_and_free) O;
}
S(q_shift) {
  QUEUE *h = (QUEUE*)&ο[7];
  QUEUE *q = QUEUE_NEXT(h);
  Α(q, roll_in_and_free) O;
}
S(q_for_each_n) {
  R(QUEUE *, q);
  QUEUE *h = (QUEUE*)&ο[7];
  R(n_t, n);
  if (q == h)
    C(1);
  else
    A8(q, roll_in, n, and, n, QUEUE_NEXT(q), q_for_each_n, and3) O;
}
S(q_for_each) {
  QUEUE *h = (QUEUE*)&ο[7];
  R(n_t, n);
  A3(n, QUEUE_NEXT(h), q_for_each_n) O;
}
Sar(q_not)(got)
Sar(q_and)(god)
S(q_oor) { R(p_t*, oο); ο[9].p = oο, C(1); }
S(q_set) { R(p_t*, oο); ο[9].p =  0, QUEUE_INIT((QUEUE*)&oο[7]), A(oο) C(1); }
S(q_new) { Α(q_not, q_and, q_oor, ο, 512, os_new_ps, q_set, and) O; }

SarP(init)(god);
NP(pgod) {
  R(Q_t, a);
  R(Q_t, b);
  A(a + b) C(1);
}
SP(Main_n) {
  R(p_t *, qο);
  Α(debugger, 
    6, 3, q_push, and3,
    3, 6, q_push, and3,
    pgod, q_for_each, and2,
          q_shift, and,
          q_shift, and,
          os_wordump, os_wordump, andor,
          qο, os_queue) O;
}
SP(Main) {
  Α(q_new, Main_n, and) O;
}
EN(tail,
q_for_each,         L)EN(L,
q_pop,              L)EN(L,
q_push,             L)EN(L,
q_remove,           L)EN(L,
q_shift,            L)EN(L,
q_unshift,          L)EN(L,
Main,         exports)
