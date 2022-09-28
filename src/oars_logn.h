#pragma once
#include <stdio.h>
#define LOG printf("%s(%lu)\n", __FUNCTION__, α)
/*
*/
#undef N
#define N(Name)                                                                \
  void Name##Nar(OARS);                                                        \
  void Name(OARS) {                                                            \
    LOG;                                                                       \
    Name##Nar(T);                                                              \
  }                                                                            \
  void Name##Nar(OARS)
