#pragma once
#define L CAT(expimp_, __LINE__)
#define E(Tail, Name, Addr, Head)                                              \
  N(Head) { A3(#Name, Addr, Tail) C(1); }
#define I(Tail, Name, Addr, Head)                                              \
  N(Head) { A3(#Name, &Addr, Tail) C(1); }
#define IN(Tail, Name, Head)                                                   \
  n_t Name;                                                                    \
  I(Tail, Name, Name, Head)
#define EN(Tail, Name, Head) E(Tail, Name, Name, Head)
