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
and7,               L)IN(L,
or3,                L)IN(L,

new_soll_ps,  imports);

SoP(init)( C(1); )
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
N(spith);

N(thenS);
Narg3P(thenS_oor )(buf,   void*,
                   len,   Q_t,
                   pos,   Q_t)(
  ο[8].p, buf, len, pos, gor, ο[7].p, os_queue)
Nargo(mk_thenS   )(thenS_oor, 2, spith)
Nargo(thenS      )(and, mk_thenS, and)

N(orelse);
NargoP(orelse_oor)(
  gor, ο[7].p, os_queue,
  gor, ο[8].p, os_queue, and3
)
Nargo(mk_orelse  )(orelse_oor, 2, spith)
Nargo(orelse     )(and, mk_orelse, and)

N(term);
N4P(term_oor)(cο,   p_t*,
              buf,  const char*,
              len,  Q_t,
              pos,  Q_t)(
  if (pos >= len) C(2);
  else if (ο[7].Q == (Q_t)buf[pos]) Α(buf, len, pos + 1, gor, cο, os_queue) O;
  else C(2);
)
NargoP(term)(term_oor, 1, spith)

N(empty);
Narg4P(empty_oor )(cο,    p_t*,
                   buf,   void*,
                   len,   Q_t,
                   pos,   Q_t)(
  buf, len, pos, gor, cο, os_queue
)
Nargo(empty    )(0, empty_oor, spith)

NargoP(term_s    )('s', term)
NargoP(term_a    )('a', term)
  //  j
  //  act
  //    act
  //    q os_queue and3
  //  p os_queue
  //
  //  (p ‘thenS‘ q) j = union (map q (p j))
  //  e.g., assuming that the input is "ssss", then
  //  (term_s ‘thenS‘ term_s) 1 => {3}
  //
  //  (p ‘orelse‘ q) j = unite (p j) (q j)
  //  e.g, assuming that the input is "ssss", then
  //  (empty ‘orelse‘ term_s) 2 => {2, 3} 
  //
  //  sS   =  (term_s ‘thenS‘ sS ‘thenS‘ sS) ‘orelse‘ empty
  //  sS 1 => {1, 2, 3, 4, 5}
// TODO: can be implemented as pith ray
Nargo(Ο)(ο, god)
NargoP(sS_oor)(
  term_s, Ο, thenS, Ο, thenS,
  empty, orelse
)
NargoP(sS)(ο, 0, sS_oor, god, got, 512, os_new_pith)
Nargo(s)(god)
/*
s     ::= np vp | s pp
np    ::= noun | det noun | np pp
pp    ::= prep np
vp    ::= verb np
det   ::= ’a’ | ’t’
noun  ::= ’i’ | ’m’ | ’p’ | ’b’
verb  ::= ’s’
prep  ::= ’n’ | ’w’

The Haskell code below defines a parser for the
above grammar, using our combinators:
s     = memoize "s" ((np ‘thenS‘ vp) ‘orelse‘ (s ‘thenS‘ pp))
np    = memoize "np" (noun ‘orelse‘ (det ‘thenS‘ noun) ‘orelse‘ (np ‘thenS‘ pp))
pp    = memoize "pp" (prep ‘thenS‘ np)
vp    = memoize "vp" (verb ‘thenS‘ np)
det   = memoize "det" (term ’a’ ‘orelse‘ term ’t’)
noun  = memoize "noun" (term ’i’
               ‘orelse‘ term ’m’
               ‘orelse‘ term ’p’
               ‘orelse‘ term ’b’)
verb  = memoize "verb" (term ’s’)
prep  = memoize "prep" (term ’n’ ‘orelse‘ term ’w’)
*/
NargoP(mk_empty1 )(ο[Φ].p, 0, pgod, pgod, pgot, 512, os_new_pith)
NargoP(mk_empty2 )(ο[Φ].p, 0, pgod, pgod, pgot, 512, os_new_pith)
NargoP(mk_empty3 )(ο[Φ].p, 0, pgod, pgod, pgot, 512, os_new_pith)
NargoP(act1)(god)
NargoP(act2)(god)
NargoP(act3)(god)
NargoP(queue)(os_queue)
Narg3P(exam_n    )(p, p_t*,
                   q, p_t*,
                   b, p_t*)(
  "abc", 1, 0, act1,
                 act2,
                   act3,
                   b, queue, and3,
                 q, queue, and7,
               p, queue
)
NargoP(exam      )(
  debugger,
  term_a, and,
  term_a, and,
  term_a, and,
  term_a, and,
  //mk_empty1,
  //mk_empty2, and,
  //mk_empty3, and,
  //exam_n,    and
)

NargoP(exam0)("sssss", 5, 0, sS)

// S := S a | a
//Nargo(term_b)(god)
//Nargo(term_c)(god)
//Nargo(Sa    )(
//  term_b, 
//  Sa, term_a
//)
NargoP(Not)(os_wordump)
NargoP(And)(os_wordump)
NargoP(Oor)(os_wordump)
NargoP(mk_dumper )(ο, 0, 
                   Oor,
                   And,
                   Not,
                   512, os_new_pith)

NargoP(მთავარი)(exam, mk_dumper, os_queue, and)

Sarg2(parser)(inp, const char*,
              len, Q_t)(
  got,             1, os_soll_n,
  god,             1, os_soll_a,
  gor,             1, os_soll_a,
  inp, 0, len, -1, 4, os_soll_a,
  ο, 512, new_soll_ps, and4
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
empty,              L)EN(L,
lookahead,          L)EN(L,
mk_dumper,          L)EN(L,
parser,             L)EN(L,
parser,             L)EN(L,
sS,                 L)EN(L,
shift,              L)EN(L,
term,               L)EN(L,
term_a,             L)EN(L,
term_oor,           L)EN(L,
term_s,             L)EN(L,
მთავარი,      exports);

N2(set_state)(oο,   p_t*,
              wc,   Q_t)({
  while(wc)
    oο[--wc + 7].v = σ[--α].v;
  Α(oο) C(1);
})
Narg2(spith )(oor,  n_t,
              wc,   Q_t)(ο, 0, oor, god, got, 512, os_new_pith, wc, set_state, and2)
