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

static N(ps    ){ R(const char*, str); print("%s", str), C(1); }
//static N(pld   ){ R(q_t, v); print("%ld", v), C(1); }
static N(pnl   ){                      print("\n"     ), C(1); }
static N(plu   ){ R(Q_t, v); print("%lu", v), C(1); }

NP(var    ) { TS(lp_t);
  R(n_t, var_nar);
  (void)var_nar;
  Α(dot) O;
}

// term_s = term ’s’
// where term t j
// = {}     , if j > l_input
// = {j + 1}, if jth element of input = t
// = {}     , otherwise
NP(term   ) { TS(lp_t);
  R(const char*, str);
  if (o->pos < o->len && o->input[o->pos] == str[0]) 
    Α(o->pos + 1, o->c) O;
  else
    C(0);
}

// (p ‘orelse‘ q) j = unite (p j) (q j)
// e.g., assuming that the input is "sssss", then
// (empty ‘orelse‘ term_s) 2 => {2, 3}
NP(orelse ) {
  Α(dot, dot, dot, andor) O;
}

// (p ‘thenS‘ q) j = union (map q (p j))
// e.g., assuming that the input is "sssss", then
// (term_s ‘thenS‘ term_s) 1 => {3}
NP(thenS  ) {
  Α(dot, dot, god, andor) O;
}

N(Sa     ) { TS(lp_t);
  Α(Sa, "a", term, thenS,
        "b", term, orelse, Sa, var
  ) O;
}
N(coll   ){ R(p_t*, oο); R(n_t, nar); nar(oο, α, ρ, σ); }

Nar(plunl )("pos:", ps, plu, and, pnl, and)
N(example){ Α(Sa, plunl, "baaa", 4, 0, 4, os_soll_n, coll, and) O; }

N(მთავარი ){ Α(example) O; }
N(init    ){ C(1); }

// clang-format off
EN(tail,
მთავარი,      exports);
