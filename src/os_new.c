#include "oars.h"
#include <stdlib.h>
N(nalloc) {
  R(Q_t, size);
  void *m = malloc(size);
  if (m)
    A(m) C(1);
  else
    C(2);
}
N(nfree) {
  R(void *, m);
  free(m);
  C(1);
}
static N(os_new_n) {
  R(p_t *, nο);
  R(Q_t, state_count);
  R(Q_t, word_count);
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
N(and);
N(os_new) {
  R(Q_t, state_count);
  R(Q_t, word_count);
  A6(word_count, state_count, (word_count + state_count) * sizeof(void *),
     nalloc, os_new_n, and)
  O;
}
N(os_delete) {
  R(p_t *, nσ);
  free(nσ[0].v);
  C(1);
}
