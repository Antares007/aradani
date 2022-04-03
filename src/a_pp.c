#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
co0,                L)IN(L,
co1,                L)IN(L,
co2,                L)IN(L,
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
andor,              L)IN(L,
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
  R(p_t *, sο);
  if (sο[Ǎ].Q)
    A(sο[--sο[Ǎ].Q].v) C(1);
  else
    C(2);
}
N(sοpush) {
  R(p_t *, sο);
  R(void *, v);
  if ((sο[Ǎ].Q + 1) < sο[Σ].Q)
    sο[sο[Ǎ].Q++].v = v, C(1);
  else
    C(2);
}
N(sοfind) {
  R(p_t *, sο);
  R(void *, v);
  for (Q_t i = 0; i < sο[Ǎ].Q; i++)
    if (sο[i].v == v)
      return C(1);
  C(0);
}
Q_t cslen(const char *cs) {
  Q_t len = 0;
  while (cs[len])
    len++;
  return len;
}
N(swap) {
  R(void *, b);
  R(void *, a);
  Α(b, a) C(1);
}
N(drop) { α--, C(1); }
N(dup_swap_drop) { Α(os_soll_dup, swap, and, drop, and) O; }

enum {
  Position,
  Buffer,
  Length,
  Nexts,
  Memo,
  Line,
};
#define PP(Name)                                                               \
  print("\n%2lx %s %lu d:%lu %s\n", ((Q_t)paper >> 12) & 0xFF, ο[5].cs,        \
        paper[Position].Q, paper[Nexts].p[Ǎ].Q, #Name);                        \
  for (Q_t i = 0; i < paper[Memo].p[Ǎ].Q; i++)                                 \
    print(" %s", paper[Memo].p[i].cs);                                         \
  if (paper[Memo].p[Ǎ].Q)                                                      \
    print("\n");                                                               \
  for (Q_t i = 0; i < paper[Nexts].p[Ǎ].Q; i++)                                \
    print(" %s", paper[Nexts].p[i].p[5].cs);                                   \
  if (paper[Nexts].p[Ǎ].Q)                                                     \
    print("\n");                                                               \
  for (Q_t i = 0; i < paper[Line].p[Ǎ].Q; i++)                                 \
    print(" %s", paper[Line].p[i].cs);                                         \
  if (paper[Line].p[Ǎ].Q)                                                      \
    print("\n");
N(paper) {
  R(const char *, buffer);
  R(Q_t, position);
  Α(position, buffer, cslen(buffer),
    0, os_soll_n,
    0, os_soll_n, and2,
    0, os_soll_n, and2,
    6, os_soll_n, and2)
  O;
}
N(paper_dup) {
  R(p_t *, op);
  Α(op, op[0].Q, op[1].cs, op[2].Q,
    op[3].v, dup_swap_drop,
    op[4].v, dup_swap_drop, and2,
    op[5].v, dup_swap_drop, and2,
    6, os_soll_n, and2)
  O;
}
NP(curtails_) {
  R(p_t *, paper);
  Q_t curt = 0;
  for (Q_t i = 0; i < paper[Memo].p[Ǎ].Q; i++)
    if (cmp(paper[Memo].p[i].cs, ο[5].cs) == 0)
      curt++;
  if (curt > paper[Length].Q) {
    paper[Memo].p[Ǎ].Q = 0;
    A(paper) C(1);
  } else {
    A(paper) C(0);
  }
}
N(paper_memoize_pith) {
  R(p_t *, paper);
  p_t *line = paper[Line].p;
  line[line[Ǎ].Q++].v = ο[5].v ? ο[5].v : ο[3].v ? ο[3].v : ο[4].v;
  if (ο[5].Q)
    Α(ο[5].Q, paper[Memo].p, sοpush) O;
  else
    C(1);
}
N(paper_push_next) {
  R(p_t *, paper);
  R(p_t *, next);
  Α(next, paper[Nexts].p, sοpush) O;
}
N(gor_apply) {
  R(p_t *, oο);
  Α(co0, oο, os_queue) O;
}
N(paper_goto_next) {
  R(p_t *, paper);
  Α(paper, paper[Nexts].p, sοpop, gor_apply, and) O;
}
N(paper_inc_position) {
  R(p_t *, paper);
  paper[Position].Q++;
  paper[Memo].p[Ǎ].Q = 0;
  C(1);
}

N(empty_oor) {
  R(p_t *, paper);
  //PP(Ε);
  Α(paper, paper_memoize_pith, paper, paper_goto_next, and2) O;
}

N(orelse_oor_nn) {
  R(p_t *, rpaper);
  R(p_t *, lpaper);
  Α(lpaper, ο[7].c, gor_apply, rpaper, ο[8].c, gor_apply, and, and4) O;
}
N(orelse_oor_n) {
  R(p_t *, paper);
  //PP(orelse);
  Α(paper, paper_memoize_pith, paper, paper_dup, and2, orelse_oor_nn, and) O;
}
N(curtails) {
  R(p_t *, paper);
  if (ο[5].cs)
    for (Q_t i = 0; i < paper[Memo].p[Ǎ].Q; i++)
      if (cmp(paper[Memo].p[i].cs, ο[5].cs) == 0)
        return A(paper) C(1);
  A(paper) C(0);
}
N(orelse_oor) { Α(curtails, paper_goto_next, orelse_oor_n, andor) O; }
N(thenS_oor_n) {
  R(p_t *, paper);
  //PP(thenS);
  Α(ο[8].c, paper, paper_push_next, and2,
            paper, paper_memoize_pith, and2,
            paper, ο[7].c, gor_apply, and3) O;
}
N(thenS_oor) { Α(curtails, paper_goto_next, thenS_oor_n, andor) O; }

N(term_oor) {
  R(p_t *, paper);
  //PP(V);
  if (paper[Position].Q >= paper[Length].Q ||
      (Q_t)paper[Buffer].cs[paper[Position].Q] != (Q_t)ο[7].cs[0]) {
    C(1);//Α(paper, paper_goto_next) O;
  } else {
    Α(paper, paper_inc_position, paper, paper_memoize_pith, and2, paper,
      paper_goto_next, and2)
    O;
  }
}
N(set_parent) {
  R(p_t *, oο);
  oο[Φ].v = ο;
  Α(oο) C(1);
}
N(mk_orelse) {
  R(p_t *, r);
  R(p_t *, l);
  Α(orelse_oor, 0, god, 0, "orelse", 0, 0, l, r, 9, os_soll_n, set_parent, and)
  O;
}
N(mk_thenS) {
  R(p_t *, r);
  R(p_t *, l);
  Α(thenS_oor, 0, god, 0, "thenS", 0, 0, l, r, 9, os_soll_n, set_parent, and) O;
}
N(mk_term) {
  R(p_t *, l);
  Α(term_oor, 0, god, l, "term", 0, 0, l, 0, 9, os_soll_n, set_parent, and) O;
}
N(mk_empty) {
  Α(empty_oor, 0, god, "ε", "empty", 0, 0, 0, 0, 9, os_soll_n, set_parent, and)
  O;
}
N(orelse) {
  R(p_t *, vο);
  Α(dot, vο, mk_orelse, and2) O;
}
N(thenS) {
  R(p_t *, vο);
  Α(dot, vο, mk_thenS, and2) O;
}
N(term) { mk_term(T()); }
N(empty) { mk_empty(T()); }
N(memoize);

N(term_s) { Α("s", term) O; }
N(exam_thenS) { Α(term_s, term_s, thenS) O; }
N(exam_orelse) { Α(empty, term_s, orelse) O; }

N(set_o5) {
  R(Q_t, id);
  R(p_t *, oο);
  oο[5].Q = id;
  A(oο) C(1);
}

N(parse);
N(term_b) { Α("b", term) O; }
N(term_a) { Α("a", term) O; }

N(Sa);
N(Sa_Sa_term_a) { Α(Sa, term_a, thenS, "T", set_o5, and2) O; }
N(Sa) { Α(term_b, Sa_Sa_term_a, orelse, "O", set_o5, and2) O; }

N(sS) { Α(term_s, sS, thenS, sS, thenS, empty, orelse, "sS", set_o5, and2) O; }
N(sSa) { Α(sS, term_a, thenS, "sSa", set_o5, and2) O;}
N(exam) { Α(0, "ssssa", paper, sSa, parse) O; }

N(set_α_zero) { α = 0, C(1); }
N(paper_dump) {
  R(p_t *, paper);
  PP(REZ);
  Α(paper, os_soll_free, os_wordump, and, set_α_zero, and) O;
}

NP(Not) { Α(paper_dump) O; }
NP(And) { C(1); }
NP(Oor) { Α(paper_dump) O; }

N(mk_dumper) { Α(ο, 0, Oor, And, Not, 512, os_new_pith) O; }

N(მთავარი) { Α(exam, mk_dumper, 1, os_queue_n, and2) O; }

N(exam_run) {
  R(n_t, vs);
  R(p_t *, paper);
  ο[5].v = "return???";
  Α(ο, paper, paper_push_next, paper, vs, gor_apply, and3) O;
}
N(parse) {
  R(n_t, r);
  R(n_t, l);
  Α(l, r, and, exam_run, and) O;
}

EN(tail, მთავარი, exports);

N(set_state) {
  R(Q_t, wc);
  R(p_t *, oο);
  while (wc)
    oο[--wc + 7].v = σ[--α].v;
  oο[5].Q = 0;
  Α(oο) C(1);
}
NP(ray_not) { Α(co2, ο[Φ].p, os_queue, ο, os_soll_free, and2) O; }
N(new_pith) {
  R(Q_t, wc);
  R(n_t, oor);
  Α(ο, 0, oor, god, ray_not, 512, os_new_pith, wc, set_state, and2) O;
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

N(term_i) { Α("i", term) O; }
N(term_m) { Α("m", term) O; }
N(term_p) { Α("p", term) O; }
N(term_t) { Α("t", term) O; }
N(term_n) { Α("n", term) O; }
N(term_w) { Α("w", term) O; }
N(pp);
N(np_pp);
N(s);
N(noun) {
  Α(term_i, term_m, orelse, term_p, orelse, term_b, orelse, noun, memoize) O;
}
N(det) { Α(term_a, term_t, orelse, det, memoize) O; }
N(prep) { Α(term_n, term_w, orelse, prep, memoize) O; }
N(verb) { Α(term_s, verb, memoize) O; }
N(det_noun) { Α(det, noun, thenS) O; }
N(np) { Α(noun, det_noun, orelse, np_pp, orelse, np, memoize) O; }
N(vp) { Α(verb, np, thenS, vp, memoize) O; }
N(s_pp) { Α(s, pp, thenS) O; }
N(s) { Α(np, vp, thenS, s_pp, orelse, s, memoize) O; }
N(pp) { Α(prep, np, thenS, pp, memoize) O; }
N(np_pp) { Α(np, pp, thenS) O; }
