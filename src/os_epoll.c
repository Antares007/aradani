#include "aradani.h"
#include <fcntl.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <sys/socket.h>

#define MAX_EVENT_NUMBER 1024 // event
static N(gor) { C(0); }
static N(god) { C(1); }

N(os_bind);
N(os_listen);
N(mksocket);
N(os_queue);
N(os_next);
N(os_new);

int epoll_fd;
struct epoll_event events[MAX_EVENT_NUMBER];

struct state_s {
  long fd;
  p_t *dσ;
  int flag;
};

static int SetNonblocking(int fd) {
  int old_option = fcntl(fd, F_GETFL);
  int new_option = old_option | O_NONBLOCK;
  fcntl(fd, F_SETFL, new_option);
  return old_option;
}
static void addtopoll(p_t *σ) {
  struct state_s *s = S(state_s, σ);
  struct epoll_event event;
  event.data.ptr = σ;
  event.events = EPOLLIN | EPOLLET;
  epoll_ctl(epoll_fd, EPOLL_CTL_ADD, s->fd, &event);
  SetNonblocking(s->fd);
}
N(addtopolln) {
  R(p_t *, nσ);
  addtopoll(nσ);
  A(nσ) C(1);
}
int os_epoll_sockets() { return 0; }
void os_epoll_wait(Q_t ms) {
  long ret = epoll_wait(epoll_fd, events, MAX_EVENT_NUMBER, ms);
  if (ret < 0)
    printf("epoll errorn"), exit(1);
  for (Q_t i = 0; i < ret; i++) {
    p_t *σ = events[i].data.ptr, *ο = σ[0].v;
    Q_t α = 0;
    q_t ρ = σ[2].q;
    struct state_s *s = S(state_s, σ);

    if (s->flag) {
      printf("aa\n");
      struct sockaddr_in client_address;
      socklen_t client_addrlength = sizeof(client_address);
      long connfd =
          accept(s->fd, (struct sockaddr *)&client_address, &client_addrlength);
      printf("z\n");
      A10(0, connfd, mksocket, addtopolln, da, god, s->dσ, 2, os_queue, da4)
      X;
    } else if (events[i].events & EPOLLIN) {
      printf("bb\n");
    }
  }
}
void os_epoll_init() { epoll_fd = epoll_create(5); }

// TODO: use As macro instead of composition after creation
static N(setσ) {
  R(p_t *, nσ);
  R(long, fd);
  R(long, flag);
  struct state_s *s = S(state_s, nσ);
  s->fd = fd;
  s->flag = flag;
  A(nσ) C(1);
}

static N(os_socket_an) {
  R(p_t *, oσ);
  struct state_s *s = S(state_s, σ);
  s->dσ = oσ;
  addtopoll(σ);
  A5(σ, gor, s->dσ, 2, os_queue) X;
}
static N(os_socket_da) {}
static N(os_socket_ara) {}
N(mksocket) {
  R(Q_t, listen_fd);
  R(Q_t, flag);
  A10(flag, listen_fd, os_socket_an, os_socket_da, os_socket_ara, 0x1000,
      wordCountOf(struct state_s), os_new, setσ, da)
  O;
}
N(os_socket) {
  long listen_fd = socket(PF_INET, SOCK_STREAM, 0);
  if (listen_fd < 0) {
    printf("fail to create socket!\n");
    return C(2);
  }
  A3(1, listen_fd, mksocket) O;
}
static N(drain_an) {
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
  printf("events: %lx\n", events);
  C(1);
}
N(test_epoll) {
  A('hell') C(1);
  // A10(os_socket, "127.0.0.1", 7000, os_bind, da3, drain, mkdrain, da2,
  //    os_listen, da)
  // O;
}
//
// ondata    d =
// onconnect s = ondata s 'DATA' 1 os_on
// exam      s = onconnect s 'CONN' 1 os_on
// N(os_on) {
//   R(Q_t, wc);
//   R(Q_t, event);
//   R(p_t *, nσ);
//   struct state_s *s = S(state_s, nσ);
//   s->fd = 0;
//   A3(wc, event, nσ) O;
// }

#include <arpa/inet.h>
#include <netinet/in.h>
#include <strings.h>

N(os_listen) {
  R(p_t *, kσ);
  R(p_t *, nσ);
  A5(kσ, gor, nσ, 2, os_queue) O;
}
#define As(T, n)                                                               \
  struct T n =                                                                 \
      (α += wordCountOf(struct T), (struct T *)&ο[α - wordCountOf(struct T)])
#define Rs(T, n) struct T n = ((struct T *)&ο[α -= wordCountOf(struct T)])

N(l_setnoblock) {
  R(q_t, fd);
  int flags = fcntl(fd, F_GETFL, 0);
  if (flags < 0)
    return C(2);
  flags |= O_NONBLOCK;
  A(fd) C(fcntl(fd, F_SETFL, flags) != -1 ? 1 : 2);
}
N(l_epoll_ctl) {
  R(Q_t, events);
  R(void *, ptr);
  R(Q_t, fd);
  R(Q_t, op);
  R(Q_t, epoll_fd);
  struct epoll_event event;
  event.data.ptr = ptr;
  event.events = events;
  C(epoll_ctl(epoll_fd, op, fd, &event) < 0 ? 2 : 1);
}
N(l_socket) {
  long fd = socket(PF_INET, SOCK_STREAM, 0);
  if (fd < 0)
    A("fail to create socket!") C(2);
  else
    A(fd) C(1);
}
N(l_address) {
  R(Q_t, port);
  R(const char *, ip);
  As(sockaddr_in, *address);
  address->sin_family = AF_INET;
  inet_pton(AF_INET, ip, &address->sin_addr);
  address->sin_port = htons(port);
  C(1);
}
N(l_bind) {
  Rs(sockaddr_in, *address);
  R(Q_t, fd);
  long r = bind(fd, (struct sockaddr *)address, sizeof(*address));
  if (r == -1)
    A("fail to bind socket!") C(2);
  else
    A(fd) C(1);
}

N(os_bind) {}
