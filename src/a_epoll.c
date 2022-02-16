#include "arsi.h"
#include "gotgod.h"
// clang-format off
IBS(                L)IN(L,
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
os_hrtime,          L)IN(L,
os_new,             L)IN(L,
os_queue,           L)IN(L,
//
and,                L)IN(L,
and2,               L)IN(L,
and3or,             L)IN(L,
and5,         imports);

S(მთავარი) { C(1); }

void init() { print("\ninit %s\n", __FILE__); }
// clang-format off
EN(tail,
მთავარი,      exports);
