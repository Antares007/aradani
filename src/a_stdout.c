#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
l_close,            L)IN(L,
l_free,             L)IN(L,
l_malloc,           L)IN(L,
l_setnoblock,       L)IN(L,
l_write,            L)IN(L,
nar,                L)IN(L,
os_new_n,           L)IN(L,
os_queue,           L)IN(L,
//
and,                L)IN(L,
and2,               L)IN(L,
and2or,             L)IN(L,
and3or,             L)IN(L,
andor,              L)IN(L,
andor3,             L)IN(L,
or,                 L)IN(L,
or2,                L)IN(L,
or3,                L)IN(L,
//
q_for_each,         L)IN(L,
q_pop,              L)IN(L,
q_push,             L)IN(L,
q_remove,           L)IN(L,
q_shift,            L)IN(L,
q_unshift,          L)IN(L,
//
epoll_ctl_add_out,  L)IN(L,
epoll_ctl_del_out,  L)IN(L,
epoll_ctl_mod_out,  L)IN(L,
//
is_alfa_zero,       L)IN(L,
match,        imports)

#include "unistd.h"
#include "os/queue.h"

typedef struct wr_t {
  n_t on_epoll_event;
  Q_t fd;
  QUEUE readables_queue;
  QUEUE chunks_queue;
  Q_t queue_length;
  Q_t is_writeable:1;
  Q_t is_readables_unmuted:1;
} wr_t;

SS(set_writeable,   wr_t)( s->is_writeable = 1, C(1); )
SS(unset_writeable, wr_t)( s->is_writeable = 0, C(1); )
SS(is_overflow,     wr_t)( C(s->queue_length > 15); )

Sar(bye_all)(god) // remove all readables from queue
Sar(is_writeable)(god) // if is_writable
Sar(is_active)(god) // if readables queue is not empty
Sar(add_to_readables_queue)(god) // add to queue
Sar(remove_readable)(god) // remove from queue if it is in queue
 
S(unmute_reader) { R(p_t*, rο); Α('UNM', god, rο, os_queue) O; }

Sar(mute_readable)(god)
Sar(unmute_readable)(god)

// Α(unmute_reader, &s->readables_queue, q_for_each) O;
SS(q_cpp,                     wr_t)( s->queue_length++, C(1); )
SS(q_cmm,                     wr_t)( s->queue_length--, C(1); )
SS(is_readables_unmuted,      wr_t)( C(s->is_readables_unmuted); )
SS(toggle_readables_unmuted,  wr_t)( s->is_readables_unmuted = !s->is_readables_unmuted, C(1); )
SarS(chunk_shift,             wr_t)(&s->chunks_queue, q_shift,   q_cmm, and)
SarS(chunk_push,              wr_t)(&s->chunks_queue, q_push,    q_cpp, and)
SarS(chunk_unshift,           wr_t)(&s->chunks_queue, q_unshift, q_cpp, and)
SarS(mute_all_readables,      wr_t)(mute_readable, &s->readables_queue, q_for_each)
SarS(unmute_all_readables,    wr_t)(unmute_readable, &s->readables_queue, q_for_each)

Sar(ensure_all_readables_is_muted)(
  is_readables_unmuted, toggle_readables_unmuted, mute_all_readables, and2)
Sar(ensure_all_readables_is_unmuted)(
  is_readables_unmuted, toggle_readables_unmuted, unmute_all_readables, or2)


N(chunk_free) { α -= 2; R(char*, buff); Α(buff, l_free) O; }

S(queue_loop_write);
Sar(on_chunk)(
  0, chunk_push, is_overflow, and,
    ensure_all_readables_is_muted,
    god, andor,
  queue_loop_write, and)

Sar(stdout_and_n)(
  is_alfa_zero,
  'CNK', on_chunk,  match, or3,
  got, or)
Sar(stdout_and)(
  is_active,
    stdout_and_n,
    got, andor)

Sar(stdout_oor_n)(
  is_writeable,
    dup, unmute_reader,
    god, and2or,
  add_to_readables_queue, and)
Sar(stdout_oor)(
  is_active, epoll_ctl_add_out, or, stdout_oor_n, and)

Sar(stdout_not_nn)(
  remove_readable,
    is_active, epoll_ctl_del_out, or,
    got, and3or)
Sar(stdout_not_n)(
  is_alfa_zero,
    bye_all, epoll_ctl_del_out, and,
    stdout_not_nn, and3or)
Sar(stdout_not)(
  is_active,
    stdout_not_n,
    got, andor)

S(is_fully_written) {
  R(Q_t, off);
  R(Q_t, len);
  A2(len, off) C(len == 0);
}
S(loop_write);
Sar(queue_loop_write)(
  loop_write, ο, os_queue)
Sar(loop_write_nnn)(
  is_fully_written,
    chunk_free,
    chunk_unshift, andor,
  queue_loop_write, and)
Sar(loop_write_nn)(
  ο[8].Q, l_write,
    loop_write_nnn,
    unset_writeable, epoll_ctl_mod_out, and, andor3)
Sar(loop_write_n)(
  chunk_shift, 
    loop_write_nn,
    ensure_all_readables_is_unmuted, andor)
Sar(loop_write)(
  is_writeable,
    loop_write_n,
    epoll_ctl_mod_out, andor)
Sar(on_epoll_out)(
  set_writeable, loop_write, and)
N(stdout_set) {
  R(p_t*, oο);
  wr_t *s = (wr_t *)&oο[7];
  s->on_epoll_event = on_epoll_out;
  s->fd = STDOUT_FILENO;
  QUEUE_INIT(&s->readables_queue);
  QUEUE_INIT(&s->chunks_queue);
  s->is_writeable = 0;
  s->is_readables_unmuted = 0;
  s->queue_length = 0;
  A(oο) C(1);
}
Sar(mk_stdout)(
  stdout_not, stdout_and, stdout_oor, "≪", os_new_n,
  STDOUT_FILENO, l_setnoblock, and2,
  stdout_set, and)
SarP(init)(god)

// clang-format off
EN(tail,
mk_stdout,      exports)
