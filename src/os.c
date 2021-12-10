#include "oars.h"
#include <stdio.h>

N(os_queue_init);
N(os_exports);
N(and4);

#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

static void *mapfile(const char *filename, void *pith) {
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

N(os_pith) { --α, A(os_exports) C(1); }
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
#include "junctions.h"
int main(int argc, char **argv) {
  // rec defined σ
  p_t ο[512], *σ = &ο[512 - 4];
  q_t α = 0, ρ = 0;
  σ[--ρ].c = os_not;
  σ[--ρ].c = os_and;
  σ[--ρ].c = os_or;
  σ[0].v = ο;
  σ[1].Q = α;
  σ[2].q = ρ;
  σ[3].v = σ;
  const char *filename = argc < 2 ? "src/arsi00.arsi" : argv[1];
  void (*exports)() = mapfile(filename, os_exports);
  n_t theword = 0;
  exports(&theword, ray_and, ray_or);
  if (theword)
    A3(os_queue_init, theword, and) O;
}
