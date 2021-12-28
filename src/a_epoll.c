#include "arsi.h"
// clang-format off
IN(0,
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
os_new,               L)IN(L,
os_wordump,           L)int(*print)(const char*, ...);I(L,
printf, print,        L)n_t os_next_org;I(L,
//
os_next, os_next_org, L)IN(L,
os_queue,             L)IN(L,
//
and,                  L)IN(L,
and2,                 L)IN(L,
and3,                 L)IN(L,
and3or,               L)IN(L,
not,                  L)IN(L,
not2and2or2,          L)IN(L,
not2and2or3,          L)IN(L,
not2and2or6,          L)IN(L,
notand,               L)IN(L,
notand4,              L)IN(L,
or,                   L)IN(L,
or3,                  L)IN(L,
or4,                  L)IN(L,
or6,                  L)IN(L,
//
s_pith,           import);

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
N(epoll_ctl2) {
  R(q_t, events);
  R(q_t, op);
  R(p_t*, sσ);
  struct state_s *s = S(struct state_s, sσ);
  A6(epoll_fd, op, s->fd, sσ, (events | EPOLLET | EPOLLONESHOT), l_epoll_ctl) O;
}
NP(epoll_add_in)  { A3(EPOLL_CTL_ADD,  EPOLLIN, epoll_ctl2) O; }
NP(epoll_add_out) { A3(EPOLL_CTL_ADD, EPOLLOUT, epoll_ctl2) O; }
NP(epoll_mod_in)  { A3(EPOLL_CTL_MOD,  EPOLLIN, epoll_ctl2) O; }
NP(epoll_mod_out) { A3(EPOLL_CTL_MOD, EPOLLOUT, epoll_ctl2) O; }
N(sock);
NP(process_events) {
  R(q_t, i);
  R(q_t, ret);
  p_t *sσ = events[i].data.ptr;
  if (i == ret) C(1);
  else A3(ret, i, S(struct state_s, sσ)->word) O;
}
N(os_next);
N(god) { C(1); }
NP(nread) {
  R(p_t*, cσ);
  struct state_s *c = S(struct state_s, cσ);
  A14(0, c->fd, l_read,
      1, god,
      2, god,
      3, cσ, epoll_mod_in, σ, 2, os_queue, not2and2or6) X;
}
NP(client_word) {
  R(q_t, i);
  R(q_t, ret);
  p_t *cσ = events[i].data.ptr;
  struct state_s *c = S(struct state_s, cσ);
  A9(cσ, nread, c->dσ, 2, os_queue, ret, i + 1, process_events, and3) O;
}

NP(os_next_epoll_wait) {
  A8(epoll_fd, events, MAX_EVENT_NUMBER, -1, l_epoll_wait,
     0, process_events, and2) O;
}
NP(queue_epoll_wait)   {
  A6(os_next_epoll_wait, os_next, and, σ[4].v, 3, os_queue) O;
}
NP(os_next) {
  A5(os_next_org, os_next_epoll_wait, os_next_org, and, or3) O;
}

//The sink MUST be greeted back with a callbag payload
//that is either the source itself
//or another callbag (known as the "talkback"). 
NP(client_socket_or) {
  R(p_t *, oσ);
  struct state_s *s = S(struct state_s, σ);
  s->dσ = oσ;
  A2(σ, epoll_add_in) X;
}
//Window of valid deliveries:
//A callbag MUST NOT be delivered data before it has been greeted
//A callbag MUST NOT be delivered data after it has been terminated
//A sink MUST NOT be delivered data after it terminates its source
NP(client_socket_and) {
}
//A callbag is terminated when the first argument is 2 and the
//second argument is either undefined (signalling termination
//due to success) or any truthy value (signalling termination
//due to failure).
NP(client_socket_not) {
}
NP(make_client_socketσ) {
  A6(client_socket_or, client_socket_and, client_socket_not, 0x1000, wordCountOf(struct state_s), os_new) O;
}
NP(set_client_socketσ) {
  R(p_t *, cσ);
  R(q_t, fd);
  struct state_s *c = S(struct state_s, cσ);
  c->fd = fd;
  c->word = client_word;
  A(cσ) C(1);
}
NP(naccept) {
  R(q_t, fd);
  A8(fd, l_accept, l_setnoblock, and, make_client_socketσ, and, set_client_socketσ, and) O;
}
NP(server_word) {
  R(q_t, i);
  R(q_t, ret);
  p_t *sσ = events[i].data.ptr;
  struct state_s *s = S(struct state_s, sσ);
  A12(s->fd, naccept,
      god,
      god, s->dσ, 2, os_queue, notand4,
      ret, i + 1, process_events, and3) O;
}


NP(set_epoll_fd) { R(Q_t, fd); epoll_fd = fd; C(1); }
NP(მთავარი) { A4(3, l_epoll_create, set_epoll_fd, and) O; }

N(updater) { A2(მთავარი, and) C(1); }
void init() { updateσ(s_pith, updater); }

NP(sock_or) {
  R(p_t *, oσ);
  struct state_s *s = S(struct state_s, σ);
  s->dσ = oσ;
  A9(epoll_fd, EPOLL_CTL_ADD, s->fd, σ, (EPOLLIN | EPOLLET), l_epoll_ctl,
     s->fd, l_listen, and2) X;
}
NP(sock_and) {}
NP(sock_not) {}
NP(sock) { A6(sock_or, sock_and, sock_not, 0x1000, wordCountOf(struct state_s), os_new) O; }
NP(setup_os_socket) {
  R(Q_t, fd);
  R(p_t *, sσ);
  struct state_s *s = S(struct state_s, sσ);
  s->fd = fd;
  s->word = server_word;
  A(sσ) C(1);
}
NP(os_socket) { A5(sock, l_socket, and, setup_os_socket, and) O; }

NP(drop) { --α, C(1); }
NP(os_bind) {
  R(Q_t, port);
  R(const char *, ip);
  R(p_t *, sock);
  struct state_s *s = S(struct state_s, sock);
  A11(sock, s->fd, ip, port, l_address, l_bind, and, l_setnoblock, and, drop, and) O;
}
N(gor) { C(0); }
NP(os_listen) {
  R(p_t *, sink);
  R(p_t *, sock);
  A5(sink, gor, sock, 2, os_queue) O;
}
NP(drain_or) {
  R(Q_t, nread);
  print("drain_or  - α:%ld nread:%ld\n", α, nread);
  α = 0, os_next(T());
}
NP(drain_not) {
  R(Q_t, nread);
  print("drain_not - α:%ld nread:%ld\n", α, nread);
  α = 0, os_next(T());
}
NP(mkdrain) {
  R(n_t, drain_and);
  A6(drain_or, drain_and, drain_not, 0x1000, 0, os_new) O;
}

// clang-format off
EN(tail,          
mkdrain,                L)EN(L,
os_bind,                L)EN(L,
os_listen,              L)EN(L,
os_next,                L)EN(L,
os_socket,              L)EN(L,
//
s_pith,            export);
