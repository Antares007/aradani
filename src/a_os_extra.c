#include "arsi.h"
// clang-format off
IF(iε,
printf, print,              L, int, const char*, ...)IN(L,
//
and,                        L)IN(L,
and2,                       L)IN(L,
notand,               imports);

N(os_ls) {
  R(n_t, export);
  R(void*, addr);
  R(const char*, name);
  (void)addr;
  print("%s\t%p\n", name, addr);
  A4(export, god, os_ls, notand) O;
}

N(init) { C(1); }

EN(tail,
os_ls,              exports);
