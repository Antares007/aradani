#include "oant.h"
static void dot(OANT) { O; }
static void God(OANT) { C(1); }
static void import(OANT);
static int cmp(const char *s1, const char *s2) {
  while (*s1 == *s2++)
    if (*s1++ == 0)
      return (0);
  return (*(unsigned char *)s1 - *(unsigned char *)--s2);
}
static N(import_n) {
  RN(const char *, efname);
  (void)efname;
  RN(n_t, exps);
  RN(n_t, eaddr);
  RN(const char *, ename);
  RN(n_t, imps);
  RN(n_t *, iaddr);
  RN(const char *, iname);
  if (cmp(iname, ename))
    A6(iname, iaddr, imps, exps, import_n, ψ[010].c) O;
  else
    *iaddr = eaddr, A3(imps, exps, import) O;
}
static N(import) {
  RN(n_t, exps);
  RN(n_t, imps);
  A6(imps, exps, import_n, ψ[010].c, God, ψ[031].c) O;
}
static N(impexp_n) {
  RN(n_t, export);
  RN(n_t *, ζ);
  RN(n_t, ι);
  RN(n_t, ε);
  *ζ = export;
  A4(ε, ι, export, import) O;
}
static N(impexp) {
  RN(n_t, Tail);
  RN(n_t *, ζ);
  RN(n_t, ι);
  RN(n_t, ε);
  if (*ζ)
    A1(ε) C(1);
  else
    A7(ε, ι, ζ, impexp, Tail, impexp_n, ψ[010].c) O;
}
N(run) {
  τ -= 2;
  RN(n_t, nar);
  τ--;
  nar(T);
}
N(Tail) __attribute__((section(".text.end")));
N(Tail){};
N(Head) __attribute__((section(".text.begin")));
N(Head) {
  volatile n_t t = Tail;
  A6(impexp, t, dot, ψ[010].c, run, ψ[010].c) O;
}
