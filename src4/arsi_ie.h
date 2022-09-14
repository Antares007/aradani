#pragma once
#include "oars.h"
#define L CAT(expimp_, __LINE__)
#define I(Tail, Name, Address, Head)                                           \
  static N(Head) { A3(Name, &Address, Tail) C(1); }
#define E(Tail, Name, Address, Head)                                           \
  static N(Head) { A3(Name, Address, Tail) C(1); }
#define IN(Tail, Name, Head)                                                   \
  static n_t Name;                                                             \
  I(Tail, #Name, Name, Head)
#define IO(Tail, Name, Head)                                                   \
  static n_t inner_##Name;                                                             \
  I(Tail, #Name, inner_##Name, Head)
#define EN(Tail, Name, Head) E(Tail, #Name, Name, Head)
