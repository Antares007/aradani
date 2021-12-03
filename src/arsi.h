#pragma once
#include "importexportmacros.h"
#include "oars.h"
#undef NP
#define NP(n) N(n##p); N(n) { print("%p\t%ld\t%ld\t%s\n", σ, α, ρ, #n); n##p(T()); } N(n##p)
N(import);
N(export);
void tail() __attribute__((section(".text.end")));
void head() __attribute__((section(".text.begin")));
N(tail) {}
static N(got) { C(2); }
static N(god) { C(1); }
static N(gor) { C(0); }
n_t Tail;
N(σeτail) {
  R(n_t, addr);
  Tail = addr;
  A(addr) C(1);
}
N(head) {
  ((void)gor), ((void)god), ((void)got), ((void)Tail);

  R(n_t, impexp);

  if (Tail)
    A(export) C(1);
  else
    A5(import, export, tail, σeτail, impexp) O;
}
