#include "aradani.h"
#include "arsi.h"
#include "mmap.h"
#include <stdio.h>
typedef unsigned long Q_t;
typedef unsigned int W_t;
W_t names[] = {'fun1', 'fun2'};
struct o_s {
  n_t fun1;
  n_t fun2;
};
static struct o_s o;
// k0 k1 k2 . σ
N(k0) {
  R(p_t *, s);
  σ[-1].v = s;
  s[s[0].q + 1].c(T());
}
N(k1) {
  R(Q_t, name);
  R(n_t, nar);
  if (name == 'main') {
    o.fun1 = nar;
  } else {
    p_t *s = &σ[-1];
    s[s[0].q + 1].c(T());
  }
}
N(k2) {}
void end() {
  printf("end!\n");
}
void onerror() {
  printf("error!\n");
}
void pith(char *name, void *add, void *next) {
  printf("%s %p\n", name, add);
  ((b_t)next)(pith, end, onerror);
}
int main(int argc, char *argv[]) {
  // if (argc < 2) {
  //  printf("%s filenameToRun\n", argv[0]);
  //  return -1;
  //}
  unsigned long size;
  b_t arsi = mapfile("src/arsi.arsi", &size);
  arsi(pith, end, onerror);
  printf("done %p %ld\n", arsi, size);
  return 0;
}
