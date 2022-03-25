#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
dot,                L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
nar,                L)IN(L,
os_new_psn,         L)IN(L,
os_queue,           L)IN(L,
os_soll_a,          L)IN(L,
os_soll_free,       L)IN(L,
os_soll_n,          L)IN(L,
os_unsoll,          L)IN(L,
os_wordump,         L)IN(L,

and,                L)IN(L,
and2,               L)IN(L,
and3,               L)IN(L,
and3or,             L)IN(L,
and4,               L)IN(L,

new_soll_psn, imports);
SargoP(init)(god)

#define BUF ο[7].p[0].cs
#define POS ο[7].p[1].Q
#define LEN ο[7].p[2].Q
#define LHD ο[7].p[3].Q
// The basic idea is to use the continuation-passing style of
// programming (CPS) so that the parser computes multiple results,
// for ambiguous cases, incrementally.
//
// Top-down RECOGNIZERS can be implemented as a set
// of mutually recursive processes which search for
// parses using a top-down expansion of the gram-
// mar rules defining non-terminals while looking for
// matches of terminals with tokens on the input. 
//
// (p ‘orelse‘ q) j = unite (p j) (q j)
// e.g, assuming that the input is "ssss", then
// (empty ‘orelse‘ term_s) 2 => {2, 3} 
//
// (p ‘thenS‘ q) j = union (map q (p j))
// e.g., assuming that the input is "ssss", then
// (term_s ‘thenS‘ term_s) 1 => {3}
//
// sS   =  (term_s ‘thenS‘ sS ‘thenS‘ sS) ‘orelse‘ empty
// sS 1 => {1, 2, 3, 4, 5}
// example grammer: 
// s    = np ‘thenS‘ vp
// np   = noun ‘orelse‘ (det ‘thenS‘ noun)
// vp   = verb ‘thenS‘ np
// det  = term ’a’ ‘orelse‘ term ’t’
// noun = term ’i’ ‘orelse‘ term ’m’
//                 ‘orelse‘ term ’p’
//                 ‘orelse‘ term ’b’
// verb = term ’s’
N3(term_god)(buf,  const char*,
                pos,  Q_t,
                len,  Q_t)(
  if (pos == len) return C(2);
  if (ο[7].Q == (Q_t)buf[pos])  Α(pos, buf, pos+1, len) C(1);
  else                          Α(pos, buf, pos+0, len) C(0);
)
N2(term_set  )(rο,  p_t*, c,   Q_t)(
  rο[7].Q = c, A(rο) C(1);
)
Narg2(mk_term)(rο,  p_t*, c,   Q_t)(
  got, term_god, gor, rο, 512, "term", os_new_psn, c, term_set, and2
)
Narg1(term   )(c,   Q_t)(
  c, mk_term, 2, os_soll_n
)
Narg1(recog_unsoll_dot)(rsοll,  p_t*)(
  rsοll, os_unsoll, 
  rsοll, os_soll_free, and2,
         dot,          and
)
Narg2(theand_n  )(lsοll, p_t*,  rsοll, p_t*)(
  rsοll, recog_unsoll_dot,
  lsοll, recog_unsoll_dot, and2,
             5, os_soll_n, and2
)
Nargo(theand    )(
  and, theand_n, and
)
Nargo(orelse    )(god)
Nargo(empty     )(god)
Nargo(term_s    )('s', term)

Nargo(sS        )(
  term_s, sS, theand, sS, theand,
  empty, orelse
)
Nargo(exam_apply)(
  "sssss", 0, 5, god, ο, sS, recog_unsoll_dot, and,
                                 os_queue, and
)
// S := S a | a
// Nargo(term_a)('a', term)
// Nargo(Sa    )(Sa, term_a, theand, term_a, orelse)

Sarg2(parser)(inp, const char*,
              len, Q_t)(
  got,             1, os_soll_n,
  god,             1, os_soll_a,
  gor,             1, os_soll_a,
  inp, 0, len, -1, 4, os_soll_a,
  ο, 512, "p", new_soll_psn, and4
)
So(lookahead)(
  if (POS < LEN) LHD = BUF[POS], A(LHD) C(1);
  else C(2);
)
So(shift    )(
  Q_t lookahead = LHD;
  if (lookahead == -1) C(2);
  else LHD = -1, POS++, A(lookahead) C(1);
)

Sargo(example)(
  lookahead,
  lookahead, and,
  shift,     and,
  lookahead, and,
  shift,     and,
  lookahead, and,
  shift,     and)

SargoP(მთავარი)(example, 2, god, 1, god, 0, god, 0222, nar, "sa", 3, parser, os_queue, and)

EN(tail,
lookahead,          L)EN(L,
parser,             L)EN(L,
shift,              L)EN(L,
მთავარი,      exports);
