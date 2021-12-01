#include "oars.h"
#include <stdio.h>

N(os_run);
N(os_new);
N(os_next);
N(os_queue);
N(os_queue_init);
N(os_exports);
N(os_wordump);
N(and);
N(and2);
static N(os_pith) { --α, A(os_exports) C(1); }
static N(os_არა) { printf("os_ara\n"); }
static N(os_და) { printf("os_da\n"), A3(os_wordump, os_next, and) O; }
static N(os_ან) { printf("os_an\n"); }

N(main_nn) {
  R(p_t *, nσ);
  R(const char *, filename);
  printf("%s\n", filename);
  A9("მთავარი", filename, os_pith, os_run, nσ, 4, os_queue, os_next, and)
  O;
}
N(main_n) {
  R(const char *, filename);
  A9(filename, os_ან, os_და, os_არა, 4090, 0, os_new, main_nn, and) O;
}
#include <unistd.h>
int main(int argc, char **argv) {
  p_t ο[512], *σ = &ο[512];
  q_t α = 0, ρ = 0;
  const char *filename = argc < 2 ? "src/arsi00.arsi" : argv[1];
  A4(os_queue_init, filename, main_n, and2) O;
}
