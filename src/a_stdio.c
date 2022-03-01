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
#include <sys/epoll.h>

static p_t* stdinο;
static p_t* stdoutο;
static Q_t  epoll_fd;
static Q_t  c;
static char buffer[0x1000];
struct epoll_event events[2];

Sar(epollwait,
    epoll_fd, events, sizeof(events) / sizeof(*events), 0, l_epoll_wait)
S(prn) {
  R(Q_t, num);
  print("%ld %ld\n", c, num), C(1);
}
S(process_in) { A6(0, buffer, sizeof(buffer), l_read, prn, and) O; }
S(processevents) {
  R(Q_t, num);
  if (num) A6(events[num - 1].data.ptr, ο[Φ].p, os_queue, num - 1, processevents, and2) O;
  else C(1);
}
Sar(queuewait,
    epollwait, processevents, and, queuewait, and, ο[Φ].p, os_queue)

Sar(epoll_ctl_add_in,
    epoll_fd, EPOLL_CTL_ADD, STDIN_FILENO, process_in, EPOLLIN | EPOLLET, l_epoll_ctl)

SP(stdin_oor) { R(p_t*, oο); A8(ο, gor, oο, os_queue, epoll_ctl_add_in, and, queuewait, and) O; }
SP(stdin_and) { C(1); }
SP(stdin_not) { C(1); }
SarP(mk_stdin,
     got, god,  stdin_oor, "≫", 0111, os_new_nj,
     STDIN_FILENO, l_setnoblock, and2)
SP(stdout_oor) {
  R(p_t*, oο);
  (void)oο;
  C(1);
}
SarP(mk_stdout,
     god, god, stdout_oor, "≪", 0111, os_new_nj,
     STDOUT_FILENO, l_setnoblock, and2)

SP(set) {
  R(p_t*, outο);
  R(p_t*, inο);
  R(Q_t, fd);
  epoll_fd = fd, stdinο = inο, stdoutο = outο, C(1);
}

SarP(init, 5, l_epoll_create, mk_stdin, and,
                             mk_stdout, and,
                                   set, and)

Nar(example, stdoutο, gor, stdinο, os_queue);

Nar(ls, exports, os_ls)

// clang-format off
EN(tail,
ls,                 L)EN(L,
example,      exports)
