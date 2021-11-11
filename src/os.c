#include "aradani.h"
#include "os_queue.h"
#include <stdio.h>
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
  printf("os_new\n");
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
#include "os_exports.h"
N(stab) { --α, A(os_exports) C(1); }
N(os_run);
static N(os_არა) { printf("os_ara\n"); }
static N(os_და) {
  printf("os_da\n");
  os_next(T());
}
static N(os_ან) { printf("os_an\n"); }
N(main_nn) {
  printf("main_nn\n");
  R(p_t *, nσ);
  R(const char *, filename);
  printf("%s\n", filename);
  A9("მთავარი", filename, stab, os_run, nσ, 4, os_queue, os_next, da)
  O;
}
N(main_n) {
  printf("main_n\n");
  R(const char *, filename);
  A9(filename, os_ან, os_და, os_არა, 4090, 0, os_new, main_nn, da) O;
}
int main(int argc, char **argv) {
  printf("main\n");
  p_t ο[512], *σ = &ο[512];
  q_t α = 0, ρ = 0;
  A4(os_queue_init, argc < 2 ? "src/arsi00.arsi" : argv[1], main_n, da2) O;
}
