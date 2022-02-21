#pragma once
#include "oars.h"
#define IB(Head)                                                               \
  static int imported = 0;                                                     \
  S(exports);                                                                  \
  S(imports);                                                                  \
  S(init);                                                                     \
  S(Head) { imported = 1, init(T()); }                                         \
  S(αnd)    { A(0010) ο[5].c(T()); }                                           \
  S(αndor3) { A(0013) ο[5].c(T()); }                                           \
  static int cmp(const char *s1, const char *s2) {                             \
    while (*s1 == *s2++) if (*s1++ == 0) return (0);                           \
    return (*(unsigned char *)s1 - *(unsigned char *)--s2);                    \
  }                                                                            \
  S(dc) {                                                                      \
    R(n_t, ex);                                                                \
    R(void *, ea);                                                             \
    R(const char *, en);                                                       \
    R(n_t, im);                                                                \
    R(void **, ia);                                                            \
    R(const char *, in);                                                       \
    if (cmp(en, in)) Α(in, ia, im, ex, dc, αnd) O;                             \
    else *ia = ea,   Α(im, exports, ex, dc, αnd, αndor3) O;                    \
  }                                                                            \
  N(tail) __attribute__((section(".text.end")));                               \
  N(tail) {};                                                                  \
  N(head) __attribute__((section(".text.begin")));                             \
  N(head) { imported ? exports(T()) : (Α(imports, exports, tail, dc, αnd, αndor3) O); }
#define E(Ta, Na, Ad, He) S(He) { Α(Na,  Ad, Ta) C(1); }
#define I(Ta, Na, Ad, He) S(He) { Α(Na, &Ad, Ta) C(0); }
#define IBS(Head) IB(iff)IF(iff, printf, print, Head, int, const char *, ...)

#define L CAT(expimp_, __LINE__)
#define EN(Tail, Name, Head) E(Tail, #Name, Name, Head)
#define IN(Tail, Name, Head)                                                   \
  static n_t Name;                                                             \
  I(Tail, #Name, Name, Head)
#define IF(Tail, IName, Name, Head, Ret, ...)                                  \
  static Ret (*Name)(__VA_ARGS__);                                             \
  I(Tail, #IName, Name, Head)
#define IFN(Tail, Name, Head, Ret, ...)                                        \
  IF(Tail, Name, Name, Head, Ret, __VA_ARGS__)
