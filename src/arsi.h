#pragma once
#include "oars.h"
#include "arsi_ie.h"
#include "arsi_jun.h"
#define IB(Head)                                                               \
  static int ιmported = 0;                                                     \
  S(exports);                                                                  \
  S(imports);                                                                  \
  S(init);                                                                     \
  S(Head) { ιmported = 1, init(T()); }                                         \
  static int cmp(const char *s1, const char *s2) {                             \
    while (*s1 == *s2++) if (*s1++ == 0) return (0);                           \
    return (*(unsigned char *)s1 - *(unsigned char *)--s2);                    \
  }                                                                            \
  ΑND;ΑNDOR3;                                                                  \
  S(δc) {                                                                      \
    R(n_t, ex);                                                                \
    R(void *, ea);                                                             \
    R(const char *, en);                                                       \
    R(n_t, im);                                                                \
    R(void **, ia);                                                            \
    R(const char *, in);                                                       \
    if (cmp(en, in)) Α(in, ia, im, ex, δc, αnd) O;                             \
    else *ia = ea,   Α(im, exports, ex, δc, αnd, αndor3) O;                    \
  }                                                                            \
  N(tail) __attribute__((section(".text.end")));                               \
  N(tail) {};                                                                  \
  N(head) __attribute__((section(".text.begin")));                             \
  N(head) { ιmported ? exports(T()) : (Α(imports, exports, tail, δc, αnd, αndor3) O); }
