#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
debugger,                L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
nar,                L)IN(L,
os_queue,           L)IN(L,
os_wordump,         L)IN(L,

and,                L)IN(L,
and2,               L)IN(L,
or,                 L)IN(L,

lookahead,          L)IN(L,
parser,             L)IN(L,
shift,        imports);

SargoP(init)(god)
#define LOOKAHEAD ο[7].p[3].Q
#define U8CP_CK(Name, Mask, Check) S1(Name)(v, Q_t)(C((v & Mask) == Check);)
#define U8CP_UM(Name, Unmask)      S1(Name)(v, Q_t)(A(v & Unmask) C(1);)
U8CP_CK(ck0xxxxxxx, 0x80, 0x00)
U8CP_CK(ck110xxxxx, 0xe0, 0xc0)
U8CP_CK(ck1110xxxx, 0xf0, 0xe0)
U8CP_CK(ck11110xxx, 0xf8, 0xf0)
U8CP_CK(ck10xxxxxx, 0xc0, 0x80)
U8CP_UM(um0xxxxxxx, 0xff)
U8CP_UM(um110xxxxx, 0x1f)
U8CP_UM(um1110xxxx, 0x0f)
U8CP_UM(um11110xxx, 0x07)
U8CP_UM(um10xxxxxx, 0x3f)

S2(bin_lsh     )(l,Q_t, r,Q_t)(A(l << r) C(1);)
S2(bin_or      )(l,Q_t, r,Q_t)(A(l |  r) C(1);)
Sargo(la)(lookahead)
Sargo(u8cp_b1)(
  la,      ck0xxxxxxx, and, shift, and, um0xxxxxxx, and)
Sargo(u8cp_b2)(
  la,      ck110xxxxx, and, shift, and, um110xxxxx, and,  6, bin_lsh, and2,
  la, and, ck10xxxxxx, and, shift, and, um10xxxxxx, and,     bin_or,  and)
Sargo(u8cp_b3)(
  la,      ck1110xxxx, and, shift, and, um1110xxxx, and, 12, bin_lsh, and2,
  la, and, ck10xxxxxx, and, shift, and, um10xxxxxx, and,  6, bin_lsh, and2,
  la, and, ck10xxxxxx, and, shift, and, um10xxxxxx, and,     bin_or,  and,  bin_or, and)
Sargo(u8cp_b4)(
  la,      ck11110xxx, and, shift, and, um11110xxx, and, 18, bin_lsh, and2,
  la, and, ck10xxxxxx, and, shift, and, um10xxxxxx, and, 12, bin_lsh, and2,
  la, and, ck10xxxxxx, and, shift, and, um10xxxxxx, and,  6, bin_lsh, and2,
  la, and, ck10xxxxxx, and, shift, and, um10xxxxxx, and,     bin_or,  and,  bin_or, and, bin_or, and)
Sargo(u8cp)(u8cp_b1, u8cp_b2, or, u8cp_b3, or, u8cp_b4, or)

Sargo(example)(u8cp,
               u8cp, and,
               u8cp, and,
               u8cp, and,
               u8cp, and,
               u8cp, and,
               u8cp, and)

Q_t cslen(const char* cs) { Q_t len = 0; while(cs[len]) len++; return len; }
Sarg2(parse)(n,     n_t,
             buff,  const char*)(
  n, 2, os_wordump, 1, os_wordump, 0, os_wordump, 0222, nar, 
  buff, cslen(buff), parser, os_queue, and)

Sargo(მთავარი)(example, "ašა🦅ს β", parse)


EN(tail,
u8cp,               L)EN(L, 
მთავარი,      exports)
