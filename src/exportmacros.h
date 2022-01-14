#pragma once
#define L CAT(expimp_, __LINE__)
#define E(Tail, Name, Addr, Head)                                              \
  N(Head) { A3(#Name, Addr, Tail) C(1); }
#define EN(Tail, Name, Head) E(Tail, Name, Name, Head)
#define FEN(Tail, Name, Head)                                                  \
  N(Name);                                                                     \
  EN(Tail, Name, Head)
#define EB(Tail) EN(Tail, ο, export)
