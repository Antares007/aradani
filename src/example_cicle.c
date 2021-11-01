#include "aradani.h"
#include "os.h"
#include "os_queue.h"
#include <stdio.h>
static N(gor) { C(0); }
static N(god) { C(1); }
static N(so0) {
  R(p_t *, oσ);
  printf("so0\n");
  A7(σ, gor, oσ, 3, os_queue, os_next, da) O;
}
static N(so1) {
  R(p_t *, oσ);
  R(Q_t, c);
  if (c % 100000000 == 0)
    printf("so1 %ld\n", c);
  A8(c + 1, σ, god, oσ, 3, os_queue, os_next, da) O;
}
static N(so2) { printf("so2\n"); }
static N(so) { A6(so0, so1, so2, 64, 0, os_new) O; }
static N(si0) {
  R(p_t *, oσ);
  printf("si0\n");
  A7(σ, god, oσ, 3, os_queue, os_next, da) O;
}
static N(si1) {
  R(p_t *, oσ);
  R(Q_t, c);
  if (c % 100000000 == 1)
    printf("si1 %ld\n", c);
  A8(c + 1, σ, god, oσ, 3, os_queue, os_next, da) O;
}
static N(si2) { printf("si2\n"); }
static N(si) { A6(si0, si1, si2, 64, 0, os_new) O; }
N(example_cicle) { A8(0, si, gor, so, daa, 3, os_queue, დაა) O; }
