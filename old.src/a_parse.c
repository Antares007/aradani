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
os_wordump,         L)IN(L, //
and,                L)IN(L,
and2,               L)IN(L,
and3,               L)IN(L,
and4,               L)IN(L,
and5,               L)IN(L,
and6,               L)IN(L,
and7,               L)IN(L,
andor,              L)IN(L,
andor2,             L)IN(L,
not,                L)IN(L,
not2and,            L)IN(L,
not2and2or2,        L)IN(L,
or,           imports);
// clang-format on

Q_t cslen(const char *cs) {
  Q_t len = 0;
  while (cs[len])
    len++;
  return len;
}

S(um0xxxxxxx) {
  R(Q_t, v);
  (v & 0x80) == 0x00 ? (A(v & 0xff) C(1)) : (A(v) C(0));
}
S(um10xxxxxx) {
  R(Q_t, v);
  (v & 0xc0) == 0x80 ? (A(v & 0x3f) C(1)) : (A(v) C(2));
}
S(um110xxxxx) {
  R(Q_t, v);
  (v & 0xe0) == 0xc0 ? (A(v & 0x1f) C(1)) : (A(v) C(0));
}
S(um1110xxxx) {
  R(Q_t, v);
  (v & 0xf0) == 0xe0 ? (A(v & 0x0f) C(1)) : (A(v) C(0));
}
S(um11110xxx) {
  R(Q_t, v);
  (v & 0xf8) == 0xf0 ? (A(v & 0x07) C(1)) : (A(v) C(0));
}

S(lookahead) { A((Q_t)ο[15].cs[ο[17].Q]) C(1); }
S(shift) {
  if (ο[17].Q < ο[16].Q)
    ο[17].Q++, C(1);
  else
    C(2);
}
S(bin_lsh) {
  R(Q_t, r);
  R(Q_t, l);
  A(l << r) C(1);
}
S(bin_or) {
  R(Q_t, r);
  R(Q_t, l);
  A(l | r) C(1);
}
S(lookahead_shift) { A3(lookahead, shift, and) O; }
S(u8cp_b1) { Α(um0xxxxxxx) O; }
S(u8cp_b2) { Α(um110xxxxx,       6, bin_lsh, and2, lookahead_shift, and,
               um10xxxxxx, and,  bin_or, and) O; }
S(u8cp_b3) { Α(um1110xxxx,      12, bin_lsh, and2, lookahead_shift, and,
               um10xxxxxx, and,  6, bin_lsh, and2, lookahead_shift, and,
               um10xxxxxx, and,  bin_or, and, bin_or, and) O; }
S(u8cp_b4) { Α(um11110xxx,      18, bin_lsh, and2, lookahead_shift, and,
               um10xxxxxx, and, 12, bin_lsh, and2, lookahead_shift, and,
               um10xxxxxx, and,  6, bin_lsh, and2, lookahead_shift, and,
               um10xxxxxx, and, bin_or, and, bin_or, and, bin_or, and) O; }
S(u8cp   ) { Α(lookahead_shift, u8cp_b1, and, u8cp_b2, or, u8cp_b3, or, u8cp_b4, or) O; }

S(Μ      ) { R(n_t, nar); Α(nar, nar, Μ, and2, god, or) O; }
S(set_alfa_zero) { α = 0, C(1); }
S(testuni) {
  ο[15].cs = "aŠა𓅪 α𓅨";
  ο[16].Q = cslen(ο[15].cs);
  ο[17].Q = 0;
  print("\ncs:\t%s\nlen:\t%lu\n\n", ο[15].cs, ο[16].Q);
  Α(u8cp, Μ, god, not, os_wordump, and) O;
}
N(მთავარი) { Α(debugger, testuni, and, set_alfa_zero, and) O; }
SP(init) { Α(god) O; }
// clang-format off
EN(tail,
bin_lsh,            L)EN(L,
bin_or,             L)EN(L,
lookahead,          L)EN(L,
lookahead_shift,    L)EN(L,
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
