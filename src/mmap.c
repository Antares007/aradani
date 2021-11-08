#include "mmap.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

N(mapfile) {
  R(n_t, bpith);
  R(const char *, filename);
  int fd = open(filename, O_RDWR);
  struct stat sb;
  if (fd == -1 || fstat(fd, &sb) == -1)
    return C(2);
  void *addr =
      mmap((void *)0x0000777777700000, sb.st_size,
           PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_FIXED, fd, 0);
  close(fd);
  *(void **)((char *)addr + sb.st_size - 10) = bpith;
  A(addr) C(1);
}
