#pragma once
#include <stdio.h>
#define LOG printf("α:%lu ρ:%lu %s\n", α, ρ, __FUNCTION__)
#undef N
#define N(Name)                                                                \
  void Name##Nar(OARS);                                                        \
  void Name(OARS) {                                                            \
    LOG;                                                                       \
    Name##Nar(T);                                                              \
  }                                                                            \
  void Name##Nar(OARS)
