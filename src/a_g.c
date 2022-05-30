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
N(Ο         ){ VLog; O; }
N(Τnn       ){ VLog; R(p_t*, rhsoll); Α( dot,rhsoll, os_soll_free, and2) O; }
N(Τn        ){ VLog; Α(os_soll_n, Τnn, and) O; }
N(ε         ){ VLog; Α("ε", ps, pnl, and,
                                dot, and,
                                god, and,
                                god, and,
                                god, and) O; }
N(Ξ         ){ VLog; Α(ps, pnl, and, dot, and) O; } 
N(Ϋ         ){ VLog; R(const char*, name); R(n_t, svar); print("\t%s %p\n", name, svar); O; }
N(Τ         ){ Α(1, Τn) O; }

Nar(init)(god)
// clang-format off
EN(tail,
Ξ,                  L)EN(L,
Ο,                  L)EN(L,
Τ,                  L)EN(L,
Ϋ,                  L)EN(L,
ε,            exports);      
