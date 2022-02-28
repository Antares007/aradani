#include "arsi.h"
#include "gotgod.h"
// clang-format off
IBS(                L)IN(L,
os_new_j,           L)IN(L,
os_queue,           L)IN(L,
//
and,                L)IN(L,
and3,         imports)

S(init) {C(1);}

static Q_t counter[3];
SP(n0) { counter[0]++, C(1); }
SP(n1) { counter[1]++, C(1); }
SP(n2) { counter[2]++, C(1); }

S(make_pith) {
  A17(n2, n2, and,
      n1, n1, and, n1, and,
      n0, n0, and, n0, and, n0, and,
      0357, os_new_j) O; 
}
SP(test1) {
  R(p_t *, oο);
  Α(gor, oο, os_queue,
    god, oο, os_queue, and3,
    got, oο, os_queue, and3) O;
  print("0. %lu\n", counter[0] == 4);
  print("1. %lu\n", counter[1] == 3);
  print("2. %lu\n", counter[2] == 2);
}
NarP(os_new_test, make_pith, test1, and)

// clang-format off
EN(tail,
os_new_test,        exports)
