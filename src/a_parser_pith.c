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
NP(pgot) { Α(got) O; }
NP(pgod) { Α(god) O; }
NP(pgor) { Α(gor) O; }
N(spith);

N(thenS);
NP(thenS_oor) {
  R(Q_t, pos);
  R(Q_t, len);
  R(void *, buf);
  Α(ο[8].p, buf, len, pos, gor, ο[7].p, os_queue) O;
}
NP(thenS) { Α(thenS_oor, 2, spith) O; }

N(orelse);
NP(orelse_oor) {
  Α(gor, os_soll, os_soll_dup, and,
    ο[7].p, os_queue_soll, and2,
    ο[8].p, os_queue_soll, and2) O;
}
NP(orelse) { Α(orelse_oor, 2, spith) O; }

N(term);
NP(term_oor) {
  R(Q_t, pos);
  R(Q_t, len);
  R(const char *, buf);
  R(p_t *, cο);
  if (pos >= len)                   C(1);
  else if (ο[7].Q == (Q_t)buf[pos]) Α(buf, len, pos + 1, gor, cο, os_queue) O;
  else                              C(2);
}
NP(term) { Α(term_oor, 1, spith) O; }

N(empty);
NP(empty_oor) {
  R(Q_t, pos);
  R(Q_t, len);
  R(void *, buf);
  R(p_t *, cο);
  Α(buf, len, pos, gor, cο, os_queue) O;
}
NP(empty) { Α(empty_oor, 0, spith) O; }

NP(term_s) { Α('s', term) O; }
NP(term_a) { Α('a', term) O; }

N(Ο) { Α(ο) C(1); }

NP(sS_oor) { Α(gor,
    term_s,
    ο, thenS, and2,
    //ο, thenS, and2,
    empty,    and,
    orelse,   and,
os_queue, and) O; }
NP(sS) { Α(sS_oor, 0, spith) O; }

NP(queue) { os_queue(T()); }
NP(exam) { Α(ο, "sssss", 5, 0, gor,
  //            term_s, term_s, and, thenS, and,
              sS,
              queue, and) O; }

NP(Not) { Α(os_wordump) O; }
NP(And) { Α(os_wordump) O; }
NP(Oor) { Α(os_wordump) O; }
NP(mk_dumper) { Α(ο, 0, Oor, And, Not, 512, os_new_pith) O; }
NP(მთავარი) { Α(exam, mk_dumper, 1, os_queue_n, and2) O; }

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
  Α(ο, 0, oor, god, got, 512, os_new_pith, wc, set_state, and2) O;
}
