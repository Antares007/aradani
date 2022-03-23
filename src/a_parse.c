#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
debugger,           L)IN(L,
dot,                L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
nar,                L)IN(L,
os_ls,              L)IN(L,
os_new,             L)IN(L,
os_queue,           L)IN(L,
os_soll_a,          L)IN(L,
os_soll_free,       L)IN(L,
os_soll_n,          L)IN(L,
os_unsoll,          L)IN(L,
os_wordump,         L)IN(L,

and,                L)IN(L,
and2,               L)IN(L,
and3,               L)IN(L,
and3or,             L)IN(L,
and4,               L)IN(L,
and5,               L)IN(L,
and6,               L)IN(L,
and7,               L)IN(L,
andor,              L)IN(L,
andor2,             L)IN(L,
not,                L)IN(L,
not2and,            L)IN(L,
not2and2or2,        L)IN(L,
or,                 L)IN(L,

new_soll_psn,       L)IN(L,
new_soll_psn_a,     L)n_t la;I(L,

"lookahead", la,    L)IN(L,
parse,              L)n_t sh;I(L,
"shift", sh,  imports);

Sarg1(Μ)(n,     n_t)(n, n, Μ, and2)

N2(is_eq )(cps,p_t*, c,Q_t)( A(cps) C(cps[1].Q == c); )
N2(is_neq)(cps,p_t*, c,Q_t)( A(cps) C(cps[1].Q != c); )

Narg1(unsoll_free_dot)(soll, p_t*)(
  soll, os_unsoll,
  soll, os_soll_free, and2,
  dot, and)


S1(is_in_id_cp_range)(cps, p_t*)( C('a' <= cps[0].Q && cps[0].Q <= 'z'); )
Nargo(id_cp)(la, is_in_id_cp_range, and, sh, and)
Nargo(id)(id_cp, id_cp, Μ, and2)

Sargo(testuni)(debugger, id, and)
Sargo(მთავარი)(testuni, "abc šა🦅სβo", parse)

SargoP(init)(god)

EN(tail,
მთავარი,      exports);
