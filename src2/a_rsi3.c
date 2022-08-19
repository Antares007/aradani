#include "a_rsi2.h"

// clang-format off
                    IN(gor,
nar1,             L)IN(L,
nar2,             L)IN(L,
nar3,             L)IN(L,
nar4,             L)IN(L,
nar6,       imports)

N(and) { A(010, aradani) O; }
N(one) { A(1, god) O; }
N(add) {
  RN(Q_t, r);
  RN(Q_t, l);
  A(l + r, god) O;
} 
N(two) { A(one, one, and, add, and) O; }
N(nar7) {
  A(one, two, and, add, and,
         two, and, add, and,
         two, and, add, and) O;
}
                    EN(tail,
nar7,       exports)
