#include "arsi.h"
#include "gotgod.h"
// clang-format off
IBS(                L)IN(L,
nar,                L)IN(L,
os_ls,              L)IN(L,
os_new,             L)IN(L,
os_queue,           L)IN(L,
os_wordump,         L)IN(L,
//
and,                L)IN(L,
not,                L)IN(L,
or,           imports);
void init() {}

S(Main) { Α(7, os_wordump) O; }

// clang-format off
EN(tail,
Main,      exports);
