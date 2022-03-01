#include "oars.h"
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <strings.h>
#include <sys/epoll.h>
#include <unistd.h>
N(l_close) {
  R(Q_t, fd);
  close(fd), C(1);
}
N(l_read) {
  R(Q_t, nbyte);
  R(void *, buf);
  R(Q_t, fd);
  printf("EAGAIN:%d\n",EAGAIN);
  Q_t num = read(fd, buf, nbyte);
  if (num < 0)
    C(2);
  else
    A(num) C(1);
}
N(l_read2) {
  R(Q_t, connfd);
  R(Q_t, nread);
  ssize_t ret = recv(connfd, ((char *)ο) + nread, sizeof(void *), 0);
  if (ret < 0)
    A(nread) C((errno == EAGAIN || errno == EWOULDBLOCK) ? 0 : 2);
  else if (ret == 0)
    A(nread) C(1);
  else
    α = (nread + ret + sizeof(void *) - 1) / sizeof(void *),
    A3(nread + ret, connfd, l_read) O;
}
N(l_accept) {
  R(q_t, fd);
  struct sockaddr_in clnt_addr;
  socklen_t clnt_addr_len = sizeof(clnt_addr);
  q_t rez = accept(fd, (struct sockaddr *)&clnt_addr, &clnt_addr_len);
  if (rez < 0)
    C(2);
  else
    A(rez) C(1);
}
N(l_address) {
  R(Q_t, port);
  R(const char *, ip);
  struct sockaddr_in *address = (void *)&σ[α];
  α += wordCountOf(struct sockaddr_in);
  bzero(address, sizeof(*address));
  address->sin_family = AF_INET;
  inet_pton(AF_INET, ip, &address->sin_addr);
  address->sin_port = htons(port);
  C(1);
}
N(l_bind) {
  α -= wordCountOf(struct sockaddr_in);
  struct sockaddr_in *address = (void *)&σ[α];
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
  C(fcntl(fd, F_SETFL, flags) != -1 ? 1 : 2);
}
N(l_socket) {
  long fd = socket(PF_INET, SOCK_STREAM, 0);
  if (fd < 0)
    A("fail to create socket!") C(2);
  else
    A(fd) C(1);
}
N(l_listen) {
  R(q_t, fd);
  q_t rez = listen(fd, 101);
  if (rez < 0)
    A("fail to listen socket!") C(2);
  else
    C(1);
}
