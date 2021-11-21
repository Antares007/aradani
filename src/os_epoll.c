#include "oars.h"
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/epoll.h>
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
N(l_epoll_create) {
  R(Q_t, size);
  q_t fd = epoll_create(size);
  if (fd < 0)
    C(2);
  else
    A(fd) C(1);
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
N(l_epoll_wait) {
  R(Q_t, timeout);
  R(Q_t, maxevents);
  R(struct epoll_event *, events);
  R(Q_t, epfd);
  q_t ret = epoll_wait(epfd, events, maxevents, timeout);
  if (ret < 0)
    C(2);
  else
    A(ret) C(1);
}
N(l_setnoblock) {
  R(q_t, fd);
  int flags = fcntl(fd, F_GETFL, 0);
  if (flags < 0)
    return C(2);
  flags |= O_NONBLOCK;
  A(fd) C(fcntl(fd, F_SETFL, flags) != -1 ? 1 : 2);
}
N(l_socket) {
  long fd = socket(PF_INET, SOCK_STREAM, 0);
  if (fd < 0)
    A("fail to create socket!") C(2);
  else
    A(fd) C(1);
}
