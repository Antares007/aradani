#pragma once
#include "exportmacros.h"
#include "oars.h"
#define Mpith(n) void n(void *s, const char *name, void *addr, m_t ie)
Mpith(import);
M(export);
void tail() __attribute__((section(".text.end")));
void head() __attribute__((section(".text.begin")));
M(tail) {}
int cmp(const char *s1, const char *s2) {
  while (*s1 == *s2++)
    if (*s1++ == 0)
      return (0);
  return (*(unsigned char *)s1 - *(unsigned char *)--s2);
}
static int imported = 0;

static void imp_err(void **s) { ((void (*)())s[2])(s[0]); }

#define I(Tail, Name, Addr, Head)                                              \
  Mpith(Head) {                                                                \
    if (cmp(#Name, name) == 0) {                                               \
      Addr = addr;                                                             \
      if ((Tail) == 0)                                                         \
        imported = 1,                                                          \
        export(((void **)s)[0], ((void **)s)[1], ((void **)s)[2]);             \
      else                                                                     \
        ie(s, Tail, imp_err);                                                  \
    } else                                                                     \
      ie(s, Head, imp_err);                                                    \
  }
#define IN(Tail, Name, Head)                                                   \
  n_t Name;                                                                    \
  I(Tail, Name, Name, Head)
M(head) {
  volatile m_t t = tail;
  if (imported)
    export(s, and_ray, or_ray);
  else
    t(&(void *[]){s, and_ray, or_ray}, import, imp_err);
}
#undef NP
#define NP(n)                                                                  \
  N(n##p);                                                                     \
  N(n) {                                                                       \
    print("%p\t%ld\t%ld\t%s\n", σ, α, ρ, #n);                                  \
    n##p(T());                                                                 \
  }                                                                            \
  N(n##p)
