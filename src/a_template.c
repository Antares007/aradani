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
os_queue,                 L)int(*print)(const char*, ...);I(L,
printf, print,            L)IN(L,
//
debugger,            import);

N(მთავარი) {
  A5(and, debugger, export, ls_export, and2) O;
}

EN(tail,
მთავარი,             export);
