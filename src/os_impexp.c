#include "aradani.h"
int cmp(const char *s1, const char *s2) {
  while (*s1 == *s2++)
    if (*s1++ == 0)
      return (0);
  return (*(unsigned char *)s1 - *(unsigned char *)--s2);
}
static N(god) { C(1); }
static N(impexp_nn) {
  R(n_t, export);
  R(n_t, eaddr);
  R(const char *, ename);
  R(n_t, import);
  R(n_t *, iaddr);
  R(const char *, iname);
  // printf("%s %s\n", iname, ename);
  if (cmp(iname, ename) == 0) {
    *iaddr = eaddr;
    A6(import, god, export, impexp_nn, da, andaaa) O;
  } else {
    A6(iname, iaddr, import, export, impexp_nn, da) O;
  }
}
static N(impexp_n) {
  R(n_t, tailexport);
  R(n_t, export);
  R(n_t, import);
  A10(import, export, god, tailexport, impexp_nn, da, export, god, daa,
      anndaaaaaa)
  O;
}
N(os_impexp) {
  R(n_t, setail);
  R(n_t, tail);
  R(n_t, export);
  R(n_t, import);
  A8(import, export, os_impexp, tail, setail, da, impexp_n, da) O;
}
