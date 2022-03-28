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

#define LOG print("%lx %2lu α:%lu σ[α-1].Q:%lu %s\n", ((Q_t)σ >> 12) & 0xff, ο[3].Q, α, σ[α-1].Q, __FUNCTION__)
N(queue) { os_queue(T()); }
N(queue_n) { os_queue_n(T()); }
N(queue_soll) { os_queue_soll(T()); }

N(empty);
N(empty_oor) {
  LOG;
  R(Q_t, pos);
  R(Q_t, len);
  R(void *, buf);
  R(p_t *, cο);
  Α(buf, len, pos, gor, cο, queue) O;
}
N(empty) { Α(empty_oor, 0, spith) O; }

N(orelse);
N(orelse_oor) {
  LOG;
  Α(gor,
    os_soll,
    os_soll_dup, and,
    ο[7].p, queue_soll, and2,
    ο[8].p, queue_soll, and2) O;
}
N(orelse) { Α(orelse_oor, 2, spith) O; }

N(thenS);
N(thenS_oor) {
  LOG;
  R(Q_t, pos);
  R(Q_t, len);
  R(void *, buf);
  Α(ο[8].p, buf, len, pos, gor, ο[7].p, queue) O;
}
N(thenS) { Α(thenS_oor, 2, spith) O; }

N(term);
N(term_oor) {
  LOG;
  R(Q_t, pos);
  R(Q_t, len);
  R(const char *, buf);
  R(p_t *, cο);
  if (pos >= len) {
    print("A\n");
    α = 0, C(1);
  } else if (ο[7].Q == (Q_t)buf[pos]) {
    print("B\n"), Α(buf, len, pos + 1, gor, cο, queue) O;
  } else {
    print("C\n");
    α = 0, C(1);
  }
}
N(term) { Α(term_oor, 1, spith) O; }

N(term_s) { Α('s', term) O; }
N(term_a) { Α('a', term) O; }
N(Ο)      { Α(ο) C(1); }

N(sen) { Α(term_s, ο, thenS, and2, ο, thenS, and2) O; }
N(sS_oor) {
  LOG;
  Α(
  gor,
    empty, 
      sen, and, orelse, and,
  queue, and) O;
}// term_s, term_a, and, thenS,  and, term_s, and, thenS,  and,
N(sS) { Α(sS_oor, 0, spith) O; }

NP(exam) {
        Α(ο, "sasss", 5, 0, gor,
            //sS,
            term_a,
            queue, and) O;
}
N(drop3) {
  if (α == 3) {
    R(Q_t, pos);
    R(Q_t, len);
    R(const char *, buf);
    print("\n---> %s(%lu)%lu\n", buf,pos,len);
    C(1);
  } else Α(os_wordump) O;
}
NP(Not) { Α(drop3) O; }
NP(And) { Α(drop3) O; }
NP(Oor) { Α(drop3) O; }
N(mk_dumper) { Α(ο, 0, Oor, And, Not, 512, os_new_pith) O; }
N(მთავარი) { Α(exam, mk_dumper, 1, queue_n, and2) O; }

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
