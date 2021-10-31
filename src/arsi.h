#pragma once
#include "oars.h"
void tail() __attribute__((section(".text.end")));
N(tail) {}
static N(got) { C(2); }
#define CAT_(a, b) a##b
#define CAT(a, b) CAT_(a, b)
#define L CAT(e, __LINE__)
#define E(t, name, addr, n)                                                    \
  N(n) { A3(name, addr, t) C(1); }
#define I(t, name, addr, n)                                                    \
  N(n) { A3(name, &addr, t) C(1); }
void head() __attribute__((section(".text.begin")));
N(imports);
N(exports);
N(head) {
  ((void)got);
  R(n_t, impexp);
  A4(imports, exports, tail, impexp) O;
}
