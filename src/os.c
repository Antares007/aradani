#include "oars.h"
#include <stdio.h>
#include <string.h>

void *mapfile(const char *, void *);
void os_exports(void *, void (*)(), void (*)());

void ray_or(const char *s_pith) { printf("We can't find s_pith '%s'.\n", s_pith); }
void ray_and(const char *s_pith, const char *name, p_t *σ, void(ie)()) {
  if (strcmp(s_pith, name) == 0) {
    printf("Found 's_pith,' at %p so let's go.\n", σ);
    p_t *ο = σ[0].v;
    Q_t α  = σ[1].Q;
    q_t ρ  = σ[2].q;
    printf("A: %p %lu %ld %p\n", ο, α, ρ, σ);
    O;
  } else
    ie(s_pith, ray_and, ray_or);
}
int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Would you mind adding the 'filename' as an argument?\n");
    return 8;
  }
  const char *filename = argv[1];
  void (*exports)() = mapfile(filename, os_exports);
  if (exports == 0) {
    printf("Can't 'mmap' file '%s'.\n", filename);
    return 9;
  }
  exports("s_pith", ray_and, ray_or);
}
