#pragma once
#include "oars2.h"
#include "a_rsi2_jun.h"
static n_t gor, god, got, aradani, import, tail;
static N(imports);
static N(exports);
N(geno_n) {
  tail = R.v;
  A(imports, tail, import, exports, god, 020, aradani) O;
}
N(zia) __attribute__((section(".text.end")));
N(zia){};
N(geno) __attribute__((section(".text.begin")));
N(geno) {
  import  = R.c;
  aradani = R.c;
  gor     = R.c;
  god     = R.c;
  got     = R.c;
  A(got, god, gor, aradani, import, zia, geno_n, 010, aradani) O;
}
