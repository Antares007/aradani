#pragma once
// clang-format off
#include "os/pith_coords.h"
#define FFF(σ) (ο[Φ].v ? (((Q_t)σ - ο[Φ].p[Φ].p[Φ].Q) >> 12) : 0)
#define PLog_(PRN)                                                             \
  PRN("ο%02lx %3ld %3ld σ%02lx %s:%s\n",                                       \
      FFF(ο), α, ρ,                                 \
      FFF(σ), __FUNCTION__, __FILE__)
#define S(Name) static N(Name)
#define NP(Name) N(Name##_p);N(Name){PLog;Name##_p(T());}N(Name##_p)
#define SP(Name) S(Name##_p);S(Name){PLog;Name##_p(T());}S(Name##_p)
#ifndef ARSI
#include <stdio.h>
#define PLog PLog_(printf)
#else
#define PLog PLog_(print)
#endif
