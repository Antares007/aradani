#pragma once
#include "import_export.h"
#include "oars.h"
#define Iε N(imports) { imported = 1, A2(init, exports) anδ(T()); }
N(init);
N(imports);
N(exports);
N(tail) __attribute__((section(".text.end")));
N(tail) {}
static int imported = 0;
static N(iε) { α -= 3, imported = 1, A2(init, exports) anδ(T()); }
N(head) __attribute__((section(".text.begin")));
N(head) {
  (void)δo_imp;
  (void)iε;
  n_t nar = (imported ? exports : (A2(tail, imports) anδ));
  nar(T());
}

#undef NP
#define NP(n)                                                                  \
  N(n##p);                                                                     \
  N(n) {                                                                       \
    print("%p %ld\t%ld\t%s:%s\n", ο, α, ρ, __FILE_NAME__, __FUNCTION__);       \
    n##p(T());                                                                 \
  }                                                                            \
  N(n##p)
