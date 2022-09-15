#include "arsi.h"
#include "gotgod.h"
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

void nar(OARS);
void os_queue_n(OARS);

S(and) { Α(010, nar) O; }

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
  R(n_t, root);
  R(const char *, filename);
  n_t e = mapfile(filename, root);
  if (e)
    A(e) C(1);
  else
    C(2);
}
S(os_bark_import_first_n) {
  --α;
  R(n_t, n);
  --α;
  A(n) C(1);
}
void os_debug_init(OARS);
N(os_bark_import_first) {
  R(n_t, e);
  Α(e, e, os_debug_init, 0020, nar, os_bark_import_first_n, 0010, nar) O;
}
S(os_bark_seed_and_import_first) {
  R(n_t, root);
  R(const char *, name);
  Α(name, root, os_seed, os_bark_import_first, 010, nar) O;
}
NP(os_bark) {
  R(p_t *, oο);
  R(n_t, root);
  R(const char *, name);
  Α(name, root, os_bark_seed_and_import_first, dot, and, oο, 5, os_queue_n) O;
}
S(os_ls_n) {
  R(n_t, export);
  R(void*, addr);
  R(const char*, name);
  printf("%p %s\n", addr, name);
  Α(export, god, os_ls_n, 0110, nar) O;
}
N(os_ls) {
  R(n_t, export);
  Α(export, os_ls_n, 010, nar) O;
}
