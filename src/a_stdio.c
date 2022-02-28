#include "arsi.h"
#include "gotgod.h"
// clang-format off
IBS(                L)IN(L,
l_accept,           L)IN(L,
l_address,          L)IN(L,
l_bind,             L)IN(L,
l_close,            L)IN(L,
l_epoll_create,     L)IN(L,
l_epoll_ctl,        L)IN(L,
l_epoll_wait,       L)IN(L,
l_listen,           L)IN(L,
l_read,             L)IN(L,
l_setnoblock,       L)IN(L,
l_socket,           L)IN(L,
os_hrtime,          L)IN(L,
os_ls,              L)IN(L,
os_new_nj,          L)IN(L,
os_queue,           L)IN(L,
//
and,                L)IN(L,
and2,               L)IN(L,
and3,               L)IN(L,
and6,               L)IN(L,
not,                L)IN(L,
//
debug_init,         L)IN(L,
debug_οdump,  imports);
#include "unistd.h"

static p_t* stdinο;
static Q_t  epoll_fd;
SP(stdin_oor) {
  R(p_t*, oο);
  Α(ο, gor, oο, os_queue) O;
}
SarP(mk_stdin,  got, god, stdin_oor, "≫", 0111, os_new_nj,  STDIN_FILENO, l_setnoblock, and2)
SarP(mk_stdout, god, god,       god, "≪", 0111, os_new_nj, STDOUT_FILENO, l_setnoblock, and2)
SP(set) {
  R(p_t*, oο);
  R(Q_t, fd);
  epoll_fd = fd;
  stdinο = oο;
  C(1);
}
SarP(init, 5, l_epoll_create, mk_stdin, and, set, and)

Nar(example, mk_stdout, gor, stdinο, os_queue, and3);
Nar(ls, exports, os_ls)

// clang-format off
EN(tail,
ls,                 L)EN(L,
example,      exports)
