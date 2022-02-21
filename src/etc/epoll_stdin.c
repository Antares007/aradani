#include <sys/epoll.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int SetNonblocking(int fd) {
  int old_option = fcntl(fd, F_GETFL);
  int new_option = old_option | O_NONBLOCK;
  fcntl(fd, F_SETFL, new_option);
  return old_option;
}

int main(void)
{
    char buffer[4096];
    int fd = epoll_create(5);

    struct epoll_event event;

    event.events = EPOLLIN | EPOLLET;
    event.data.fd = 0;

    epoll_ctl(fd, EPOLL_CTL_ADD, STDIN_FILENO, &event);
    SetNonblocking(STDIN_FILENO);
    unsigned long c = 0;
    for (;;) {
        // fprintf(stderr, "Going into epoll_wait\n");
        int num = epoll_wait(fd, &event, 1, 0);
        // fprintf(stderr, "Going into read: %d\n", event.data.fd);
        if(num > 0) printf("%ld %ld\n", c, read(0, buffer, sizeof(buffer)));
        c++;
    }
}
