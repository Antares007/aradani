#include "arsi.h"
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
void *mapfile(const char *filename, void *pith) {
  int fd = open(filename, O_RDONLY);
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
static void os_and(αos_t *o, const char *n, void *a,
                   void (*e)(struct αos_t *)) {
  p_t *args = o->d;
  p_t *σ = args[0].p, *ο = args[2].p;
  Q_t α = args[1].Q, ρ = args[3].Q;
  A(a) C(1);
}
static void os_or(αos_t *o) {
  p_t *args = o->d;
  p_t *σ = args[0].p, *ο = args[2].p;
  Q_t α = args[1].Q, ρ = args[3].Q;
  C(0);
}
static int cmp(const char *s1, const char *s2) {
  while (*s1 == *s2++)
    if (*s1++ == 0)
      return (0);
  return (*(unsigned char *)s1 - *(unsigned char *)--s2);
}
N(os_bark) {
  R(ε_t, root);
  R(const char *, name);
  ε_t e = mapfile(name, root);
  e(&(αos_t){.a = os_and,
             .o = os_or,
             .cmp = cmp,
             .d = (void *[]){σ, (void *)α, ο, (void *)ρ}});
}
static void os_print(αos_t *o, const char *n, void *a,
                     void (*e)(struct αos_t *)) {
  printf("%s %p\n", n, a), e(o);
}
static int one() { return 1; }
N(os_ls) {
  R(ε_t, e);
  e(&(αos_t){.a = os_print,
             .o = os_or,
             .cmp = one,
             .d = (void *[]){σ, (void *)α, ο, (void *)ρ}});
}
