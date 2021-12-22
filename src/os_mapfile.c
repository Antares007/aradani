#include <fcntl.h>
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

