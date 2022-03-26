#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
debugger,           L)IN(L,
dot,                L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
nar,                L)IN(L,
os_new_pith,        L)IN(L,
os_queue,           L)IN(L,
os_soll_a,          L)IN(L,
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

new_soll_psn, imports);
SargoP(init)(god)
// The basic idea is to use the continuation-passing style of
// programming (CPS) so that the parser computes multiple results,
// for ambiguous cases, incrementally.
//
// Top-down RECOGNIZERS can be implemented as a set
// of mutually recursive processes which search for
// parses using a top-down expansion of the gram-
// mar rules defining non-terminals while looking for
// matches of terminals with tokens on the input. 


NargoP(pgot)(got)
NargoP(pgod)(god)
NargoP(pgor)(gor)

N3P(term_god)(buf,    const char*,
             len,    Q_t,
             pos,    Q_t)(
  if (pos == len) C(2);
  else Α(buf, len, pos + (ο[7].Q == (Q_t)buf[pos])) C(ο[7].Q == (Q_t)buf[pos]);
)
Nargo(mk_term   )(1, "Ť", pgor, term_god,  pgot, 512, os_new_pith)
Nargo(term      )(mk_term)

NargoP(thenS_god )(ο, ο[7].p, os_unsoll_apply)
Nargo(mk_thenS  )(1, "Š", gor, thenS_god, got, 512, os_new_pith)
Narg2(thenS_n   )(lsοll, p_t*,  rsοll, p_t*)(
  rsοll, mk_thenS, 
  lsοll, os_unsoll_apply, and2,
            5, os_soll_n, and2
)
Nargo(thenS     )(and, thenS_n, and)
// (p ‘thenS‘ q) j = union (map q (p j))
// e.g., assuming that the input is "ssss", then
// (term_s ‘thenS‘ term_s) 1 => {3}
Narg1P(apply)(sοll, n_t)(god, ο, sοll, os_queue, and)
Q_t i=0;
NoP(orelse_god)(
  Α(ο[7].p, apply) O;
)
NargoP(orelse  )(2, "Ǒ", pgor, orelse_god, pgot, 512, os_new_pith)

// (p ‘orelse‘ q) j = unite (p j) (q j)
// e.g, assuming that the input is "ssss", then
// (empty ‘orelse‘ term_s) 2 => {2, 3} 

NargoP(term_s     )('s', term)
NargoP(term_a     )('a', term)
// sS   =  (term_s ‘thenS‘ sS ‘thenS‘ sS) ‘orelse‘ empty
// sS 1 => {1, 2, 3, 4, 5}
NargoP(mk_empty  )(0, "ε", pgor, pgod, pgot, 512, os_new_pith)
Nargo(empty      )(mk_empty)
NargoP(sS        )(
    empty,
    term_s, orelse,
    term_a, orelse)

NargoP(mk_empty1)(0, "ε1", pgor, pgod, pgot, 512, os_new_pith)
NargoP(mk_empty2)(0, "ε2", pgor, pgod, pgot, 512, os_new_pith)
NargoP(mk_empty3)(0, "ε3", pgor, pgod, pgot, 512, os_new_pith)
NargoP(exam)(god, ο, mk_empty1, mk_empty2, and, mk_empty3, and, os_queue, and)

NargoP(exam0)("sssss", 5, 0, sS, apply)

// S := S a | a
//Nargo(term_a)('a', term)
//Nargo(term_b)('b', term)
//Nargo(term_c)('c', term)
//Nargo(Sa    )(
//  term_b, 
//  Sa, term_a, thenS, orelse3,
//  Sa, term_c, thenS, orelse3,
//  Sa, term_s, thenS, orelse3
//)
NargoP(Not)(os_wordump)
NargoP(And)(os_wordump)
NargoP(Oor)(os_wordump)
NargoP(mk_dumper )(ο, 0, "D",
                   Oor,
                   And,
                   Not,
                   512, os_new_pith)
Nargo(მთავარი)(exam, mk_dumper, os_queue, and)

Sarg2(parser)(inp, const char*,
              len, Q_t)(
  got,             1, os_soll_n,
  god,             1, os_soll_a,
  gor,             1, os_soll_a,
  inp, 0, len, -1, 4, os_soll_a,
  ο, 512, "p", new_soll_psn, and4
)

#define BUF ο[7].p[0].cs
#define POS ο[7].p[1].Q
#define LEN ο[7].p[2].Q
#define LHD ο[7].p[3].Q
So(lookahead)(
  if (POS < LEN) LHD = BUF[POS], A(LHD) C(1);
  else C(2);
)
So(shift    )(
  Q_t lookahead = LHD;
  if (lookahead == -1) C(2);
  else LHD = -1, POS++, A(lookahead) C(1);
)

Nargo(example)(
  lookahead,
  lookahead, and,
  shift,     and,
  lookahead, and,
  shift,     and,
  lookahead, and,
  shift,     and)

//SargoP(მთავარი)(example, 2, god, 1, god, 0, god, 0222, nar, "sa", 3, parser, os_queue, and)

EN(tail,
apply,              L)EN(L,
empty,              L)EN(L,
lookahead,          L)EN(L,
mk_dumper,          L)EN(L,
mk_empty,           L)EN(L,
mk_term,            L)EN(L,
parser,             L)EN(L,
sS,                 L)EN(L,
shift,              L)EN(L,
term,               L)EN(L,
term_god,           L)EN(L,
term_s,             L)EN(L,
მთავარი,      exports);