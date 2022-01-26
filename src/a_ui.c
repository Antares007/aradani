#include "arsi.h"
// clang-format off
IN(iε,
os_new,                   L)IN(L,
os_wordump,               L)IF(L,
printf, print,            L, int, const char*, ...)IN(L,
//
os_queue,                 L)p_t *oο;I(L,
"ο", oο,                  L)IN(L,
//
and,                      L)IN(L,
and2,               imports);

N(მთავარი) { A5(1, 2, 3, 4, os_wordump) O; }

N(init) { oο[oο[1].Q++].v = მთავარი, C(1); }

E(tail,
"ο", oο,              exports);
