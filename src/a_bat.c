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
and4or,             L)IN(L,
and5or,             L)IN(L,
andor,              L)IN(L,
or,           imports);

N(init         ) { C(1); }
N(spop         ) { R(p_t *, sο); if (sο[Ǎ].Q) A(sο[--sο[Ǎ].Q].v) C(1); else C(2); }
N(spush        ) { R(p_t *, sο); R(void *, v); if ((sο[Ǎ].Q + 1) < sο[Σ].Q) sο[sο[Ǎ].Q++].v = v, C(1); else C(2); }
N(setο         ) { R(p_t *, oο); oο[Φ].p = ο; Α(oο) C(1); }
N(soll_n       ) { Α(os_soll_n, setο, and) O; }


N(orelse3 ) { Α(2, ο[0].c) O; } N(orelse2 ) { Α(2, ο[0].c) O; } N(orelse  ) { Α(1, ο[0].c) O; }
N(thenS3  ) { Α(3, ο[1].c) O; } N(thenS2  ) { Α(2, ο[1].c) O; } N(thenS   ) { Α(1, ο[1].c) O; }
N(empty   ) { Α(ο[2].c) O; } N(term    ) { Α(ο[3].c) O; } N(var2    ) { Α(ο[4].c) O; }
N(var     ) { Α(god, ο[4].c) O; }

N(r) { C(1); }
N(Š) {
  Α(Š, "a", term, thenS2,
       "b", term, orelse2, r, "Š", var2) O; }
/*            Š→Ša|b
         Š            a ← T
        / \               ↑
       Š   a          b ← O
      / \                 ↑
     Š   a            a ← T
    /                     ↑
   b                  b ← O
                      
   */
N(r1) { C(1); }
N(r2) { C(1); }
N(r3) { C(1); }

N(sTs) { Α(    "s", term,
                "s", term, thenS2,
            r3, "sTs", var2) O; }
N(sOs) { Α(     empty,
                "s", term, orelse2,
            r3, "sOs", var2) O; }

NP(sS) { Α("s", term, sS, thenS, 
                             empty, orelse, r3, "sS", var2) O; }
typedef struct lp_t {
  p_t ostv[5]; const char* input; Q_t len; Q_t pos; char* name; Q_t lc; p_t* nextsolls;
} lp_t;

#define TS(T) T*o=(T*)ο;(void)o

N(variable_soll );
N(rleft         ) { C(1); }
N(rright        ) { C(1); }
N(isnot_variable) { R(n_t, nar); A(nar) C(nar != var2 && nar != var); }

N(orelse_ray_nn ) { TS(lp_t); Α(o->input, o->pos, variable_soll, os_queue, and) O; }
NP(orelse_ray_n ) { Α(isnot_variable,
                      rleft, "left", var2, god,
                      god, and4or, orelse_ray_nn, and) O; }
N(chain_var_soll) { TS(lp_t); Α(o->input, o->pos, variable_soll) O; }
N(orelse_ray_l  ) { R(Q_t, wc); Α(chain_var_soll, wc + 3, os_queue_n, and2, orelse_ray_n, and) O; }
NP(orelse_ray   ) { R(Q_t, wc);
  Α(isnot_variable,
     rright, "right", var2, god,
     god, and4or, wc, orelse_ray_l, and2) O;
}
NP(print_state     ) { TS(lp_t); print("%s pos:%lu nsc:%lu lc:%lu\n", o->input, o->pos, o->nextsolls[Ǎ].Q, o->lc); C(1); }
N(can_match_input  ) { TS(lp_t); R(char*, s); C(o->pos < o->len && o->input[o->pos] == s[0]); }
N(move_ahead       ) { TS(lp_t); o->pos++, C(1); }
NP(thenS_ray       ) { TS(lp_t); Α(soll_n, o->nextsolls, spush, and2, dot, and) O; }
N(reduce_next_soll ) { TS(lp_t); Α(o->nextsolls, spop, os_unsoll_free, and, dot, and) O; }
NP(term_ray        ) { TS(lp_t); Α(can_match_input, move_ahead, and, reduce_next_soll, and, print_state, or) O; }
NP(var_ray         ) { TS(lp_t);
  R(char *, name);
  R(n_t, r);
  if (o->name == 0) {
    o->name = name,
    print("AAA %s\n", o->name), Α(r, print_state, and, 3, soll_n, o->nextsolls, spush, and2, dot, and) O;
  } else if (cmp(o->name, name) == 0) {
    print("BBB %s\n", o->name), o->lc++;
  } else {
    print("CCC %s\n", o->name), O;
  }
}
Q_t cslen(const char *cs);
N(variable_soll ) {
  R(Q_t, pos);
  R(const char*, input);
  char* name = 0;
  Q_t left_rec_count = 0;
  Α(orelse_ray, thenS_ray, reduce_next_soll, term_ray, var_ray,
    input, cslen(input), pos, name, left_rec_count,
    0, os_soll_n, // next_solls
    11, os_soll_n, and2) O;
}
N(example      ) {
  Α(sS,
     //os_unsoll_free, and, os_wordump, and,
     "ss", 0, variable_soll, os_queue, and) O;
}

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
//Var(noun)('i', o->ο, 'm', o->ο, 'p', o->ο, 'b')
//Var(verb)('s')
//Var(prep)('n', o->ο, 'w')
