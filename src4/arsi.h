#pragma once
#include "arsi_ie.h"
static N(imports);
static N(exports);

N(Tail) __attribute__((section(".text.end")));
N(Tail){};
N(Head) __attribute__((section(".text.begin")));
N(Head) {
  n_t I = R.c;
  n_t *Τ = R.v;
  A7(Τ, I, Tail, imports, exports, I, Τ[030]) O;
}
static N(Gor) { C(0); }
