#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
debugger,           L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
nar,                L)IN(L,
os_ls,              L)IN(L,
os_new,             L)IN(L,
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
new_soll_psn_a, imports);

#define οb ο[15].cs
#define οs ο[16].Q
#define οp ο[17].Q

Q_t cslen(const char* cs) { Q_t len = 0; while(cs[len]) len++; return len; }

#define U8CP_UM(Name, Mask, Check, Unmask, Ray)                                   \
  S1(Name)(v,    Q_t)( (v & Mask) == Check ? (A(v & Unmask)C(1)) : (A(v)C(Ray)); )
U8CP_UM(um0xxxxxxx, 0x80, 0x00, 0xff, 0)
U8CP_UM(um10xxxxxx, 0xc0, 0x80, 0x3f, 2)
U8CP_UM(um110xxxxx, 0xe0, 0xc0, 0x1f, 0)
U8CP_UM(um1110xxxx, 0xf0, 0xe0, 0x0f, 0)
U8CP_UM(um11110xxx, 0xf8, 0xf0, 0x07, 0)

So(lookahead)      ( A((Q_t)οb[οp]) C(1); )
So(shift)          ( if (οp < οs) οp++, C(1); else C(2); )
So(bin_lsh)        ( R(Q_t, r); R(Q_t, l); A(l << r) C(1); )
So(bin_or)         ( R(Q_t, r); R(Q_t, l); A(l |  r) C(1); )
So(drop_and_gor)( α--, C(0); )

Sargo(lookahead_shift)(lookahead, shift,  and)

Sargo(u8cp_b1)(
  lookahead,      um0xxxxxxx, and, drop_and_gor, or)
Sargo(u8cp_b2)(
  lookahead,      um110xxxxx, and, drop_and_gor, or,  6, bin_lsh, and2, shift, and,
  lookahead, and, um10xxxxxx, and, bin_or, and)
Sargo(u8cp_b3)(
  lookahead,      um1110xxxx, and, drop_and_gor, or, 12, bin_lsh, and2, shift, and,
  lookahead, and, um10xxxxxx, and,                    6, bin_lsh, and2, shift, and, 
  lookahead, and, um10xxxxxx, and, bin_or, and, bin_or, and)
Sargo(u8cp_b4)(
  lookahead,      um11110xxx, and, drop_and_gor, or, 18, bin_lsh, and2, shift, and,
  lookahead, and, um10xxxxxx, and,                   12, bin_lsh, and2, shift, and,
  lookahead, and, um10xxxxxx, and,                    6, bin_lsh, and2, shift, and,
  lookahead, and, um10xxxxxx, and,  bin_or, and, bin_or, and, bin_or, and)
Sargo(u8cp)(u8cp_b1, u8cp_b2, or, u8cp_b3, or, u8cp_b4, or)

S2(soll)(spos,Q_t, oα,Q_t)(Q_t wc = α - oα, cpos = οp + 1; οp = spos, Α(spos, cpos, wc + 2, os_soll_n) O;)
S2(rstr)(spos,Q_t, oα,Q_t)(α = oα, οp = spos, C(0);)
S2(rstt)(spos,Q_t, oα,Q_t)(α = oα, οp = spos, C(2);)
So(la)(
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
N2(is_eq)(cps,p_t*, c,Q_t)( A(cps) C(cps[1].Q == c); )
NargoP(sdrop_and_gor)(os_soll_free, gor, and)

Nargo(id_and_d)(
  la, 'd', is_eq, and2,
    sh, god, and,
    sdrop_and_gor, and3or)
Nargo(id_and_n)(
  la, 'n', is_eq, and2,
    sh, id_and_d, and,
    sdrop_and_gor, and3or)
Nargo(id_and)(
  la, 'a', is_eq, and2,
    sh, id_and_n, and,
    sdrop_and_gor, and3or)

Nargo(id_cp)(
  la, is_in_id_cp_range, and,
    sh,
    drop_and_gor, 011, nar)
Nargo(id)(
  id_cp, id_cp, Μ, and2)

Nargo(οpgod)(οp, god)
Nargo(lash)(la, sh, and)
No(testuni)(
  οb = "and šა🦅α β";//";
  οs = cslen(οb);
  οp = 0;
  print("\ncs:\t%s\nlen:\t%lu\n\n", οb, οs);
  Α(id_and) O;
  //Α(debugger, id_and, and) O;
  //Α(id, lash, Μ, 02, nar) O;
  //Α(lash,
  //  lash, and,
  //  lash, and,
  //  lash, and,
  //  lash, and,
  //  lash, and,
  //  la, and) O;
)

So(set_alfa_zero)( α = 0, C(1); )
Sargo(მთავარი)(
  testuni,
  2, os_wordump,
  1, os_wordump,
  0, os_wordump, 0222, nar,
  set_alfa_zero, 0010, nar)

SargoP(init)(god)

EN(tail,
bin_lsh,            L)EN(L,
bin_or,             L)EN(L,
is_eq,              L)EN(L,
la,                 L)EN(L,
lookahead,          L)EN(L,
lookahead_shift,    L)EN(L,
sdrop_and_gor,      L)EN(L,
sh,                 L)EN(L,
shift,              L)EN(L,
testuni,            L)EN(L,
u8cp,               L)EN(L,
u8cp_b1,            L)EN(L,
u8cp_b2,            L)EN(L,
u8cp_b3,            L)EN(L,
u8cp_b4,            L)EN(L,
um0xxxxxxx,         L)EN(L,
um10xxxxxx,         L)EN(L,
um110xxxxx,         L)EN(L,
um1110xxxx,         L)EN(L,
um11110xxx,         L)EN(L,
Μ,                  L)EN(L,
მთავარი,      exports);
