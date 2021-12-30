#include "oars.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
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
typedef void (*f_t)();
void ray_err(f_t *s) { s[1](); }
void ray_and(f_t *s, const char *name, p_t *σ, void(ie)()) {
  (strcmp("s_pith", name) == 0) ? s[0](σ) : ie(s, ray_and, ray_err);
}
void bark(const char *name, void *tail, f_t ok, f_t err) {
  void (*head)() = mapfile(name, tail);
  (head == 0) ? err() : head((f_t[]){ok, err}, ray_and, ray_err);
}
