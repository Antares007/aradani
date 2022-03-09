#include "arsi.h"
#include "gotgod.h"
// clang-format off
IBS(                L)IN(L,
l_epoll_create,     L)IN(L,
l_epoll_ctl,        L)IN(L,
l_epoll_wait,       L)IN(L,
l_free,             L)IN(L,
l_malloc,           L)IN(L,
l_read,             L)IN(L,
l_setnoblock,       L)IN(L,
l_write,            L)IN(L,
nar,                L)IN(L,
os_ls,              L)IN(L,
os_new_nj,          L)IN(L,
os_queue,           L)IN(L,
//
and,                L)IN(L,
and2,               L)IN(L,
andor,              L)IN(L,
andor3,             L)IN(L,
not3,               L)IN(L,
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

S(epoll_on_wait) {
  R(q_t, num);
  if (num) {
    print("\n\n*** num: %ld\n", num);
    p_t *oο = events[num - 1].data.ptr;
    Α(oο[7].c, oο, os_queue, num - 1, epoll_on_wait, and2) O;
  } else C(1);
}
Sar(epoll_get_events)(epoll_fd, events, sizeof(events) / sizeof(*events), 0, l_epoll_wait)
SarP(epoll_ctl_add_in )(epoll_fd, EPOLL_CTL_ADD, STDIN_FILENO,  ο, EPOLLIN  | EPOLLET | EPOLLONESHOT, l_epoll_ctl)
SarP(epoll_ctl_del_in )(epoll_fd, EPOLL_CTL_DEL, STDIN_FILENO,  ο, EPOLLIN  | EPOLLET | EPOLLONESHOT, l_epoll_ctl)
SarP(epoll_ctl_mod_in )(epoll_fd, EPOLL_CTL_MOD, STDIN_FILENO,  ο, EPOLLIN  | EPOLLET | EPOLLONESHOT, l_epoll_ctl)

SarP(epoll_ctl_add_out)(epoll_fd, EPOLL_CTL_ADD, STDOUT_FILENO, ο, EPOLLOUT | EPOLLET | EPOLLONESHOT, l_epoll_ctl)
SarP(epoll_ctl_del_out)(epoll_fd, EPOLL_CTL_DEL, STDOUT_FILENO, ο, EPOLLOUT | EPOLLET | EPOLLONESHOT, l_epoll_ctl)
SarP(epoll_ctl_mod_out)(epoll_fd, EPOLL_CTL_MOD, STDOUT_FILENO, ο, EPOLLOUT | EPOLLET | EPOLLONESHOT, l_epoll_ctl)

Sar(loop_in_queue)(epoll_get_events, epoll_on_wait, and, loop_in_queue, and, ο[Φ].p, os_queue)

S(drop) { α--, C(1); }
S(read_stdin_n) {
  R(void *, buffer);
  Α(buffer, 0x10000, STDIN_FILENO, l_read,
    drop, l_free, and, not3) O;
}
Sar(read_stdin)(0x10000, l_malloc, read_stdin_n, and)

S(is_eof             ) { R(Q_t, num); R(void*, buff); Α(buff, num) C(num == 0); };
S(match              ) { R(n_t, n); R(Q_t, m); R(Q_t, l); if (l == m) n(T()); else A(l) C(0); }
S(greet              ) { R(p_t*, pο); R(p_t*, cο); Α(cο, gor, pο, os_queue) O; }
S(activate           ) { R(p_t *, oο); ο[8].p = oο, C(1); }
S(deactivate         ) { ο[8].p = 0, C(1); }
S(hi                 ) { Α(ο, gor, ο[8].p, os_queue) O; }
S(bye                ) { Α(ο, got, ο[8].p, os_queue) O; }
S(activate_and_greet ) { Α(activate, hi, and) O; }
S(stop_and_deactivate) { Α(bye, deactivate, and) O; }
S(is_readable        ) { C(ο[10].Q != 0); }
S(is_active          ) { C(ο[8].p != 0); }
S(is_unmuted         ) { C(ο[9].Q != 0); }
SP(set_unmuted       ) { ο[9].Q = 1, C(1); }
SP(set_muted         ) { ο[9].Q = 0, C(1); }
SP(set_readable      ) { ο[10].Q = 1, C(1); }
SP(set_unreadable    ) { ο[10].Q = 0, C(1); }


S(loop_read_send_chunks);
Sar(queue_loop_read_send_chunks)(
  loop_read_send_chunks, ο, os_queue)

Sar(queue_chunk_send)('CNK', god, ο[8].p, os_queue)

Sar(loop_read_send_chunks_n)(
  read_stdin,
    is_eof, queue_chunk_send, queue_chunk_send, queue_loop_read_send_chunks, and, andor3,
    set_unreadable, epoll_ctl_mod_in, and,
    0063, nar)
Sar(loop_read_send_chunks)(
  is_unmuted,
    loop_read_send_chunks_n,
    god, andor)
S(is_alfa_zero) { C(α == 0); }
/****************************************************************************** 
 *                       pith of STDIN                                        *
 ******************************************************************************/
Sar(stdin_oor)(
  is_active,
    stop_and_deactivate,
    epoll_ctl_add_in, andor,
  activate_and_greet, and)

Sar(stdin_mute)(
  is_unmuted,
    set_muted,
    god, andor);

Sar(stdin_unmute_n)(
  set_unmuted, is_readable, and,
    loop_read_send_chunks,
    epoll_ctl_mod_in, andor)
Sar(stdin_unmute)(
    is_unmuted, stdin_unmute_n, or)

Sar(stdin_and_n)(
  is_alfa_zero,
  'MUT', stdin_mute,  match, or3,
  'UNM', stdin_unmute,  match, or3,
  got, or)
Sar(stdin_and)(
  is_active,
    stdin_and_n,
    got, andor)

Sar(stdin_not_n)(
  is_alfa_zero,
    bye,
    god, andor,
  epoll_ctl_del_in, and)
Sar(stdin_not)(
  is_active,
    stdin_not_n,
    got, andor)

Sar(on_epoll_in)(
  set_readable, loop_read_send_chunks, and)
  //7   ) epoll on wait word
  //8  0) Unactive
  //   *) Pith (p_t*) of active consumer
  //9  0) Muted
  //   1) Unmuted
  //10 0) EAGAIN no more data to read register epoll event  waiting EPOLLIN event
  //   1) Readable can read until EAGAIN
S(stdin_set) {
  R(p_t *, oο); oο[7].c = on_epoll_in, oο[8].p = 0, oο[9].Q = 0, oο[10].Q = 0, A(oο) C(1);
}
Sar(mk_stdin)(
     stdin_not, stdin_and, stdin_oor, "≫", 0111, os_new_nj,
     stdin_set, and,
     STDIN_FILENO, l_setnoblock, and2)

/****************************************************************************** 
 *                       pith of STDOUT                                       *
 ******************************************************************************/
#include "os/queue.h"
SP(is_writeable          ) { C(ο[9].Q != 0); }
SP(set_writeable         ) {   ο[9].Q = 1, C(1); }
SP(unset_writeable       ) {   ο[9].Q = 0, C(1); }

SP(is_overflow           ) { C(ο[13].Q > 15); }

SP(ensure_producer_is_muted     ) { if (!ο[12].Q) ο[12].Q = 1, Α('MUT', god, ο[8].p, os_queue) O; else C(1); }
SP(ensure_producer_is_unmuted   ) { if ( ο[12].Q) ο[12].Q = 0, Α('UNM', god, ο[8].p, os_queue) O; else C(1); }

SarP(stdout_oor_n)(
  activate, ensure_producer_is_unmuted, and,
  epoll_ctl_add_out, and)
SarP(stdout_oor)(
    is_active,
      got,
      stdout_oor_n, andor)
N(chunk_free) {
  R(Q_t,   len);
  R(char*, buff);
  buff[len - 1] = 0;
  print("%p %lu\n", buff, len);
  Α(buff, l_free) O;
}
SP(dequeue_chunk) {
  p_t *q;
  if (&ο[10] == (q = (p_t *)QUEUE_NEXT((QUEUE *)&ο[10]))) C(0);
  else ο[13].Q--, QUEUE_REMOVE((QUEUE*)q), Α(q[2].v, q[3].Q, q[4].Q, q, l_free) O;
}
SP(queue_chunk_tail_and_cpp) { R(p_t *, q); ο[13].Q++, QUEUE_INSERT_TAIL((QUEUE *)&ο[10], (QUEUE *)q), C(1); }
SP(queue_chunk_head_and_cpp) { R(p_t *, q); ο[13].Q++, QUEUE_INSERT_HEAD((QUEUE *)&ο[10], (QUEUE *)q), C(1); }
SP(make_queue_item_n) {
  R(p_t *, q);
  R(Q_t, off);
  R(Q_t, len);
  R(void*, buff);
  q[2].v = buff, q[3].Q = len, q[4].Q = off, A(q) C(1);
}
SarP(make_queue_item)(5 * 8, l_malloc, make_queue_item_n, and)
SarP(queue_chunk_tail)(make_queue_item, queue_chunk_tail_and_cpp, and)
SarP(queue_chunk_head)(make_queue_item, queue_chunk_head_and_cpp, and)

S(queue_loop_write);
NarP(on_chunk)(
  0, queue_chunk_tail, is_overflow, and,
    ensure_producer_is_muted,
    god, andor,
  queue_loop_write, and)
SarP(stdout_and_n)(
  is_alfa_zero,
  'CNK', on_chunk,  match, or3,
  got, or)
SarP(stdout_and)(
  is_active,
    stdout_and_n,
    got, andor)

SarP(stdout_not_n)(
  is_alfa_zero,
    bye,
    god, andor,
  epoll_ctl_del_out, and)
SarP(stdout_not)(
  is_active,
    stdout_not_n,
    got, andor)
SP(is_fully_written) {
  R(Q_t, off);
  R(Q_t, len);
  A2(len, off) C(len == 0);
}
SP(drop_chunk) { α -= 3, C(1); }
SarP(cant_write_eagain)(
  unset_writeable, epoll_ctl_mod_out, and)
S(loop_write);
SarP(queue_loop_write)(
  loop_write, ο, os_queue)
SarP(loop_write_nnn)(
  is_fully_written,
    drop_chunk,
    queue_chunk_head, andor,
  queue_loop_write, and)
SarP(loop_write_nn)(
  STDOUT_FILENO, l_write,
    loop_write_nnn,
    cant_write_eagain, andor)
SarP(loop_write_n)(
  dequeue_chunk, 
    loop_write_nn,
    ensure_producer_is_unmuted, andor)
SarP(loop_write)(
  is_writeable,
    loop_write_n,
    epoll_ctl_mod_out, andor)
SarP(on_epoll_out)(
  set_writeable, loop_write, and)
  // 7   ) epoll on wait word
  // 8  0) Unactive
  //    *) Pith (p_t*) of active consumer
  // 9  0) EAGAIN no more data can be written. register epoll event and wait EPOLLOUT event
  //    1) Writable can write until EAGAIN
  // 10    QUEUE
  // 11    QUEUE
  // 12 0) producer unmuted
  //    1) producer muted
  // 13    queue length
S(stdout_set) {
  R(p_t*, oο);
  oο[7].c = on_epoll_out;
  oο[8].p = 0;
  oο[9].Q = 0;
  QUEUE_INIT((QUEUE*)&oο[10]);
  oο[12].Q = 1;
  oο[13].Q = 0;
  A(oο) C(1);
}
Sar(mk_stdout)(
  stdout_not, stdout_and, stdout_oor, "≪", 0111, os_new_nj,
  STDOUT_FILENO, l_setnoblock, and2,
  stdout_set, and)

S(set) {
  R(p_t*, outο);
  R(p_t*, inο);
  R(Q_t, fd);
  epoll_fd = fd, stdinο = inο, stdoutο = outο, C(1);
}

Sar(init)(
  5, l_epoll_create, mk_stdin, and,
  mk_stdout, and,
  set, and,
  loop_in_queue, and,
  exports, debug_init, and2)

Nar(example)(
  stdoutο, stdinο, greet);

Nar(ls)(
  exports, os_ls)

// clang-format off
EN(tail,
ls,                 L)EN(L,
example,      exports)
