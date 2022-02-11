#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
os_hrtime,          L)IN(L,
os_new,             L)IN(L,
os_queue,           L)IN(L,
os_wordump,         L)IN(L,
//
and,                L)IN(L,
and2,               L)IN(L,
and3,               L)IN(L,
and4,               L)IN(L,
and5,               L)IN(L,
and6,               L)IN(L,
and7,               L)IN(L,
andor,              L)IN(L,
notand,             L)IN(L,
or,           imports);
// clang-format on

N(მთავარი) { A3(os_hrtime, os_wordump, and) O; }
void init() { print("\ninit %s\n", __FILE__); }

// clang-format off
EN(tail,
მთავარი,      exports);
