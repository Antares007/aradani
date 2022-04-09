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
and2or2,            L)IN(L,
and2or4,            L)IN(L,
and2or5,            L)IN(L,
and3,               L)IN(L,
and3or,             L)IN(L,
and3or4,            L)IN(L,
and4,               L)IN(L,
and4or,             L)IN(L,
and4or2,            L)IN(L,
and5or,             L)IN(L,
and5or4,            L)IN(L,
and6or4,            L)IN(L,
and7or,             L)IN(L,
andor,              L)IN(L,
andor4,             L)IN(L,
andor5,             L)IN(L,
or,                 L)IN(L,
or2,          imports);

typedef struct lp_t { p_t ostv[5]; const char* input; Q_t len; Q_t pos; char* name; Q_t lc; p_t* nextsolls; } lp_t;
#define TS(T) T*o=(T*)ο;(void)o
N(init          ) { C(1); }

N(setο          ) { R(p_t *, oο); oο[Φ].p = ο; Α(oο) C(1); }
N(soll_n        ) { Α(os_soll_n, setο, and) O; }

N(coll) {
  R(p_t*, oο);
  R(n_t, nar);
  nar(oο, α, ρ, σ);
}
N(soll_pop) {
  R(p_t *, sο);
  if (sο[Ǎ].Q) A(sο[--sο[Ǎ].Q].v) C(1); else C(0);
}
N(soll_push) {
  R(p_t *, sο);
  R(void *, v);
  if ((sο[Ǎ].Q + 1) < sο[Σ].Q) sο[sο[Ǎ].Q++].v = v, C(1); else C(0);
}
N(soll_contains) {
  R(p_t *, sο);
  for (Q_t i = 0; i < sο[Ǎ].Q; i++)
    if (sο[i].v == σ[α - 1].v)
      return C(1);
  C(0);
}

N(orelse) { Α(ο[0].c) O; }
N(thenS3) { Α(3, ο[1].c) O; }
N(thenS2) { Α(2, ο[1].c) O; }
N(thenS) { Α(1, ο[1].c) O; }
N(empty) { Α(ο[2].c) O; }
N(term) { Α(ο[3].c) O; }
N(var) { Α(ο[4].c) O; }
N(r) { C(1); }

/*            S→Ša|b
         S            a ← T
        / \               ↑
       S   a          b ← O
      / \                 ↑
     S   a            a ← T
    /                     ↑
   b                  b ← O 
Parser computes multiple results, for ambiguous cases, incrementally */












N(r1) { C(1); }
N(r2) { C(1); }
N(r3) { C(1); }
N(print_state  ) {
  R(const char*, desc);
  TS(lp_t); print("%s pos:%lu nsc:%lu lc:%lu\n", desc, o->pos, o->nextsolls[Ǎ].Q, o->lc); C(1); }

N(sTs) { Α("s", term,
           "s", term, thenS2,
           "sTs", var) O; }
N(sOs) { Α(empty,
           "s", term, orelse,
           "sOs", var) O; }
N(sS  ) { Α("s", term, sS, thenS, 
                   empty, orelse, "sS", var) O; }

#include <stdio.h>
N(ps ) { R(const char*, str); print("%s", str), C(1); }
N(pnl) {                      print("\n"     ), C(1); }

N(o02  ) { Α("2", term, o02, var) O; }
N(o01  ) { Α("1", term, o01, var) O; }
N(o00  ) { Α("0", term, o00, var) O; }
N(o2   ) { Α(o00, "a", term,  thenS2, o02, orelse, o2, var) O; }
N(o1   ) { Α(o00, "b", term, orelse, o02, orelse, o1, var) O; }
N(o0   ) { Α(o00, o01, orelse, o02, orelse, o0, var) O; }
N(o012 ) { Α(o0, o1, thenS, o2, orelse, o012, var) O; }

N(term_s    ) { Α("s", term) O; }
N(term_a    ) { Α("a", term) O; }
N(term_b    ) { Α("b", term) O; }


N(drop_n    ) { R(Q_t, wc); α -= wc; C(1); }
N(drop      ) { α -= 1; C(1); }
N(ppar      ) { R(n_t, n); Α("(", ps, n, and, ")", ps, and2) O; }
Nar(por)(" || ", ps)
Nar(pand)(" && ", ps)

NarP(Š)(Š, term_a, thenS,
           term_b, orelse, Š, var)
Nar(Exp )(
    Exp, "+", term, thenS2, Exp, thenS,
    Exp, "-", term, thenS2, Exp, thenS, orelse,
    Exp, "*", term, thenS2, Exp, thenS, orelse,
    Exp, "/", term, thenS2, Exp, thenS, orelse,
    "i", term, orelse,
          Exp, var)

Nar(push_to_nexts)(os_soll_n, ο[8].p, soll_push, and2)
Nar(enter)(dot, ppar)

Nar(check_door)(ο[7].v, soll_contains)
Nar(center)(check_door,
              "rec", ps,
              enter, and2or)
Nar(cont_from_nexts)(
  ο[8].p, soll_pop,
    os_unsoll_free, pand, and, center, and,
    god, and5or)

SarP(or_r)(center, por, and, center, and)
SarP(ts_r)(push_to_nexts, check_door, and,
  "rec", ps, cont_from_nexts, and,
  enter, and4or)
SarP(em_r)("ε", ps, cont_from_nexts, and)
SarP(tr_r)("\"", ps, ps, and, "\"", ps, and2, cont_from_nexts, and)
SarP(va_r)(ο[7].v, soll_push, dot, and)

Nar(example)(
  Exp, or_r, ts_r, em_r, tr_r, va_r, 7, 5, 0, os_soll_n,
                                           0, os_soll_n, and2,
                                           9, os_soll_n, and2,
                                              coll,      and, "hello bro", ps, and2)

N(variable_soll     );
N(orelse_ray       ) { TS(lp_t);
  R(Q_t, wc);
  Α(o->input, o->pos, variable_soll,
                     wc, os_queue_n, and2,
                                dot, and,
                                god, and) O;
}
N(can_match_input  ) { TS(lp_t); R(char*, s); C(o->pos < o->len && o->input[o->pos] == s[0]); }
N(move_ahead      ) { TS(lp_t); o->pos++, o->lc = 0, C(1); }
N(thenS_ray        ) { TS(lp_t);
  Α(soll_n, o->nextsolls,
     soll_push, and2,
     dot, and) O;
}
N(reduce_next_soll) { TS(lp_t);
  Α(o->nextsolls, soll_pop, os_unsoll_free, and, dot, and) O; }
N(term_ray         ) { TS(lp_t);
  Α(can_match_input, move_ahead, and, reduce_next_soll, and, "drop", print_state, or2) O;
}

N(var_ray          ) { TS(lp_t);
  R(char *, name);
  if (o->name == 0)
    o->name = name,
    Α(print_state, and, 3, soll_n, o->nextsolls, soll_push, and2, dot, and) O;
  else if (cmp(o->name, name) == 0) 
      ;
  else
      ;
}
Q_t cslen(const char *cs);
N(variable_soll    ) {
  R(Q_t, pos);
  R(const char*, input);
  char* name = 0;
  Q_t left_rec_count = 0;
  Α(orelse_ray, thenS_ray, reduce_next_soll, term_ray, var_ray,
    input, cslen(input), pos, name, left_rec_count,
    0, os_soll_n, // next_solls
    11, os_soll_n, and2) O;
}
N(Sa      ) {
  Α("a", term, Sa  ) O;
}
N(example_ ) {
  Α("s", term,
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
