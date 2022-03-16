#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
debugger,           L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
l_free,             L)IN(L,
l_malloc,           L)IN(L,
os_wordump,         L)IN(L,
//
and,                L)IN(L,
and2,               L)IN(L,
and3,               L)IN(L,
and4,               L)IN(L,
andor,        imports);
// clang-format off
#include "os/queue.h"
S(queue_insert_tail) {
  R(QUEUE *, qσ);
  R(QUEUE *, h);
  QUEUE_INSERT_TAIL(h, qσ), C(1);
}
S(queue_insert_head) {
  R(QUEUE *, qσ);
  R(QUEUE *, h);
  QUEUE_INSERT_HEAD(h, qσ), C(1);
}
S(roll_out) {
  R(p_t *, qσ);
  R(QUEUE *, h);
  qσ[2].Q = α;
  while (α)
    --α, qσ[α + 3].v = σ[α].v;
  Α(h, qσ) C(1);
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
  R(QUEUE *, h);
  if (q == h)
    return C(0);
  A5(q, roll_in, q, q_remove, and2) O;
}
S(q_push) {
  R(QUEUE *, h);
  Q_t β = α + 3;
  A7(h, β * sizeof(void *), l_malloc, roll_out, and, queue_insert_tail, and) O;
}
S(q_unshift) {
  R(QUEUE *, h);
  Q_t β = α + 3;
  A7(h, β * sizeof(void *), l_malloc, roll_out, and, queue_insert_head, and) O;
}
S(q_pop) {
  R(QUEUE *, h);
  QUEUE *q = QUEUE_PREV(h);
  Α(h, q, roll_in_and_free) O;
}
S(q_shift) {
  R(QUEUE *, h);
  QUEUE *q = QUEUE_NEXT(h);
  Α(h, q, roll_in_and_free) O;
}
S(q_for_each_n) {
  R(QUEUE *, q);
  R(QUEUE *, h);
  R(n_t, n);
  if (q == h)
    C(1);
  else
    A10(q, q, roll_in, n, and, n, h, QUEUE_NEXT(q), q_for_each_n, and4) O;
}
S(q_for_each) {
  R(QUEUE *, h);
  R(n_t, n);
  A4(n, h, QUEUE_NEXT(h), q_for_each_n) O;
}

SarP(init)(god);
SP(pgod) {
  R(Q_t, a);
  R(Q_t, b);
  R(QUEUE*, q);
  (void)q;
  //A3(a + b, q, q_remove) O;
  A2(a + b, god) O;
}
SP(Main_n) {
  R(QUEUE *, h);
  Α(debugger, 
    6, 3, h, q_push, and4,
    3, 6, h, q_push, and4,
    pgod, h, q_for_each, and3,
          h, q_shift, and2,
          h, q_shift, and2,
          os_wordump,
          os_wordump, andor) O;
}
SP(Main) {
  QUEUE h;
  QUEUE_INIT(&h), Α(&h, Main_n) O;
}
// clang-format off
EN(tail,
q_for_each,         L)EN(L,
q_pop,              L)EN(L,
q_push,             L)EN(L,
q_remove,           L)EN(L,
q_shift,            L)EN(L,
q_unshift,          L)EN(L,
Main,         exports)
