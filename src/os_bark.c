#include "oars.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

static void *mapfile(const char *filename, void *pith) {
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
N(os_run_arsi) {
  R(void *, pith);
  R(const char *, file_name);
  n_t arsi = mapfile(file_name, pith);
  if (arsi)
    arsi(T());
  else
    C(2);
}