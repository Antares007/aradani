#pragma once
#include "a_rsi2_jun.h"
#include "oars.h"
static n_t tail;
static N(gor) { C(0); }
static N(imports);
static N(exports);

N(zia) __attribute__((section(".text.end")));
N(zia){};
N(geno) __attribute__((section(".text.begin")));
N(geno) {
  n_t impexp = R.c;
  (void)gor;
  A5(imports, exports, &tail, zia, impexp) O;
}
