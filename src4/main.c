#include "arsi_ie.h"
#include "oars.h"
#include "oars_logn.h"
#include <stdio.h>

void Got(OARS);
void God(OARS);
void Gor(OARS);
void map_pith(OARS);
extern n_t Τ[01000];

static int cmp(const char *s1, const char *s2) {
  while (*s1 == *s2++)
    if (*s1++ == 0)
      return (0);
  return (*(unsigned char *)s1 - *(unsigned char *)--s2);
}
void import(OARS);
N(import_n) {
  RN(n_t, exps);
  RN(n_t, eaddr);
  RN(const char *, ename);
  RN(n_t, imps);
  RN(n_t *, iaddr);
  RN(const char *, iname);
  if (cmp(iname, ename))
    A6(iname, iaddr, imps, exps, import_n, Τ[010]) O;
  else
    *iaddr = eaddr, A3(imps, exps, import) O;
}
N(import) {
  RN(n_t, exps);
  RN(n_t, imps);
  A6(imps, exps, import_n, Τ[010], God, Τ[031]) O;
}
// clang-format off
N(U){C(1);} N(V){C(1);} N(W){C(1);} N(X){C(1);} N(Y){C(1);} N(Z){C(1);}
                  EN(Got,
God,            L)EN(L,
Gor,            L)EN(L,
Got,            L)EN(L,
U,              L)EN(L,
V,              L)EN(L,
W,              L)EN(L,
X,              L)EN(L,
Y,              L)EN(L,
Z,        exports);
// clang-format on

N(root) { α--, A1(exports) C(1); }
N(impexp_n) {
  RN(n_t, export);
  RN(n_t *, tail);
  RN(n_t, imports);
  RN(n_t, exports);
  *tail = export;
  A4(exports, imports, export, import) O;
}
N(impexp) {
  RN(n_t, Tail);
  RN(n_t *, tail);
  RN(n_t, imports);
  RN(n_t, exports);
  if (*tail)
    A1(exports) C(1);
  else
    A7(exports, imports, tail, impexp, Tail, impexp_n, Τ[010]) O;
}
//  A5(exports, imports, &tail, Tail, impexp) O;
N(LoadPith_n_n) {
  RN(n_t, exp);
  RN(n_t, nar);
  RN(const char *, name);
  printf("%s %p %p\n", name, nar, exp);
  A3(exp, LoadPith_n_n, Τ[010]) O;
}
N(LoadPith_n) {
  RN(n_t, nar);
  A6(impexp, nar, Τ[0], Τ[010], LoadPith_n_n, Τ[010]) O;
}
N(LoadPith) { A5("src4/a_pith2.pith", root, map_pith, LoadPith_n, Τ[010]) O; }
// clang-format on

N(ray_not) {}
N(ray_and) { printf("%lu\n", σ[--α].q); }
N(ray_oor) {}

int main() {
  p_t ο[0x1000];
  Q_t α = 0;
  p_t σ[0x1000];
  Q_t ρ = sizeof(σ) / sizeof(*σ);
  ο[--ρ].v = ray_not;
  ο[--ρ].v = ray_and;
  ο[--ρ].v = ray_oor;
  LoadPith(T);
  return 0;
}
