#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
god,                L)IN(L,

Ξ,                  L)IN(L,
Ο,                  L)IN(L,
Τ,                  L)IN(L,
Ϋ,                  L)IN(L,
ε,            imports);      

#define Var(Name,  ...)  N(Name) { Α(__VA_ARGS__, Name, #Name, Ϋ) O; }
#define VLog print("V "); PLog

Var(o,                "o", Ξ)
Var(b,                "b", Ξ)
Var(B,                "B", Ξ)
Var(a,                "a", Ξ)
Var(s,                "s", Ξ)
Var(εΟaΟsoΤΟSoΤΟSbΤBΤ,  ε,
                    Ο,  a,
                    Ο,  s, o, Τ,
                    Ο,  εΟaΟsoΤΟSoΤΟSbΤBΤ, o, Τ,
                    Ο,  εΟaΟsoΤΟSoΤΟSbΤBΤ, b, Τ, B, Τ)
Var(εΟs,                ε, Ο, s)
Var(ssΤ,                s, s, Τ)
Var(bΟSaΤ,              b, Ο, bΟSaΤ, a, Τ)

N(pgod      ){ VLog; print("---->%lu\n", ο[0].Q), C(1); }
Nar(example )(pgod, εΟs)

Nar(მთავარი   )(god)

Nar(init)(god)
// clang-format off
EN(tail,
bΟSaΤ,              L)EN(L,
ssΤ,                L)EN(L,
εΟaΟsoΤΟSoΤΟSbΤBΤ,  L)EN(L,
εΟs,                L)EN(L,
მთავარი,      exports);
