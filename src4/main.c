#include "arsi_ie.h"
#include "oars.h"
#include "oars_logn.h"
#include <stdio.h>

void Got(OARS);
void God(OARS);
void Gor(OARS);
void da(OARS);
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
    A6(iname, iaddr, imps, exps, import_n, da) O;
  else
    *iaddr = eaddr, A3(imps, exps, import) O;
}
N(import) {
  RN(n_t, exps);
  RN(n_t, imps);
  A6(imps, exps, import_n, Τ[010],
           God,                    Τ[031]) O;
}

// clang-format off
                  EN(Got,
God,            L)EN(L,
Gor,            L)EN(L,
Got,      exports);
// clang-format on

N(root) {
  α -= 2;
  A1(exports) C(1);
}
N(impexp) {
  RN(n_t, exports_);
  RN(n_t, impr);
  RN(n_t, tail);
  A5(impr, tail, import, exports_, Τ[010]) O;
}
N(LoadPith_n_n) {
  RN(n_t, exp_next);
  RN(n_t, nar);
  RN(const char *, name);
  printf("%s %p %p\n", name, nar, exp_next);
  A3(exp_next, LoadPith_n_n, da) O;
}
N(LoadPith_n) {
  RN(n_t, nar);
  A5(Τ, impexp, nar, LoadPith_n_n, da) O;
}
N(LoadPith) { A5("src4/a_pith.pith", root, map_pith, LoadPith_n, da) O; }
// clang-format on

N(seven) { A(7) C(1); }
N(add) {
  q_t r = R.q;
  q_t l = R.q;
  A(l + r) C(1);
}
N(CountTo14) { A5(seven, seven, da, add, da) O; }

// clang-format off
N(TestAraDaNi) {
  A12(God, Τ[0],
      Got, Got, Τ[0100],
      God, God, Τ[0010],
      Gor, Gor, Τ[0001], Τ[0333]) O;
}
// clang-format on
N(ray_not) {}
N(ray_and) { printf("%lu\n", σ[--α].q); }
N(ray_oor) {}
N(Setup) {
  ο[--ρ].v = ray_not;
  ο[--ρ].v = ray_and;
  ο[--ρ].v = ray_oor;
  LoadPith(T);
}
int main() {
  p_t ο[0x1000];
  Q_t α = 0;
  p_t σ[0x1000];
  Q_t ρ = sizeof(σ) / sizeof(*σ);
  Setup(T);
  return 0;
}
