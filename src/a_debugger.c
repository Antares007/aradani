#include "arsi.h"
// clang-format off
IN(iε,    
and,                                     L)IN(L,
and2,                                    L)IN(L,
notand,                                  L)IN(L,
notand2,                                 L)IN(L,
or,                                      L)IN(L,
//
la_stdin,                                L)IF(L,
printf, print,                     imports, int, const char*, ...);
// clang-format on

typedef struct {
  n_t nargo;
  const char *name;
} nargoname_t;
#define MNN 2048
nargoname_t nargonames[MNN];
static void nop() {}
void fillnames_pith(int i, const char *name, void *nargo, void(exports)()) {
  nargonames[i].name = name;
  nargonames[i].nargo = nargo;
  exports(i + 1, fillnames_pith, nop);
}
void hook() {
  volatile m_t t = tail;
  t(0, fillnames_pith, nop);
}
void init() {}
Q_t findnm(void *nargo) {
  for (Q_t i = 0; i < MNN; i++)
    if (nargonames[i].nargo == nargo)
      return i;
  return -1;
}

N(os_wordump) {
  print("ο:%p α:%02ld               ρ: %02ld σ: %p\n", ο, α, ρ, σ);
  long i = 0;
  while (i < α) {
    q_t k = findnm(ο[i].v);
    if (k < 0)
      print("%lx ", ο[i].Q);
    else
      print("%s ", nargonames[k].name);
    i++;
  }
  print("\n...\n"), i = ρ;
  while (i < 0) {
    q_t k = findnm(σ[i].v);
    if (k < 0)
      print("%lx ", σ[i].Q);
    else
      print("%s ", nargonames[k].name);
    i++;
  }
  C(1);
}
N(god) { C(1); }
N(debugger) { A3(os_wordump, la_stdin, and) O; }
N(მთავარი) {
  hook();
  C(1);
}
// clang-format off
EN(tail,
debugger,                        L)EN(L,
მთავარი,                    exports);
