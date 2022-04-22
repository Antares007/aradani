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
os_call_n,          L)IN(L,
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
and2or7,            L)IN(L,
and3,               L)IN(L,
and3or,             L)IN(L,
and3or3,            L)IN(L,
and3or4,            L)IN(L,
and4,               L)IN(L,
and4or,             L)IN(L,
and4or2,            L)IN(L,
and5,               L)IN(L,
and5or,             L)IN(L,
and5or3,            L)IN(L,
and5or4,            L)IN(L,
and6or4,            L)IN(L,
and7or,             L)IN(L,
andor,              L)IN(L,
andor2,             L)IN(L,
andor4,             L)IN(L,
andor5,             L)IN(L,
or,                 L)IN(L,
or2,                L)IN(L,
or3,                L)IN(L,
or4,                L)IN(L,
or5,          imports);

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

N(set_alfa_zero ) { α = 0, C(1); }    

static N(ps    ){ R(const char*, str); print("%s", str), C(1); }
//static N(pld   ){ R(q_t, v); print("%ld", v), C(1); }
//static N(pnl   ){                      print("\n"     ), C(1); }
//static N(plu   ){ R(Q_t, v); print("%lu", v), C(1); }
//
N(coll          ){ R(p_t*, oο); R(n_t, nar); nar(oο, α, ρ, σ); }
N(drop          ){ α--, C(1); }
N(empty_soll    ){ Α(0, os_soll_n) O; }
N(empty_pith    ){ Α(empty_soll) O; }

typedef struct lp_t { const char* input; Q_t len; Q_t pos; p_t* continuation;  p_t* solls; } lp_t;
#define TS(T) T*o=(T*)ο;(void)o
#define Var_(...) {TS(lp_t);Α(__VA_ARGS__) O;}
#define Var(Name) N(Name) Var_
#define VarP(Name) NP(Name) Var_

Var(is_left_rec_condition  )(o->solls, soll_contains)
Var(set_in_entered_vars_set)(o->solls, soll_contains, drop, o->solls, soll_push, andor2)
N(is_match){ TS(lp_t); R(const char*,  str); C(o->pos < o->len && o->input[o->pos] == str[0]); }

Var (extend_pith  )(ο, god)

VarP(term         )(is_match, "yes", ps, "no", ps, and2or2)
VarP(orelse       )(extend_pith, coll, and, dot, and)
VarP(thenS        )(drop, is_left_rec_condition, and, drop, dot, andor)
VarP(var          )(set_in_entered_vars_set, dot, and)

Var(pls           )("+", term)
Var(mns           )("-", term)
Var(mul           )("*", term)
Var(div           )("/", term)
Var(id            )("a", term)
Var(opr           )("(", term)
Var(cpr           )(")", term)
Var(cma           )(",", term)
// id, id, id, orelse, thenS3
Var(Exp        )(
  id,
  opr, Exp, thenS, cpr, thenS, orelse,
  Exp, pls, thenS, Exp, thenS, orelse,
  Exp, mns, thenS, Exp, thenS, orelse,
  Exp, div, thenS, Exp, thenS, orelse,
  Exp, mul, thenS, Exp, thenS, orelse,
  Exp, var      )

// continuation is chained solls and representing long sentence 
Nar(example)(Exp,
             "(a+a)*a", 7, 0,
             os_wordump, set_alfa_zero, and, 3, os_soll_n,
             0, os_soll_n, and2,
             5, os_soll_n, and2,
             os_queue, and)

Nar(მთავარი)(example)
Nar(init   )(god)

// clang-format off
EN(tail,
მთავარი,      exports);
