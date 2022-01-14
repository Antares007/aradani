#pragma once
#include "exportmacros.h"
#include "oars.h"

void tail() __attribute__((section(".text.end")));
N(tail) {}

N(init);
N(import);
N(export);

static N(anδ);
static N(noτ);
static N(god) { C(1); }
static int cmp(const char *s1, const char *s2);
static int imported = 0;
static N(iε) { α -= 3, imported = 1, export(T()); }
static N(δo_imp) {
  R(n_t, thisImp);
  R(void **, iaddr);
  R(const char *, iname);
  R(n_t, prevImp);

  R(n_t, export);
  R(void *, eaddr);
  R(const char *, ename);

  A4(export, god, noτ, cmp(iname, ename) ? thisImp : (*iaddr = eaddr, prevImp))
  anδ(T());
}
#define I(PrevImp, Name, Addr, ThisImp)                                        \
  N(ThisImp) { A4(PrevImp, #Name, &Addr, ThisImp) δo_imp(T()); }
#define IN(PrevImp, Name, ThisImp)                                             \
  n_t Name;                                                                    \
  I(PrevImp, Name, Name, ThisImp)
#define IB(PrevImp)                                                            \
  p_t *ο;                                                                      \
  I(PrevImp, ο, ο, import)

void head() __attribute__((section(".text.begin")));
N(head) {
  (void)δo_imp, (void)iε;
  volatile n_t t = tail;
  n_t nar = (imported ? export : (ο[α++].c = t, ο[α++].c = import, anδ));
  nar(T());
}

static N(ρ4ξ2) { ρ += 4, C(2); }
static N(ρ3α1) { ρ += 3, A(ο[ρ++].v) O; }
static N(ρ4ξ1) { ρ += 4, C(1); }
static N(ρ4ξ0) { ρ += 4, C(0); }
static N(anδ) {
  ο[--ρ].c = ο[--α].c, ο[--ρ].v = ρ4ξ2, ο[--ρ].v = ρ3α1, ο[--ρ].v = ρ4ξ0, O;
}
static N(noτ) {
  ο[--ρ].c = ο[--α].c, ο[--ρ].v = ρ3α1, ο[--ρ].v = ρ4ξ1, ο[--ρ].v = ρ4ξ0, O;
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
