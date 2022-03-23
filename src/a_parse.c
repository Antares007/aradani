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
new_soll_psn_a,     L)IN(L,

u8cp,         imports);

#define οb ο[7].p[0].cs
#define οp ο[7].p[1].Q
#define οs ο[7].p[2].Q

S2(soll)(spos,Q_t, oα,Q_t)(Q_t wc = α - oα, cpos = οp + 1; οp = spos, Α(spos, cpos, wc + 2, os_soll_n) O;)
S2(rstr)(spos,Q_t, oα,Q_t)(α = oα, οp = spos, C(0);)
S2(rstt)(spos,Q_t, oα,Q_t)(α = oα, οp = spos, C(2);)
So(lacp)(
  Q_t a = α;
  Α('u8cp', u8cp,
    οp, a, rstt, 
    οp, a, soll,
    οp, a, rstr, 0333, nar) O;
)
S1(sh)(soll, p_t*)(
  Q_t npos = soll[soll[-1].Q - 1].Q;
  if (npos < οs)
    οp = npos, A(soll) C(1);
  else
    A(soll) C(2);
)
N1(unsh)(soll, p_t*)(
  Q_t opos = soll[soll[-1].Q - 2].Q;
  οp = opos, Α(soll, os_soll_free) O;
)
Sarg1(Μ)(n,     n_t)(n, n, Μ, and2)

S1(is_in_id_cp_range)(cp,     p_t*)(
  A(cp) C('a' <= cp[1].Q && cp[1].Q <= 'z');)
N2(is_eq )(cps,p_t*, c,Q_t)( A(cps) C(cps[1].Q == c); )
N2(is_neq)(cps,p_t*, c,Q_t)( A(cps) C(cps[1].Q != c); )
NargoP(sdrop_and_gor)(os_soll_free, gor, and)

Sargo(id_and_d)(
  lacp, 'd', is_eq, and2,
    sh, god, and,
    sdrop_and_gor, and3or)
Sargo(id_and_n)(
  lacp, 'n', is_eq, and2,
    sh, id_and_d, and,
    sdrop_and_gor, and3or);
Nargo(id_and)(
  lacp, 'a', is_eq, and2,
    sh, id_and_n, and,
    sdrop_and_gor, and3or);

Narg1(unsoll_free_dot)(soll, p_t*)(
  soll, os_unsoll,
  soll, os_soll_free, and2,
  dot, and)

So(drop_and_gor)( α--, C(0); )
Nargo(id_cp)(
  lacp, is_in_id_cp_range, and,
    sh,
    drop_and_gor, 011, nar)
Nargo(id)(
  id_cp, id_cp, Μ, and2)

Nargo(οpgod)(οp, god)
Nargo(lash)(lacp, sh, and)

Q_t cslen(const char* cs) { Q_t len = 0; while(cs[len]) len++; return len; }
Narg1(parser)(input, const char*)(
  got, 1, os_soll_n,
  god, 1, os_soll_a,
  gor, 1, os_soll_a,
  input, 0, cslen(input), 3, os_soll_a,
  ο, 512, "p", new_soll_psn, and4)

No(prr)(
  print("%s %lu %lu\n", ο[7].p[0].cs, ο[7].p[1].Q, ο[7].p[2].Q);
  C(1);
)
No(testuni)(
  //Α(id_and) O;
  //Α(debugger, id_and, and) O;
  //Α(id, lash, Μ, 02, nar) O;
  Α(lash,
    lash, and,
    lash, and,
    lash, and,
    lash, and,
    lash, and,
    lacp, and) O;
)

So(set_alfa_zero)( α = 0, C(1); )
Sargo(მთავარი)(
  prr,
  testuni, and,
  2, os_wordump, 1, os_wordump, 0, os_wordump, 0222, nar,
  set_alfa_zero, and,
  "ašა🦅α β", parser, os_queue, and)

SargoP(init)(god)

EN(tail,
is_eq,              L)EN(L,
lacp,               L)EN(L,
sdrop_and_gor,      L)EN(L,
sh,                 L)EN(L,
testuni,            L)EN(L,
Μ,                  L)EN(L,
მთავარი,      exports);
