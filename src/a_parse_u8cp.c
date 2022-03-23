#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,

and,                L)IN(L,
and2,               L)IN(L,
or,           imports);

SargoP(init)(god)

#define οb ο[7].p[0].cs
#define οp ο[7].p[1].Q
#define οs ο[7].p[2].Q

#define U8CP_UM(Name, Mask, Check, Unmask, Ray)                                   \
  S1(Name)(v, Q_t)((v & Mask)==Check?(A(v & Unmask)C(1)):(A(v)C(Ray));)

U8CP_UM(um0xxxxxxx, 0x80, 0x00, 0xff, 0)
U8CP_UM(um110xxxxx, 0xe0, 0xc0, 0x1f, 0)
U8CP_UM(um1110xxxx, 0xf0, 0xe0, 0x0f, 0)
U8CP_UM(um11110xxx, 0xf8, 0xf0, 0x07, 0)

U8CP_UM(um10xxxxxx, 0xc0, 0x80, 0x3f, 2)

So(lookahead   )(A((Q_t)οb[οp]) C(1); )
So(shift       )(if (οp < οs) οp++, C(1); else C(2);)
So(drop_and_gor)( α--, C(0); )

S2(bin_lsh     )(l,Q_t, r,Q_t)(A(l << r) C(1);)
S2(bin_or      )(l,Q_t, r,Q_t)(A(l |  r) C(1);)

Sargo(u8cp_b1)(
  um0xxxxxxx)
Sargo(u8cp_b2)(
  um110xxxxx,       6, bin_lsh, and2, shift, and, lookahead, and,
  um10xxxxxx, and,     bin_or, and)
Sargo(u8cp_b3)(
  um1110xxxx,      12, bin_lsh, and2, shift, and, lookahead, and,
  um10xxxxxx, and,  6, bin_lsh, and2, shift, and, lookahead, and,
  um10xxxxxx, and,     bin_or, and, bin_or, and)
Sargo(u8cp_b4)(
  um11110xxx,      18, bin_lsh, and2, shift, and, lookahead, and,
  um10xxxxxx, and, 12, bin_lsh, and2, shift, and, lookahead, and,
  um10xxxxxx, and,  6, bin_lsh, and2, shift, and, lookahead, and,
  um10xxxxxx, and,     bin_or, and, bin_or, and, bin_or, and)
Sargo(u8cp)(
  lookahead,
    u8cp_b1, and,
    u8cp_b2, or,
    u8cp_b3, or,
    u8cp_b4, or,
  drop_and_gor, or)

EN(tail,
u8cp,         exports)
