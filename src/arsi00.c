#include "importexportmacros.h"
#include "oars.h"
#include "queue.h"
N(import);
N(export);
void tail() __attribute__((section(".text.end")));
void head() __attribute__((section(".text.begin")));
N(tail) {}
static N(got) { C(2); }
static N(god) { C(1); }
static N(gor) { C(0); }

n_t Tail;
N(σeτail) {
  R(n_t, addr);
  Tail = addr;
  A(addr) C(1);
}
N(hook);
void Moakhie3_Moakhie1_C0(p_t *ο, unsigned long α, long ρ, p_t *σ) {
  ρ += 3, ρ += 1, σ[ρ + (0)].c(ο, α, ρ, σ);
};
void Moakhie3_Amoakhe1_O(p_t *ο, unsigned long α, long ρ, p_t *σ) {
  ρ += 3, ο[α++].v = σ[ρ++].v, ο[α - 1].c(ο, α - 1, ρ, σ);
};
void Moakhie3_Moakhie1_C2(p_t *ο, unsigned long α, long ρ, p_t *σ) {
  ρ += 3, ρ += 1, σ[ρ + (2)].c(ο, α, ρ, σ);
};
void da(p_t *ο, unsigned long α, long ρ, p_t *σ) {
  σ[--ρ].c = ο[--α].c, 0;
  σ[--ρ].c = Moakhie3_Moakhie1_C2;
  σ[--ρ].c = Moakhie3_Amoakhe1_O;
  σ[--ρ].c = Moakhie3_Moakhie1_C0;
  ο[α - 1].c(ο, α - 1, ρ, σ);
}
N(head) {
  ((void)gor), ((void)god), ((void)got), ((void)Tail);
  R(n_t, impexp);
  if (Tail)
    A(export) C(1);
  else
    A7(import, export, tail, σeτail, impexp, hook, da) O;
}
typedef int (*printf_t)(const char *__restrict __format, ...);
// clang-format off
IN(gor,    
an,                                     L)IN(L,
arada,                                  L)IN(L,
arada2,                                 L)IN(L,
da2,                                    L)IN(L,
//
la_stdin,                               L)IN(L,
os_new,                                 L)IN(L,
os_wordump,                             L)INT(L,
printf, printf_t,                  import);
// clang-format on

typedef struct {
  n_t nargo;
  const char *name;
} nargoname_t;
#define MNN 2048
nargoname_t nargonames[MNN];
N(fillnargonames) {
  R(Q_t, i);
  R(n_t, export);
  R(n_t, nargo);
  R(const char *, name);
  printf("%s\n", name);
  nargonames[i % MNN].nargo = nargo;
  nargonames[i % MNN].name = name;
  A5(export, god, i + 1, fillnargonames, arada2) O;
}
N(hook) {
  R(n_t, addr);
  A5(addr, addr, 0, fillnargonames, da2) O;
}
N(debugger) {
  printf("press any key\n");
  A3(os_wordump, la_stdin, da) O;
}
N(მთავარი) { A2(6, 1) C(1); }

// clang-format off
EN(Tail,
debugger,                              L)EN(L,
მთავარი,                          export);
