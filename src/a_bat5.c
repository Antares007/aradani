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
os_queue_clear,     L)IN(L,
os_queue_n,         L)IN(L,
os_queue_soll,      L)IN(L,
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
and2or3,            L)IN(L,
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
and7,               L)IN(L,
and7or,             L)IN(L,
andor,              L)IN(L,
andor2,             L)IN(L,
andor3,             L)IN(L,
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
  R(void *, v);
  for (Q_t i = 0; i < sο[Ǎ].Q; i++)
    if (sο[i].v == v)
      return C(1);
  C(0);
}
Nar(empty_soll) (0, os_soll_n);

N(ps          ) { R(const char*, str); print("%s", str), C(1); }
N(pld         ) { R(q_t, v); print("%ld", v), C(1); }
N(pnl         ) {                      print("\n"     ), C(1); }
N(plu         ) { R(Q_t, v); print("%lu", v), C(1); }
N(coll        ) { R(p_t*, oο); R(n_t, nar); nar(oο, α, ρ, σ); }
N(drop        ) { α--, C(1); }
N(drop_n      ) { R(Q_t, wc); α -= wc, C(1); }

#define TS(T) T*o=(T*)ο;(void)o
#define Var_(...) { Α(__VA_ARGS__) O; }
#define Var(Name) N(Name) Var_
#define VarP(Name) NP(Name) Var_
#define VLog print("V "); PLog
N(orelse_n    ){ ο[0].c(T()); }
N(thenS_n     ){ ο[1].c(T()); }
N(term        ){ ο[2].c(T()); }
N(empty       ){ ο[3].c(T()); }
N(variable    ){ ο[4].c(T()); }

Var(pls       )("+", term)
Var(mns       )("-", term)
Var(mul       )("*", term)
Var(div       )("/", term)
Var(opr       )("(", term)
Var(cpr       )(")", term)
Var(Exp       )("a", term,
                opr, Exp, 1, thenS_n, cpr, 1, thenS_n, 7, orelse_n,
                Exp, mul, 1, thenS_n, Exp, 1, thenS_n, 7, orelse_n,
                Exp, div, 1, thenS_n, Exp, 1, thenS_n, 7, orelse_n,
                Exp, mns, 1, thenS_n, Exp, 1, thenS_n, 7, orelse_n,
                Exp, pls, 1, thenS_n, Exp, 1, thenS_n, 7, orelse_n,
                Exp, variable)

N(o_orelse_n  ) { VLog; Α(os_soll_n, os_soll_free, and, dot, and) O; }
N(o_thenS_n   ) { VLog; Α(os_soll_n, os_soll_free, and, dot, and) O; }
N(o_empty     ) { VLog;      C(1); }
N(o_term      ) { VLog; α--, C(1); }
N(o_variable  ) { Α(drop, dot, and) O; }
// bSaTO3SV
//                  b
//                  V₁
//          b       |-a
//         SV₁     SV₁
//  b       |-a     |-a
// SV₀ SaT SV₀ Sat SV₀ Sat
//  |       |       |
//
//  a(ET)TO₅E+TETO₅EV
//                     a
//                    EV₁
//                     |-+
//  a                  |-E
// EV₀  (ET)T E+TET   EV₀  (ET)T E+TET
//  |                  |
//
//  εsOSV
//  ε      ε s
//  |       \|
// SV₀  s   SV₀
//  |        |

Nar(o_pith    )(o_orelse_n, o_thenS_n, o_term, o_empty, o_variable, 5, os_soll_n)
Nar(example_0 )("a+a*a", 5, 0, Exp, o_pith,
                                      coll, and,
                                os_wordump, and)
Nar(init      )(god)
Nar(ss1)(     1, gor, 2, os_soll_n)
Nar(ss2)(ss1, 2, god, 2, os_soll_n, and4)

Nar(example2  )(ss2,
                os_unsoll_free, and,
                dot, and,
                os_wordump, and)

Nar(მთავარი   )(example)
// clang-format off
EN(tail,
მთავარი,      exports);
Q_t cslen(const char *cs) {
  Q_t len = 0;
  while (cs[len])
    len++;
  return len;
}
