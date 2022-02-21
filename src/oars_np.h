#pragma once
#define NP_(n, PRN, N)                                                         \
  N(n##p);                                                                     \
  N(n) {                                                                       \
    PRN("%p %s %ld\t%ld\t%s\t:%s\n", σ, (char*)ο[4].v, α, ρ, __FUNCTION__, __FILE__); \
    n##p(T());                                                                 \
  }                                                                            \
  N(n##p)
#ifndef ARSI
#include <stdio.h>
#define NP(n) NP_(n, printf, N)
#define SP(n) NP_(n, printf, S)
#else
#define NP(n) NP_(n, print, N)
#define SP(n) NP_(n, print, S)
#endif
#undef PRN

