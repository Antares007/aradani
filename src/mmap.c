#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#define handle_error(msg)                                                      \
  do {                                                                         \
    perror(msg);                                                               \
    exit(EXIT_FAILURE);                                                        \
  } while (0)
void *mapfile(const char *filename, size_t *size) {
  int fd = open(filename, O_RDWR);
  struct stat sb;
  if (fd == -1)
    handle_error(filename);
  if (fstat(fd, &sb) == -1)
    handle_error("fstat");
  if (size)
    *size = sb.st_size;
  void *addr =
      mmap((void *)0x0000777777700000, sb.st_size,
           PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_FIXED, fd, 0);

  close(fd);
  return addr;
}
