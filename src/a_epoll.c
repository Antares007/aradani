#include "arsi.h"
#include "gotgod.h"
// clang-format off
IBS(                L)IN(L,
ada,                L)IN(L,
//
l_accept,           L)IN(L,
l_address,          L)IN(L,
l_bind,             L)IN(L,
l_epoll_create,     L)IN(L,
l_epoll_ctl,        L)IN(L,
l_epoll_wait,       L)IN(L,
l_listen,           L)IN(L,
l_read,             L)IN(L,
l_setnoblock,       L)IN(L,
l_socket,           L)IN(L,
//
os_bark,            L)IN(L,
os_hrtime,          L)IN(L,
os_ls,              L)IN(L,
os_new,             L)IN(L,
os_queue,           L)IN(L,
//
and,                L)IN(L,
and2,               L)IN(L,
and3or,             L)IN(L,
and5,         imports);

S(მთავარი) {
  const char* cc1 = "src/a_cycle.arsi";
  const char* cc2 = "src/a_async.arsi";
  const char* cc3 = "src/a_parse.arsi";
  AS(
    god,
    cc1, exports, ο, os_bark, 040, ada,
    cc2, exports, ο, os_bark, 040, ada,
    cc3, exports, ο, os_bark, 040, ada
  ) O;
}


void init() { print("\ninit %s\n", __FILE__); }
// clang-format off
EN(tail,
მთავარი,      exports);
