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
and2or,             L)IN(L,
and3,               L)IN(L,
and3or,             L)IN(L,
and4,               L)IN(L,
and5,               L)IN(L,
and6,               L)IN(L,
and7,               L)IN(L,
andor,              L)IN(L,
andor2,             L)IN(L,
andor3,             L)IN(L,
not,                L)IN(L,
not2and,            L)IN(L,
not2and2or2,        L)IN(L,
or,                 L)IN(L,

new_soll_psn,       L)IN(L,
new_soll_psn_a,     L)n_t la;I(L,

"lookahead", la,    L)IN(L,
parse,              L)n_t sh;I(L,
"shift", sh,  imports);

Sarg1(Μ)(n,     n_t)(
  n,
    n, Μ,
    god, and2or)

N2(is_eq    )(cps,p_t*, cp,Q_t)( C(cps[0].Q == cp); )
N2(is_neq   )(cps,p_t*, cp,Q_t)( C(cps[0].Q != cp); )
Narg1(ncp   )(cp,Q_t)(la, cp, is_neq, and2, sh, and)
Narg1(cp    )(cp,Q_t)(la, cp, is_eq,  and2, sh, and)

S2(is_anyof )(cps,p_t*, chars,const char*)( while(*chars) if (cps[0].Q == *chars++) return C(1); C(0);)
Narg1(anyof )(chars, const char*)(la, chars, is_anyof, and2, sh, and)
Narg1(noneof)(chars, const char*)(la, chars, is_anyof, and2, gor, sh, andor)

S3(is_in_range)(cps,    p_t*,
                from,   Q_t,
                to,     Q_t)(C(from <= cps[0].Q && cps[0].Q <= to);)
Narg2(range   )(from,   Q_t,
                to,     Q_t)(la, from, to, is_in_range, and3, sh, and)

Narg1(unsoll)(soll, p_t*)(soll, os_unsoll, soll, os_soll_free, and2)
N1(reduce)(alfa, Q_t)( Q_t wc = α - alfa; Α(wc, os_soll_n) O;)

Nargo(ws_cp)(" \n\r\t", anyof, os_soll_free, and)
Nargo(ws   )(ws_cp, Μ)

Nargo(comma_cp )(',', cp, os_soll_free, and)
Nargo(comma_sep)(ws, comma_cp, and, ws, and)

Nargo(id_cp )('a', 'z', range)
Nargo(id_n )(
  id_cp,  
    id_n,
    god, andor)
Nargo(id)(id_cp, id_n, and, 'id', sα, reduce, and3)

/*
u8cp_b3
  la, ck1110xxxx, sh, um1110xxxx, 12 bin_lsh, 
  la, ck10xxxxxx, sh, um10xxxxxx,  6 bin_lsh, 
  la, ck10xxxxxx, sh, um10xxxxxx,    bin_or and bin_or
sentences:
  arg1 arg2 nara.
  arg1 narB and narc.
  arg1 arg2 nara, arg1 narB and narc.
*/
Nargo(pos)(ο[7].p[1].Q, god)
Sargo(testuni)(
  id,
  ws, and,
  id, and,
  ws, and,
  id, and,
  comma_sep, and,
  "sophie", noneof, and2,
    pos,
    pos, gor, and, andor3)

Sargo(მთავარი)(testuni, "abc x   ; šა🦅სβo", parse)

SargoP(init)(god)

EN(tail,
მთავარი,      exports);
