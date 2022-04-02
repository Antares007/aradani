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
os_unsoll_free_apply,L)IN(L,
os_wordump,         L)IN(L,

and,                L)IN(L,
and2,               L)IN(L,
and3,               L)IN(L,
and3or,             L)IN(L,
and4,               L)IN(L,
and5,               L)IN(L,
and5or3,            L)IN(L,
and7,               L)IN(L,
andor3,             L)IN(L,
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

(<+>)       :: R -> R -> R
p <+> q     = \r -> union (p r) (q r)
(*>)        :: R -> R -> R
p *> q      = \r -> unions $ map q $ elems $ p r
parse       :: R -> PosSet
parse p     = p 0 */
static NP(init) { C(1); }
N(new_pith);
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
    sο[sο[Ǎ].Q++].v = v, C(1); 
  else C(2);
}
N(sοfind) {
  R(p_t*, sο);
  R(void*, v);
  for (Q_t i = 0; i < sο[Ǎ].Q; i++)
    if (sο[i].v == v) return C(1);
  C(0);
}

Q_t cslen(const char* cs) { Q_t len = 0; while(cs[len]) len++; return len; }
enum {
  Position,
  Buffer,
  Length,
  Nexts,
  Memo,
};
N(paper) {
  R(const char *, buffer);
  R(Q_t, position);
  Α(position, buffer, cslen(buffer),
    0, os_soll_n,
    0, os_soll_n, and2,
    5, os_soll_n, and2) O;
}
N(paper_push_next) {
  R(p_t*, paper);
  R(p_t*, next);
  Α(next, paper[Nexts].p, sοpush) O;
}
N(os_unsoll_free_apply_) {
  A(os_unsoll_free_apply) O;
}
N(paper_goto_next) {
  R(p_t*, paper);
  Α(paper, paper[Nexts].p, sοpop, os_unsoll_free_apply, and) O;
}
N(paper_inc_position) {
  R(p_t*, paper);
  paper[Position].Q++;
  C(1);
}
N(gor_apply     ) { R(p_t*, oο); Α(gor, oο, os_queue) O; }
N(soll_gor_apply) { R(p_t*, oο); Α(oο, gor_apply, 2, os_soll_n) O; }

//empty j     = {j}
NP(empty_oor ) {
  R(p_t*, paper);
  Α(paper, paper_goto_next) O;
}
//(p <+> q) j = (p j) ∪ (q j) 
NP(orelse_oor) { C(1); }
//(p  *> q) j = (map q (p j))
NP(thenS_oor ) {
  R(p_t *, paper);
  print("%s %lu\n", paper[Buffer].cs, paper[Position].Q);
  //Α(gor, ο[7].c, os_queue,
  //     thenS_mk_next_soll, and,
  //          nexts, sοpush, and2,
  //        ο, memo, sοpush, and3) O; 
  Α(ο[8].c,  soll_gor_apply, and,
    paper,   paper_push_next, and2,
    paper, ο[7].c, gor_apply, and3) O;
}
//               ⎧
//               ⎪ {},      j ≥ #input
// term t j    = ⎨ {j + 1}, j th element of input = t
//               ⎪ {},      otherwise
//               ⎩
NP(term_oor  ) {
  R(p_t*, paper);
  print("%s %lu\n", paper[Buffer].cs, paper[Position].Q);
  if (paper[Position].Q >= paper[Length  ].Q ||
 (Q_t)paper[Buffer  ].cs[  paper[Position].Q] != ο[7].Q) {
    print("a\n");
    Α(paper, paper_goto_next) O;
  } else {
    print("b\n");
    Α(paper, paper_inc_position,
      paper, paper_goto_next, and2) O;
  }
}

N(mk_orelse ) { Α(orelse_oor, 2, new_pith) O; }
N(mk_thenS  ) { Α(thenS_oor,  2, new_pith) O; }
N(mk_term   ) { Α(term_oor,   1, new_pith) O; }
N(mk_empty  ) { Α(empty_oor,  0, new_pith) O; }
N(orelse    ) { R(p_t *, vο); Α(dot, vο, mk_orelse, and2) O; }
N(thenS     ) { R(p_t *, vο); Α(dot, vο, mk_thenS, and2) O; }
N(term      ) { mk_term(T()); }
N(memoize);



NargoP(term_s)('s', term)
NargoP(exam_thenS)(term_s, term_s, thenS)
N(exam_run) {
  R(n_t, vs);
  R(p_t*, paper);
  Α(ο, soll_gor_apply,
    paper, paper_push_next, and2,
    paper, vs, gor_apply, and3) O;
}
NargoP(exam)(
  1, "sssss", paper,
         exam_thenS, and,
           exam_run, and
)
/*
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
               Sa, 'a', term, thenS2, orelse4,     Sa, memoize)
*/

N(Not) { PLog; C(1); }
N(And) { PLog; C(1); }
N(Oor) { PLog; Α(os_unsoll, os_wordump, and) O; }
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

N(new_pith) {
  R(Q_t, wc);
  R(n_t, oor);
  Α(ο[Φ].p, 0, oor, god, got, 512, os_new_pith, wc, set_state, and2) O;
}
static p_t memo[512][2];
N(memoize_n) {
  R(Q_t, id);
  R(void *, v);
  for (Q_t i = 0; i < sizeof(memo) / sizeof(*memo); i++)
    if (memo[i][0].Q == 0)
      return memo[i][0].Q = id, memo[i][1].v = v, A(v) C(1);
  A(v) C(1);
}
N(memoize) {
  PLog;
  R(Q_t, id);
  for (Q_t i = 0; i < sizeof(memo) / sizeof(*memo); i++)
    if (memo[i][0].Q == id)
      return α = 0, A(memo[i][1].v) C(1);
  Α(dot, id, memoize_n, and2) O;
}
