#include "arsi.h"
// clang-format off
IN(gor,
an,                   L)IN(L,
anda3,                L)IN(L,
ara,                  L)IN(L,
arada,                L)IN(L,
da,                   L)IN(L,
da2,                  L)IN(L,
da3,                  L)IN(L,

ls_export,            L)IN(L,
os_new,               L)IN(L,
os_queue,             L)int(*print)(const char*, ...);I(L,
printf, print,        L)IN(L,

os_bind,              L)IN(L,
os_listen,            L)IN(L,
os_next,              L)IN(L,
os_socket,       import);
// clang-format on

N(drain_an) {
  α--;
  os_next(T());
}
static N(drain_ara) {}
N(mkdrain) {
  R(n_t, drain_da);
  A6(drain_an, drain_da, drain_ara, 0x1000, 0, os_new) O;
}
N(drain) {
  R(Q_t, events);
  print("events: %lx\n", events);
  C(1);
}
N(მთავარი) {
  //A(os_next) O;
  A9(export, ls_export, god, ara, σ, 4, os_queue, os_next, da) O;
  //A10(os_socket, "127.0.0.1", 7000, os_bind, da3, drain, mkdrain, da2,
  //    os_listen, da)
  //O;
}

// clang-format off
EN(Tail,          
მთავარი,         export);
