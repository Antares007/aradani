#include "exportmacros.h"
#include "oars.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

void bark(const char *name, void *tail, n_t nargo, p_t *σ);
void os_exports(void *, void (*)(), void (*)());

N(Main) { printf("Main\n"), O; }
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

N(os_wordump) {
  printf("ο:%p α:%02ld               ρ: %02ld σ: %p\n", ο, α, ρ, σ);
  long i = 0;
  while (i < α) {
    printf("%016lx ", ο[i].Q);
    if (++i < α)
      printf("%016lx\n", ο[i].Q);
    else
      printf("\n");
    i++;
  }
  C(1);
}
N(os_new) {
  R(Q_t, state_count);
  R(Q_t, word_count);
  p_t *nο = malloc((word_count + state_count) * sizeof(void*));
  p_t *nσ = nο + (word_count + state_count - 3);
  Q_t nα = 0;
  q_t nρ = -state_count;
  nσ[--nρ].c = ο[--α].c;
  nσ[--nρ].c = ο[--α].c;
  nσ[--nρ].c = ο[--α].c;
  nσ[0].v = nο;
  nσ[1].Q = nα;
  nσ[2].q = nρ;
  A(nσ) C(1);
}
N(os_delete) {
  R(p_t *, nσ);
  free(nσ[0].v);
  C(1);
}

// clang-format off
static void m_gor(void *s, void(a)(), void(o)()) { o(s); }
E(m_gor,
bark, bark,                  L)EN(L,
os_delete,                   L)EN(L,
os_new,                      L)E(L,
os_wordump, os_wordump,      L)E(L,
printf, printf,     os_exports);
// clang-format on

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
