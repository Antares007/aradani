#include "arsi.h"
#include "queue.h"

// clang-format off
IN(gor,    
da,                                     L)IN(L,
da2,                                    L)IN(L,
//
os_next,                                L)IN(L,
//
debugger,                          import);
// clang-format on

N(მთავარი) { A3(9, da, debugger) O; }

// clang-format off
EN(Tail,
მთავარი,                           export);
