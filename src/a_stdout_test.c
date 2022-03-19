#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
dot,                L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
os_ls,              L)IN(L,
os_queue,           L)IN(L,
os_seed,            L)IN(L,
os_wordump,         L)IN(L,
//
and,                L)IN(L,
and4,         imports)

SarP(init)(god)

E(got, "0",             0,L)E(L,
"0",                    0,L)E(L,
"printf",           print,L)E(L,
"god",                god,L)E(L,
"gor",                gor,L)E(L,
"got",                got,L)E(L,
"l_free",             god,L)E(L,
"l_setnoblock",       god,L)E(L,
"l_write",            god,L)E(L,
"os_new_n",           god,L)E(L,
"os_queue",           god,L)E(L, //
"and",                god,L)E(L,
"and2",               god,L)E(L,
"and2or",             god,L)E(L,
"and3or",             god,L)E(L,
"andor",              god,L)E(L,
"andor3",             god,L)E(L,
"or",                 god,L)E(L,
"or3",                god,L)E(L, //
"q_for_each",         god,L)E(L,
"q_push",             god,L)E(L,
"q_shift",            god,L)E(L,
"q_soll_free",        god,L)E(L,
"q_soll_remove",      god,L)E(L,
"q_unshift",          god,L)E(L, //
"epoll_ctl_add_out",  god,L)E(L,
"epoll_ctl_del_out",  god,L)E(L,
"epoll_ctl_mod_out",  god,L)E(L, //
"is_alfa_zero",       god,L)E(L,
"match",       god,exports2)

SP(მთავარი_n) {
  const char* arsi_fname = "src/a_stdout.tarsi";
  Α(arsi_fname, exports2, os_seed, os_ls, and) O;
}
SP(მთავარი) {
  Α(მთავარი_n, ο, os_queue) O;
}

// clang-format off
EN(tail,
მთავარი,      exports)
