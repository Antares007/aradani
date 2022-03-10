#include "arsi.h"
#include "gotgod.h"
// clang-format off
IBS(                L)IN(L,
debugger,           L)IN(L,
os_new,             L)IN(L,
os_queue_n,         L)IN(L,
//
and,                L)IN(L,
and4,         imports)

S(init) {C(1);}

static Q_t counter[3];
SP(n0) { counter[0]++, C(1); }
SP(n1) { counter[1]++, C(1); }
SP(n2) { counter[2]++, C(1); }
Sar(pgot)(n2, n2, and)
Sar(pgod)(n1, n1, and, n1, and)
Sar(pgor)(n0, n0, and, n0, and, n0, and)
S(make_pith) {
  A4(pgot, pgod, pgor, os_new) O; 
}
SP(test1) {
  R(p_t *, oο);
  Α(debugger,
    gor, oο, 1, os_queue_n, and4,
    god, oο, 1, os_queue_n, and4,
    got, oο, 1, os_queue_n, and4) O;
  print("0. %lu\n", counter[0] == 4);
  print("1. %lu\n", counter[1] == 3);
  print("2. %lu\n", counter[2] == 2);
}
NarP(os_new_test)(make_pith, test1, and)

// clang-format off
EN(tail,
os_new_test,        exports)
