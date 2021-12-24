#include "exportmacros.h"
#include "oars.h"
#define END(Tail, Name, Head)                                                  \
  N(Name);                                                                     \
  EN(Tail, Name, Head)

// clang-format off
#undef L
#define L CAT(expimp_2_, __LINE__)
static void m_gor(void *s, void(a)(), void(o)()) { o(s); }
#include <stdio.h>
#include <stdlib.h>
E(m_gor,
free, free,                  L)E(L,
malloc, malloc,              L)E(L,
printf, printf,     os_exports);
