#include "oars.h"
#include <stdio.h>

N(os_run);
N(os_queue_init);
N(os_exports);
N(and4);

#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

static void * mapfile(const char*filename, void*bpith) {
  int fd = open(filename, O_RDWR);
  struct stat sb;
  if (fd == -1 || fstat(fd, &sb) == -1)
    return 0;
  void *addr =
      mmap((void *)0x0000777777700000, sb.st_size,
           PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_FIXED, fd, 0);
  close(fd);
  *(void **)((char *)addr + sb.st_size - 10) = bpith;
  return addr;
}

static N(os_pith) { --α, A(os_exports) C(1); }
static N(os_not) { printf("os_not\n"); }
static N(os_and) { printf("os_and\n"); }
static N(os_or ) { printf("os_or\n"); }

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
  A6(os_queue_init, "მთავარი", filename, os_pith, os_run, and4) O;
}
