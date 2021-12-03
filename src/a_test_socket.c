#include "arsi.h"
// clang-format off
IN(gor,
and,                        L)IN(L,
and2,                       L)IN(L,
and3,                       L)IN(L,
and3or,                     L)IN(L,
and4,                       L)IN(L,
not,                        L)IN(L,
notand,                     L)IN(L,
or,                         L)IN(L,

ls_export,                  L)IN(L,
os_new,                     L)IN(L,
os_queue,                   L)int(*print)(const char*, ...);I(L,
printf, print,              L)IN(L,

mkdrain,                    L)IN(L,
os_bind,                    L)IN(L,
os_listen,                  L)IN(L,
os_next,                    L)IN(L,
os_socket,                  L)n_t შიდა_მთავარი;I(L,
მთავარი, შიდა_მთავარი, import);

NP(ondata) {
  R(Q_t, nread);
  print("drain_and - α:%ld nread:%ld\n", α, nread);
  α=0, os_next(T());
}
NP(drain) {
  R(p_t*, cσ);
  print("events: %p\n", cσ);
  A9(ondata, mkdrain,
     gor, cσ, 2, os_queue, and4,
     os_next, and) O;
}
NP(მთავარი) {
  // A(os_next) O;
  // A9(export, ls_export, god, not, σ, 4, os_queue, os_next, and) O;
  A12(შიდა_მთავარი,
      os_socket, and,
      "127.0.0.1", 7000, os_bind, and3,
      drain, mkdrain, and2,
      os_listen, and) O;
}

// clang-format off
EN(Tail,          
მთავარი,               export);
