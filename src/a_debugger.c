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
// clang-format off
N(rot) { ρ += 4, C(2); };
N(rod) { ρ += 3, ο[α++].v = σ[ρ++].v, O; };
N(ror) { ρ += 4, C(0); };
// TODO: define most usefull junctions in header file.
//       lets spread them around all codebase;
N(and1) { σ[--ρ].c = ο[--α].c; σ[--ρ].c = rot; σ[--ρ].c = rod; σ[--ρ].c = ror; O; }
N(mod_export);
N(mod_export_n) {
  R(n_t, export);
  R(n_t, addr);
  R(const char*, name);
  R(Q_t, i);
  A6(i + 1, name, addr, export, mod_export, and1) C(1);
}
N(mod_export) {
  A4(0, export, mod_export_n, and1) O;
}
N(head) {
  ((void)gor), ((void)god), ((void)got), ((void)Tail);
  R(n_t, impexp);
  if (Tail)
    A(export) C(1);
  else
    A7(import, export, tail, σeτail, impexp, hook, and1) O;
}

// clang-format off
IN(gor,    
and,                                     L)IN(L,
and2,                                    L)IN(L,
notand,                                  L)IN(L,
notand2,                                 L)IN(L,
or,                                      L)IN(L,
//
la_stdin,                                L)int(*print)(const char*, ...);I(L,
printf, print,                      import);
// clang-format on

typedef struct {
  n_t nargo;
  const char *name;
} nargoname_t;
#define MNN 2048
nargoname_t nargonames[MNN];

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
N(fillnargonames) {
  R(Q_t, i);
  R(n_t, export);
  R(n_t, nargo);
  R(const char *, name);
  nargonames[i % MNN].nargo = nargo;
  nargonames[i % MNN].name = name;
  A5(export, god, i + 1, fillnargonames, notand2) O;
}
N(hook) {
  R(n_t, addr);
  A5(addr, addr, 0, fillnargonames, and2) O;
}
N(debugger) { A3(os_wordump, la_stdin, and) O; }

// clang-format off
EN(Tail,
debugger,                        export);
