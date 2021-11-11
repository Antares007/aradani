#include "aradani.h"
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
  R(Q_t, σminuscount)
  R(Q_t, οσcount)
  R(void *, m)
  p_t *nο = m;
  p_t *nσ = nο + οσcount;
  Q_t nα = 0;
  q_t nρ = -σminuscount;
  nσ[--nρ].c = ο[--α].c;
  nσ[--nρ].c = ο[--α].c;
  nσ[--nρ].c = ο[--α].c;
  nσ[0].v = nο;
  nσ[1].Q = nα;
  nσ[2].q = nρ;
  A(nσ) C(1);
}
N(os_new) {
  R(Q_t, σminuscount);
  R(Q_t, οpluscount);
  Q_t οσcount = οpluscount + σminuscount + 3, οσpluscount = οσcount + 3;
  A6(οσpluscount * sizeof(void *), nalloc, οσcount, σminuscount, os_new_n, da3)
  O;
}
N(os_delete) {
  R(p_t *, nσ);
  free(nσ[0].v);
  C(1);
}
