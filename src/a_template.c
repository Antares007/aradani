#include "arsi.h"
// clang-format off
IN(0,
and,                      L)IN(L,
and2,                     L)IN(L,
or,                       L)IN(L,
//
ls_export,                L)IN(L,
os_new,                   L)IN(L,
os_next,                  L)IN(L,
os_queue,                 L)IF(L,
printf, print,            L, int, const char*, ...)IN(L,
//
debugger,                 L)n_t მთავარი2;I(L,
"მთავარი", მთავარი2,   imports);

N(მთავარი) {
  A7(and, მთავარი2, debugger, and, exports, ls_export, and2) O;
}

EN(tail,
მთავარი,             exports);
