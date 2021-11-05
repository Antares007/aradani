#include "os_epoll.h"
#include "aradani.h"
#include "os.h"
#include <stdio.h>
#include <sys/epoll.h>
#include <sys/socket.h>

#define MAX_EVENT_NUMBER 1024 // event

int epoll_fd;
struct epoll_event events[MAX_EVENT_NUMBER];

void os_epoll_init() { epoll_fd = epoll_create(5); }

struct state_s {
  long fd;
};

static N(setσ) {
  R(p_t *, nσ);
  R(long, fd);
  struct state_s *s = S(state_s, nσ);
  s->fd = fd;
  C(1);
}

static N(os_socket_an) {
  R(p_t *, oσ);
  A(oσ) O;
}
static N(os_socket_da) {}
static N(os_socket_ara) {}

N(os_socket) {
  long listen_fd = socket(PF_INET, SOCK_STREAM, 0);
  if (listen_fd < 0) {
    printf("fail to create socket!\n");
    return C(2);
  }
  A9(listen_fd, os_socket_an, os_socket_da, os_socket_ara, 0x1000,
     wordCountOf(struct state_s), os_new, setσ, da)
  O;
}
N(os_on) {
  R(Q_t, wc);
  R(Q_t, event);
  R(p_t *, nσ);
  struct state_s *s = S(state_s, nσ);
  s->fd = 0;
  A3(wc, event, nσ) O;
}
N(os_listen) {
  R(p_t *, nσ);
  R(p_t *, kσ);
  A2(nσ, kσ) O;
}
// ondata    d =
// onconnect s = ondata s 'DATA' 1 os_on
// exam      s = onconnect s 'CONN' 1 os_on
