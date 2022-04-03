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
os_unsoll_free,     L)IN(L,
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
// clang-format on
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
enum { Position, Buffer, Length, Nexts, Memo, };
N(paper) {
  R(const char *, buffer);
  R(Q_t, position);
  Α(position, buffer, cslen(buffer),
    0, os_soll_n,
    0, os_soll_n, and2,
    5, os_soll_n, and2) O;
}
N(swap      ) { R(void*, b); R(void*, a); Α(b, a) C(1); }
N(drop      ) { α--, C(1); }
N(swap_drop ) { Α(swap, drop, and) O; }
N(paper_dup ) {
  R(p_t *, op);
  Α(op,
    op[0].Q, op[1].cs, op[2].Q,
    op[3].v, os_soll_dup, swap_drop, and,
    op[4].v, os_soll_dup, swap_drop, and, and4,
          5, os_soll_n, and2) O;
}
N(paper_join) {
  R(p_t *, rp);
  R(p_t *, lp);
  Α((rp[0].Q < lp[0].Q ? lp[0].Q : rp[0].Q), lp[1].cs, lp[2].Q,
    lp[3].v,
    lp[4].v, 5, os_soll_n) O;
}
N(paper_push_next) {
  R(p_t*, paper);
  R(p_t*, next);
  Α(next, paper[Nexts].p, sοpush) O;
}
N(gor_apply ) { R(p_t*, oο); Α(gor, oο, os_queue) O; }
N(paper_goto_next) {
  R(p_t*, paper);
  Α(paper, paper[Nexts].p, sοpop, gor_apply, and) O;
}
N(paper_inc_position) {
  R(p_t*, paper);
  paper[Position].Q++;
  C(1);
}

NP(empty_oor ) {
  R(p_t*, paper);
  Α(paper, paper_goto_next) O;
}

N(orelse_join) {
  R(p_t *, paper);
  ο[++ο[7].Q + 7].p = paper;
  if (ο[7].Q == 2)
    Α(ο[7+1].p, ο[2+7].p, paper_join,
                     paper_goto_next, and) O;
  else
    C(1);
}
NP(orelse_oor_nn) {
  R(p_t *, rpaper);
  R(p_t *, lpaper);
  Α(lpaper, ο[7].c, gor_apply,
    rpaper, ο[8].c, gor_apply, and, and4) O;
}
N(orelse_oor_n) {
  R(p_t *, oο);
  R(p_t *, paper);
  Α(oο,
    paper, paper_push_next,
    paper, paper_dup, and2,
            orelse_oor_nn, and) O;
}
N(orelse_oor) {
  Α(0, orelse_join, 1, new_pith,
                   orelse_oor_n, and) O;
}
NP(thenS_oor ) {
  R(p_t *, paper);
  Α(ο[8].c, paper, paper_push_next, and2,
            paper, ο[7].c, gor_apply, and3) O;
}

NP(term_oor ) {
  R(p_t*, paper); print("%s %lu\n", paper[Buffer].cs, paper[Position].Q);
  if (paper[Position].Q >= paper[Length ].Q ||
 (Q_t)paper[Buffer ].cs[ paper[Position].Q] != ο[7].Q) {
    Α(paper, paper_goto_next) O;
  } else {
    Α(paper, paper_inc_position,
      paper, paper_goto_next, and2) O;
  }
}

N(mk_orelse   ) { Α(orelse_oor, 2, new_pith) O; }
N(mk_thenS    ) { Α(thenS_oor,  2, new_pith) O; }
N(mk_term     ) { Α(term_oor,   1, new_pith) O; }
N(mk_empty    ) { Α(empty_oor,  0, new_pith) O; }
N(orelse      ) { R(p_t *, vο); Α(dot, vο, mk_orelse, and2) O; }
N(thenS       ) { R(p_t *, vο); Α(dot, vο, mk_thenS, and2) O; }
N(term        ) { mk_term(T()); }
N(empty       ) { mk_empty(T()); }
N(memoize);

NP(term_s     ) { Α('s', term) O; }
NP(exam_thenS ) { Α(term_s, term_s, thenS) O; }
NP(exam_orelse) { Α(empty, term_s, orelse) O; }
NP(exam_sS    ) { Α(term_s, exam_sS, thenS, empty, orelse) O; }

N(parse);
N(exam        ) { Α(1, "sssss", paper, exam_thenS, parse) O; }

N(term_i  ) { Α('i', term) O; }
N(term_m  ) { Α('m', term) O; }
N(term_p  ) { Α('p', term) O; }
N(term_b  ) { Α('b', term) O; }
N(term_a  ) { Α('a', term) O; }
N(term_t  ) { Α('t', term) O; }
N(term_n  ) { Α('n', term) O; }
N(term_w  ) { Α('w', term) O; }
N(pp);N(np_pp);N(s);
N(noun    ) { Α(term_i,
                term_m, orelse,
                term_p, orelse,
                term_b, orelse,       noun, memoize) O; }
N(det     ) { Α(term_a,
                term_t, orelse,        det, memoize) O; }
N(prep    ) { Α(term_n,
                term_w, orelse,       prep, memoize) O; }
N(verb    ) { Α(term_s,               verb, memoize) O; }
N(det_noun) { Α(det, noun, thenS) O; }
N(np      ) { Α(noun,
                det_noun, orelse,
                np_pp,    orelse,       np, memoize) O; }
N(vp      ) { Α(verb, np, thenS,        vp, memoize) O; }
N(s_pp    ) { Α(s, pp, thenS) O; }
N(s       ) { Α(np, vp, thenS,
                s_pp,  orelse,           s, memoize) O; }
N(pp      ) { Α(prep, np, thenS,        pp, memoize) O; }
N(np_pp   ) { Α(np,    pp, thenS) O; }

NP(Not      ) { C(1); }
NP(And      ) { C(1); }
NP(Oor      ) { Α(os_unsoll_free, os_wordump, and) O; }
N(mk_dumper ) { Α(ο, 0, Oor, And, Not, 512, os_new_pith) O; }
N(მთავარი   ) { Α(exam, mk_dumper, 1, os_queue_n, and2) O; }
N(exam_run  ) {
  R(n_t, vs);
  R(p_t*, paper);
  Α(ο,
    paper, paper_push_next,
    paper, vs, gor_apply, and3) O;
}
N(parse) {
  R(n_t, r);
  R(n_t, l);
  Α(l, r, and, exam_run, and) O;
}

EN(tail,
მთავარი,      exports);

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
  R(Q_t, id);
  for (Q_t i = 0; i < sizeof(memo) / sizeof(*memo); i++)
    if (memo[i][0].Q == id)
      return α = 0, A(memo[i][1].v) C(1);
  Α(dot, id, memoize_n, and2) O;
}
