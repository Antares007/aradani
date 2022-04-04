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
and5or5,            L)IN(L,
and7,               L)IN(L,
andor,              L)IN(L,
andor2,             L)IN(L,
andor3,             L)IN(L,
andor5,             L)IN(L,
or3,          imports);
// clang-format off
/*  (<+>)       :: R -> R -> R
    p <+> q     = \r -> union (p r) (q r)
    (*>)        :: R -> R -> R
    p *> q      = \r -> unions $ map q $ elems $ p r
    parse       :: R -> PosSet
    parse p     = p 0 */
static NP(init) { C(1); }
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
    print("%s ", paper[Nexts].p[i].cs);                                        \
  if (paper[Line].p[Ǎ].Q) print("\n  l:");                                     \
  for (Q_t i = 0; i < paper[Line].p[Ǎ].Q; i++)                                 \
    print(" %s", paper[Line].p[i].p[4].cs);                                    \
  print("\n");

N(paper_dump) {
  R(p_t*, paper);
  PP(DUMP)
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
  Α(op,
    op[0].Q, op[1].cs, op[2].Q,
    op[3].v, dup_swap_drop,
    op[4].v, dup_swap_drop, and2,
    op[5].v, dup_swap_drop, and2,
    6, os_soll_n, and2) O;
}
N(clear_visited_memo) {
  R(p_t *, paper);
  paper[Memo].p[Ǎ].Q = 0;
  A(paper) C(1);
}
N(paper_inc_position) {
  R(p_t *, paper);
  paper[Position].Q++;
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
  Α(paper_dup, get_rightο, and, onpaper, and,
                get_leftο, and, onpaper, and) O;
}
N(pname){
  R(p_t*, oο);
  print("%s\n", oο[4].cs);
  A(oο) C(1);
}
N(goto_or) {
  R(p_t *, oο);
  R(p_t *, p);
  Α(p, co0, oο, 2, os_queue_n,
    ο, p[Line].p, spush, and3) O;
}
NP(return_and) {
  R(p_t *, p);
  Α(p, co1, p[Line].p, spop, 2, os_queue_n, and2) O;
}
N(return_not) {
  R(p_t *, p);
  Α(p, co2, p[Line].p, spop, 2, os_queue_n, and2) O;
}
N(add_to_visited) {
  R(p_t*, p);
  p_t *v = p[Memo].p;
  if (ο[5].v) v[v[Ǎ].Q++].v = ο[5].v;
  Α(p) C(1);
}
N(is_visited) {
  R(p_t*, p);
  p_t *v = p[Memo].p;
  for (Q_t i = 0; i < v[Ǎ].Q; i++)
    if(v[i].v == ο[5].v)
      return A(p) C(1);
  A(p) C(0);
}
N(increment_left_rec       ) { 
  R(p_t*, p);
  p_t *v = p[Nexts].p;
  if (ο[5].cs) v[v[Ǎ].Q++].cs = ο[5].cs;
  Α(p) C(1);
}
N(clear_left_rec           ) { 
  R(p_t*, p);
  p_t *v = p[Nexts].p;
  v[Ǎ].Q = 0;
  Α(p) C(1);
}
N(is_more_then_tokens_plus1) { 
  R(p_t*, p);
  p_t *v = p[Memo].p;
  Q_t c = 0;
  for (Q_t i = 0; i < v[Ǎ].Q; i++)
    if(v[i].v == ο[5].v)
      c++;
  A(p) C(c > (p[Length].Q - p[Position].Q + 1));
}

N(open_door) { ο[6].Q = 0, C(1); }
N(close_door) { ο[6].Q = 1, C(1); }
N(is_closed) { C(ο[6].Q == 1); }

N(orelse_oor_n) { Α(is_visited,
                     return_and,
                     goto_or, split_line, andor2) O; }
N(orelse_oor  ) { Α(increment_left_rec, is_more_then_tokens_plus1, and, return_and, orelse_oor_n, andor) O; }
N(orelse_and  ) { Α(clear_left_rec, add_to_visited, and, return_and, and) O; }
N(orelse_not  ) { Α(return_not) O; }

N(thenS_oor_n ) { Α(is_visited,
                     return_and,
                     close_door, get_leftο, and, goto_or, and, andor5) O; }
N(thenS_oor   ) { Α(increment_left_rec, is_more_then_tokens_plus1, and, return_and, thenS_oor_n, andor) O; }
N(thenS_and   ) { Α(is_closed,
                     open_door, get_rightο, and, goto_or, and,
                     clear_left_rec, add_to_visited, and, return_and, and, and5or5) O; }
N(thenS_not   ) { Α(return_not) O; }

N(term_oor    ) {
  Α(paper_match_input,
     paper_inc_position, clear_visited_memo, and, return_and, and,
     return_not, and5or) O;
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

NP(parse_n) {
  R(n_t, grammer);
  R(Q_t, pos);
  R(const char*, input);
  Α(pos, input, paper,
              grammer, and,
              goto_or, and) O;
}
NP(p) {
  R(p_t*, oο);
  Α(parse_n, oο, os_queue) O;
}
N(setαzero   ) { α = 0, C(1); }
N(paper_dump2) { Α(paper_dump, setαzero, and) O; }
N(parse) {
  Α(paper_dump2,
    paper_dump2,
    paper_dump2,
    "",
    "",
    "",
    "",
    7,
    os_soll_n, setο, and, p, and) O;
}

EN(tail,
empty,              L)EN(L,
orelse,             L)EN(L,
paper,              L)EN(L,
parse,              L)EN(L,
term,               L)EN(L,
thenS,        exports);
