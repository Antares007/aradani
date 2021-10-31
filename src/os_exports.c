#include "os_exports.h"
#include "aradani.h"
#include "os.h"
#include "os_debugger.h"
#include "os_queue.h"
#include "os_wordump.h"

#define L CAT(e, __LINE__)
#define E(t, name, addr, n)                                                    \
  N(n) { A3(name, addr, t) C(1); }
static N(got) { σ[ρ + 2].c(T()); }
static N(god) { σ[ρ + 1].c(T()); }
static N(gor) { σ[ρ + 0].c(T()); }

// clang-format off
E(got,
"an"       , an,                 L)E(L,
"ara"      , ara,                L)E(L,
"arada"    , arada,              L)E(L,
"da"       , da,                 L)E(L,
"daaaa"    , daaaa,              L)E(L,
"drop"     , drop,               L)E(L,
"god"      , god,                L)E(L,
"gor"      , gor,                L)E(L,
"gor"      , gor,                L)E(L,
"got"      , got,                L)E(L,
"loog"     , loog,               L)E(L,
"os_delete", os_delete,          L)E(L,
"os_new"   , os_new,             L)E(L,
"os_next"  , os_next,            L)E(L,
"os_queue" , os_queue,           L)E(L,
"pause"    , pause,              L)E(L,
"stdinla"  , stdinla,            L)E(L,
"wordump"  , wordump,   os_exports);
// clang-format on
