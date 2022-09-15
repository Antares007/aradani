#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
debugger,           L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
os_new,             L)IN(L,
os_queue_n,         L)IN(L, //
and,                L)IN(L,
and4,         imports);
// clang-format on
SP(init) { Α(god) O; }
static Q_t counter[3];
SP(n0) { counter[0]++, C(1); }
SP(n1) { counter[1]++, C(1); }
SP(n2) { counter[2]++, C(1); }
S(pgot) { Α(n2, n2, and) O; }
S(pgod) { Α(n1, n1, and, n1, and) O; }
S(pgor) { Α(n0, n0, and, n0, and, n0, and) O; }
S(make_pith) { A4(pgot, pgod, pgor, os_new) O; }
SP(test1) {
  R(p_t *, oο);
  Α(debugger, gor, oο, 1, os_queue_n, and4, god, oο, 1, os_queue_n, and4, got,
    oο, 1, os_queue_n, and4)
  O;
  print("0. %lu\n", counter[0] == 4);
  print("1. %lu\n", counter[1] == 3);
  print("2. %lu\n", counter[2] == 2);
}
NP(os_new_test) { Α(make_pith, test1, and) O; }
// clang-format off
EN(tail,
os_new_test,        exports)
