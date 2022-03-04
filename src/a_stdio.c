#include "arsi.h"
#include "gotgod.h"
// clang-format off
IBS(                L)IN(L,
l_accept,           L)IN(L,
l_address,          L)IN(L,
l_bind,             L)IN(L,
l_close,            L)IN(L,
l_epoll_create,     L)IN(L,
l_epoll_ctl,        L)IN(L,
l_epoll_wait,       L)IN(L,
l_free,             L)IN(L,
l_listen,           L)IN(L,
l_malloc,           L)IN(L,
l_read,             L)IN(L,
l_setnoblock,       L)IN(L,
l_socket,           L)IN(L,
nar,                L)IN(L,
os_hrtime,          L)IN(L,
os_ls,              L)IN(L,
os_new_nj,          L)IN(L,
os_queue,           L)IN(L,
//
and,                L)IN(L,
and2,               L)IN(L,
and3,               L)IN(L,
and6,               L)IN(L,
andor,              L)IN(L,
not,                L)IN(L,
notand4or,          L)IN(L,
//
debug_init,         L)IN(L,
debug_οdump,  imports);
#include "unistd.h"
#include <sys/epoll.h>

static p_t* stdinο;
static p_t* stdoutο;
static Q_t  epoll_fd;
struct epoll_event events[2];
typedef struct stdin_t {
  n_t epollin;
  p_t *sink;
} stdin_t;

Sar(epoll_get_events,
    epoll_fd, events, sizeof(events) / sizeof(*events), 0, l_epoll_wait)

Sar(reset_in, epoll_fd, EPOLL_CTL_MOD, STDIN_FILENO, ο, EPOLLIN | EPOLLET | EPOLLONESHOT, l_epoll_ctl)

S(eagain) { Α(reset_in) O; }

SP(sent_chunk_to_sink) {
  R(void*, buffer);
  R(q_t, num);
  stdin_t *s = (stdin_t*)&ο[7];
  Α(num, buffer, 'CNK', god, s->sink, os_queue) O;
}
S(epollin);
SarP(queue_process_in, epollin, ο, os_queue)
S(process_in_n) {
  R(void*, buffer);
  R(Q_t,   size);
  Α(STDIN_FILENO, buffer, size, l_read,
    buffer, l_free,
    buffer, sent_chunk_to_sink, queue_process_in, and,
    eagain,
    0241, nar) O;
}
SP(epollin) {
  Q_t size = 0x10000;
  A5(size, size, l_malloc, process_in_n, and) O;
}
S(process_events) {
  R(q_t, num);
  if (num) {
    p_t *oο = events[num - 1].data.ptr;
    Α(oο[7].c, oο, os_queue, num - 1, process_events, and2) O;
  } else C(1);
}
Sar(loop_in_queue,
    epoll_get_events, process_events, and, loop_in_queue, and, ο[Φ].p, os_queue)

S(welcome) { R(p_t *, oο); ο[8].p = oο; A4(ο, gor, ο[8].p, os_queue) O; }
S(bye) { A4(ο, got, ο[8].p, os_queue) ο[8].p = 0, O; }
S(is_active) { C(ο[8].p != 0); }
Sar(epoll_ctl_add_in,
    epoll_fd, EPOLL_CTL_ADD, STDIN_FILENO, ο, EPOLLIN | EPOLLET | EPOLLONESHOT, l_epoll_ctl)

SarP(stdin_oor,
     is_active, bye, epoll_ctl_add_in, andor,
                                welcome, and)

SP(stdin_and) { α = 0, C(1); }
SP(stdin_not) { C(1); }
SP(stdin_set) {
  R(p_t *, oο);
  stdin_t *s = (stdin_t*)&oο[7];
  s->epollin = epollin;
  A(oο) C(1);
}
SarP(mk_stdin,
     stdin_not, stdin_and, stdin_oor, "≫", 0111, os_new_nj,
     stdin_set, and,
     STDIN_FILENO, l_setnoblock, and2)

SP(stdout_oor) {
  R(p_t*, oο);
  ο[8].p = oο;
  C(1);
}
S(stdout_and) {
  R(Q_t, m);
  if (m == 'CNK') {
    R(char*, buff);
    R(Q_t,   len);
    buff[len-1] = 0;
    print("%p %lu\n", buff, len);
    Α(buff, l_free) O;
  } else C(2);
}
SP(stdout_not) { C(1); }
SarP(mk_stdout,
     stdout_not, stdout_and, stdout_oor, "≪", 0111, os_new_nj,
     STDOUT_FILENO, l_setnoblock, and2)

SP(set) {
  R(p_t*, outο);
  R(p_t*, inο);
  R(Q_t, fd);
  epoll_fd = fd, stdinο = inο, stdoutο = outο, C(1);
}

SarP(init, 5, l_epoll_create, mk_stdin, and,
                             mk_stdout, and,
                                   set, and,
                         loop_in_queue, and)

Nar(example, stdoutο, gor, stdinο, os_queue);

Nar(ls, exports, os_ls)

// clang-format off
EN(tail,
ls,                 L)EN(L,
example,      exports)
