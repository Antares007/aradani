#include "arsi.h"
#include "gotgod.h"
// clang-format off
IB(L)IF(L,
printf, print,      L, int, const char *, ...)IN(L,
os_ls,              L)IN(L,
os_new,             L)IN(L,
os_queue,           L)IN(L,
//
and,                L)IN(L,
and2,               L)IN(L,
and3,               L)IN(L,
and3or,             L)IN(L,
and4,               L)IN(L,
not,                L)IN(L,
notand,             L)IN(L,
or,           imports);

N(mkdrain) { C(1); }
NP(on_data) {
  R(Q_t, nread);
  print("drain_and - α:%ld nread:%ld\n", α, nread);
  α = 0;
}
NP(on_connection) {
  R(p_t*, cσ);
  print("events: %p\n", cσ);
  A7(on_data, mkdrain, gor, cσ, 2, os_queue, and4) O;
}

void init() {}
NP(მთავარი_test) {
  A2(exports, os_ls) O;
  //A10(os_socket,
  //    "127.0.0.1", 7000, os_bind, and3,
  //    on_connection, mkdrain, and2,
  //    os_listen, and) O;
}

// clang-format off
EN(tail,          
მთავარი_test, exports);

