#include <fcntl.h>
#include <stdio.h>
#include <sys/epoll.h>
#include <unistd.h>

int SetNonblocking(int fd) {
  int old_option = fcntl(fd, F_GETFL);
  int new_option = old_option | O_NONBLOCK;
  fcntl(fd, F_SETFL, new_option);
  return old_option;
}

int main(void) {
  char buffer[4096];
  int fd = epoll_create(5);

  struct epoll_event event;

  event.events = EPOLLIN | EPOLLET;
  event.data.fd = STDIN_FILENO;
  epoll_ctl(fd, EPOLL_CTL_ADD, STDIN_FILENO, &event);
  SetNonblocking(STDIN_FILENO);

  event.events = EPOLLOUT | EPOLLET;
  event.data.fd = STDOUT_FILENO;
  epoll_ctl(fd, EPOLL_CTL_ADD, STDOUT_FILENO, &event);
  SetNonblocking(STDOUT_FILENO);

  backpressure unsigned long c = 0;
  struct epoll_event events[10];
  for (;;) {
    // fprintf(stderr, "Going into epoll_wait\n");
    int num = epoll_wait(fd, events, 10, 0);
    // fprintf(stderr, "Going into read: %d\n", event.data.fd);
    for (long i = 0; i < num; i++) {
      int fd = events[i].data.fd;
      if      (fd == STDIN_FILENO) printf("%ld %ld\n", c, read(0, buffer, sizeof(buffer)));
      else if (fd == STDOUT_FILENO) c++;
    }
  }
}
