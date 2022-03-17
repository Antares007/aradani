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
and2or2,            L)IN(L,
and3,               L)IN(L,
and3or,             L)IN(L,
and4,               L)IN(L,
andor,        imports);
#include "a_queue.h"
// clang-format off
SarP(init)(god);
S(q_unroll) {
  R(p_t *, qσ);
  Q_t wc = qσ[-1].Q;
  for (Q_t i = 0; i < wc; i++)
    σ[α + i].v = qσ[i].v;
  α += wc, C(1);
}
S(q_roll_n) {
  R(Q_t, wc);
  R(p_t *, qσ);
  qσ[0].Q = 0, qσ[2].Q = wc, qσ += 3, α -= wc;
  for (Q_t i = 0; i < wc; i++)
    qσ[i].v = σ[α + i].v;
  A(qσ) C(1);
}
S(q_roll) {
  R(Q_t, wc);
  Α((wc + 3) * sizeof(p_t), l_malloc, wc, q_roll_n, and2) O;
}
S(q_roll_free) {
  R(p_t *, qσ);
  Α(qσ - 3, l_free) O;
}
S(q_prev_roll) {
  R(p_t *, h);
  p_t *q = Q_PREV(h);
  if (q == h)
    C(0);
  else
    A(q) C(1);
}
S(q_next_roll) {
  R(p_t *, h);
  p_t *q = Q_NEXT(h);
  if (q == h)
    C(0);
  else
    A(q) C(1);
}
S(q_roll_remove) {
  R(p_t *, qσ);
  if (qσ[-3].Q) Q_REMOVE(qσ), C(1);
  else C(2);
}
S(q_roll_ruf) {
  R(p_t *, qσ);
  Α(qσ, q_roll_remove, qσ, q_unroll, and2, qσ, q_roll_free, and2) O;
}
S(q_roll_push) {
  R(p_t *, h);
  R(p_t *, qσ);
  Q_INSERT_TAIL(h, qσ), C(1);
}
S(q_roll_unshift) {
  R(p_t *, h);
  R(p_t *, qσ);
  Q_INSERT_HEAD(h, qσ), C(1);
}
S(q_push) {
  R(p_t *, h);
  Q_t wc = α;
  Α(wc, q_roll, h, q_roll_push, and2) O;
}
S(q_unshift) {
  R(p_t *, h);
  Q_t wc = α;
  Α(wc, q_roll, h, q_roll_unshift, and2) O;
}
S(q_pop) {
  R(p_t *, h);
  Α(h, q_prev_roll, q_roll_ruf, and) O;
}
S(q_shift) {
  R(p_t *, h);
  Α(h, q_next_roll, q_roll_ruf, and) O;
}
//S(q_for_each);
//S(q_for_each_n) {
//  R(p_t *, qσ);
//  R(p_t *, h);
//  R(n_t, nar);
//  Α(qσ, nar, nar, h, q_for_each, god, and3or) O;
//}
//S(q_for_each) {
//  R(p_t *, h);
//  R(n_t, nar);
//  Α(nar, h, h, q_next_roll,
//      q_for_each_n,
//      god, andor) O;
//}
//
//SP(pgod) {
//  R(p_t *, qσ);
//  (void)qσ;
//  A(god) O;
//}
S(მთავარი_n) {
  R(p_t *, h);
  Α(debugger,
    6, 3, h, q_push, and4,
    2, 3, h, q_unshift, and4,
    3, 6, h, q_push, and4,
    1, 2, h, q_unshift, and4,
  //pgod, h, q_for_each, and3,
          h, q_pop, and2,
          h, q_pop, and2,
          h, q_shift, and2,
          h, q_shift, and2,
         -1, os_wordump,
         +0, os_wordump, and2or2)
  O;
}
S(მთავარი) {
  p_t h[3];
  (QUEUE_INIT((QUEUE *)h), Α(h + 3, მთავარი_n) O);
}
// clang-format off
EN(tail,
q_next_roll,        L)EN(L,
q_pop,              L)EN(L,
q_prev_roll,        L)EN(L,
q_push,             L)EN(L,
q_roll,             L)EN(L,
q_roll_free,        L)EN(L,
q_roll_n,           L)EN(L,
q_roll_push,        L)EN(L,
q_roll_remove,      L)EN(L,
q_roll_ruf,         L)EN(L,
q_roll_unshift,     L)EN(L,
q_shift,            L)EN(L,
q_unroll,           L)EN(L,
q_unshift,          L)EN(L,
მთავარი_n,          L)EN(L,
მთავარი,      exports);
