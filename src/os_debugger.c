#include "os_debugger.h"
#include "aradani.h"
#include <stdio.h>

N(stdinla) {
  A((long)fgetc(stdin)) C(1);
}
N(drop) {
  α--;
  C(1);
}
N(pause) {
  A3(stdinla, drop, da) O;
}
