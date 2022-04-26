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
  R(void *, v);
  for (Q_t i = 0; i < sο[Ǎ].Q; i++)
    if (sο[i].v == v)
      return C(1);
  C(0);
}

N(ps    ){ R(const char*, str); print("%s", str), C(1); }
N(pld   ){ R(q_t, v); print("%ld", v), C(1); }
N(pnl   ){                      print("\n"     ), C(1); }
N(plu   ){ R(Q_t, v); print("%lu", v), C(1); }
const char* name(void* addr);
N(psoll) {
  R(p_t*, s);
  for(Q_t i = 0; i < s[Ǎ].Q; i++)
    print("%s ", name(s[i].v));
  print("\n");
  A(s) C(1);
}
N(pσ) { for(Q_t i = 0; i < α; i++) print("%s ", name(σ[i].v)); print("\n"); C(1); }

S(coll          ){ R(p_t*, oο); R(n_t, nar); nar(oο, α, ρ, σ); }
N(drop          ){ α--, C(1); }

typedef struct lp_t { p_t* continuation;  p_t* entered_set; } lp_t;
#define TS(T) T*o=(T*)ο;(void)o
#define Var_(...) {TS(lp_t);Α(__VA_ARGS__) O;}
#define Var(Name) N(Name) Var_
#define VarP(Name) NP(Name) Var_
N(continuation) {
  R(p_t*, s);
  Α(s, soll_pop, os_unsoll_free, and,
    s, soll_pop, and2, coll, and) O;
}
S(empty) { Α(                                                         ο, os_unsoll,       dot, and) O; }
N(term ){
  R(const char*,    str);
  R(p_t*,           s);
  p_t*hsoll         = s[4].p;
  Q_t pos           = s[2].Q;
  Q_t len           = s[1].Q;
  const char* input = s[0].cs;
  if (pos < len && input[pos] == str[0])
    Α(input, len, pos + 1, 0, os_soll_n, hsoll, 5, os_soll_n, and3,   ο, os_unsoll, and2, dot, and) O;
  else 
    print("input:%s len:%lu pos:%lu queue:%lu\n", s[0].cs, s[1].Q, s[2].Q, s[4].p[Ǎ].Q / 2),
    Α(s[4].v, continuation) O;
}
N(queue_soll) {
  R(p_t*, pith);
  R(p_t*, rhsoll);
  Α(pith, σ[0].p[4].p, soll_push,
  rhsoll, σ[0].p[4].p, soll_push, and3) O;
}
N(orelse_n_n) {
  R(p_t*, rhsoll);
  Α(σ[0].v, rhsoll, os_unsoll_free, dot, and, 5, os_soll_n, ο, queue_soll, and2, dot, and) O; }
N(orelse_n   ) { Α(os_soll_n, orelse_n_n, and) O; }

N(is_true_pith) {
  R(p_t*, oο);
  Q_t pos = σ[0].p[2].Q;
  Q_t ray = oο[Σ - pos].Q == 0x757575;
  oο[Σ - pos].Q = 0x757575;
//  print("pith: %p pos: %lu ray: %lu\n", oο, pos, ray);
  C(ray);
}
NP(pcontinuation) { continuation(T()); }
N(thenS_n_n  ) {
  R(p_t*, rsoll);
  Α(ο, is_true_pith,
    σ[0].p[4].v, pcontinuation,
    rsoll, os_unsoll, ο, coll, and2, 025, nar, 11, os_soll_n, coll, and) O;
}
N(thenS_n    ) { Α(os_soll_n, thenS_n_n, and) O; }
N(var        ) { Α(σ[0].v, soll_push, dot, and) O; }

Var(thenS    )(1,  thenS_n)
Var(orelse   )(1, orelse_n)
Var(orelse3  )(3, orelse_n)
Var(orelse5  )(5, orelse_n)
VarP(term_a  )("a", term)
VarP(term_b  )("b", term)

VarP(term_s  )("s", term)
VarP(sS      )(empty, 
              term_s, sS, thenS, sS, thenS, orelse5,
              sS, var)


VarP(a       )("a", term)
VarP(b       )("b", term)
VarP(Sa)(b, Sa, a, thenS, orelse3)

VarP(pls       )("+", term)
VarP(mns       )("-", term)
VarP(mul       )("*", term)
VarP(div       )("/", term)
VarP(opr       )("(", term)
VarP(cpr       )(")", term)
               
VarP(Exp       )(a,
                opr, Exp, thenS, cpr, thenS, orelse5,
                //Exp, mul, thenS, Exp, thenS, orelse5,
                Exp, pls, thenS, Exp, thenS, orelse5,
                //Exp, mns, thenS, Exp, thenS, orelse5,
                //Exp, div, thenS, Exp, thenS, orelse5,
                Exp, var)
VarP(aTs       )(term_a, term_s, thenS)
Var(sOs        )(empty, term_s, orelse, sOs, var)

N(parse);
//Nar(example)("ss", sS,  parse)
//Nar(example)("as", aTs, parse)
//Nar(example)("sssss", sOs, parse)
Nar(example)("(a+a)+a", Exp, parse)
//Nar(example)("baaaa", Sa, parse)
Nar(მთავარი)(example)

N(phead){
  R(p_t*,s);
//  print("input:%s len:%lu pos:%lu queue:%lu\n", s[0].cs, s[1].Q, s[2].Q, s[4].p[Ǎ].Q / 2);
  Α(s[4].v, soll_pop, os_unsoll_free, and, s[4].v, soll_pop, and2, coll, and) O;
}
Q_t cslen(const char *cs) { Q_t len = 0; while (cs[len]) len++; return len; }
N(s_pith) { Α(phead, 1, os_soll_n) O; }
N(parse) {
  R(n_t, symb);
  R(const char*, input);
  Α(input, cslen(input), 0, 0, os_soll_n,
                            0, os_soll_n, and2,
                            5, os_soll_n, and2, symb, s_pith, and2, coll, and) O; }

void* names[1024][2];
Q_t names_i = 0;
const char* name(void* addr) {
  for(Q_t i = 0; i < names_i; i++)
    if(names[i][0] == addr) return names[i][1];
  return "n/a";
}
#define Name(Nm) names[names_i][0] = Nm, names[names_i][1] = #Nm, names_i++
N(init_names) {
  Name(empty);
  Name(term);
  Name(orelse_n);
  Name(thenS_n);
  Name(var);
  Name(thenS);
  Name(orelse);
  Name(orelse3);
  Name(orelse5);
  Name(a);
  Name(b);
  Name(Sa);
  Name(pls);
  Name(mns);
  Name(mul);
  Name(div);
  Name(opr);
  Name(cpr);
  Name(Exp);
  Name(term_a);
  Name(term_b);
  Name(term_s);
  Name(sS);
  Name(aTs);
  Name(sOs);
  C(1);
}
Nar(init   )(init_names)

// clang-format off
EN(tail,
მთავარი,      exports);

