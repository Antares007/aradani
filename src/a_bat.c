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
typedef struct lp_t {
  n_t orelse, thenS, empty, term, variable;
  const char* input;
  Q_t len;
  Q_t pos;
  n_t start_var;
  Q_t llc;
  p_t* solls;
} lp_t;
#define TS(T) T*o=(T*)ο;(void)o
#define Var_(...) {TS(lp_t);Α(__VA_ARGS__) O;}
#define Var(Name) N(Name) Var_
#define VarP(Name) NP(Name) Var_
N(init  ) { C(1); }
N(ps    ){ R(const char*, str); print("%s", str), C(1); }
N(pnl   ){                      print("\n"     ), C(1); }
N(ppar  ){ R(n_t, n); Α("(", ps, n, and, ")", ps, and2) O; }
Nar(por )(" || ", ps)
Nar(pand)(" && ", ps)
Nar(quot)("\"", ps)
N(drop_n){ R(Q_t, wc); α -= wc; C(1); }
N(drop  ){ α -= 1; C(1); }
N(coll) {
  R(p_t*, oο);
  R(n_t, nar);
  nar(oο, α, ρ, σ);
}
N(soll_pop) {
  R(p_t *, sο);
  if (sο[Ǎ].Q)
    A(sο[--sο[Ǎ].Q].v) C(1);
  else
    C(0);
}
N(soll_push) {
  R(p_t *, sο);
  R(void *, v);
  if ((sο[Ǎ].Q + 1) < sο[Σ].Q)
    sο[sο[Ǎ].Q++].v = v, C(1);
  else
    C(0);
}
N(soll_contains) {
  R(p_t *, sο);
  for (Q_t i = 0; i < sο[Ǎ].Q; i++)
    if (sο[i].v == σ[α - 1].v)
      return C(1);
  C(0);
}
Var(orelse)(o->orelse)
Var(thenS)(1, o->thenS)
Var(empty)(o->empty)
Var(term)(o->term)
Var(var)(o->variable)

Nar(plus )("+", term)
Nar(minus)("-", term)
Nar(mul  )("*", term)
Nar(div  )("/", term)
Nar(id   )("i", term)
Nar(opar )("(", term)
Nar(cpar )(")", term)
Nar(Exp  )(
  id, 
  Exp, div,   thenS, Exp, thenS, orelse,
  Exp, mul,   thenS, Exp, thenS, orelse,
  Exp, plus,  thenS, Exp, thenS, orelse,
  Exp, minus, thenS, Exp, thenS, orelse,
                                    Exp, var)
Var(term_a    )("a", term)
Var(term_b    )("b", term)
Var(term_o    )("o", term)
Var(term_s    )("s", term)
Var(sTs       )(term_a, term_s, thenS,  sTs, var)
Var(sOs       )(empty,  term_a, orelse, sOs, var)
Var(Sa        )(term_b,
                Sa, term_o, thenS, orelse,
                Sa, term_a, thenS, orelse,
                sOs, var)

Var(push      )(os_soll_n, o->solls, soll_push, and2)
Var(pop       )(o->solls, soll_pop, os_unsoll_free, and)
Var(push_enter)(push, dot, and)
Var(pop_enter )(pop, dot, and)

VarP(or_r     )(dot, dot, and)
VarP(ts_r     )(push_enter, pop_enter, and)
VarP(em_r     )("ε", ps)
VarP(tr_r     )(quot, ps, and, quot, and)
VarP(va_r     )(drop, dot, and)

Q_t cslen(const char *cs);
N(parser_pith) {
  R(Q_t,    pos);
  R(char*,  input);
  R(n_t,    start_var);
  Α(or_r, ts_r, em_r, tr_r, va_r,
    input, cslen(input), pos, start_var, 0,
    0, os_soll_n,
    11, os_soll_n, and2) O;
}
N(parse) {
  R(lp_t *, pp);
  Α(pp->start_var, pp, coll) O;
}
Nar(example)(
  sTs, "sssss", 0, parser_pith, parse, and, " done! ", ps, and2)

N(მთავარი  ) { Α(example) O; }

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
