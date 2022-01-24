#pragma once
#include "oars.h"
#include "gorgodandgot.h"
#define I(PrevImp, Name, Addr, ThisImp)                                        \
  N(ThisImp) { A4(PrevImp, Name, &Addr, ThisImp) δo_imp(T()); }
#define IN(PrevImp, Name, ThisImp)                                             \
  n_t Name;                                                                    \
  I(PrevImp, #Name, Name, ThisImp)
#define IF(Tail, IName, Name, Head, Ret, ...)                                  \
  Ret (*Name)(__VA_ARGS__);                                                    \
  I(Tail, #IName, Name, Head)
#define IB(PrevImp)                                                            \
  p_t *ο;                                                                      \
  I(PrevImp, "ο", ο, imports)

static int cmp(const char *s1, const char *s2);
static N(δo_imp) {
  R(n_t, thisImp);
  R(void **, iaddr);
  R(const char *, iname);
  R(n_t, prevImp);
  R(n_t, prevExp);
  R(void *, eaddr);
  R(const char *, ename);
  n_t cont = cmp(iname, ename) == 0 ? *iaddr = eaddr, prevImp : thisImp;
  A2(prevExp, cont)
  anδ(T());
}
static int cmp(const char *s1, const char *s2) {
  (void)δo_imp;
  while (*s1 == *s2++)
    if (*s1++ == 0)
      return (0);
  return (*(unsigned char *)s1 - *(unsigned char *)--s2);
}
#define L CAT(expimp_, __LINE__)
#define E(Tail, Name, Addr, Head)                                              \
  N(Head) { A3(Name, Addr, Tail) C(1); }
#define EN(Tail, Name, Head) E(Tail, #Name, Name, Head)
#define FEN(Tail, Name, Head)                                                  \
  N(Name);                                                                     \
  EN(Tail, Name, Head)
#define EB(Tail) EN(Tail, ο, exports)
