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
N(drop_n        ){ R(Q_t, wc); α -= wc, C(1); }

typedef struct lp_t { p_t* continuation;  p_t* entered_set; } lp_t;
#define TS(T) T*o=(T*)ο;(void)o
#define Var_(...) {TS(lp_t);Α(__VA_ARGS__) O;}
#define Var(Name) N(Name) Var_
#define VarP(Name) NP(Name) Var_
N(eval_pith) { Α(os_unsoll, dot, and) O; }
#define VLog print("%lu/%lu/%lu ", σ[1].Q, σ[2].Q, σ[3].Q); PLog
N(depth_pp) { σ[3].Q++, C(1); }
N(depth_mm) { σ[3].Q--, C(1); }
N(empty) { VLog; Α(ο, eval_pith) O; }
N(term ) { VLog;
  R(const char*,    str);
  R(Q_t,            depth);
  R(Q_t,            pos);
  R(Q_t,            len);
  R(const char*,    input);
  if (pos < len && input[pos] == str[0])
    Α(input, len, pos + 1, depth, ο, eval_pith) O;
  else {
    print("pos >= len || input[pos](%c) != str[0](%c)\n", pos, len, input[pos], str[0]);
    C(1);
  }
}
N(orelse_n_n) {
  R(p_t*, rhsoll);
  Α(σ[0].v, σ[1].v, σ[2].v, σ[3].v, rhsoll, os_unsoll_free, dot, and, 4+4, os_soll_n,
                                                                    ο, os_queue_soll, and2,
                                                                                 dot, and) O; }
N(orelse_n  ) { VLog; R(Q_t, wc); Α(wc, os_soll_n, orelse_n_n, and) O; }
N(cont_eval ) {
  R(p_t*, oο);
  R(p_t*, rhsoll);
  Α(rhsoll, os_unsoll, oο, depth_mm, and2, coll, and) O;
}
N(is_true_pith) {
  Q_t ray = ο[ο[Σ].Q - σ[2].Q].Q == 0x75757575;
  ο[ο[Σ].Q - σ[2].Q].Q = 0x75757575;
  if (ray) print("true pith\n");
  C(ray);
}
N(thenS_n_n ) {
  R(p_t*, rhsoll);
  Α(is_true_pith,
      4, drop_n,
      rhsoll, ο, cont_eval, and2or3, 7, os_soll_n,
                                         depth_pp, and,
                                             coll, and) O;
}
N(thenS_n   ) { VLog; Α(os_soll_n, thenS_n_n, and) O; }
N(var       ) { VLog; Α(drop, dot, and) O; }

Var(thenS    )(1,  thenS_n)
Var(orelse   )(1, orelse_n)
Var(orelse3  )(3, orelse_n)
Var(orelse5  )(5, orelse_n)
VarP(term_a  )("a", term)
VarP(term_b  )("b", term)

Var(term_s  )("s", term)
Var(sS      )( term_s, sS, thenS, sS, thenS,
              empty, orelse,
              sS, var)


Var(a       )("a", term)
Var(b       )("b", term)
Var(c       )("c", term)
Var(Sa)(b,
        Sa, a, thenS, orelse3,
//        Sa, c, thenS, orelse3,
        Sa, var)

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
Nar(example)("b", Sa, parse)
//Nar(example)("sss", sS,  parse)
//Nar(example)("as", aTs, parse)
//Nar(example)("sssss", sOs, parse)
//Nar(example)("(a+a)+a", Exp, parse)
Nar(მთავარი)(example)

N(phead){
  R(Q_t,            depth);
  R(Q_t,            pos);
  R(Q_t,            len);
  R(const char*,    input);
  print("B input:%s len:%lu pos:%lu depth:%lu\n", input, len, pos, depth), C(1);
}
Q_t cslen(const char *cs) { Q_t len = 0; while (cs[len]) len++; return len; }
N(s_pith) { Α(phead, 1, os_soll_n) O; }
N(parse) {
  R(n_t, symb);
  R(const char*, input);
  Α(input, cslen(input), 0, 0, symb, s_pith,
                                       coll, and) O; }

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

