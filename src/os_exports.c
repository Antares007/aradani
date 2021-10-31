#include "os.h"
#include "os_exports.h"
#include "os_queue.h"
#include "os_wordump.h"

#define L CAT(e, __LINE__)
#define E(t, name, addr, n)                                                    \
  N(n) { A3(name, addr, t) C(1); }
static N(got) { σ[ρ + 2].c(T()); }

// clang-format off
E(got,
"loog"     , loog     ,          L)E(L,
"os_delete", os_delete,          L)E(L,
"os_new"   , os_new   ,          L)E(L,
"os_next"  , os_next  ,          L)E(L,
"os_queue" , os_queue ,          L)E(L,
"wordump"  , wordump  , os_exports);
// clang-format on
