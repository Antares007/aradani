#include "oars.h"
static N(got) { C(2); }
#define CAT_(a, b) a##b
#define CAT(a, b) CAT_(a, b)
#define L CAT(e, __LINE__)
#define E(t, name, addr, n)                                                    \
  N(n) { A3(name, addr, t) C(1); }
#define I(t, name, addr, n)                                                    \
  N(n) { A3(name, &addr, t) C(1); }
N(imports);
N(exports);
N(ღრმაარსი);
N(head) {
  R(n_t, impexp);
  A4(imports, exports, ღრმაარსი, impexp) O;
}
struct {
  n_t next, sdkfj, aldjk, askdj;
} o;

// clang-format off
I(got,
"os_next", o.next,        L)I(L,
"os_next", o.next,       L)I(L,
"os_next", o.aldjk, imports);

N(mmain) { A(9) C(1); }
N(s1) { A('s1') C(1);}
N(s2) { A('s2') C(1);}
N(s3) { A('s3') C(1);}

E(got,
"s1",       s1,         L)E(L,
"s2",       s2,         L)E(L,
"s3",       s3,         L)E(L,
"მთავარი",  mmain,      exports)
    // clang-format on
