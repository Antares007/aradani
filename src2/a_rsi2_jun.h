#pragma once
#define L CAT(expimp_, __LINE__)
#define I(Tail, Name, Address, Head)                                           \
  static N(Head) { A(Name, &Address, Tail, σ1) O; }
#define E(Tail, Name, Address, Head)                                           \
  static N(Head) { A(Name, Address, Tail, σ1) O; }

#define IN(Tail, Name, Head)                                                   \
  static n_t Name;                                                             \
  I(Tail, #Name, Name, Head)
#define EN(Tail, Name, Head) E(Tail, #Name, Name, Head)
