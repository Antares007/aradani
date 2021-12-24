#include "exportmacros.h"
#include "oars.h"
#define END(Tail, Name, Head)                                                  \
  N(Name);                                                                     \
  EN(Tail, Name, Head)

// clang-format off
#undef L
#define L CAT(expimp_2_, __LINE__)
static void m_gor(void *s, void(a)(), void(o)()) { o(s); }
#include <stdio.h>
END(m_gor,
//l_accept,                 L)END(L,
//l_address,                L)END(L,
//l_bind,                   L)END(L,
//l_epoll_create,           L)END(L,
//l_epoll_ctl,              L)END(L,
//l_epoll_wait,             L)END(L,
//l_listen,                 L)END(L,
//l_read,                   L)END(L,
//l_setnoblock,             L)END(L,
//l_socket,                 L)END(L,
//la_stdin,                 L)END(L,
ls_export,                L)END(L,
//os_delete,                L)END(L,
//os_new,                   L)END(L,
//os_next,                  L)END(L,
//os_queue,                 L)END(L,
os_wordump,               L)E(L,
printf, printf,  os_exports);
