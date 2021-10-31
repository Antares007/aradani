#include "arsi.h"
struct {
  n_t next, mtavari;
} o;

// clang-format off
I(got,
"os_next", o.next,            L)I(L,
"მთავარი", o.mtavari, imports);
N(mmain) { A(6) o.mtavari(T()); }

E(got,
"მთავარი",  mmain, exports);
// clang-format on
