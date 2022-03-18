#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
debugger,           L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
l_free,             L)IN(L,
l_malloc,           L)IN(L,
os_soll_free,       L)IN(L,
os_soll_n,          L)IN(L,
os_unsoll,          L)IN(L,
os_wordump,         L)IN(L,
//
and,                L)IN(L,
and2,               L)IN(L,
and2or2,            L)IN(L,
and3,               L)IN(L,
and3or,             L)IN(L,
and4,               L)IN(L,
andor,        imports);
#include "os/queue.h"
#define S2Q(s) ((QUEUE*)((s) + (s)[-1].Q - 3))
#define Q2S(q) (((p_t*)(q)) - ((p_t*)(q))[2].Q)
// clang-format on
Sar(init)(god);
// TODO: Define os_rollσ os_unrollσ and use those in q_roll/unroll.
// TODO: In addition, define os_rollο and os_unrollο.
S(drop3) { α -= 3, C(1); }
Sar(q_unroll)(os_unsoll, drop3, and)
S(q_roll) {
  R(Q_t, wc);
  Q_t wc3 = wc + 3;
  Α(0, 0, wc, wc3, os_soll_n) O;
}
Sar(q_roll_free)(os_soll_free);
S(q_roll_push) {
  R(p_t *, h);
  R(p_t *, qσ);
  QUEUE_INSERT_TAIL(S2Q(h), S2Q(qσ)), C(1);
}
S(q_roll_unshift) {
  R(p_t *, h);
  R(p_t *, qσ);
  QUEUE_INSERT_HEAD(S2Q(h), S2Q(qσ)), C(1);
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
  else if (qσ[qσ[-1].Q - 3].Q)
    QUEUE_REMOVE(S2Q(qσ)), A(qσ) C(1);
  else
    C(2);
}
S(q_roll_pop) {
  R(p_t *, h);
  A3(h, Q2S(QUEUE_PREV(S2Q(h))), q_roll_remove) O;
}
S(q_roll_shift) {
  R(p_t *, h);
  A3(h, Q2S(QUEUE_NEXT(S2Q(h))), q_roll_remove) O;
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
    p_t *nqσ = Q2S(QUEUE_NEXT(S2Q(qσ)));
    Α(qσ, nar, nar, h, nqσ, q_for_each_n, and4) O;
  }
}
S(q_for_each) {
  R(p_t *, h);
  R(n_t, nar);
  p_t *qσ = Q2S(QUEUE_NEXT(S2Q(h)));
  Α(nar, h, qσ, q_for_each_n) O;
}
S(q_make_n) {
  R(p_t *, qσ);
  qσ += 1;
  qσ[-1].Q = 3;
  QUEUE_INIT((QUEUE *)qσ);
  qσ[2].Q = 0;
  A(qσ) C(1);
}
Sar(q_make)(sizeof(void *) * 4, l_malloc, q_make_n, and);

Q_t i = 0;
S(pgod) {
  R(p_t *, qσ);
  A2(i++, (qσ[0].Q << 32) | qσ[1].Q) C(1);
}
// clang-format off
NP(show_n) {
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
N(show_nn) {
  R(p_t *, h);
  Α(h, os_unsoll, os_wordump, and) O;
}
Sar(show)(q_make, show_n, and)
// clang-format off
EN(tail,
q_for_each,         L)EN(L,
q_for_each_n,       L)EN(L,
q_make,             L)EN(L,
q_make_n,           L)EN(L,
q_pop,              L)EN(L,
q_push,             L)EN(L,
q_roll,             L)EN(L,
q_roll_free,        L)EN(L,
q_roll_push,        L)EN(L,
q_roll_remove,      L)EN(L,
q_roll_ruf,         L)EN(L,
q_roll_unshift,     L)EN(L,
q_shift,            L)EN(L,
q_unroll,           L)EN(L,
q_unshift,          L)EN(L,
show_n,             L)EN(L,
show,         exports);
