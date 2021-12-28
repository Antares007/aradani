#include "oars.h"
#include <stdio.h>
#include <stdlib.h>
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
N(os_new) {
  R(Q_t, state_count);
  R(Q_t, word_count);
  p_t *nο = malloc((word_count + state_count) * sizeof(void*));
  p_t *nσ = nο + (word_count + state_count - 3);
  Q_t nα = 0;
  q_t nρ = -state_count;
  nσ[--nρ].c = ο[--α].c;
  nσ[--nρ].c = ο[--α].c;
  nσ[--nρ].c = ο[--α].c;
  nσ[0].v = nο;
  nσ[1].Q = nα;
  nσ[2].q = nρ;
  A(nσ) C(1);
}
N(os_delete) {
  R(p_t *, nσ);
  free(nσ[0].v);
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
N(la_stdin) { fgetc(stdin), C(1); }
