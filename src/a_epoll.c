#include "arsi.h"
// clang-format off
IN(gor,
an,                   L)IN(L,
anda3,                L)IN(L,
ara,                  L)IN(L,
arada,                L)IN(L,
da,                   L)IN(L,
//
l_address,            L)IN(L,
l_bind,               L)IN(L,
l_epoll_ctl,          L)IN(L,
l_setnoblock,         L)IN(L,
l_socket,             L)IN(L,
//
os_next,              L)IN(L,
os_wordump,           L)int(*print)(const char*, ...);I(L,
printf, print,   import);
// clang-format on

N(მთავარი) { A2(9, 6) C(1); }

N(os_socket) { C(1); }
N(os_bind) { C(1); }
N(os_listen) { C(1); }

// clang-format off
EN(Tail,          
os_bind,                L)EN(L,
os_listen,              L)EN(L,
os_socket,              L)EN(L,
მთავარი,           export);
