#pragma once
#include "oars.h"
// TODO: merge with os_queue.c
void os_epoll_wait(Q_t);
void os_epoll_init();
int os_epoll_sockets();
