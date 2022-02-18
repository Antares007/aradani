#include "arsi.h"
#include "gotgod.h"
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

N(ada);
N(os_queue);

static void *mapfile(const char *filename, void *pith) {
  int fd = open(filename, O_RDONLY);
  struct stat sb;
  if (fd == -1 || fstat(fd, &sb) == -1)
    return 0;
  static Q_t saddr = 0x0000777777700000;
  void *addr =
      mmap((void *)saddr, sb.st_size, PROT_READ | PROT_WRITE | PROT_EXEC,
           MAP_PRIVATE | MAP_FIXED, fd, 0);
  close(fd);
  if (addr == MAP_FAILED)
    return 0;
  *(void **)((char *)addr + sb.st_size - 10) = pith;
  saddr += ALIGN(sb.st_size, 0x1000);
  return addr;
}
N(os_seed) {
  R(ε_t, root);
  R(const char *, filename);
  ε_t e = mapfile(filename, root);
  if (e)
    A(e) C(1);
  else
    C(2);
}
static void os_and(αos_t *o, const char *n, void *a,
                   void (*e)(struct αos_t *)) {
  p_t *args = o->d;
  p_t *σ = args[0].p, *ο = args[2].p;
  Q_t α = args[1].Q, ρ = args[3].Q;
  A(a) C(1);
}
static void os_or(αos_t *o, const char *mn, const char *in) {
  p_t *args = o->d;
  p_t *σ = args[0].p, *ο = args[2].p;
  Q_t α = args[1].Q, ρ = args[3].Q;
  AS(mn, in) C(0);
}
S(os_bark_import_first) {
  R(ε_t, e);
  e(&(αos_t){
      .a = os_and, .o = os_or, .d = (void *[]){σ, (void *)α, ο, (void *)ρ}});
}
S(os_bark_seed_and_import_first) {
  R(ε_t, root);
  R(const char *, name);
  AS(name, root, os_seed, os_bark_import_first, 010, ada) O;
}
N(os_bark) {
  R(p_t *, oο);
  AS(os_bark_seed_and_import_first, dot, 010, ada, oο, os_queue) O;
}
static void os_print(αos_t *o, const char *n, void *a,
                     void (*e)(struct αos_t *)) {
  printf("%p %s\n", a, n), e(o);
}
N(os_ls) {
  R(ε_t, e);
  e(&(αos_t){
      .a = os_print, .o = os_or, .d = (void *[]){σ, (void *)α, ο, (void *)ρ}});
}
