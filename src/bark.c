#include "oant.h"
static void dot(OANT) { O; }
static void Got(OANT) { C(2); }
static void God(OANT) { C(1); }
static void Gor(OANT) { C(0); }
static void import(OANT);
static N(da) {
  ο[α - 3].v = Gor;
  ο[α - 2].v = ν[--τ].v;
  ο[α - 1].v = Got;
  ν[τ - 1].c(ο, α - 3, ν, τ - 1);
}
static N(Gor3) { ο[α + 6].c(ο, α + 9, ν, τ); }
static N(Got4) { ο[α + 11].c(ο, α + 12, ν, τ); }
static N(unrollGod3) {
  ν[τ++].v = ο[α + 1].v;
  α += 3;
  ν[τ++].v = ο[α + 1].v;
  α += 3;
  C(1);
}
static N(da3an) {
  ο[α - 3].v = ν[--τ].v;
  ο[α - 12].v = Gor3;

  ο[α - 2].v = ν[--τ].v;
  ο[α - 5].v = ν[--τ].v;
  ο[α - 8].v = ν[--τ].v;
  ο[α - 11].v = unrollGod3;

  ο[α - 10].v = Got4;

  ν[τ - 1].c(ο, α - 12, ν, τ - 1);
}
static int cmp(const char *s1, const char *s2) {
  while (*s1 == *s2++)
    if (*s1++ == 0)
      return (0);
  return (*(unsigned char *)s1 - *(unsigned char *)--s2);
}
N(import_n) {
  RN(const char *, efname);
  (void)efname;
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
  A6(imps, exps, import_n, da, God, da3an) O;
}
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
    A7(exports, imports, tail, impexp, Tail, impexp_n, da) O;
}
N(Tail) __attribute__((section(".text.end")));
N(Tail){};
N(Head) __attribute__((section(".text.begin")));
N(Head) {
  volatile n_t t = Tail;
  A4(impexp, t, dot, da) O;
}
