#pragma once
#include "import_export.h"
#define EB(Imports, Exports, Tail)                                             \
  void Exports(αos_t *);                                                       \
  void Tail(αos_t *o) __attribute__((section(".text.end")));                   \
  void Tail(αos_t *o) {}                                                       \
  void CAT(Head, Tail)(αos_t * o) __attribute__((section(".text.begin")));     \
  void CAT(Head, Tail)(αos_t * o) {                                            \
    volatile ε_t t = Tail;                                                     \
    if (imported)                                                              \
      Exports(o);                                                              \
    else                                                                       \
      t(&(αos_t){                                                              \
          .a = Imports, .o = o->o, .s = o, .mn = __FILE__, .d = Exports});     \
  }
#define IB(Init, Head)                                                         \
  static int imported = 0;                                                     \
  void Init();                                                                 \
  void Head(αos_t *o, const char *n, void *a, void(e)(αos_t *)) {              \
    imported = 1, Init(o->s), ((ε_t)o->d)(o->s);                               \
  }
#undef NP
#define NP(n)                                                                  \
  N(n##p);                                                                     \
  N(n) {                                                                       \
    print("%p %p %ld\t%ld\t%s:%s\n", σ, ο, α, ρ, __FILE__, __FUNCTION__);      \
    n##p(T());                                                                 \
  }                                                                            \
  N(n##p)
