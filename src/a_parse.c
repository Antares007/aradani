#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
debugger,           L)IN(L,
dot,                L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
nar,                L)IN(L,
os_ls,              L)IN(L,
os_new,             L)IN(L,
os_queue,           L)IN(L,
os_soll_a,          L)IN(L,
os_soll_free,       L)IN(L,
os_soll_n,          L)IN(L,
os_unsoll,          L)IN(L,
os_wordump,         L)IN(L,

and,                L)IN(L,
and2,               L)IN(L,
and2or,             L)IN(L,
and3,               L)IN(L,
and3or,             L)IN(L,
and3or3,            L)IN(L,
and4,               L)IN(L,
and5,               L)IN(L,
and6,               L)IN(L,
and7,               L)IN(L,
andor,              L)IN(L,
andor2,             L)IN(L,
andor3,             L)IN(L,
not,                L)IN(L,
not2and,            L)IN(L,
not2and2or2,        L)IN(L,
or,                 L)IN(L,
or2,                L)IN(L,
or3,                L)IN(L,

new_soll_psn,       L)IN(L,
new_soll_psn_a,     L)n_t la;I(L,

"lookahead", la,    L)IN(L,
lookahead_set,      L)IN(L,
parse,              L)IN(L,
prn_a,              L)IN(L,
shift,        imports);

SarP(init)(god)
Sargo(testuni)(
  la,
  shift, and,
  la,    and,
  shift, and,
  prn_a
)
Sargo(მთავარი)(testuni, "aaa bbb ccc", parse)

EN(tail,
მთავარი, exports)
/*
u8cp_b3
  la, ck1110xxxx, shift, um1110xxxx, 12 bin_lsh, 
  la, ck10xxxxxx, shift, um10xxxxxx,  6 bin_lsh, 
  la, ck10xxxxxx, shift, um10xxxxxx,    bin_or and bin_or
sentences:
  na.
  a1 na.
  a1 a2 na.
  a1 a2 a3 na.
  na and nb
  a1 na and nb.
  a1 na and a1 nb and a1 nc.
  a1 na , a1 nb and a1 nc.
  a1 a2 na and nb.
  na, nb and nc.
  na, nb, nc.
  arg1 nara and narc.
  arg1 arg2 nara, arg1 narB and narc.
*/
