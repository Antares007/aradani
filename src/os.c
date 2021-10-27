#include "aradani.h"
#include "mmap.h"
#include "os_expimp.h"
#include "os_queue.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
N(os_new) {
  R(Q_t, ws);
  R(Q_t, wc);
  Noars(n, ο[--α].c, ο[--α].c, ο[--α].c, wc, ws);
  A(nσ) C(1);
}
N(os_delete) {
  R(p_t *, nσ);
  free(nσ[0].v);
  C(1);
}
static N(os_არა) { printf("os_არა\n"); }
// TODO: remove os_next calls by extending meaning of dOt
static N(os_და) {
  printf("os_და\n");
  os_next(T());
}
static N(os_ან) {
  printf("os_ან\n");
  os_next(T());
}
N(ang) { C(0); }
N(dag) { C(1); }
N(so0) {
  R(p_t *, oσ);
  printf("so0\n");
  A6(σ, ang, oσ, os_queueee, os_next, da) O;
}
N(so1) {
  R(p_t *, oσ);
  R(Q_t, c);
  if (c % 100000000 == 0)
    printf("so1 %ld\n", c);
  A7(c + 1, σ, dag, oσ, os_queueee, os_next, da) O;
}
N(so2) { printf("so2\n"); }
N(so) { A6(so0, so1, so2, 64, 0, os_new) O; }
N(si0) {
  R(p_t *, oσ);
  printf("si0\n");
  A6(σ, dag, oσ, os_queueee, os_next, da) O;
}
N(si1) {
  R(p_t *, oσ);
  R(Q_t, c);
  if (c % 100000000 == 1)
    printf("si1 %ld\n", c);
  A7(c + 1, σ, dag, oσ, os_queueee, os_next, da) O;
}
N(si2) { printf("si2\n"); }
N(si) { A6(si0, si1, si2, 64, 0, os_new) O; }
int main(int argc, char **argv) {
  os_init_queue();
  Noars(, os_ან, os_და, os_არა, 0x1000, 0);
  printf("aa\n");
  A7(0, si, ang, so, daa, os_queueee, და) O;
  // if (argc < 2)
  //  printf("%s filenameToRun\n", argv[0]);
  // unsigned long size;
  // n_t arsi = mapfile(argc < 2 ? "src/arsi00.arsi" : argv[1], &size);
  //*(void **)((char *)arsi + size - 10) = ღრმაარსი;
  // A2(arsi, არსი) O;
}
