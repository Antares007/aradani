#pragma once
#include "import_export.h"
#include "oars.h"
N(init);
N(import);
N(export);
N(tail) __attribute__((section(".text.end")));
N(tail) {}
static int imported = 0;
static N(iε) { α -= 3, imported = 1, A2(init, export) anδ(T()); }
N(head) __attribute__((section(".text.begin")));
N(head) {
  (void)δo_imp;
  n_t nar = (imported ? export : (A2(tail, import) anδ));
  nar(T());
}

#undef NP
#define NP(n)                                                                  \
  N(n##p);                                                                     \
  N(n) {                                                                       \
    print("%p\t%ld\t%ld\t%s\n", σ, α, ρ, #n);                                  \
    n##p(T());                                                                 \
  }                                                                            \
  N(n##p)
