#pragma once
#include "arsi_ie.h"
static N(ι);
static N(ε);
static n_t ζ;
static N(Gor) { C(0); }

N(Tail) __attribute__((section(".text.end")));
N(Tail){};
N(Head) __attribute__((section(".text.begin")));
N(Head) {
  n_t impexp = R.c;
  A5(ε, ι, &ζ, Tail, impexp) O;
}
