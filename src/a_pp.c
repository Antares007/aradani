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
/*
s    = np vp thenS
       s  pp thenS orelse3      "s" memoize
np   = noun
       det noun thenS orelse3
       np  pp   thenS orelse3   "np" memoize
pp   = prep np thenS            "pp" memoize  
vp   = verb np thenS            "vp" memoize  
det  = 'a' term
       't' term orelse2         "det" memoize 
noun = 'i' term 
       'm' term orelse2
       'p' term orelse2
       'b' term orelse2         "noun" memoize  
verb = 's' term                 "verb" memoize
prep = 'n' term
       'w' term orelse2         "prep" memoize 

s    = memoize "s" ((np ‘thenS‘ vp) ‘orelse‘ (s ‘thenS‘ pp))
np   = memoize "np" (noun ‘orelse‘ (det ‘thenS‘ noun) ‘orelse‘ (np ‘thenS‘ pp))
pp   = memoize "pp" (prep ‘thenS‘ np)
vp   = memoize "vp" (verb ‘thenS‘ np)
det  = memoize "det" (term ’a’ ‘orelse‘ term ’t’)
noun = memoize "noun" (term ’i’
                       ‘orelse‘ term ’m’
                       ‘orelse‘ term ’p’
                       ‘orelse‘ term ’b’)
verb = memoize "verb" (term ’s’)
prep = memoize "prep" (term ’n’ ‘orelse‘ term ’w’)
*/
static NP(init) { C(1); }
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
N(empty_oor) {
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
//N(orelse) { Α(orelse_oor, 2, new_pith) O; }
//N(thenS ) { Α(thenS_oor,  2, new_pith) O; }
//N(term  ) { Α(term_oor,   1, new_pith) O; }
//N(empty ) { Α(empty_oor,  0, new_pith) O; }

//N(term_s) { Α('s', term) O; }
//N(term_a) { Α('a', term) O; }
//N(term_b) { Α('b', term) O; }
//N(term_c) { Α('c', term) O; }
 
N(term   ){PLog; α -= 1, C(1); }
N(orelse2){PLog; α -= 2, O; }
N(orelse3){PLog; α -= 3, O; }
N(thenS  ){PLog; α -= 1, O; }
N(memoize){PLog; α -= 1, O; }
N(noun   ){PLog;
        Α('i', term,
          'm', term, orelse2,
          'p', term, orelse2,
          'b', term, orelse2,        "noun", memoize) O;}
N(det    ){PLog;
        Α('a', term,
          't', term, orelse2,         "det", memoize) O;}
N(prep   ){PLog;
        Α('n', term,
          'w', term, orelse2,        "prep", memoize) O;}
N(verb   ){PLog;
        Α('s', term,                 "verb", memoize) O;}
N(pp);
N(np     ){PLog;
        Α(noun,
          det, noun, thenS, orelse3,
          np,  pp,   thenS, orelse3,  "np", memoize) O;}
N(vp     ){PLog;
        Α(verb, np, thenS,            "vp", memoize) O;}
N(s      ){PLog;
        Α(np, vp, thenS,
          s,  pp, thenS, orelse3,     "s", memoize) O;}
N(pp     ){PLog;
        Α(prep, np, thenS,            "pp", memoize) O;}

N(exam){Α(np) O; }


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
