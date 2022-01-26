#include "arsi.h"
// clang-format off
IF(iε,
printf, print,              L, int, const char*, ...)IN(L,
//
and,                        L)IN(L,
and2,                       L)IN(L,
notand,               imports);
// clang-format on

N(os_ls_n) {
  R(n_t, export);
  R(void *, addr);
  R(const char *, name);
  (void)addr;
  print("%s\t%p\n", name, addr);
  A4(export, god, os_ls_n, notand) O;
}
N(os_ls) {
  R(n_t, exports);
  A3(exports, os_ls_n, and) O;
}

N(init) { C(1); }

// clang-format off
EN(tail,
os_ls,              exports);
