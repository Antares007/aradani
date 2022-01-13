#pragma once
#include "exportmacros.h"
#include "oars.h"

void init();

N(import);
N(export);

void tail() __attribute__((section(".text.end")));
N(tail) {}

static int cmp(const char *s1, const char *s2) {
  while (*s1 == *s2++)
    if (*s1++ == 0)
      return (0);
  return (*(unsigned char *)s1 - *(unsigned char *)--s2);
}
static int imported = 0;

static N(δ2) { ρ += 4, C(2); }
static N(δ1) { ρ += 3, A(ο[ρ++].v) O; }
static N(δ0) { ρ += 4, C(0); }
static N(anδ) {
  ο[--ρ].c = ο[--α].c, ο[--ρ].v = δ2, ο[--ρ].v = δ1, ο[--ρ].v = δ0, O;
}
N(do_imp) {
  R(n_t, ThisImport);
  R(void **, ImportAddress);
  R(const char *, ImportName);
  R(n_t, NextImport);
  R(n_t, ie);
  R(void *, addr);
  R(const char *, name);
  if (cmp(ImportName, name) == 0) {
    *ImportAddress = addr;
    if (NextImport == 0) {
      imported = 1;
      init();
      A(export) O;
    } else
      A3(ie, NextImport, anδ) O;
  } else
    A3(ie, ThisImport, anδ) O;
}
#define I(NextImport, ImportName, ImportAddress, ThisImport)                   \
  N(ThisImport) {                                                              \
    A5(NextImport, #ImportName, &ImportAddress, ThisImport, do_imp) O;         \
  }
#define IN(NextImport, ImportName, ThisImport)                                 \
  n_t ImportName;                                                              \
  I(NextImport, ImportName, ImportName, ThisImport)
#define IO(Tail)                                                               \
  p_t *ο;                                                                      \
  I(Tail, ο, ο, import)

void head() __attribute__((section(".text.begin")));
N(head) {
  volatile n_t t = tail;
  imported ? export(T()) : (A3(t, import, anδ) O);
}

#undef NP
#define NP(n)                                                                  \
  N(n##p);                                                                     \
  N(n) {                                                                       \
    print("%p\t%ld\t%ld\t%s\n", σ, α, ρ, #n);                                  \
    n##p(T());                                                                 \
  }                                                                            \
  N(n##p)
