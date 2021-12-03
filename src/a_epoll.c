#include "arsi.h"
// clang-format off
IN(gor,
and,                  L)IN(L,
and2,                 L)IN(L,
and3,                 L)IN(L,
and3or,               L)IN(L,
not,                  L)IN(L,
notand,               L)IN(L,
notand4,              L)IN(L,
or,                   L)IN(L,
//
l_accept,             L)IN(L,
l_address,            L)IN(L,
l_bind,               L)IN(L,
l_epoll_create,       L)IN(L,
l_epoll_ctl,          L)IN(L,
l_epoll_wait,         L)IN(L,
l_listen,             L)IN(L,
l_read,               L)IN(L,
l_setnoblock,         L)IN(L,
l_socket,             L)IN(L,
ls_export,            L)IN(L,
os_new,               L)n_t os_next_org;I(L,
os_next, os_next_org, L)IN(L,
os_queue,             L)IN(L,
os_wordump,           L)int(*print)(const char*, ...);I(L,
printf, print,        L)IN(L,
//
debugger,        import);

#include <arpa/inet.h>
#include <sys/epoll.h>
#define MAX_EVENT_NUMBER 1024 // event
q_t epoll_fd;
struct epoll_event events[MAX_EVENT_NUMBER];
struct state_s {
  long fd;
  p_t *dσ;
  n_t word;
};
N(sock);
N(os_next);
N(csock_or) {
  print("csock_or %ld\n", α);
  R(p_t *, oσ);
  struct state_s *s = S(struct state_s, σ);
  s->dσ = oσ;
  A8(epoll_fd, EPOLL_CTL_ADD, s->fd, σ, (EPOLLIN | EPOLLET | EPOLLONESHOT), l_epoll_ctl,
     os_next, and) O;
}
N(csock_and) {}
N(csock_not) {}
N(csock) {
  A6(csock_or, csock_and, csock_not, 0x1000, wordCountOf(struct state_s), os_new) O;
}
N(client_word);
N(set_client_socket) {
  R(p_t *, cσ);
  R(q_t, fd);
  struct state_s *c = S(struct state_s, cσ);
  c->fd = fd;
  c->word = client_word;
  A(cσ) C(1);
}
N(naccept) {
  R(q_t, fd);
  A8(fd, l_accept,
     l_setnoblock, and,
     csock, and,
     set_client_socket, and) O;
}
N(process_events) {
  R(q_t, i);
  R(q_t, ret);
  p_t *sσ = events[i].data.ptr;
  if (i == ret) C(1);
  else A3(ret, i, S(struct state_s, sσ)->word) O;
}
N(client_word) {
  print("client_word\n");
  R(q_t, i);
  R(q_t, ret);
  p_t *cσ = events[i].data.ptr;
  struct state_s *c = S(struct state_s, cσ);
  A10(0, c->fd, l_read, c->dσ, 3, os_queue,
     ret, i + 1, process_events, and3) O;
}
N(server_word) {
  print("server_word\n");
  R(q_t, i);
  R(q_t, ret);
  p_t *sσ = events[i].data.ptr;
  struct state_s *s = S(struct state_s, sσ);
  A12(s->fd, naccept,
      god,
      god, s->dσ, 2, os_queue, notand4,
      ret, i + 1, process_events, and3) O;
}
N(os_next_epoll_wait) {
  A10(epoll_fd, events, MAX_EVENT_NUMBER, -1, l_epoll_wait,
      0, process_events, and2,
      os_next, and) O;
}
N(os_next) {
  A3(os_next_org, os_next_epoll_wait, or) O;
}
N(set_epoll_fd) {
  R(Q_t, fd);
  epoll_fd = fd;
  print("epoll_fd: %d\n", epoll_fd);
  C(1);
}
N(მთავარი) {
  A4(3, l_epoll_create,
     set_epoll_fd, and) O;
}
N(sock_or) {
  print("sock_or %ld\n", α);
  R(p_t *, oσ);
  struct state_s *s = S(struct state_s, σ);
  s->dσ = oσ;
  A11(epoll_fd, EPOLL_CTL_ADD, s->fd, σ, (EPOLLIN | EPOLLET), l_epoll_ctl,
      s->fd, l_listen, and2,
      os_next, and) O;
}
N(sock_and) {}
N(sock_not) {}
N(sock) {
  A6(sock_or, sock_and, sock_not, 0x1000, wordCountOf(struct state_s), os_new) O;
}
N(setup_os_socket) {
  R(Q_t, fd);
  R(p_t *, sσ);
  struct state_s *s = S(struct state_s, sσ);
  s->fd = fd;
  s->word = server_word;
  A(sσ) C(1);
}
N(os_socket) {
  A5(sock,
     l_socket, and,
     setup_os_socket, and) O;
}
N(drop) { --α, C(1); }
N(os_bind) {
  R(Q_t, port);
  R(const char *, ip);
  R(p_t *, sock);
  struct state_s *s = S(struct state_s, sock);
  A11(sock, s->fd, ip, port, l_address,
      l_bind, and,
      l_setnoblock, and,
      drop, and) O;
}
N(os_listen) {
  R(p_t *, sink);
  R(p_t *, sock);
  A5(sink, gor, sock, 2, os_queue) O;
}
N(drain_or) {
  R(Q_t, nread);
  print("drain_or  - α:%ld nread:%ld\n", α, nread);
  α = 0, os_next(T());
}
N(drain_not) {
  R(Q_t, nread);
  print("drain_not - α:%ld nread:%ld\n", α, nread);
  α = 0, os_next(T());
}
N(mkdrain) {
  print("mkdrain\n");
  R(n_t, drain_and);
  A6(drain_or, drain_and, drain_not, 0x1000, 0, os_new) O;
}
// clang-format off
EN(Tail,          
mkdrain,                L)EN(L,
os_bind,                L)EN(L,
os_listen,              L)EN(L,
os_next,                L)EN(L,
os_socket,              L)EN(L,
მთავარი,           export);
