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

N(clear_sigma ) { α = 0, C(1); }    

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

p_t *memo_soll;
uint64_t inline MurmurOAAT64 (const char * beg, const char * end)
{
  uint64_t h = 525201411107845655ull;
  for (;beg!=end;++beg) {
    h ^= *beg;
    h *= 0x5bd1e9955bd1e995;
    h ^= h >> 47;
  }
  return h;
}

N(set_memo) { R(p_t*, msoll); memo_soll = msoll; C(1); }
N(init_memo) { Α(0, os_soll_n, set_memo, and) O; }
N(drop_n) { R(Q_t, wc); α -= wc, C(1); }
N(queue) {
  R(Q_t, wc);
  Q_t hash = MurmurOAAT64((void*)&σ[α-wc],(void*)&σ[α]);
  R(p_t *, oο);
  //if(wc == 4)
  //  print("inp:%s pos:%lu %p %p %p\n", σ[α-wc].cs, σ[α-wc+2].Q, oο, σ[α-1].v, hash);
  Α(hash, memo_soll, soll_contains,
    wc + 1, drop_n,
    memo_soll, soll_push, oο, wc, os_queue_n, and3,  026, nar) O;
}
N(coll          ){ R(p_t*, oο); R(n_t, nar); nar(oο, α, ρ, σ); }
N(drop          ){ α--, C(1); }
N(empty_soll    ){ Α(0, os_soll_n) O; }
N(empty_pith    ){ Α(empty_soll) O; }

typedef struct lp_t { p_t* continuation;  p_t* entered_set; } lp_t;
#define TS(T) T*o=(T*)ο;(void)o
#define Var_(...) {TS(lp_t);Α(__VA_ARGS__) O;}
#define Var(Name) N(Name) Var_
#define VarP(Name) NP(Name) Var_
N(cpp) { σ[0].p[3].Q+=2, C(1); }
N(cm ) { σ[0].p[3].Q-=1, C(1); }
N(empty) { Α(ο, os_unsoll, dot, and) O; }
N(term ){
  R(const char*,    str);
  R(p_t*,           s);
  Q_t c             = s[3].Q;
  Q_t pos           = s[2].Q;
  Q_t len           = s[1].Q;
  const char* input = s[0].cs;
  //  print("inp:%s pos:%lu\n", input, pos);
  if (pos < len && input[pos] == str[0])
    Α(input, len, pos + 1, c, 4, os_soll_n, ο, os_unsoll, and2, dot, and) O;
  else
    C(1);
}
N(orelse_n_n   ){
  R(p_t*, rhsoll);
  Α(σ[0].v, rhsoll, os_unsoll_free, dot, and, ο, 5, queue, dot, and) O;
}
N(orelse_n     ){
  R(Q_t, wc);
  Α(wc, os_soll_n, orelse_n_n, and) O;
}
N(thenS_n      ){
  R(Q_t, wc);
  Α(ο, os_unsoll, dot, and, 4, os_soll_n, wc + 1, queue, wc + 3, os_soll_n, and4, cpp, and, coll, and) O;
}
N(var           ){ Α(drop, dot, and) O; }
Var(thenS       )(1, thenS_n)
Var(orelse      )(1, orelse_n)
Var(orelse3     )(3, orelse_n)
Var(orelse5     )(5, orelse_n)
Var(term_a      )("a", term)
Var(term_b      )("b", term)

VarP(term_s     )("s", term)
VarP(sS         )(empty, 
                  term_s, sS, thenS, sS, thenS, orelse5,
                  sS, var)


Var(a             )("a", term)
Var(b             )("b", term)
Var(Sa)(b,
        Sa, a, thenS, orelse3)

Var(pls           )("+", term)
Var(mns           )("-", term)
Var(mul           )("*", term)
Var(div           )("/", term)
Var(opr           )("(", term)
Var(cpr           )(")", term)

Var(Exp         )(a,
                  opr, Exp, thenS, cpr, thenS, orelse5,
                  Exp, mul, thenS, Exp, thenS, orelse5,
                  Exp, pls, thenS, Exp, thenS, orelse5,
                  //Exp, mns, thenS, Exp, thenS, orelse5,
                  //Exp, div, thenS, Exp, thenS, orelse5,
                  Exp, var)
Var(aTs)(term_a, term_s, thenS)
Var(sOs)(empty, term_s, orelse, sOs, var)

N(parse);

Nar(example)("sssss", sS,  parse)
//Nar(example)("as", aTs, parse)
//Nar(example)("sssss", sOs, parse)
//Nar(example)("(a+a)*a", Exp, parse)
//Nar(example)("baaaa", Sa, parse)
Nar(მთავარი)(example)

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
  Name(orelse_n_n);
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
Nar(init   )(init_memo, init_names, and)

// clang-format off
EN(tail,
მთავარი,      exports);

// continuation is chained entered_set and representing long sentence 
N(phead){
  R(p_t*,s);
  print("input:%s len:%lu pos:%lu\n", s[0].cs, s[1].Q, s[2].Q);
  C(1);
}
Q_t cslen(const char *cs) { Q_t len = 0; while (cs[len]) len++; return len; }
N(parse) {
  R(n_t, symb);
  R(const char*, input);
  Α(input, cslen(input), 0, 0, 4, os_soll_n, symb, phead, 1, os_soll_n, and4, coll, and) O; }

