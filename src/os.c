#include "aradani.h"
#include "mmap.h"
//#include "os_queue.h"
//#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

Nd(os_new) {
  R(Q_t, ws);
  R(Q_t, wc);
  OarS(n, ο[--α].c, ο[--α].c, ο[--α].c, wc, ws);
  A(nσ) C(1);
}

Nd(os_delete) {
  R(p_t *, nσ);
  free(nσ[0].v);
  C(1);
}
#include "os_exports.h"
N(stab) { --α, A(os_exports) C(1); }
N(nn) {
  R(n_t, export);
  R(n_t, addr);
  R(char *, name);
  printf("N %s %p\n", name, addr);
  A3(export, nn, da) O;
}
int cmp(const char *s1, const char *s2);
N(os_impexp);
N(run) {
  R(n_t, export);
  R(n_t, addr);
  R(char *, name);
  R(char *, mame);
  printf("N %s %p\n", name, addr);
  if (cmp(mame, name) == 0) {
    A(addr) O;
  } else {
    A4(mame, export, run, da) O;
  }
}
N(loadrun_n) {
  R(n_t, pith);
  R(const char *, nargoname);
  A6(nargoname, os_impexp, pith, run, da, da2) O;
}
N(loadrun) {
  R(n_t, bpith);
  R(const char *, filename);
  R(const char *, nargoname);
  A6(nargoname, filename, bpith, mapfile, loadrun_n, da) O;
}
static Nd(os_არა) {}
static Nd(os_და) {}
static Nd(os_ან) {}
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
int main(int argc, char **argv) {
  p_t ο[512], *σ = &ο[512];
  q_t α = 0, ρ = 0;

  // os_queue_init();
  // return 9;
  // OarS(, os_ან, os_და, os_არა, 0x1000, 0);
  const char *filename = argc < 2 ? "src/arsi00.arsi" : argv[1];
  printf("%s\n", filename);
  A4("მთავარი", filename, stab, loadrun) O;
}
