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
and4,         imports);
#include "os/queue.h"
// clang-format on
S(q_roll_out    ) { R(p_t *, qσ); Q_t wc = qσ[-1].Q; for (Q_t i = 0; i < wc; i++) σ[α + i].v = qσ[i].v; α += wc, C(1); }
S(q_roll_in_n   ) { R(Q_t, wc); R(p_t*, qσ); qσ[0].Q = 0, qσ[2].Q = wc, qσ += 3, α -= wc; for (Q_t i = 0; i < wc; i++) qσ[i].v = σ[α + i].v; A(qσ) C(1); }
S(q_roll_in     ) { R(Q_t, wc); Α((wc + 3) * sizeof(p_t), l_malloc, wc, q_roll_in_n, and2) O; }
S(q_roll_free   ) { R(p_t *, qσ); Α(qσ - 3, l_free) O; }
S(q_prev_roll   ) { R(QUEUE *, h); QUEUE *q = QUEUE_PREV(h); if (q == h) C(0); else A((p_t*)q + 3) C(1); }
S(q_next_roll   ) { R(QUEUE *, h); QUEUE *q = QUEUE_NEXT(h); if (q == h) C(0); else A((p_t*)q + 3) C(1); }
S(q_roll_remove ) { R(p_t *, qσ); qσ -= 3; if (qσ[0].Q) (QUEUE_REMOVE((QUEUE*)qσ), C(1)); else C(2); }
S(q_roll_ruf    ) { R(p_t *, qσ); Α(qσ, q_roll_remove, qσ, q_roll_out, and2, qσ, q_roll_free, and2) O; }
S(q_roll_push   ) { R(QUEUE *, h); R(p_t *, qσ); (QUEUE_INSERT_TAIL(h, (QUEUE*)(qσ - 3)), C(1)); }
S(q_roll_unshift) { R(QUEUE *, h); R(p_t *, qσ); (QUEUE_INSERT_HEAD(h, (QUEUE*)(qσ - 3)), C(1)); }
S(q_push        ) { R(QUEUE*, h); Q_t wc = α; Α(wc, q_roll_in, h, q_roll_push, and2) O; }
S(q_unshift     ) { R(QUEUE*, h); Q_t wc = α; Α(wc, q_roll_in, h, q_roll_unshift, and2) O; }
S(q_pop         ) { R(QUEUE*, h); Α(h, q_prev_roll, q_roll_ruf, and) O; }
S(q_shift       ) { R(QUEUE*, h); Α(h, q_next_roll, q_roll_ruf, and) O; }
S(Main_n) {
  R(QUEUE *, h);
  Α(debugger, 
    6, 3, h, q_push, and4,
    3, 6, h, q_push, and4,
    1, 2, h, q_push, and4,
    2, 3, h, q_push, and4,
//    pgod, h, q_for_each, and3,
          h, q_pop, and2,
          h, q_pop, and2,
          h, q_shift, and2,
          h, q_shift, and2,
         -1, os_wordump,
         +0, os_wordump, and2or2) O;
}
S(Main) {
  QUEUE h;
  (QUEUE_INIT(&h), Α(&h, Main_n) O);
}
EN(tail,
q_roll_out,         L)EN(L,
q_roll_in_n,        L)EN(L,
q_roll_in,          L)EN(L,
q_roll_free,        L)EN(L,
q_prev_roll,        L)EN(L,
q_next_roll,        L)EN(L,
q_roll_remove,      L)EN(L,
q_roll_ruf,         L)EN(L,
q_roll_push,        L)EN(L,
q_roll_unshift,     L)EN(L,
q_push,             L)EN(L,
q_unshift,          L)EN(L,
q_pop,              L)EN(L,
q_shift,            L)EN(L,
Main_n,             L)EN(L,
Main,         exports);
//S(q_for_each_n) {
//  R(QUEUE *, q);
//  R(QUEUE *, h);
//  R(n_t, n);
//  if (q == h)
//    C(1);
//  else
//    A10(q, q, roll_in, n, and, n, h, QUEUE_NEXT(q), q_for_each_n, and4) O;
//}
//S(q_for_each) {
//  R(QUEUE *, h);
//  R(n_t, n);
//  A4(n, h, QUEUE_NEXT(h), q_for_each_n) O;
//}

//SP(pgod) {
//  R(Q_t, a);
//  R(Q_t, b);
//  R(QUEUE*, q);
//  (void)q;
//  //A3(a + b, q, q_remove) O;
//  A2(a + b, god) O;
//}
SarP(init)(god);
