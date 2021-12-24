#include "oars.h"
#include <stdio.h>
#include <string.h>

void bark(const char *name, void *tail, n_t nargo, p_t *σ);
void os_exports(void *, void (*)(), void (*)());

N(Main) {
  printf("Main\n");
  O;
}
N(print_error) { printf("error\n"); }
int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Would you mind adding the 'filename' as an argument?\n");
    return 8;
  }
  const char *filename = argv[1];
  p_t ο[4], *σ = ο + sizeof(ο) / sizeof(*ο) - 3;
  q_t α = 0, ρ = 0;
  ο[α++].v = print_error;
  σ[0].v = ο, σ[1].Q = α, σ[2].q = ρ;
  bark(filename, os_exports, Main, σ);
}
