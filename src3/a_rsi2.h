#pragma once
#include "oars.h"
#include "a_rsi2_jun.h"
static n_t tail;
static N(imports);
static N(exports);
static N(gor) { C(0); }
N(zia) __attribute__((section(".text.end")));
N(zia){};
N(geno) __attribute__((section(".text.begin")));
N(geno) {
  n_t impexp = R.c;
  A5(imports, exports, &tail, zia, impexp) O;
}
