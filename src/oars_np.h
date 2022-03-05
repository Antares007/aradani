#pragma once
#include "os/pith_coords.h"
#define NP_(n, PRN, N)                                                         \
  N(n##p);                                                                     \
  N(n) {                                                                       \
    PRN("%p %s % 3ld % 3ld %s:%s\n", σ, ο[Ν].cs, α, ρ, __FUNCTION__,           \
        __FILE__);                                                             \
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
