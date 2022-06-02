#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
dot,                L)IN(L,
god,                L)IN(L,

os_soll_n,          L)IN(L,
os_wordump,         L)IN(L,

and,                L)IN(L,

coll,               L)IN(L,
d_pith,             L)IN(L,
Ξ,                  L)IN(L,
Ο,                  L)IN(L,
Ϋ,                  L)IN(L,
ε,            imports);      

#define Var(Name,  ...)  N(Name) { Α(__VA_ARGS__, Name, #Name) ο[2].c(T()); }
#define VLog print("V "); PLog
Var(o, "o", ο[1].v)
Var(b, "b", ο[1].v)
Var(a, "a", ο[1].v)
Var(s, "s", ο[1].v)
Var(x, "x", ο[1].v)
Var(Sa,     ο[0].v,
            ο[0].v,  b,
            ο[0].v,  b, a, b,
            ο[0].v,  Sa, a,
            ο[0].v,  Sa, a, a, x,
            ο[0].v,  Sa, b)
Var(εΟs,    ο[0].c,
            ο[0].c, s)
Var(ss, s, s)

N(pgod      ){ VLog; print("---->%lu\n", ο[Ǎ].Q), C(1); }
Nar(example )(pgod, εΟs, d_pith, coll, and)

Nar(მთავარი   )(example)

Nar(init)(god)
// clang-format off
EN(tail,
ss,                 L)EN(L,
εΟs,                L)EN(L,
მთავარი,      exports);
