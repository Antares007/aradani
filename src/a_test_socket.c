#include "arsi.h"
// clang-format off
IN(0,
ls_export,                  L)IN(L,
os_new,                     L)int(*print)(const char*, ...);I(L,
printf, print,              L)IN(L,
//
os_queue,                   L)IN(L,
//
and,                        L)IN(L,
and2,                       L)IN(L,
and3,                       L)IN(L,
and3or,                     L)IN(L,
and4,                       L)IN(L,
not,                        L)IN(L,
notand,                     L)IN(L,
or,                         L)IN(L,
//
mkdrain,                    L)IN(L,
os_bind,                    L)IN(L,
os_listen,                  L)IN(L,
os_socket,                  L)IN(L,
//
s_pith,                import);

NP(on_data) {
  R(Q_t, nread);
  print("drain_and - α:%ld nread:%ld\n", α, nread);
  α = 0;
}
N(gor) { C(0); }
NP(on_connection) {
  R(p_t*, cσ);
  print("events: %p\n", cσ);
  A7(on_data, mkdrain, gor, cσ, 2, os_queue, and4) O;
}

NP(მთავარი_test) {
  A2(export, ls_export) O;
  //A10(os_socket,
  //    "127.0.0.1", 7000, os_bind, and3,
  //    on_connection, mkdrain, and2,
  //    os_listen, and) O;
}

N(updater) { A2(მთავარი_test, and) C(1); }
void init() { updateσ(s_pith, updater); }

// clang-format off
EN(tail,          
s_pith,                export);
