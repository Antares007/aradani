#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
dot,                L)IN(L,
god,                L)IN(L,
os_soll_free,       L)IN(L,
os_soll_n,          L)IN(L,

and,                L)IN(L,
and2,         imports)

#define Var(Name,  ...) N(Name)  { Α(__VA_ARGS__, Name, #Name, Ϋ) O; }
#define VarP(Name, ...) NP(Name) { Α(__VA_ARGS__, Name, #Name, Ϋ) O; }
#define VLog print("V "); PLog

N(ps        ){ R(const char*, str); print("%s", str), C(1); }
N(pnl       ){ print("\n"), C(1); }
N(drop      ){ VLog; α--, C(1); }
N(Ο         ){ VLog; ο[0].c(T()); }
N(ε         ){ VLog; ο[0].c(T()); }
N(Ξ         ){ VLog; ο[1].c(T()); }
N(Ϋ         ){ VLog; ο[2].c(T()); }

N(drop1dot  ){ VLog; α-=1, O; }
N(drop2dot  ){ VLog; α-=2, O; }
NP(coll     ) { R(p_t*, oο); R(n_t, nar); nar(oο, α, ρ, σ); }
Nar(d_pith  )(dot, drop1dot, drop2dot, 3, os_soll_n)
Nar(init)(god)
// clang-format off
EN(tail,
coll,               L)EN(L,
d_pith,             L)EN(L,
Ξ,                  L)EN(L,
Ο,                  L)EN(L,
Ϋ,                  L)EN(L,
ε,            exports);      
