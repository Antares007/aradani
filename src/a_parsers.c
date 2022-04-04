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
and5or,             L)IN(L,
and5or3,            L)IN(L,
and7,               L)IN(L,
andor,              L)IN(L,
andor3,             L)IN(L,
or3,          imports);
// clang-format off
/*  (<+>)       :: R -> R -> R
    p <+> q     = \r -> union (p r) (q r)
    (*>)        :: R -> R -> R
    p *> q      = \r -> unions $ map q $ elems $ p r
    parse       :: R -> PosSet
    parse p     = p 0 */
static NP(init) { C(1); }
N(new_pith);
N(spop) {
  R(p_t *, sο);
  if (sο[Ǎ].Q)
    A(sο[--sο[Ǎ].Q].v) C(1);
  else
    C(2);
}
N(spush) {
  R(p_t *, sο);
  R(void *, v);
  if ((sο[Ǎ].Q + 1) < sο[Σ].Q)
    sο[sο[Ǎ].Q++].v = v, C(1);
  else
    C(2);
}
N(sfind) {
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
  print("\n%2lx %s %lu d:%lu %s", ((Q_t)paper >> 12) & 0xFF, ο[5].cs,          \
        paper[Position].Q, paper[Nexts].p[Ǎ].Q, #Name);                        \
  if (paper[Memo].p[Ǎ].Q) print("\n  m:");                                     \
  for (Q_t i = 0; i < paper[Memo].p[Ǎ].Q; i++)                                 \
    print("%s ", paper[Memo].p[i].cs);                                         \
  if (paper[Nexts].p[Ǎ].Q) print("\n  n:");                                    \
  for (Q_t i = 0; i < paper[Nexts].p[Ǎ].Q; i++)                                \
    print("%s ", paper[Nexts].p[i].p[5].cs);                                   \
  if (paper[Line].p[Ǎ].Q) print("\n  l:");                                     \
  for (Q_t i = 0; i < paper[Line].p[Ǎ].Q; i++)                                 \
    print(" %s", paper[Line].p[i].p[4].cs);                                    \
  print("\n");

N(paper_dump) {
  R(p_t*, paper);
  PP(PPPPPPPPPPPPP)
  A(paper) C(1);
}
N(paper) {
  R(const char *, buffer);
  R(Q_t, position);
  Α(position, buffer, cslen(buffer), 0, os_soll_n, 0, os_soll_n, and2, 0,
    os_soll_n, and2, 6, os_soll_n, and2)
  O;
}
N(paper_dup) {
  R(p_t *, op);
  Α(op, op[0].Q, op[1].cs, op[2].Q, op[3].v, dup_swap_drop, op[4].v,
    dup_swap_drop, and2, op[5].v, dup_swap_drop, and2, 6, os_soll_n, and2)
  O;
}
N(paper_push_next) {
  R(p_t *, paper);
  R(p_t *, next);
  Α(next, paper[Nexts].p, spush) O;
}
N(gor_apply) {
  R(p_t *, oο);
  Α(co0, oο, os_queue) O;
}
N(paper_inc_position) {
  R(p_t *, paper);
  paper[Position].Q++;
  paper[Memo].p[Ǎ].Q = 0;
  A(paper) C(1);
}
N(paper_match_input) {
  R(p_t *, paper);
  Q_t pos = paper[Position].Q;
  Q_t len = paper[Length].Q;
  const char *buf = paper[Buffer].cs;
  A(paper) C(pos < len && (Q_t)ο[7].cs[0] == buf[pos]);
}
N(get_rightο) { A(ο[8].c) O; }
N(get_leftο) { A(ο[7].c) C(1); }

N(split_line) {
  R(n_t, onpaper);
  Α(os_soll_dup, get_rightο, and, onpaper, and, get_leftο, and, onpaper, and) O;
}
N(pname){
  R(p_t*, oο);
  print("%s\n", oο[4].cs);
  A(oο) C(1);
}
NP(goto_or) {
  R(p_t *, oο);
  R(p_t *, p);
  Α(p, co0, oο, pname, 2, os_queue_n, and2,
    ο, p[Line].p, spush, and3) O;
}
NP(return_and) {
  R(p_t *, p);
  Α(p, co1, p[Line].p, spop, pname, and, 2, os_queue_n, and2) O;
}
NP(return_not) {
  R(p_t *, p);
  Α(p, co2, p[Line].p, spop, pname, and, 2, os_queue_n, and2) O;
}

N(open_door) { ο[6].Q = 0, C(1); }
N(close_door) { ο[6].Q = 1, C(1); }
N(is_closed) { C(ο[6].Q == 1); }

N(orelse_oor_n){ Α(goto_or) O; }
N(orelse_oor) { Α(orelse_oor_n, split_line) O; }
N(orelse_and) { Α(return_and) O; }
N(orelse_not) { Α(return_not) O; }

N(thenS_oor) { Α(close_door, get_leftο, and, goto_or, and) O; }
N(thenS_and) {
  Α(paper_dump, is_closed, and,
    open_door, get_rightο, and, goto_or, and,
    return_and, and5or) O;
}
N(thenS_not) { Α(return_not) O; }

N(term_oor) {
  Α(paper_match_input,
     paper_inc_position, return_and, and,
     return_not, and3or) O;
}
N(empty_oor) { Α(return_and) O; }

N(setο) {
  R(p_t *, oο);
  oο[Φ].p = ο;
  Α(oο) C(1);
}
N(mk_orelse) {
  R(p_t *, r);
  R(p_t *, l);
  Α(orelse_oor, orelse_and, orelse_not, 0, "orelse", 0, 0, l, r, 9, os_soll_n,
    setο, and)
  O;
}
N(mk_thenS) {
  R(p_t *, r);
  R(p_t *, l);
  Α(thenS_oor, thenS_and, thenS_not, 0, "thenS", 0, 0, l, r, 9, os_soll_n, setο,
    and)
  O;
}
N(mk_term) {
  R(p_t *, l);
  Α(term_oor, 0, 0, l, "term", 0, 0, l, 0, 9, os_soll_n, setο, and) O;
}
N(mk_empty) {
  Α(empty_oor, 0, 0, "ε", "empty", 0, 0, 0, 0, 9, os_soll_n, setο, and) O;
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

N(set_state) {
  R(Q_t, wc);
  R(p_t *, oο);
  while (wc)
    oο[--wc + 7].v = σ[--α].v;
  oο[5].Q = 0;
  Α(oο) C(1);
}
N(ray_not) { Α(co2, ο[Φ].p, os_queue, ο, os_soll_free, and2) O; }
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
EN(tail,
empty,              L)EN(L,
orelse,             L)EN(L,
paper,              L)EN(L,
parse,              L)EN(L,
term,               L)EN(L,
thenS,        exports);

