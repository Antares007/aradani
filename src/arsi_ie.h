#pragma once
#define E(Ta, Na, Ad, He) S(He) { Α(Na,  Ad, Ta) C(1); }
#define I(Ta, Na, Ad, He) S(He) { Α(Na, &Ad, Ta) C(0); }
#define IBS(Head) IB(πrn)IF(πrn, printf, print, Head, int, const char *, ...)
#define L CAT(expimp_, __LINE__)
#define EN(Tail, Name, Head) E(Tail, #Name, Name, Head)
#define END(Tail, Name, Head)                                                  \
  N(Name);                                                                     \
  EN(Tail, Name, Head)
#define IN(Tail, Name, Head)                                                   \
  static n_t Name;                                                             \
  I(Tail, #Name, Name, Head)
#define IF(Tail, IName, Name, Head, Ret, ...)                                  \
  static Ret (*Name)(__VA_ARGS__);                                             \
  I(Tail, #IName, Name, Head)
#define IFN(Tail, Name, Head, Ret, ...)                                        \
  IF(Tail, Name, Name, Head, Ret, __VA_ARGS__)
