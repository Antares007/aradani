#pragma once
#include "arsi_ie.h"
static N(imports);
static N(exports);
static n_t tail;
static N(Gor) { C(0); }

N(Tail) __attribute__((section(".text.end")));
N(Tail){};
N(Head) __attribute__((section(".text.begin")));
N(Head) {
  n_t impexp = R.c;
  A5(exports, imports, &tail, Tail, impexp) O;
}
