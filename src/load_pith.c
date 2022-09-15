#include "oars.h"
#include "oars_logn.h"
void God(OARS);
void map_pith(OARS);
void import(OARS);
extern n_t Τ[01000];
static int cmp(const char *s1, const char *s2) {
  while (*s1 == *s2++)
    if (*s1++ == 0)
      return (0);
  return (*(unsigned char *)s1 - *(unsigned char *)--s2);
}
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
N(load_pith_n_n) {
  RN(n_t, exp);
  RN(n_t, nar);
  RN(const char *, name);
  printf("%s %p %p\n", name, nar, exp);
  A3(exp, load_pith_n_n, Τ[010]) O;
}
N(load_pith_n) {
  RN(n_t, nar);
  A4(impexp, nar, Τ[0], Τ[010]) O;
}
N(load_pith) { A5(map_pith, load_pith_n, Τ[010], load_pith_n_n, Τ[010]) O; }
