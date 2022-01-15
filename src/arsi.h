#pragma once
#include "exportmacros.h"
#include "oars.h"
N(init);
N(import);
N(export);
N(tail) __attribute__((section(".text.end")));
N(tail) {}
static int cmp(const char *s1, const char *s2);
static int imported = 0;
static N(iε) { α -= 3, imported = 1, A2(init, export) anδ(T()); }
static N(δo_imp) {
  (void)iε;
  R(n_t, thisImp);
  R(void **, iaddr);
  R(const char *, iname);
  R(n_t, prevImp);
  R(n_t, prevExp);
  R(void *, eaddr);
  R(const char *, ename);
  A2(prevExp, (cmp(iname, ename) == 0 ? *iaddr = eaddr, prevImp : thisImp))
  anδ(T());
}
#define I(PrevImp, Name, Addr, ThisImp)                                        \
  N(ThisImp) { A4(PrevImp, #Name, &Addr, ThisImp) δo_imp(T()); }
#define IN(PrevImp, Name, ThisImp)                                             \
  n_t Name;                                                                    \
  I(PrevImp, Name, Name, ThisImp)
#define IF(Tail, IName, Name, Head, Ret, ...)                                  \
  Ret (*Name)(__VA_ARGS__);                                                    \
  I(Tail, IName, Name, Head)
#define IB(PrevImp)                                                            \
  p_t *ο;                                                                      \
  I(PrevImp, ο, ο, import)

N(head) __attribute__((section(".text.begin")));
N(head) {
  (void)δo_imp;
  n_t nar = (imported ? export : (A2(tail, import) anδ));
  nar(T());
}

static int cmp(const char *s1, const char *s2) {
  while (*s1 == *s2++)
    if (*s1++ == 0)
      return (0);
  return (*(unsigned char *)s1 - *(unsigned char *)--s2);
}

#undef NP
#define NP(n)                                                                  \
  N(n##p);                                                                     \
  N(n) {                                                                       \
    print("%p\t%ld\t%ld\t%s\n", σ, α, ρ, #n);                                  \
    n##p(T());                                                                 \
  }                                                                            \
  N(n##p)
