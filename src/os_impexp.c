#include "aradani.h"
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
static N(mapfile) {
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
static int cmp(const char *s1, const char *s2) {
  while (*s1 == *s2++)
    if (*s1++ == 0)
      return (0);
  return (*(unsigned char *)s1 - *(unsigned char *)--s2);
}
static N(god) { C(1); }
static N(os_impexp_nn) {
  R(n_t, export);
  R(n_t, eaddr);
  R(const char *, ename);
  R(n_t, import);
  R(n_t *, iaddr);
  R(const char *, iname);
  if (cmp(iname, ename) == 0) {
    *iaddr = eaddr;
    A6(import, god, export, os_impexp_nn, da, anda3) O;
  } else {
    A6(iname, iaddr, import, export, os_impexp_nn, da) O;
  }
}
static N(os_impexp_n) {
  R(n_t, tailexport);
  R(n_t, export);
  R(n_t, import);
  A10(import, export, god, tailexport, os_impexp_nn, da, export, god, da2, an2da6)
  O;
}
static N(os_impexp) {
  R(n_t, setail);
  R(n_t, tail);
  R(n_t, export);
  R(n_t, import);
  A8(import, export, os_impexp, tail, setail, da, os_impexp_n, da) O;
}
static N(os_run_nn) {
  R(n_t, export);
  R(n_t, addr);
  R(char *, name);
  R(char *, mame);
  if (cmp(mame, name) == 0) {
    A(addr) O;
  } else {
    A4(mame, export, os_run_nn, da) O;
  }
}
static N(os_run_n) {
  R(n_t, pith);
  R(const char *, nargoname);
  A6(nargoname, os_impexp, pith, os_run_nn, da, da2) O;
}
N(os_run) {
  R(n_t, bpith);
  R(const char *, filename);
  R(const char *, nargoname);
  A6(nargoname, filename, bpith, mapfile, os_run_n, da) O;
}
