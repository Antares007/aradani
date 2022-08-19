#include "a_rsi2.h"

// clang-format off
                    IN(gor,
nar1,             L)IN(L,
nar2,             L)IN(L,
nar3,             L)IN(L,
nar4,       imports)

N(and ) { A(010, aradani) O; }
N(nar5) { A(god) O; }
N(nar6) { A(nar1, nar2, and, nar3, and, nar4, and) O; }

                    EN(tail,
nar5,             L)EN(L,
nar6,       exports)
