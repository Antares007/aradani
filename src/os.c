#include "aradani.h"
#include "mmap.h"
#include "os_queue.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
Nd(os_new) {
  R(Q_t, ws);
  R(Q_t, wc);
  Noars(n, ο[--α].c, ο[--α].c, ο[--α].c, wc, ws);
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
static N(gor) { C(0); }
static N(god) { C(1); }
N(so0) {
  R(p_t *, oσ);
  printf("so0\n");
  A7(σ, gor, oσ, 3, os_queue, os_next, da) O;
}
N(so1) {
  R(p_t *, oσ);
  R(Q_t, c);
  if (c % 100000000 == 0)
    printf("so1 %ld\n", c);
  A8(c + 1, σ, god, oσ, 3, os_queue, os_next, da) O;
}
N(so2) { printf("so2\n"); }
N(so) { A6(so0, so1, so2, 64, 0, os_new) O; }
N(si0) {
  R(p_t *, oσ);
  printf("si0\n");
  A7(σ, god, oσ, 3, os_queue, os_next, da) O;
}
N(si1) {
  R(p_t *, oσ);
  R(Q_t, c);
  if (c % 100000000 == 1)
    printf("si1 %ld\n", c);
  A8(c + 1, σ, god, oσ, 3, os_queue, os_next, da) O;
}
N(si2) { printf("si2\n"); }
N(si) { A6(si0, si1, si2, 64, 0, os_new) O; }
static int cmp(const char *s1, const char *s2) {
  while (*s1 == *s2++)
    if (*s1++ == 0)
      return (0);
  return (*(unsigned char *)s1 - *(unsigned char *)--s2);
}
N(impexp_nn) {
  R(n_t, export);
  R(n_t, eaddr);
  R(const char *, ename);
  R(n_t, import);
  R(n_t *, iaddr);
  R(const char *, iname);
  // printf("%s %s\n", iname, ename);
  if (cmp(iname, ename) == 0) {
    *iaddr = eaddr;
    A6(import, god, export, impexp_nn, da, andaaa) O;
  } else {
    A6(iname, iaddr, import, export, impexp_nn, da) O;
  }
}
N(impexp_n) {
  R(n_t, tailexport);
  R(n_t, export);
  R(n_t, import);
  A10(import, export, god, tailexport, impexp_nn, da, export, god, daa,
      anndaaaaaa)
  O;
}
N(impexp) {
  R(n_t, setail);
  R(n_t, tail);
  R(n_t, export);
  R(n_t, import);
  A8(import, export, impexp, tail, setail, da, impexp_n, da) O;
}
#include "os_exports.h"
N(stab) { --α, A(os_exports) C(1); }
N(nn) {
  R(n_t, export);
  R(n_t, addd);
  R(char *, name);
  printf("N %s %p\n", name, addd);
  A3(export, nn, da) O;
}
int main(int argc, char **argv) {
  os_init_queue();
  Noars(, os_ან, os_და, os_არა, 0x1000, 0);
  // printf("aa\n");
  // A8(0, si, gor, so, daa, 3, os_queue, დაა) O;
  if (argc < 2)
    printf("%s filenameToRun\n", argv[0]);
  else
    printf("%s\n", argv[1]);
  unsigned long size;
  n_t arsi = mapfile(argc < 2 ? "src/arsi00.arsi" : argv[1], &size);
  *(void **)((char *)arsi + size - 10) = stab;
  A5(impexp, arsi, nn, da, daa) O;
  // A2(impexp, arsi) O;
}
