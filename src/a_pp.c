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
              ⎧
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
parse p     = p 0 */
static NP(init) { C(1); }
N(new_pith);
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
N(empty_oor ) { PLog; C(1); }
N(orelse_oor) { PLog; Α(ο[8].c, os_unsoll_apply) O; }
N(thenS_oor ) { PLog; C(1); }
N(term_oor  ) { PLog; C(1); }
N(mk_orelse ) { PLog; Α(orelse_oor, 2, new_pith) O; }
N(mk_thenS  ) { PLog; Α(thenS_oor,  2, new_pith) O; }
N(mk_term   ) { PLog; Α(term_oor,   1, new_pith) O; }
N(mk_empty  ) { PLog; Α(empty_oor,  0, new_pith) O; }

//N(term_s) { Α('s', term) O; }
//N(term_a) { Α('a', term) O; }
//N(term_b) { Α('b', term) O; }
//N(term_c) { Α('c', term) O; }
 
N(pgod) {PLog; C(1);}

N(orelse_nn) {
  R(p_t *, soll);
  Α(dot, soll, mk_orelse, and2) O;
}
N(orelse_n ) {
  R(Q_t, wc);
  Α(wc, os_soll_n, orelse_nn, and) O;
}

N(thenS_nn) {
  R(p_t *, soll);
  Α(dot, soll, mk_thenS, and2) O;
}
N(thenS_n){ 
  R(Q_t, wc);
  Α(wc, os_soll_n, thenS_nn, and) O;
}
N(term   ){ mk_term(T()); }
N(memoize);


N(orelse ){ Α(1) orelse_n(T()); }
N(orelse2){ Α(2) orelse_n(T()); }
N(orelse3){ Α(3) orelse_n(T()); }
N(thenS  ){ Α(1) thenS_n(T()); }
N(thenS2 ){ Α(2) thenS_n(T()); }
N(thenS3 ){ Α(3) thenS_n(T()); }

NargoP(noun   )('i', term,
               'm', term, orelse2,
               'p', term, orelse2,
               'b', term, orelse2,       noun, memoize)
NargoP(det    )('a', term,
               't', term, orelse2,        det, memoize)
NargoP(prep   )('n', term,
               'w', term, orelse2,       prep, memoize)
NargoP(verb   )('s', term,                verb, memoize)
N(pp);
NargoP(np     )(noun,
               det, noun, thenS, orelse3,
               np,  pp,   thenS, orelse3,  np, memoize)
NargoP(vp     )(verb, np, thenS,            vp, memoize)
NargoP(s      )(np, vp, thenS,
               s,  pp, thenS, orelse3,      s, memoize)
NargoP(pp     )(prep, np, thenS,            pp, memoize)
NargoP(Sa     )('b', term,
               Sa, 'a', term, orelse3,     Sa, memoize)
NargoP(exam   )(gor, np, os_queue, and)


N(Not) { PLog; C(1); }
N(And) { PLog; C(1); }
N(Oor) { PLog; C(1); }
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
static p_t memo[512][2];
N(memoize_n) {
  R(Q_t, id);
  R(void *, v);
  for(Q_t i = 0; i < sizeof(memo) / sizeof(*memo); i++)
    if (memo[i][0].Q == 0)
      return memo[i][0].Q = id,
             memo[i][1].v = v,
             A(v) C(1);
  A(v) C(1);
}
N(memoize) {
  PLog;
  R(Q_t, id);
  for(Q_t i = 0; i < sizeof(memo) / sizeof(*memo); i++)
    if (memo[i][0].Q == id) return α = 0, A(memo[i][1].v) C(1);
  Α(dot, id, memoize_n, and2) O;
}
