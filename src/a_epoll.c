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

#include <sys/epoll.h>
#define MAX_EVENT_NUMBER 1024 // event
q_t epoll_fd;
struct epoll_event events[MAX_EVENT_NUMBER];
struct state_s {
  long fd;
  p_t *dσ;
  int flag;
};
N(მთავარი) { A2(9, 6) C(1); }

N(os_socket_n) { C(1); }
N(os_socket) { A3(l_socket, os_socket_n, da) O; }
N(os_bind) { A(2) C(1); }
N(os_listen) { A(3) C(1); }
N(os_next_nn) {
  print("aha\n");
  C(1);
}
N(os_next_n) { A3(os_next, os_next_nn, an) O; }

// clang-format off
EN(Tail,          
os_bind,                L)EN(L,
os_listen,              L)E(L,
os_next, os_next_n,     L)EN(L,
os_socket,              L)EN(L,
მთავარი,           export);
