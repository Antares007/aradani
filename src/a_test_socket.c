#include "arsi.h"
// clang-format off
IN(gor,
and,                    L)IN(L,
and2,                   L)IN(L,
and3,                   L)IN(L,
and3or,                 L)IN(L,
not,                    L)IN(L,
notand,                 L)IN(L,
or,                     L)IN(L,

ls_export,              L)IN(L,
os_new,                 L)IN(L,
os_queue,               L)int(*print)(const char*, ...);I(L,
printf, print,          L)IN(L,

mkdrain,                L)IN(L,
os_bind,                L)IN(L,
os_listen,              L)IN(L,
os_next,                L)IN(L,
os_socket,              L)n_t მთავარი2;I(L,
მთავარი, მთავარი2, import);

// clang-format on

N(drain) {
  R(Q_t, events);
  print("events: %lx\n", events);
  C(1);
}
N(მთავარი) {
  // A(os_next) O;
  // A9(export, ls_export, god, not, σ, 4, os_queue, os_next, and) O;
  A12(მთავარი2, os_socket, and, "127.0.0.1", 7000, os_bind, and3, drain,
      mkdrain, and2, os_listen, and)
  O;
}

// clang-format off
EN(Tail,          
მთავარი,         export);
