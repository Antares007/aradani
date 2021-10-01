#include "aradani.h"
#include "mmap.h"
#include <stdio.h>
typedef unsigned long Q_t;
typedef unsigned int W_t;
// k0 k1 k2 . σ
N(k0) {
  R(p_t *, s);
  σ[-1].v = s;
  s[s[0].q + 1].c(T());
}
N(k1) {
  R(Q_t, name);
  R(n_t, nar);
  ((void)nar);
  if (name == 'main') {
    //o.fun1 = nar;
  } else {
    p_t *s = &σ[-1];
    s[s[0].q + 1].c(T());
  }
}
N(k2) {}
int main(int argc, char *argv[]) {
  // if (argc < 2) {
  //  printf("%s filenameToRun\n", argv[0]);
  //  return -1;
  //}
  unsigned long size;
  n_t arsi = mapfile("src/arsi.arsi", &size);
  
  printf("done %p %ld\n", arsi, size);
  return 0;
}
