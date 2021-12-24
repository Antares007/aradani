#include "oars.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

void *mapfile(const char *filename, void *pith) {
  int fd = open(filename, O_RDWR);
  struct stat sb;
  if (fd == -1 || fstat(fd, &sb) == -1)
    return 0;
  void *addr =
      mmap((void *)0x0000777777700000, sb.st_size,
           PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_FIXED, fd, 0);
  close(fd);
  *(void **)((char *)addr + sb.st_size - 10) = pith;
  return addr;
}
void ray_or(void *s) { printf("We can't find s_pith.\n"); }
void ray_and(n_t nargo, const char *name, p_t *σ, void(ie)()) {
  printf("%s", name);
  if (strcmp("s_pith", name) == 0) {
    printf("Found 's_pith,' at %p so let's go.\n", σ);
    p_t *ο = σ[0].v;
    Q_t α = σ[1].Q;
    q_t ρ = σ[2].q;
    nargo(ο, α, ρ, σ);
  } else
    ie(nargo, ray_and, ray_or);
}
void bark(const char *name, void *tail, n_t nargo, p_t *σ) {
  void (*head)() = mapfile(name, tail);
  if (head == 0) {
    p_t *ο = σ[0].v;
    Q_t α = σ[1].Q;
    q_t ρ = σ[2].q;
    O;
  } else
    head(nargo, ray_and, ray_or);
}
