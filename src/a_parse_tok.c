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
and3or3,            L)IN(L,
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
or2,                L)IN(L,
or3,                L)n_t la;I(L,

"lookahead", la,    L)IN(L,
lookahead_set,      L)IN(L,
parse,              L)IN(L,
shift,        imports);

Sarg1(Μ)(n,     n_t)(
  n,
    n, Μ,
    god, and2or)

N2(is_eq    )(cps,p_t*, cp,Q_t)( C(cps[0].Q == cp); )
N2(is_neq   )(cps,p_t*, cp,Q_t)( C(cps[0].Q != cp); )
Narg1(ncp   )(cp,Q_t)(la, cp, is_neq, and2, shift, and)
Narg1(cp    )(cp,Q_t)(la, cp, is_eq,  and2, shift, and)

S2(is_anyof )(cps,p_t*, chars,const char*)( while(*chars) if (cps[0].Q == *chars++) return C(1); C(0);)
Sarg1(anyof )(chars, const char*)(la, chars, is_anyof, and2, shift, and)
//Sarg1(noneof)(chars, const char*)(la, chars, is_anyof, and2, gor, shift, andor)

S3(is_in_range)(cps,p_t*, from,Q_t, to,Q_t)(C(from <= cps[0].Q && cps[0].Q <= to);)
Sarg2(range   )(from,Q_t, to,Q_t)(la, from, to, is_in_range, and3, shift, and)

SoP(reduce)( Q_t a = α; Α(a, os_soll_n) O; )

Sargo(ws_cp     )(" \t", anyof, os_soll_free, and)
Sargo(ws        )(ws_cp, Μ)
Sargo(cprn_     )(')', cp,                      'cprn', reduce, and2)  
Sargo(cprn      )(ws, cprn_, and)
Sargo(oprn_     )('(', cp,                      'oprn', reduce, and2)  
Sargo(oprn      )(ws, oprn_, and)
Sargo(cmm_      )(',', cp,                      'cmm',  reduce, and2)  
Sargo(cmm       )(ws, cmm_, and)
Sargo(smc_      )(';', cp,                      'smc',  reduce, and2)  
Sargo(smc       )(ws, smc_, and)
Sargo(cln_      )(':', cp,                      'cln',  reduce, and2)  
Sargo(cln       )(ws, cln_, and)
Sargo(nl_       )("\n\r", anyof,                'nl',   reduce, and2)  
Sargo(nl        )(ws, nl_, and)
Sargo(id_s_cp   )('a', 'z', range, 'A', 'Z', range, or3)
Sargo(id_cp     )(id_s_cp, '0', '9', range, or3, '_', cp, or2)
Sargo(id_n      )(id_cp, id_n, god, andor)
Sargo(id        )(ws, id_s_cp, and, id_n, and,  'id',   reduce, and2)

#define LHD ο[7].p[3]
So(lookahead )(
  if (LHD.Q == -1) {
    Α(id,
      nl,             or,
      cln,            or,
      cmm,            or,
      oprn,           or,
      cprn,           or,
      smc,            or,
      lookahead_set,  and) O;
  } else A(LHD.p) C(1);
)

Sargo(pos)(ο[7].p[1].Q, god)
Sargo(prn_a)(
  pos, got, and,
  pos, god, and,
  pos, gor, and, 0333, nar)
Narg1(unsoll)(so, p_t*)(so, os_unsoll, so, os_soll_free, and2)
No(drop)(α--, C(1);)
Nargo(lash)(lookahead, drop, and, shift, and)
Sargo(testuni)(
  lash,
  lash, and,
  lash, and,
  //lookahead, shift, and,
  prn_a
)
Sargo(მთავარი)(testuni, "aaa\r.", parse)

SargoP(init)(god)

EN(tail,
lookahead,          L)EN(L, 
lookahead_set,      L)EN(L, 
parse,              L)EN(L, 
prn_a,              L)EN(L, 
shift,              L)EN(L, 
მთავარი,      exports);
