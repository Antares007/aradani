#pragma once
// clang-format off
#include "os/pith_coords.h"
#define PLog_(PRN)                                                             \
  PRN("ο%02lx %3ld %3ld σ%02lx %s:%s\n",                                       \
      ((Q_t)ο - ο[Φ].p[Φ].p[Φ].Q) >> 12, α, ρ,                                 \
      ((Q_t)σ - ο[Φ].p[Φ].p[Φ].Q) >> 12, __FUNCTION__, __FILE__)
#ifndef ARSI
#include <stdio.h>
#define PLog PLog_(printf)
#else
#define PLog PLog_(print)
#endif
