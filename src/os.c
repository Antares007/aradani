#include "aradani.h"
#include "mmap.h"
#include "os_epoll.h"
#include "os_queue.h"
#include "queue.h"
#include <assert.h>
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
static Nd(os_არა) {}
N(wordump);
N(αzero) { α = 0, C(1); }
static Nd(os_და) {
  if (α)
    A5(wordump, αzero, da, os_next, da) O;
  else
    os_next(T());
}
static Nd(os_ან) { os_next(T()); }
#include "os_exports.h"
N(stab) { --α, A(os_exports) C(1); }
N(nn) {
  R(n_t, export);
  R(n_t, addd);
  R(char *, name);
  printf("N %s %p\n", name, addd);
  A3(export, nn, da) O;
}
int cmp(const char *s1, const char *s2);
N(run) {
  R(n_t, export);
  R(n_t, addd);
  R(char *, name);
  R(char *, mame);
  printf("N %s %p\n", name, addd);
  if (cmp(mame, name) == 0) {
    A(addd) O;
  } else {
    A4(mame, export, run, da) O;
  }
}
N(os_impexp);
N(example_cicle);

int main(int argc, char **argv) {
  os_queue_init();
  os_epoll_init();
  OarS(, os_ან, os_და, os_არა, 0x1000, 0);
  if (argc < 2)
    printf("%s filenameToRun\n", argv[0]);
  else
    printf("%s\n", argv[1]);
  unsigned long size;
  n_t arsi = mapfile(argc < 2 ? "src/arsi00.arsi" : argv[1], &size);
  *(void **)((char *)arsi + size - 10) = stab;
  A6("მთავარი", os_impexp, arsi, run, da, daa) O;
  α = 0, example_cicle(T());
}
