#include "aradani.h"
#include <stdio.h>
N(os_wordump) {
  printf("ο:%p α:%02ld               ρ: %02ld σ: %p\n", ο, α, ρ, σ);
  long i = 0;
  while (i < α) {
    printf("%016lx ", ο[i].Q);
    if (++i < α)
      printf("%016lx\n", ο[i].Q);
    else
      printf("\n");
    i++;
  }
  C(1);
}
N(ls_export_n) {
  R(n_t, export);
  R(n_t, nargo);
  R(const char *, name);
  printf("%s\t%p\n", name, nargo);
  A3(export, ls_export_n, da) O;
}
N(ls_export) {
  R(n_t, export);
  A3(export, ls_export_n, da) O;
}
