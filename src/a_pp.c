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
N(new_pith);

#define LOG print("σ:%lx n:%2lu α:%lu pos:%lu %s\n",  \
                  ((Q_t)σ >> 12) & 0xff,              \
                  ο[3].Q,                             \
                  α,                                  \
                  pos,                                \
                  __FUNCTION__                        \
                  )
#define CοBufLenPos R(Q_t, pos); R(Q_t, len); R(const char *, buf); R(p_t *, cο); LOG 
N(Q)  { os_queue(T()); }
N(QN) { os_queue_n(T()); }
N(QS) { os_queue_soll(T()); }
N(sοpop) {
  R(p_t*, sο);
  if (sο[Ǎ].Q)
    A(sο[--sο[Ǎ].Q].v) C(1); 
  else C(2);
}
N(sοpush) {
  R(p_t*, sο);
  R(void*, v);
  if ((sο[Ǎ].Q + 1) < sο[Σ].Q)
    sο[sο[Ǎ].Q++].v = v, A(sο) C(1); 
  else C(2);
}
N(vε_oor) {
  CοBufLenPos;
  Α(cο, buf, len, pos, gor, cο, sοpop,
    5, QN, and2) O;
}
/*            ⎧
              ⎪ {},      j ≥ #input
term t j    = ⎨ {j + 1}, j th element of input = t
              ⎪ {},      otherwise
              ⎩
empty j     = {j}
(p <+> q) j = (p j) ∪ (q j) 
(p  *> q) j = (map q (p j))

(<+>)       :: R -> R -> R
p <+> q     = \r -> union (p r) (q r)
(*>)        :: R -> R -> R
p *> q      = \r -> unions $ map q $ elems $ p r
parse       :: R -> PosSet
parse p     = p 0

*/
N(orelse_oor) {
  CοBufLenPos;
  Α(cο, buf, len, pos, gor, 5, os_soll_n,
    os_soll_dup, and,
    ο[7].p, QS, and2,
    ο[8].p, QS, and2) O;
}
N(thenS_oor) {
  CοBufLenPos;
  Α(ο[8].p, cο, sοpush,
    buf, len, pos, gor, ο[7].p, 5, QN, and7) O;
}
N(term_oor) {
  CοBufLenPos;
  if (pos >= len) {
    print("A\n"), C(1);
  } else if (ο[7].Q == (Q_t)buf[pos]) {
    print("B\n"), Α(cο, buf, len, pos + 1, gor, cο, sοpop,
                    5, QN, and2) O;
  } else {
    print("C\n"), C(1);
  }
}
N(var_oor) {
  CοBufLenPos;
  Α(cο, buf, len, pos, gor, ο[7].p, 5, QN) O;
}
N(orelse) { Α(orelse_oor, 2, new_pith) O; }
N(thenS) { Α(thenS_oor, 2, new_pith) O; }
N(term) { Α(term_oor, 1, new_pith) O; }
N(var) { Α(var_oor, 1, new_pith) O; }
N(ε) { Α(vε_oor, 0, new_pith) O; }

N(term_s) { Α('s', term) O; }
N(term_a) { Α('a', term) O; }
N(term_b) { Α('b', term) O; }
N(term_c) { Α('c', term) O; }
N(Ο)      { Α(ο) C(1); }
N(sS);
Q_t i = 0;
Q_t j = 0;
N(TR) { PLog;
  R(const char*, trm);
  R(n_t, l);
  (void)trm, (void)l;
}
N(TS) { PLog;
  R(n_t, r);
  R(n_t, l);
  (void)r;
  if(l != ο[7].c)
    l(T());
  else
    C(1);
}
N(OR) { PLog; R(n_t, r); R(n_t, l); (void)r; if(l != ο[7].c) l(T()); else C(1); }

N(t_a) { PLog; C(1); }
N(t_b) { PLog; C(1); }
N(t_c) { PLog; C(1); }
N(t_d) { PLog; C(1); }

N(Sa);
N(Sa_a    ){ PLog; Α(Sa, t_a, TS) O; }
N(Sa_b    ){ PLog; Α(Sa, t_b, TS) O; }
N(Sa      ){ PLog; Α(Sa_a, Sa_b, OR, t_c, OR, t_d, OR) O; }


N(exam    ){ PLog; ο[7].c = Sa; Α(Sa) O; }

Nargo(sS1)(term_s,
           ο,      
           thenS,  and2,
           ο,      
           thenS,  and2)
Nargo(sS2)(ε)
Nargo(sS )(sS1,
           sS2,    and,
           orelse, and)
NP(exam22) {
  Α(sS) O;
//        Α(ο, 1, os_soll_n,
//          "sssss", 5, 0, gor, sS, and5,
//          Q, and) O;
}

N(drop3) {
  if (α == 4) {
    CοBufLenPos;
    print(">%s(%lu)%lu - %lu\n", buf,pos,len, cο[Ǎ].Q);
    C(1);
  } else Α(os_wordump) O;
}
#include "os/queue.h"
static Q_t qlen(QUEUE *h);
N(Not) { print("N %lu\n", qlen((void*)&ο[Φ].p[Φ].p[Ψ])), Α(drop3) O; }
N(And) { print("A %lu\n", qlen((void*)&ο[Φ].p[Φ].p[Ψ])), Α(drop3) O; }
N(Oor) { print("O %lu\n", qlen((void*)&ο[Φ].p[Φ].p[Ψ])), Α(drop3) O; }
N(mk_dumper) { Α(ο, 0, Oor, And, Not, 512, os_new_pith) O; }
N(მთავარი) { Α(exam, mk_dumper, 1, QN, and2) O; }

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

N(new_pith) {
  R(Q_t, wc);
  R(n_t, oor);
  Α(ο[Φ].p, 0, oor, god, got, 512, os_new_pith, wc, set_state, and2) O;
}
static Q_t qlen(QUEUE *h) {
  QUEUE *q;
  Q_t c = 0;
  for ((q) = QUEUE_NEXT(h); (q) != (h); (q) = QUEUE_NEXT(q))
    c++;
  return c;
}
