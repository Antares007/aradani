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
#define RAY_FORWARD_TO_PARENT(r)                                               \
  N(ray_forward_to_parent_##r) {                                               \
    p_t *pσ = σ[3].v;                                                          \
    pσ[pσ[2].q + r].c(pσ[0].v, pσ[1].Q, pσ[2].q, pσ);                          \
  }
RAY_FORWARD_TO_PARENT(2)
RAY_FORWARD_TO_PARENT(1)
RAY_FORWARD_TO_PARENT(0)
#define RAY_ALIGN_TO_FORWARDER(r)                                              \
  N(ray_align_to_forwarder_##r) { ρ += 6, σ[ρ - 3 + r].c(T()); }
RAY_ALIGN_TO_FORWARDER(2)
RAY_ALIGN_TO_FORWARDER(1)
RAY_ALIGN_TO_FORWARDER(0)
// TODO: move os_new/os_delete to a_next arsi.
N(os_new) {
  R(Q_t, state_count);
  R(Q_t, word_count);
  p_t *nο = malloc((word_count + state_count) * sizeof(void *));
  p_t *nσ = nο + (word_count + state_count - 4);
  Q_t nα = 0;
  q_t nρ = -state_count;
  nσ[--nρ].c = ray_forward_to_parent_2;
  nσ[--nρ].c = ray_forward_to_parent_1;
  nσ[--nρ].c = ray_forward_to_parent_0;
  nσ[--nρ].c = ο[--α].c;
  nσ[--nρ].c = ο[--α].c;
  nσ[--nρ].c = ο[--α].c;
  nσ[--nρ].c = ray_align_to_forwarder_2;
  nσ[--nρ].c = ray_align_to_forwarder_1;
  nσ[--nρ].c = ray_align_to_forwarder_0;
  nσ[0].v = nο;
  nσ[1].Q = nα;
  nσ[2].q = nρ;
  nσ[3].v = σ[3].v;
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
