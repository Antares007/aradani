#include "os_exports.h"
#include "aradani.h"
#include "os.h"
#include "os_debugger.h"
#include "os_queue.h"
#include "os_wordump.h"

#define L CAT(e, __LINE__)
#define E(t, name, addr, n)                                                    \
  N(n) { A3(name, addr, t) C(1); }
#define EN(t, name, n) E(t, #name, name, n)
static N(got) { σ[ρ + 2].c(T()); }
static N(god) { σ[ρ + 1].c(T()); }
static N(gor) { σ[ρ + 0].c(T()); }
// clang-format off
EN(got,
an,                 L)EN(L,
andaaa,             L)EN(L,
andaaaaa,           L)EN(L,
anndaaaaaa,         L)EN(L,
ara,                L)EN(L,
arada,              L)EN(L,
da,                 L)EN(L,
daaaa,              L)EN(L,
drop,               L)EN(L,
god,                L)EN(L,
gor,                L)EN(L,
got,                L)EN(L,
loog,               L)EN(L,
os_delete,          L)EN(L,
os_new,             L)EN(L,
os_next,            L)EN(L,
os_queue,           L)EN(L,
pause,              L)EN(L,
stdinla,            L)EN(L,
wordump,   os_exports);
// clang-format on
