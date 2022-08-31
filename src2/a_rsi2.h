#pragma once
#include "oars2.h"
#include "a_rsi2_jun.h"
static n_t tail;
static N(imports);
static N(exports);

N(geno_n) {
  tail = R.v;
  A(imports, tail, σ4, exports, σ1, 020, σ3) O;
}
N(zia) __attribute__((section(".text.end")));
N(zia){};
N(geno) __attribute__((section(".text.begin")));
N(geno) {
  A(zia, geno_n, 010, σ3) O;
}
