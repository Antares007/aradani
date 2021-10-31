#include "arsi.h"
struct { n_t next, sdkfj, aldjk, askdj;
} o;

// clang-format off
I(got,
"os_next", o.next,        L)I(L,
"os_next", o.next,        L)I(L,
"os_next", o.aldjk, imports);

N(mmain) { A(9) C(1); }
N(s1) { A('s1') C(1);}
N(s2) { A('s2') C(1);}
N(s3) { A('s3') C(1);}

E(got,
"os_next",       s3,          L)E(L,
"s1",       s1,          L)E(L,
"s2",       s2,          L)E(L,
"მთავარი",  mmain, exports);
// clang-format on
