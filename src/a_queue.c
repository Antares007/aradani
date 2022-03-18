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
// clang-format on
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
S(q_roll_ruf) {
  R(p_t *, qσ);
  Α(qσ, q_unroll, qσ, q_roll_free, and2) O;
}
S(q_roll_remove) {
  R(p_t *, qσ);
  R(p_t *, h);
  if (h == qσ)
    C(0);
  else if (qσ[-3].Q)
    Q_REMOVE(qσ), A(qσ) C(1);
  else
    C(2);
}
S(q_roll_pop) {
  R(p_t *, h);
  A3(h, Q_PREV(h), q_roll_remove) O;
}
S(q_roll_shift) {
  R(p_t *, h);
  A3(h, Q_NEXT(h), q_roll_remove) O;
}
S(q_pop) {
  R(p_t *, h);
  Α(h, q_roll_pop, q_roll_ruf, and) O;
}
S(q_shift) {
  R(p_t *, h);
  Α(h, q_roll_shift, q_roll_ruf, and) O;
}
S(q_for_each_n) {
  R(p_t *, qσ);
  R(p_t *, h);
  R(n_t, nar);
  if (h == qσ)
    C(1);
  else {
    p_t *nqσ = Q_NEXT(qσ);
    Α(qσ, nar, nar, h, nqσ, q_for_each_n, and4) O;
  }
}
S(q_for_each) {
  R(p_t *, h);
  R(n_t, nar);
  p_t *qσ = Q_NEXT(h);
  Α(nar, h, qσ, q_for_each_n) O;
}
Q_t i = 0;
SP(pgod) {
  R(p_t *, qσ);
  A2(i++, (qσ[0].Q << 32) | qσ[1].Q) C(1);
}
// clang-format off
S(show_n) {
  R(p_t *, h);
  Α(
    6, 3, h, q_push,
    2, 3, h, q_unshift, and4,
    3, 6, h, q_push, and4,
    1, 2, h, q_unshift, and4,
    debugger, and,
    pgod, h, q_for_each, and3,
          h, q_pop, and2,
          h, q_pop, and2,
          h, q_shift, and2,
          h, q_shift, and2,
         -1, os_wordump,
         +0, os_wordump, and2or2)
  O;
}
S(show) {
  p_t h[3];
  (QUEUE_INIT((QUEUE *)h), Α(h + 3, show_n) O);
}
// clang-format off
EN(tail,
q_for_each,         L)EN(L,
q_for_each_n,       L)EN(L,
q_pop,              L)EN(L,
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
show_n,             L)EN(L,
show,         exports);
