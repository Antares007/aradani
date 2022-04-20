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

//static N(ps    ){ R(const char*, str); print("%s", str), C(1); }
//static N(pld   ){ R(q_t, v); print("%ld", v), C(1); }
static N(pnl   ){                      print("\n"     ), C(1); }
static N(plu   ){ R(Q_t, v); print("%lu", v), C(1); }
Nar(plunl )(plu, pnl, and)

N(var   ) {
  C(1);
}

// term_s = term ’s’
// where term t j
// = {}     , if j > l_input
// = {j + 1}, if jth element of input = t
// = {}     , otherwise
N(term  ) { 
//  o->c(o->pos + 1);
  C(1);
}

// (p ‘orelse‘ q) j = unite (p j) (q j)
// e.g., assuming that the input is "sssss", then
// (empty ‘orelse‘ term_s) 2 => {2, 3}
N(orelse) {
  C(1);
}

// (p ‘thenS‘ q) j = union (map q (p j))
// e.g., assuming that the input is "sssss", then
// (term_s ‘thenS‘ term_s) 1 => {3}
N(thenS ) {
  C(1);
}

N(Sa    ) {
  Α(    "b", term,
    Sa, "a", term, thenS, orelse, Sa, var) O;
}
N(coll   ){ R(p_t*, oο); R(n_t, nar); nar(oο, α, ρ, σ); }
N(parse  ){ Α(plunl, 1, os_soll_n, coll, and) O; }
N(example){ Α("baaa", 0, Sa, parse) O; }

N(მთავარი ){ Α(example) O; }
N(init    ){ C(1); }

// clang-format off
EN(tail,
მთავარი,      exports);
