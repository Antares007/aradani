#pragma once
#include "os/pith_coords.h"
#define PLog_(PRN)                                                             \
  PRN("ο:%p σ:%3lx α:%3ld ρ:%3ld\t%s:%s\n", ο, ((Q_t)σ >> 12) & (Q_t)0xFFF, α, \
      ρ, __FUNCTION__, __FILE__)
#ifndef ARSI
#include <stdio.h>
#define PLog PLog_(printf)
#else
#define PLog PLog_(print)
#endif
