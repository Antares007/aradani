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

NP(clear_sigma ) { α = 0, C(1); }    

//static N(ps    ){ R(const char*, str); print("%s", str), C(1); }
//static N(pld   ){ R(q_t, v); print("%ld", v), C(1); }
//static N(pnl   ){                      print("\n"     ), C(1); }
//static N(plu   ){ R(Q_t, v); print("%lu", v), C(1); }
//
N(coll          ){ R(p_t*, oο); R(n_t, nar); nar(oο, α, ρ, σ); }
N(drop          ){ α--, C(1); }
N(empty_soll    ){ Α(0, os_soll_n) O; }
N(empty_pith    ){ Α(empty_soll) O; }

typedef struct lp_t { p_t* continuation;  p_t* entered_set; } lp_t;
#define TS(T) T*o=(T*)ο;(void)o
#define Var_(...) {TS(lp_t);Α(__VA_ARGS__) O;}
#define Var(Name) N(Name) Var_
#define VarP(Name) NP(Name) Var_
NP(empty) { Α(ο, os_unsoll, dot, and) O; }
NP(term){
  R(const char*,  str);
  R(Q_t,          pos);
  R(Q_t,          len);
  R(const char*,  input);
  print("inp:%s len:%lu pos:%lu\n", input, len, pos);
  if(pos < len && input[pos] == str[0]) Α(input, len, pos + 1, ο, os_unsoll, dot, and) O;
  else C(1);
}
N (orelse_n_n   ){
  R(p_t*, rhsoll);
  Α(σ[0].v, σ[1].v, σ[2].v, rhsoll, os_unsoll_free, dot, and, ο, 7, os_queue_n, dot, and) O;
}
NP(orelse_n     ){
  R(Q_t, wc);
  Α(wc, os_soll_n, orelse_n_n, and) O;
}
NP(thenS_n      ){
  R(Q_t, wc);
  Α(ο, wc + 3, os_queue_n, wc + 3, os_soll_n, coll, and) O;
}
NP(var          ){              Α(drop, dot, and) O; }

Var(thenS  )(1, thenS_n)
Var(orelse )(1, orelse_n)
Var(orelse3)(3, orelse_n)
Var(orelse5)(5, orelse_n)

VarP(a             )("a", term)
VarP(b             )("b", term)
VarP(Sa)(b,
         Sa, a, thenS, orelse3)

Var(pls           )("+", term)
Var(mns           )("-", term)
Var(mul           )("*", term)
Var(div           )("/", term)
Var(opr           )("(", term)
Var(cpr           )(")", term)

Var(Exp         )(a,
                  opr, Exp, thenS, cpr, thenS, orelse5,
                  Exp, pls, thenS, Exp, thenS, orelse5,
                  Exp, mns, thenS, Exp, thenS, orelse5,
                  Exp, div, thenS, Exp, thenS, orelse5,
                  Exp, mul, thenS, Exp, thenS, orelse5,
                  Exp, var)
Var(term_a)("a", term)
Var(term_b)("b", term)
Var(term_s)("s", term)
Var(sS )(empty, 
         term_s, sS, thenS, sS, thenS, orelse5,
         sS, var)
VarP(aTs)(term_a, term_s, thenS)
VarP(sOs)(empty, term_s, orelse, sOs, var)

NP(dump) {
  Α(god,
    os_wordump, clear_sigma, and,
    os_wordump, clear_sigma, and,
    os_wordump, clear_sigma, and, 0333, nar) O; }
//Nar(example)("sssss", 5, 0, sS, dump, 1, os_soll_n, coll, and)
//Nar(example)("as", 2, 0, aTs, dump, 1, os_soll_n, coll, and)
//Nar(example)("sssss", 5, 0, sOs, dump, 1, os_soll_n, coll, and)
Nar(example)("(a+a)*a", 7, 0, Exp, dump, 1, os_soll_n, coll, and)
//Nar(example)("baaaa", 5, 0, Sa, dump, 1, os_soll_n, coll, and)
Nar(მთავარი)(example)
Nar(init   )(god)

// clang-format off
EN(tail,
მთავარი,      exports);

// continuation is chained entered_set and representing long sentence 
