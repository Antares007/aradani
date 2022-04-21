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
andor4,             L)IN(L,
andor5,             L)IN(L,
or,                 L)IN(L,
or2,                L)IN(L,
or3,                L)IN(L,
or4,                L)IN(L,
or5,          imports);
typedef struct lp_t { n_t c; const char* input; Q_t len; Q_t pos; } lp_t;
#define TS(T) T*o=(T*)ο;(void)o
#define Var_(...) {TS(lp_t);Α(__VA_ARGS__) O;}
#define Var(Name) N(Name) Var_
#define VarP(Name) NP(Name) Var_

//static N(ps    ){ R(const char*, str); print("%s", str), C(1); }
//static N(pld   ){ R(q_t, v); print("%ld", v), C(1); }
//static N(pnl   ){                      print("\n"     ), C(1); }
//static N(plu   ){ R(Q_t, v); print("%lu", v), C(1); }
N(coll          ){ R(p_t*, oο); R(n_t, nar); nar(oο, α, ρ, σ); }
N(drop          ){ α--, C(1); }
N(empty_soll    ){ Α(0, os_soll_n) O; }
N(empty_pith    ){ Α(empty_soll) O; }
NP(term         ){
  R(const char*,  str);
  R(Q_t,          pos);
  R(Q_t,          len);
  R(const char*,  input);
  print("input:%s len:%lu pos:%lu str:%s\n", input, len, pos, str);
  if (pos < len && input[pos] == str[0])
    Α(input, len, pos + 1, ο, os_unsoll_free, dot, and) O;
  else
    print("drop/unsoll? pos:%lu\n", pos), C(1);
}
N(orelse_n_n    ){
  R(p_t*, rhsoll);
  const char* input = σ[0].cs;
  Q_t len           = σ[1].Q;
  Q_t pos           = σ[2].Q;
  Α(input, len, pos, rhsoll, os_unsoll_free, dot, and, ο, 7, os_queue_n) O;
}
NP(orelse_n     ){
  R(Q_t, wc);
  Α(wc, os_soll_n, orelse_n_n, and,
                          dot, and) O;
}
NP(thenS_n      ){
  R(Q_t, wc);
  α -= wc, O;
}
NP(var          ){ Α(drop, dot, and) O; }

N(thenS        ){ Α(1, thenS_n) O; }
N(orelse3      ){ Α(3, orelse_n) O; }
N(orelse5      ){ Α(5, orelse_n) O; }

NarP(pls        )("+", term)
NarP(mns        )("-", term)
NarP(mul        )("*", term)
NarP(div        )("/", term)
NarP(id         )("a", term)
NarP(opr        )("(", term)
NarP(cpr        )(")", term)
NarP(cma        )(",", term)
NarP(Exp        )(
  id,
  opr, Exp, thenS, cpr, thenS, orelse5,
  //Exp, pls, thenS, Exp, thenS, orelse5,
  //Exp, mns, thenS, Exp, thenS, orelse5,
  //Exp, div, thenS, Exp, thenS, orelse5,
  //Exp, mul, thenS, Exp, thenS, orelse5,
  Exp, var      )
N(set_alfa_zero) { α = 0, C(1); }    
NP(continuation ) { Α(os_wordump, set_alfa_zero, and, 3, os_soll_n) O; }
NP(example      ) { Α("(a)+a*a", 7, 0, Exp, continuation, os_queue, and) O; }

N(მთავარი       ){ Α(example) O; }
N(init          ){ C(1); }

// clang-format off
EN(tail,
მთავარი,      exports);
