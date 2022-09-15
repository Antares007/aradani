#include "oars.h"
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

N(map_pith) {
  RN(n_t, pith);
  RN(const char *, filename);
  int fd = open(filename, O_RDONLY);
  struct stat sb;
  if (fd == -1 || fstat(fd, &sb) == -1)
    return C(2);
  static Q_t saddr = 0x0000777777700000;
  char *addr =
      mmap((void *)saddr, sb.st_size, PROT_READ | PROT_WRITE | PROT_EXEC,
           MAP_PRIVATE | MAP_FIXED, fd, 0);
  close(fd);
  if (addr == MAP_FAILED)
    return C(2);
  *(n_t*)(addr + sb.st_size - 10) = pith;
  saddr += ALIGN(sb.st_size, 0x1000);
  A(addr) C(1);
}
