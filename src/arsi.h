#pragma once
#include "oars.h"
N(import);
N(export);
#define CAT_(a, b) a##b
#define CAT(a, b) CAT_(a, b)
#define L CAT(e, __LINE__)
#define E(t, name, addr, n)                                                    \
  N(n) { A3(name, addr, t) C(1); }
#define I(t, name, addr, n)                                                    \
  N(n) { A3(name, &addr, t) C(1); }
#define IN(t, name, n)                                                         \
  n_t name;                                                                    \
  I(t, #name, name, n)
void tail() __attribute__((section(".text.end")));
void head() __attribute__((section(".text.begin")));
N(tail) {}
static N(gor) { C(0); }
n_t Tail;
N(setail) {
  R(n_t, addr);
  Tail = addr;
  A(addr) C(1);
}
N(head) {
  ((void)gor), ((void)Tail);

  R(n_t, impexp);

  if (Tail)
    A(export) C(1);
  else
    A5(import, export, tail, setail, impexp) O;
}
