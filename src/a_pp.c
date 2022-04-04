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
os_new_pith,        L)IN(L,
os_queue_n,         L)IN(L,
os_soll_free,       L)IN(L,
os_wordump,         L)IN(L,

and,                L)IN(L,
and2,               L)IN(L,

empty,              L)IN(L,
orelse,             L)IN(L,
paper,              L)IN(L,
parse,              L)IN(L,
term,               L)IN(L,
thenS,        imports);
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

N(term_s) { Α("s", term) O; }
NP(exam_thenS) { Α(term_s, term_s, thenS) O; }
N(exam_orelse) { Α(empty, term_s, orelse) O; }
N(set_o5) {
  R(Q_t, id);
  R(p_t *, oο);
  oο[5].Q = id;
  A(oο) C(1);
}
N(term_b) { Α("b", term) O; }
N(term_a) { Α("a", term) O; }

N(Sa);
N(Sa_Sa_term_a) { Α(Sa, term_a, thenS, "T", set_o5, and2) O; }
N(Sa) { Α(term_b, Sa_Sa_term_a, orelse, "O", set_o5, and2) O; }

N(sS) { Α(term_s, sS, thenS, sS, thenS, empty, orelse, "sS", set_o5, and2) O; }

// N(sSa) { Α(sS, term_a, thenS, "sSa", set_o5, and2) O; }

N(exam) { Α("sssss", 0, sS, parse) O; }

N(მთავარი) { Α(exam) O; }


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
  Α(term_i, term_m, orelse, term_p, orelse, term_b, orelse) O;
}
N(det) { Α(term_a, term_t, orelse) O; }
N(prep) { Α(term_n, term_w, orelse) O; }
N(verb) { Α(term_s) O; }
N(det_noun) { Α(det, noun, thenS) O; }
N(np) { Α(noun, det_noun, orelse, np_pp, orelse) O; }
N(vp) { Α(verb, np, thenS) O; }
N(s_pp) { Α(s, pp, thenS) O; }
N(s) { Α(np, vp, thenS, s_pp, orelse) O; }
N(pp) { Α(prep, np, thenS) O; }
N(np_pp) { Α(np, pp, thenS) O; }

// clang-format off
EN(tail,
მთავარი,      exports);
