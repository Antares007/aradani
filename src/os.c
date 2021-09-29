#include "aradani.h"
#include "mmap.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  //if (argc < 2) {
  //  printf("%s filenameToRun\n", argv[0]);
  //  return -1;
  //}
  unsigned long size;
  n_t *arsi = mapfile("src/arsi.bin", &size);
  printf("done %p %ld\n", arsi, size);
  return 0;
}
