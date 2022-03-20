#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
debugger,           L)IN(L,
dot,                L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
os_soll_free,       L)IN(L,
os_soll_n,          L)IN(L,
os_unsoll,          L)IN(L,
os_wordump,         L)IN(L, //
and,                L)IN(L,
and2,               L)IN(L,
and2or2,            L)IN(L,
and3,               L)IN(L,
and4,               L)IN(L,
and4or2,            L)IN(L,
and4or4,            L)IN(L,
and5,         imports);

#include "os/queue.h"

#define S2Q(s) ((QUEUE*)((s) + (s)[-1].Q - 3))
#define Q2S(q) (((p_t*)(q)) - ((p_t*)(q))[2].Q)

SarP(init)(god);
S(drop3) { α -= 3, C(1); }
Sar(q_unroll)(os_unsoll, drop3, and)
S(q_soll) {
  R(Q_t, wc);
  Q_t wc3 = wc + 3;
  Α(0, 0, wc, wc3, os_soll_n) O;
}
Sar(q_soll_free)(os_soll_free);
S(q_soll_push) {
  R(p_t *, h);
  R(p_t *, qσ);
  QUEUE_INSERT_TAIL(S2Q(h), S2Q(qσ)), C(1);
}
S(q_soll_unshift) {
  R(p_t *, h);
  R(p_t *, qσ);
  QUEUE_INSERT_HEAD(S2Q(h), S2Q(qσ)), C(1);
}
S(q_push) {
  R(p_t *, h);
  Q_t wc = α;
  Α(wc, q_soll, h, q_soll_push, and2) O;
}
S(q_unshift) {
  R(p_t *, h);
  Q_t wc = α;
  Α(wc, q_soll, h, q_soll_unshift, and2) O;
}
S(q_soll_unsoll_free) {
  R(p_t *, qσ);
  Α(qσ, q_unroll, qσ, q_soll_free, and2) O;
}
S(q_soll_remove) {
  R(p_t *, qσ);
  R(p_t *, h);
  if (h == qσ)
    C(0);
  else if (qσ[qσ[-1].Q - 3].Q)
    QUEUE_REMOVE(S2Q(qσ)), A(qσ) C(1);
  else
    C(2);
}
S(q_soll_pop) {
  R(p_t *, h);
  A3(h, Q2S(QUEUE_PREV(S2Q(h))), q_soll_remove) O;
}
S(q_soll_shift) {
  R(p_t *, h);
  A3(h, Q2S(QUEUE_NEXT(S2Q(h))), q_soll_remove) O;
}
S(q_pop) {
  R(p_t *, h);
  Α(h, q_soll_pop, q_soll_unsoll_free, and) O;
}
S(q_shift) {
  R(p_t *, h);
  Α(h, q_soll_shift, q_soll_unsoll_free, and) O;
}
S(q_for_each_n) {
  R(p_t *, qσ);
  R(p_t *, h);
  R(p_t *, sοll);
  if (h == qσ)
    A2(sοll, os_soll_free) O;
  else 
    A14(qσ, sοll, os_unsoll, dot, and,
        sοll, h, Q2S(QUEUE_NEXT(S2Q(qσ))), q_for_each_n,
        sοll, os_soll_free, gor, and, and4or4) O;
}
S(q_for_each) {
  R(Q_t, wc);
  R(p_t *, h);
  A6(wc, os_soll_n,
     h, Q2S(QUEUE_NEXT(S2Q(h))), q_for_each_n, and3) O;
}
S(q_make_n) {
  R(p_t *, qσ);
  QUEUE_INIT((QUEUE *)qσ);
  A(qσ) C(1);
}
Sar(q_make)(0, 0, 0, 3, os_soll_n, q_make_n, and);

Q_t i = 0;
S(pgod) {
  R(Q_t, off);
  R(p_t *, sοll);
  //Α(sοll, q_soll_remove, sοll, q_soll_free, and2) O;
  A2(off+i++, (sοll[0].Q << 32) | sοll[1].Q) C(1);
}
S(show) {
  R(p_t *, h);
          Α(6, 3, h, q_push,
            2, 3, h, q_unshift, and4,
            3, 6, h, q_push, and4,
            1, 2, h, q_unshift, and4,
                     debugger, and,
     0x100, pgod, h, 2, q_for_each, and5,
                  h, q_pop, and2,
                  h, q_pop, and2,
                  h, q_shift, and2,
                  h, q_shift, and2,
                 -1, os_wordump,
                 +0, os_wordump, and2or2) O;
}
Sar(მთავარი)(q_make, show, and)

EN(tail,
q_for_each,         L)EN(L,
q_for_each_n,       L)EN(L,
q_make,             L)EN(L,
q_make_n,           L)EN(L,
q_pop,              L)EN(L,
q_push,             L)EN(L,
q_shift,            L)EN(L,
q_soll,             L)EN(L,
q_soll_free,        L)EN(L,
q_soll_push,        L)EN(L,
q_soll_remove,      L)EN(L,
q_soll_unsoll_free, L)EN(L,
q_soll_unshift,     L)EN(L,
q_unroll,           L)EN(L,
q_unshift,          L)EN(L,
show,               L)EN(L,
მთავარი,         exports);
