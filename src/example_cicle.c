#include "arsi.h"
typedef int (*printf_t)(const char *, ...);
// clang-format off
IN(gor,
da,                    L)IN(L,
da2,                   L)IN(L,
os_new,                L)IN(L,
os_next,               L)IN(L,
os_queue,              L)int(*print)(const char*, ...);I(L,
printf, print,         L)IN(L,
debugger,         import);
// clang-format on

static N(so0) {
  R(p_t *, oσ);
  print("so0\n");
  A7(σ, gor, oσ, 3, os_queue, os_next, da) O;
}
static N(so1) {
  R(p_t *, oσ);
  R(Q_t, c);
  if (c % 100000000 == 0)
    print("so1 %ld\n", c);
  A8(c + 1, σ, god, oσ, 3, os_queue, os_next, da) O;
}
static N(so2) { print("so2\n"); }
static N(so) { A6(so0, so1, so2, 64, 0, os_new) O; }
static N(si0) {
  R(p_t *, oσ);
  print("si0\n");
  A7(σ, god, oσ, 3, os_queue, os_next, da) O;
}
static N(si1) {
  R(p_t *, oσ);
  R(Q_t, c);
  if (c % 100000000 == 1)
    print("si1 %ld\n", c);
  A8(c + 1, σ, god, oσ, 3, os_queue, os_next, da) O;
}
static N(si2) { print("si2\n"); }
static N(si) { A6(si0, si1, si2, 64, 0, os_new) O; }
N(მთავარი) { 
  print("hey\n");
  A8(0, si, gor, so, da2, 3, os_queue, da2) O; 
}

// clang-format off
EN(Tail,
მთავარი,         export);
