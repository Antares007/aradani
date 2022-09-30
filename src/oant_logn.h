#pragma once
#include <stdio.h>
#define LOG printf("%s(%lu)\n", __FUNCTION__, τ)
/*
*/
#undef N
#define N(Name)                                                                \
  void Name##Nar(OANT);                                                        \
  void Name(OANT) {                                                            \
    LOG;                                                                       \
    Name##Nar(T);                                                              \
  }                                                                            \
  void Name##Nar(OANT)
