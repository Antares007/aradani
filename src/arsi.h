#pragma once
#include "oars.h"
N(import);
N(export);
void tail() __attribute__((section(".text.end")));
void head() __attribute__((section(".text.begin")));
N(tail) {}
static N(gor) { C(0); }
n_t Tail;
N(σeτail) {
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
    A5(import, export, tail, σeτail, impexp) O;
}
