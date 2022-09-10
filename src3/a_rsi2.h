#pragma once
#include "a_rsi2_jun.h"
// clang-format off
#define L CAT(expimp_, __LINE__)
#define I( Tail, Name, Address, Head) static N(Head) { A(Name)A(&Address)A(Tail) C(1); }
#define E( Tail, Name, Address, Head) static N(Head) { A(Name)A( Address)A(Tail) C(0); }
#define IN(Tail, Name,          Head) static n_t Name; I(Tail, #Name, Name, Head)
#define EN(Tail, Name,          Head)           E(Tail, #Name, Name, Head)
#include "oars.h"
// clang-format on
static N(imports);
static N(exports);
N(Tail) __attribute__((section(".text.end")));
N(Tail) { C(2); };
N(Head) __attribute__((section(".text.begin")));
N(Head) { (void)imports,(void)exports,A(imports)A(Tail) C(1); }
