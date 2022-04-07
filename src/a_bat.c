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
N(orelse_n) { Α(ο[0].c) O; }
N(thenS_n ) { Α(ο[1].c) O; }
N(empty_n ) { Α(ο[2].c) O; }
N(term_n  ) { Α(ο[3].c) O; }
N(var_n   ) { Α(ο[4].c) O; }
N(orelse3 ) { Α(3, ο[0].c) O; }
N(orelse2 ) { Α(2, ο[0].c) O; }
N(orelse  ) { Α(1, ο[0].c) O; }
N(thenS3  ) { Α(3, ο[1].c) O; }
N(thenS2  ) { Α(2, ο[1].c) O; }
N(thenS   ) { Α(1, ο[1].c) O; }
N(empty3  ) { Α(3, ο[2].c) O; }
N(empty2  ) { Α(2, ο[2].c) O; }
N(empty1  ) { Α(1, ο[2].c) O; }
N(empty   ) { Α(0, ο[2].c) O; }
N(term3   ) { Α(3, ο[3].c) O; }
N(term2   ) { Α(2, ο[3].c) O; }
N(term    ) { Α(1, ο[3].c) O; }
N(var3    ) { Α(3, ο[4].c) O; }
N(var2    ) { Α(2, ο[4].c) O; }
N(var     ) { Α(1, ο[4].c) O; }

N(init         ) { C(1); }
N(spop         ) { R(p_t *, sο);
  if (sο[Ǎ].Q) A(sο[--sο[Ǎ].Q].v) C(1); else C(2); }
N(spush        ) { R(p_t *, sο); R(void *, v);
  if ((sο[Ǎ].Q + 1) < sο[Σ].Q) sο[sο[Ǎ].Q++].v = v, C(1); else C(2); }
N(setο         ) { R(p_t *, oο); oο[Φ].p = ο; Α(oο) C(1); }
N(drop         ) { α -= 1, C(1); }
N(drop2        ) { α -= 2, C(1); }
N(drop3        ) { α -= 3, C(1); }
N(swap         ) { R(void *, b); R(void *, a); Α(b, a) C(1); }
N(dup_swap_drop) { Α(os_soll_dup, swap, and, drop, and) O; }
N(soll         ) { Α(os_soll, setο, and) O; }
N(soll_n       ) { Α(os_soll_n, setο, and) O; }


N(Š) { Α(Š, "a", term, thenS2, "b", term, orelse2, 0, Š, var2) O; }
/*            Š→Ša|b
         Š            a ← T
        / \               ↑
       Š   a          b ← O
      / \                 ↑
     Š   a            a ← T
    /                     ↑
   b                  b ← O
                      
   */

NP(r1) { C(1); }
NP(r2) { C(1); }
NP(r3) { C(1); }
NP(sTs) { Α(r1,   "s", term2,
            r2,   "s", term2, thenS3,
            r3, "sTs", var2) O; }
N(sOs) { Α(    empty,
           "s", term, thenS2,
               "sOs", var) O; }

typedef struct lp_t {
  p_t ostv[5];
  const char* input;
  Q_t         len;
  Q_t         pos;
  char*       name;
  Q_t         lc;
  p_t*        nextsolls;
} lp_t;
#define TS(T) T*o=(T*)ο;
NP(orelse_ray   ) {
  R(Q_t, wc);
  α -= wc, O;
}
NP(thenS_ray   ) { TS(lp_t);
  Α(soll_n, o->nextsolls, spush, and2, dot, and) O;
}
NP(empty_ray   ) { TS(lp_t);
  R(Q_t, wc);
  α -= wc;
  Α(o->nextsolls, spop, os_unsoll_free, and, dot, and) O;
}
NP(reduce_next ) { TS(lp_t); Α(o->nextsolls, spop, os_unsoll_free, and, dot, and) O; }
NP(term_ray    ) { TS(lp_t);
  R(Q_t, wc);
  R(const char*, str);
  R(n_t, r);
  print("%s\n", str);
  if (o->input[o->pos] == str[0]) 
    Α(r, reduce_next, and) O;
  else 
    ;
}
NP(hi         ) {  C(1); }
NP(var_ray    ) { TS(lp_t);
  R(Q_t, wc);
  R(char *, name);
  R(n_t, r);(void)wc;
  print("->%s\n", name);
  if (o->name == 0) {
    o->name = name, Α(r, 1, soll_n, o->nextsolls, spush, and2, dot, and) O;
  } else if (cmp(o->name, name) == 0) {
    o->lc++;
  } else O;
}
NP(varsoll     ) {
  Α(orelse_ray, thenS_ray, empty_ray, term_ray, var_ray,
    "sssss", 5, 0, 0, 0,
     0, os_soll_n,
    11, os_soll_n, and2) O;
}
NP(example    ) {
  Α(sTs,
     //os_unsoll_free, and, os_wordump, and,
     varsoll, os_queue, and) O;
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
