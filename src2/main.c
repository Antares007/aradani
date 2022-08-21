#include "a_rsi2_jun.h"
#include "oars2.h"
#include <stdio.h>
#include <stdlib.h>
#define LOG printf("α:%lu ρ:%lu %s\n", α, ρ, __FUNCTION__)
N(got);
N(god);
N(gor);

N(and);
N(and3or);
N(notandor);
N(mapfile);

N(one) {
  printf("one\n");
  god(T);
}
// clang-format off
E(got,
"nar1", one,        L)E(L,
"nar2", one,        L)E(L,
"nar3", one,        L)E(L,
"nar4", one,  exports);
// clang-format on

static int cmp(const char *s1, const char *s2) {
  while (*s1 == *s2++)
    if (*s1++ == 0)
      return (0);
  return (*(unsigned char *)s1 - *(unsigned char *)--s2);
}
N(import);
N(import_n) {
  RN(n_t, exps);
  RN(n_t, eaddr);
  RN(const char *, ename);
  RN(n_t, imps);
  RN(n_t *, iaddr);
  RN(const char *, iname);
  if (cmp(iname, ename))
    A(iname, iaddr, imps, exps, import_n, and) O;
  else
    *iaddr = eaddr, A(imps, exps, import) O;
}
N(import) {
  RN(n_t, exps);
  RN(n_t, imps);
  A(imps, exps, import_n, and, god, and3or) O;
}
N(qvemdebare) { A(exports, god) O; }
N(Main_nnn) {
  (void)R;
  RN(n_t, addr);
  (void)R;
  A(addr) O;
}
N(Main_nn) { A(Main_nnn, and) O; }
N(Main_n) {
  RN(n_t, pith);
  A(got, god, gor, notandor, import, pith, Main_nn, and) O;
}
N(MM) {
  A(mapfile, Main_n, and) O;
}
N(Main) { A("src2/a_rsi3.tarsi", qvemdebare, MM) O; }
N(not_ray) {LOG; printf("\n"); }
N(and_ray) {LOG; printf("%lu\n", R.Q); }
N(oor_ray) {LOG; printf("\n"); }

int main() {
  p_t σ[512];
  p_t ο[512];
  Q_t α = 0;
  Q_t ρ = sizeof(ο) / sizeof(*ο);
  ο[--ρ].c = oor_ray;
  ο[--ρ].c = and_ray;
  ο[--ρ].c = not_ray;
  ο[--ρ].Q = 0111;
  Main(T);
  return 9;
}
