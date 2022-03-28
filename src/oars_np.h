#pragma once
#include "os/pith_coords.h"
#define NP_(n, PRN, N)                                                         \
  N(n##p);                                                                     \
  N(n) {                                                                       \
    PRN("%3lx %ld\t%3ld %3ld\t%s:%s\n", ((Q_t)σ >> 12) & (Q_t)0xFFF, ο[Ι].Q,   \
        α, ρ, __FUNCTION__, __FILE__);                                         \
    n##p(T());                                                                 \
  }                                                                            \
  N(n##p)
#define PLog_(PRN)                                                             \
  PRN("%3lx %3ld %3ld %3ld\t%s:%s\n", ((Q_t)σ >> 12) & (Q_t)0xFFF, ο[Ι].Q, α,  \
      ρ, __FUNCTION__, __FILE__);
#ifndef ARSI
#include <stdio.h>
#define PLog PLog_(printf)
#define NP(n) NP_(n, printf, N)
#define SP(n) NP_(n, printf, S)
#else
#define PLog PLog_(print)
#define NP(n) NP_(n, print, N)
#define SP(n) NP_(n, print, S)
#endif
