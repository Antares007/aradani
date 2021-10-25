#include "oars.h"
void tail() __attribute__((section(".text.end")));
N(tail) {}

struct {
  n_t next;
} o;
N(imports) { A2(&o, "os_next") C(, 1); }

N(mmain) { A(9) C(, 1); }

N(exports) { A2(mmain, "მთავარი") A2(mmain, "mmain") C(, 1); }

void head() __attribute__((section(".text.begin")));
N(head) {
  R(n_t, cb);
  A4(imports, exports, tail, cb) O;
}
