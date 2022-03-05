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
and2or3,            L)IN(L,
and3,               L)IN(L,
and3or,             L)IN(L,
and6,               L)IN(L,
andor,              L)IN(L,
andor3,             L)IN(L,
not,                L)IN(L,
not2,               L)IN(L,
not2and2,           L)IN(L,
notand4or,          L)IN(L,
or,                 L)IN(L,
or3,                L)IN(L,
//
debug_init,         L)IN(L,
debug_οdump,        L)IN(L,
debug_σdump,  imports);
#include "unistd.h"
#include <sys/epoll.h>

static p_t* stdinο;
static p_t* stdoutο;
static Q_t  epoll_fd;
struct epoll_event events[2];

S(epoll_get_events);
S(reset_in);
S(epollin);
S(read_stdin);
S(is_eof);
S(eagain) { Α(reset_in) O; }

Sar(queue_chunk_send, 'CNK', god, ο[8].p, os_queue)
Sar(queue_epollin, epollin, ο, os_queue)
Sar(epollin,
    read_stdin,
    is_eof, queue_chunk_send,
            queue_chunk_send, queue_epollin, and, andor3,
    eagain,
    0061, nar, 'NOP', god, and2)

S(process_events) {
  R(q_t, num);
  if (num) {
    p_t *oο = events[num - 1].data.ptr;
    Α(oο[7].c, oο, os_queue, num - 1, process_events, and2) O;
  } else C(1);
}
Sar(loop_in_queue,
    epoll_get_events, process_events, and, loop_in_queue, and, ο[Φ].p, os_queue)

S(hi) { R(p_t*, pο); R(p_t*, cο); Α(cο, gor, pο, os_queue) O; }
S(welcome) { R(p_t *, oο); ο[8].p = oο; A4(ο, gor, ο[8].p, os_queue) O; }
S(bye) { A4(ο, got, ο[8].p, os_queue) ο[8].p = 0, O; }
S(is_active) { C(ο[8].p != 0); }
Sar(epoll_ctl_add_in,
    epoll_fd, EPOLL_CTL_ADD, STDIN_FILENO, ο, EPOLLIN | EPOLLET | EPOLLONESHOT, l_epoll_ctl)
Sar(epoll_ctl_del_in,
    epoll_fd, EPOLL_CTL_DEL, STDIN_FILENO, ο, EPOLLIN | EPOLLET | EPOLLONESHOT, l_epoll_ctl)

S(Match) { R(n_t, n); R(Q_t, m); R(Q_t, l); if (l == m) n(T()); else A(l) C(0); }

/****************************************************************************** 
 *                       pith of STDIN                                        *
 ******************************************************************************/
SarP(stdin_oor,
     is_active, bye, epoll_ctl_add_in, andor,
                                welcome, and)
Sar(mute, god);
Sar(unmute, god);
Sar(stdin_and_n,
    'NOP', god, Match,  
    'MUT', mute,  Match, or3,
    'UNM', unmute,  Match, or3,
                        got, or)
SarP(stdin_and,
    is_active, stdin_and_n, got, andor)
SarP(stdin_not,
    epoll_ctl_del_in)
S(stdin_set) {
  R(p_t *, o_ο);
  o_ο[7].Q = 0; // 0) Readable can read until EAGAIN
                // 1) EAGAIN no more data to read register epoll event
                // 2) waiting EPOLLIN event
  o_ο[8].p = 0; // 0) Unactive
                // *) Pith (p_t*) of active consumer
  o_ο[9].Q = 0; // 0) Muted
                // 1) Unmute
  A(o_ο) C(1);
}
SarP(mk_stdin,
     stdin_not, stdin_and, stdin_oor, "≫", 0111, os_new_nj,
     stdin_set, and,
     STDIN_FILENO, l_setnoblock, and2)

/****************************************************************************** 
 *                       pith of STDOUT                                       *
 ******************************************************************************/
SP(stdout_oor) {
  R(p_t*, oο);
  ο[8].p = oο;
  C(1);
}
SP(stdout_and) {
  R(Q_t, m);
  if (m == 'CNK') {
    R(char*, buff);
    R(Q_t,   len);
    buff[len-1] = 0;
    print("%p %lu\n", buff, len);
    Α('MUT', god, ο[8].p, os_queue, buff, l_free, and2) O;
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
                         loop_in_queue, and,
                   exports, debug_init, and2)
Nar(example, stdoutο, stdinο, hi);

Nar(ls, exports, os_ls)

// clang-format off
EN(tail,
ls,                 L)EN(L,
example,      exports)

S(read_stdin_n) {
  R(void *, buffer);
  Α(STDIN_FILENO, buffer, 0x10000, l_read, buffer, l_free, buffer, god, not2and2) O;
}
Sar(read_stdin, 0x10000, l_malloc, read_stdin_n, and)
S(is_eof) {
  R(void*, buff);
  R(Q_t, num);
  Α(num, buff) C(num == 0);
};
Sar(epoll_get_events,
    epoll_fd, events, sizeof(events) / sizeof(*events), 0, l_epoll_wait)
Sar(reset_in, epoll_fd, EPOLL_CTL_MOD, STDIN_FILENO, ο, EPOLLIN | EPOLLET | EPOLLONESHOT, l_epoll_ctl)
