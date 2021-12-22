#include "oars.h"
#include <stdio.h>

N(os_queue_init);
N(os_exports);
N(and);
void *mapfile(const char *, void *);

static N(os_not) { printf("os_not\n"); }
static N(os_and) { printf("os_and\n"); }
static N(os_or) { printf("os_or\n"); }
static int cmp(const char *s1, const char *s2) {
  while (*s1 == *s2++)
    if (*s1++ == 0)
      return (0);
  return (*(unsigned char *)s1 - *(unsigned char *)--s2);
}
void ray_or(void *s) { printf("O: %p\n", s); }
void ray_and(void **s, const char *name, n_t addr, void(ie)()) {
  if (cmp("მთავარი", name) == 0)
    *s = addr;
  else
    ie(s, ray_and, ray_or);
}
int main(int argc, char **argv) {
  // rec defined σ
  p_t ο[512], *σ = &ο[512 - 4];
  q_t α = 0, ρ = 0;
  σ[--ρ].c = os_not, σ[--ρ].c = os_and, σ[--ρ].c = os_or;
  σ[0].v = ο, σ[1].Q = α, σ[2].q = ρ, σ[3].v = σ;

  const char *filename = argc < 2 ? "src/arsi00.arsi" : argv[1];
  void (*exports)() = mapfile(filename, os_exports);
  n_t theword = 0;
  exports(&theword, ray_and, ray_or);
  if (theword) A3(os_queue_init, theword, and) O;
}
