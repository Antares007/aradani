#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
debugger,           L)IN(L,
dot,                L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
nar,                L)IN(L,
os_ls,              L)IN(L,
os_new_pith,        L)IN(L,
os_queue,           L)IN(L,
os_queue_n,         L)IN(L,
os_queue_soll,      L)IN(L,
os_soll,            L)IN(L,
os_soll_dup,        L)IN(L,
os_soll_free,       L)IN(L,
os_soll_n,          L)IN(L,
os_unsoll,          L)IN(L,
os_unsoll_apply,    L)IN(L,
os_wordump,         L)IN(L,

and,                L)IN(L,
and2,               L)IN(L,
and3,               L)IN(L,
and3or,             L)IN(L,
and4,               L)IN(L,
and5,               L)IN(L,
and7,               L)IN(L,
or3,          imports);
// clang-format off

static NP(init) { C(1); }
N(pgot) { Α(got) O; }
N(pgod) { Α(god) O; }
N(pgor) { Α(gor) O; }
N(spith);

#define LOG print("%p %2lu α:%lu σ[α-1].Q:%lu %s\n",σ, ο[3].Q, α, σ[α-1].Q, __FUNCTION__)

N(empty);
N(empty_oor) {
  R(Q_t, pos);
  R(Q_t, len);
  R(void *, buf);
  R(p_t *, cο);
  Α(buf, len, pos, gor, cο, os_queue) O;
}
N(empty) { Α(empty_oor, 0, spith) O; }

N(orelse);
N(orelse_oor) {
  Α(gor, os_soll, os_soll_dup, and,
    ο[7].p, os_queue_soll, and2,
    ο[8].p, os_queue_soll, and2) O;
}
N(orelse) { Α(orelse_oor, 2, spith) O; }
Q_t i = 0;
N(thenS);
N(thenS_oor) {
  LOG;
  if(i++>10) return;
  R(Q_t, pos);
  R(Q_t, len);
  R(void *, buf);
  Α(ο[8].p, buf, len, pos, gor, ο[7].p, os_queue) O;
}
NP(thenS) { Α(thenS_oor, 2, spith) O; }

N(term);
N(term_oor) {
  LOG;
  R(Q_t, pos);
  R(Q_t, len);
  R(const char *, buf);
  R(p_t *, cο);
  if (pos >= len) {
    print("a\n");
    Α(buf, len, pos, got, cο, os_queue) O;
  } else if (ο[7].Q == (Q_t)buf[pos]) {
    print("b\n"), Α(buf, len, pos + 1, gor, cο, os_queue) O;
  } else {
    print("c\n");
    C(1);
  }
}
N(term) { Α(term_oor, 1, spith) O; }

NP(term_s) { Α('s', term) O; }
NP(term_a) { Α('a', term) O; }
N(Ο)      { Α(ο) C(1); }

N(sS_oor) { Α(
    gor,
    term_s, term_a, and, thenS,  and, term_s, and, thenS,  and,
    //ο, thenS, and2,
    //ο, thenS, and2,
    //ο, thenS, and2,
    //empty,    and,
    //orelse,   and,
    2, os_queue_n, and2) O; }
N(sS) { Α(sS_oor, 0, spith) O; }

N(queue) { os_queue(T()); }
N(exam) { Α(ο, "sasss", 5, 0, gor,
  //            term_s, term_s, and, thenS, and,
              sS,
              queue, and) O; }

N(Not) { Α(os_wordump) O; }
N(And) { Α(os_wordump) O; }
N(Oor) { Α(os_wordump) O; }
N(mk_dumper) { Α(ο, 0, Oor, And, Not, 512, os_new_pith) O; }
N(მთავარი) { Α(exam, mk_dumper, 1, os_queue_n, and2) O; }

// clang-format off
EN(tail,
მთავარი,      exports);
// clang-format on

N(set_state) {
  R(Q_t, wc);
  R(p_t *, oο);
  while (wc)
    oο[--wc + 7].v = σ[--α].v;
  Α(oο) C(1);
}

N(spith) {
  R(Q_t, wc);
  R(n_t, oor);
  Α(ο[Φ].p, 0, oor, god, got, 512, os_new_pith, wc, set_state, and2) O;
}
