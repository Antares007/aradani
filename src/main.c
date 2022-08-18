#include "a_rsi2_jun.h"
#include "oars2.h"
#include <stdio.h>
#include <stdlib.h>
#define LOG printf("α:%lu ρ:%lu %s\n", α, ρ, __FUNCTION__)
N(got);
N(god);
N(gor);

N(and);
N(and3);
N(notandor);
N(mapfile);

N(one) {
  printf("one\n");
  god(T);
}
// clang-format off
E(got,
"nar1", god,        L)E(L,
"nar2", god,        L)E(L,
"nar3", god,        L)E(L,
"nar4", god,  exports);
// clang-format on

static int cmp(const char *s1, const char *s2) {
  while (*s1 == *s2++)
    if (*s1++ == 0)
      return (0);
  return (*(unsigned char *)s1 - *(unsigned char *)--s2);
}
N(import);
N(import_n) {LOG;
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
  LOG;
  RN(n_t, exps);
  RN(n_t, imps);
  A(imps, exps, import_n, and, and3) O;
}
N(qvemdebare) {
  LOG;
  printf("%d\n", R.v == import);
  printf("%d\n", R.v == notandor);
  printf("%d\n", R.v == gor);
  printf("%d\n", R.v == god);
  printf("%d\n", R.v == got);
  A(exports, god) O;
}

N(Main_nn) { LOG; }
N(Main_n) {
  LOG;
  RN(n_t, pith);
  printf("hello world! %p\n", pith);
  A(got, god, gor, notandor, import, pith, Main_nn, and) O;
}
N(Main) { A("src/a_rsi2.tarsi", qvemdebare, mapfile, Main_n, and) O; }
N(not_ray) { printf("NOT_ray\n"); }
N(and_ray) { printf("AND_ray\n"); }
N(oor_ray) { printf("OOR_ray\n"); }

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
