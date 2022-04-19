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

N(var     ) { C(1); }
// term_s = term ’s’
// where term t j
// = {}     , if j > l_input
// = {j + 1}, if jth element of input = t
// = {}     , otherwise
N(term    ) { 
  //  for each p in piths
  //  if (p.pos < p.length && p.input[p.pos] == term)
  //    piths[p] = p input len pos+1 term newpith, C(1)
  //  else
  //    piths[p] = null, C(0)
}
// (p ‘orelse‘ q) j = unite (p j) (q j)
// e.g., assuming that the input is "sssss", then
// (empty ‘orelse‘ term_s) 2 => {2, 3}
N(orelse_n) { C(1); }
// (p ‘thenS‘ q) j = union (map q (p j))
// e.g., assuming that the input is "sssss", then
// (term_s ‘thenS‘ term_s) 1 => {3}
N(thenS_n ) {
  //  for each p in piths
  C(1);
}

N(Sa      ) {
  Α(Sa, var,
    "b", term, 2, orelse_n,
    Sa, "a", term, 2, thenS_n, 5, orelse_n
  ) O;
}

NP(seven) { print("7\n");  A2(4, 7) C(1); }

N(pith    ) { Α(seven, 1, os_soll_n) O; }

NP(dump) { os_wordump(T()); }
NP(example ) { Α(co0, pith,
                 1, os_call_n, and2,
                         dump, and) O; }

N(მთავარი ) { Α(example) O; }
N(init    ) { C(1); }

// clang-format off
EN(tail,
მთავარი,      exports);
