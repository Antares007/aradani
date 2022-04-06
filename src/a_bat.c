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
os_queue,           L)IN(L,
os_queue_n,         L)IN(L,
os_soll,            L)IN(L,
os_soll_dup,        L)IN(L,
os_soll_free,       L)IN(L,
os_soll_n,          L)IN(L,
os_unsoll,          L)IN(L,
os_unsoll_free,     L)IN(L,
os_wordump,         L)IN(L,

and,                L)IN(L,
and2,               L)IN(L,
and2or,             L)IN(L,
and3,               L)IN(L,
and3or,             L)IN(L,
and4,               L)IN(L,
andor,        imports);
N(init         ) { C(1); }
N(spop         ) { R(p_t *, sο); if (sο[Ǎ].Q) A(sο[--sο[Ǎ].Q].v) C(1); else C(2); }
N(spush        ) { R(p_t *, sο); R(void *, v); if ((sο[Ǎ].Q + 1) < sο[Σ].Q) sο[sο[Ǎ].Q++].v = v, C(1); else C(2); }
N(setο         ) { R(p_t *, oο); oο[Φ].p = ο; Α(oο) C(1); } N(drop         ) { α -= 1, C(1); } N(drop2        ) { α -= 2, C(1); } N(drop3        ) { α -= 3, C(1); }
N(swap         ) { R(void *, b); R(void *, a); Α(b, a) C(1); }
N(dup_swap_drop) { Α(os_soll_dup, swap, and, drop, and) O; } N(soll         ) { Α(os_soll, setο, and) O; } N(soll_n       ) { Α(os_soll_n, setο, and) O; }

typedef struct lp_t { p_t ostv[4]; const char*input; Q_t len, pos, lc; } lp_t;
N(orelse_n) { ο[0].c(T()); }
N(thenS_n ) { ο[1].c(T()); }
N(empty_n ) { ο[2].c(T()); }
N(term_n  ) { ο[3].c(T()); }
N(var_n   ) { ο[4].c(T()); }

N(orelse3 ) { A(3) ο[0].c(T()); }
N(orelse2 ) { A(2) ο[0].c(T()); }
N(orelse  ) { A(1) ο[0].c(T()); }
N(thenS3  ) { A(3) ο[1].c(T()); }
N(thenS2  ) { A(2) ο[1].c(T()); }
N(thenS   ) { A(1) ο[1].c(T()); }
N(empty3  ) { A(3) ο[2].c(T()); }
N(empty2  ) { A(2) ο[2].c(T()); }
N(empty1  ) { A(1) ο[2].c(T()); }
N(empty   ) { A(0) ο[2].c(T()); }
N(term3   ) { A(3) ο[3].c(T()); }
N(term2   ) { A(2) ο[3].c(T()); }
N(term    ) { A(1) ο[3].c(T()); }
N(var3    ) { A(3) ο[4].c(T()); }
N(var2    ) { A(2) ο[4].c(T()); }
N(var     ) { A(1) ο[4].c(T()); }

N(Š) { Α(Š, "a", term, thenS, "b", term, orelse, Š, var) O; }
/*            Š→Ša|b
         Š            a ← T
        / \               ↑
       Š   a          b ← O
      / \                 ↑
     Š   a            a ← T
    /                     ↑
   b                  b ← O */
NP(sTs) { Α("s", term, "s", term, thenS2) O; }
N(sOs) { Α(    empty, "s", term, thenS2) O; }

Q_t i = 0;
NP(orelse_ray) { R(Q_t, wc); α -= wc, O; }
NP(thenS_ray ) { R(Q_t, wc); α -= wc, O; }
NP(empty_ray ) { R(Q_t, wc); α -= wc, O; }
NP(term_ray  ) { R(Q_t, wc); α -= wc, O; }
NP(var_ray   ) { R(Q_t, wc); α -= wc, O; }
NP(example   ) {
  Α(sTs,
    orelse_ray, thenS_ray, empty_ray, term_ray, var_ray,
    "sssss", 5, 0, 0, 9, os_soll_n,
    1, os_queue_n, and2) O;
}







Q_t cslen(const char *cs);
N(მთავარი     ) { Α(example) O; }

// clang-format off
EN(tail,
მთავარი,      exports);

Q_t cslen(const char *cs) { Q_t len = 0; while (cs[len]) len++; return len; }
//N(np);N(pp);N(vp);N(det);N(verb);N(prep);N(noun);
//Var(s   )(np, vp, s, pp);
//Var(np  )(noun, det, noun, np, pp)
//Var(pp  )(prep, np)
//Var(vp  )(verb, np)
//Var(det )('a', o->ο, 't')
//Var(noun)('i', o->ο,
//          'm', o->ο,
//          'p', o->ο,
//          'b')
//Var(verb)('s')
//Var(prep)('n', o->ο,
//          'w')
