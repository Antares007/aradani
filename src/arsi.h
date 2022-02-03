#pragma once
#include "import_export.h"
void tail(αos_t *o) __attribute__((section(".text.end")));
void tail(αos_t *o) {}
void init();
void imports(αos_t *, const char *, void *, void (*)(αos_t *));
void exports(αos_t *);

static int imported = 0;
void iε(αos_t *o, const char *n, void *a, void(e)(αos_t *)) {
  imported = 1, init(), exports(o->s);
}
void head(αos_t *o) __attribute__((section(".text.begin")));
void head(αos_t *o) {
  volatile ε_t t = tail;
  if (imported)
    exports(o);
  else
    t(&(αos_t){.a = imports, .o = o->o, .s = o, .mn = __FILE__});
}

#undef NP
#define NP(n)                                                                  \
  N(n##p);                                                                     \
  N(n) {                                                                       \
    print("%p %p %ld\t%ld\t%s:%s\n", σ, ο, α, ρ, __FILE__, __FUNCTION__);      \
    n##p(T());                                                                 \
  }                                                                            \
  N(n##p)
