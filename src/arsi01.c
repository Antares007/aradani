#include "arsi.h"
struct {
  n_t next, mtavari, pause;
} o;
n_t da;
// clang-format off
I(got,
"os_next", o.next,            L)I(L,
"pause",   o.pause,            L)I(L,
"მთავარი", o.mtavari, imports);

N(mmain) { 
  //A4(6, o.pause, o.mtavari, da) O;
  o.mtavari(T());
  }

E(got,
"მთავარი",  mmain, exports);
// clang-format on
