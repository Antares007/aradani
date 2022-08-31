#include "a_rsi2.h"

// clang-format off
                    IN(σ2,
nar1,             L)IN(L,
nar2,             L)IN(L,
nar3,             L)IN(L,
nar4,       imports)

N(nar5) { A(7, σ1) O; }
N(nar6) { A(7, σ1) O; }

                    EN(tail,
nar5,             L)EN(L,
nar6,       exports)
