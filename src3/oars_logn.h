#pragma once
#include <stdio.h>
#define LOG printf("α:%lu ρ:%lu %s\n", α, ρ, __FUNCTION__)
#undef N
#define N(Name)                                                                \
  void Name##fun(OARS);                                                        \
  void Name(OARS) {                                                            \
    LOG;                                                                       \
    Name##fun(T);                                                              \
  }                                                                            \
  void Name##fun(OARS)
