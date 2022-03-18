#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
l_epoll_create,     L)IN(L,
l_epoll_ctl,        L)IN(L,
l_epoll_wait,       L)IN(L,
os_queue,           L)IN(L,
os_queue_n,         L)IN(L,
//
and,                L)IN(L,
and2,         imports)

#include "unistd.h"
#include <sys/epoll.h>

static Q_t  epoll_fd;
struct epoll_event events[50];

S(epoll_on_wait) {
  R(q_t, num);
  if (num) {
    p_t *oο = events[num - 1].data.ptr;
    Α(oο[7].c, oο, os_queue, num - 1, epoll_on_wait, and2) O;
  } else C(1);
}
Sar(epoll_get_events)(epoll_fd, events, sizeof(events) / sizeof(*events), 0, l_epoll_wait)

SarP(epoll_ctl_add_in )(epoll_fd, EPOLL_CTL_ADD, ο[8].Q, ο, EPOLLIN  | EPOLLET | EPOLLONESHOT, l_epoll_ctl)
SarP(epoll_ctl_del_in )(epoll_fd, EPOLL_CTL_DEL, ο[8].Q, ο, EPOLLIN  | EPOLLET | EPOLLONESHOT, l_epoll_ctl)
SarP(epoll_ctl_mod_in )(epoll_fd, EPOLL_CTL_MOD, ο[8].Q, ο, EPOLLIN  | EPOLLET | EPOLLONESHOT, l_epoll_ctl)

SarP(epoll_ctl_add_out)(epoll_fd, EPOLL_CTL_ADD, ο[8].Q, ο, EPOLLOUT | EPOLLET | EPOLLONESHOT, l_epoll_ctl)
SarP(epoll_ctl_del_out)(epoll_fd, EPOLL_CTL_DEL, ο[8].Q, ο, EPOLLOUT | EPOLLET | EPOLLONESHOT, l_epoll_ctl)
SarP(epoll_ctl_mod_out)(epoll_fd, EPOLL_CTL_MOD, ο[8].Q, ο, EPOLLOUT | EPOLLET | EPOLLONESHOT, l_epoll_ctl)

Sar(loop_in_queue)(epoll_get_events, epoll_on_wait, and, loop_in_queue, and, ο[Φ].p, 5, os_queue_n)

SP(set) { R(Q_t, fd); epoll_fd = fd, C(1); }

SarP(init)(5, l_epoll_create, set, and, loop_in_queue, and)

// clang-format off
EN(tail,
epoll_ctl_add_in,  L)EN(L,
epoll_ctl_add_out, L)EN(L,
epoll_ctl_del_in,  L)EN(L,
epoll_ctl_del_out, L)EN(L,
epoll_ctl_mod_in,  L)EN(L,
epoll_ctl_mod_out, L)EN(L,
god,         exports);
