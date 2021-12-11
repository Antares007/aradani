#include "oars.h"
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
typedef void (*m_t)();
static void nop() {}
static void print_pith(void *s, const char *name, void *addr, m_t export) {
  printf("%s\t%p\n", name, addr), export(0, print_pith, nop);
}
N(ls_export) {
  R(m_t, export);
  export(0, print_pith, nop);
  C(1);
}
