#include "arsi.h"
// clang-format off
IN(iε,
os_new,                     L)IN(L,
os_wordump,                 L)IF(L,
printf, print,              L, int, const char*, ...)IN(L,
//
os_queue,                   L)p_t *oο;I(L,
"ο", oο,                    L)IN(L,
//
and,                        L)IN(L,
and2,                       L)IN(L,
notand,                     L)IN(L,
//
os_ls,                imports);

N(მთავარი) { A3(exports, os_ls, and) O; }

N(init) { oο[oο[1].Q++].v = მთავარი, C(1); }

E(tail,
"ο", oο,              exports);
