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
andor,              L)IN(L,
or,                 L)IN(L,
or3,                L)IN(L,
//
epoll_ctl_add_out,  L)IN(L,
epoll_ctl_del_out,  L)IN(L,
epoll_ctl_mod_out,  L)IN(L,
//
activate,           L)IN(L,
bye,                L)IN(L,
is_alfa_zero,       L)IN(L,
match,        imports)

#include "unistd.h"
#include "os/queue.h"
typedef struct writable_t {
  n_t on_epoll_event;
  p_t* readable;
  QUEUE q;
  Q_t queue_length;
  Q_t is_writeable:1;
  Q_t is_readable_muted:1;
} writable_t;

SS(set_writeable, writable_t)(
  s->is_writeable = 1, C(1);
)
SS(unset_writeable, writable_t)(
  s->is_writeable = 0, C(1);
)
SS(is_overflow, writable_t)(
  C(s->queue_length > 15);
)

SS(ensure_producer_is_muted,   writable_t)(
  if (!s->is_readable_muted)
    s->is_readable_muted = 1, Α('MUT', god, s->readable, os_queue) O;
  else
    C(1);
)
SS(ensure_producer_is_unmuted, writable_t)(
  if ( s->is_readable_muted)
    s->is_readable_muted = 0, Α('UNM', god, s->readable, os_queue) O;
  else
    C(1);
)

Sar(stdout_oor_n)(
  activate, ensure_producer_is_unmuted, and,
  epoll_ctl_add_out, and)
SarS(stdout_oor, writable_t)(s->readable ? got: stdout_oor_n)
N(chunk_free) {
  R(Q_t,   off);
  R(Q_t,   len);
  R(char*, buff);
  (void)len, (void)off;
  //print("%p %lu/%lu\n", buff, len, off);
  Α(buff, l_free) O;
}
SS(dequeue_chunk, writable_t)(
  p_t *q;
  if ((p_t*)&s->q == (q = (p_t *)QUEUE_NEXT(&s->q))) C(0);
  else s->queue_length--, QUEUE_REMOVE((QUEUE*)q), Α(q[2].v, q[3].Q, q[4].Q, q, l_free) O;
)
SS(queue_chunk_tail_and_cpp, writable_t)(
  R(QUEUE*, q);
  s->queue_length++, QUEUE_INSERT_TAIL(&s->q, q), C(1);
)
SS(queue_chunk_head_and_cpp, writable_t)(
  R(QUEUE*, q);
  s->queue_length++, QUEUE_INSERT_HEAD(&s->q, q), C(1);
)
S(make_queue_item_n) {
  R(p_t *, q);
  R(Q_t, off);
  R(Q_t, len);
  R(void*, buff);
  q[2].v = buff, q[3].Q = len, q[4].Q = off, A(q) C(1);
}
Sar(make_queue_item)(5 * 8, l_malloc, make_queue_item_n, and)
Sar(queue_chunk_tail)(make_queue_item, queue_chunk_tail_and_cpp, and)
Sar(queue_chunk_head)(make_queue_item, queue_chunk_head_and_cpp, and)

S(queue_loop_write);
Sar(on_chunk)(
  0, queue_chunk_tail, is_overflow, and,
    ensure_producer_is_muted,
    god, andor,
  queue_loop_write, and)
Sar(stdout_and_n)(
  is_alfa_zero,
  'CNK', on_chunk,  match, or3,
  got, or)
SarS(stdout_and, writable_t)(s->readable ? stdout_and_n : got)

Sar(stdout_not_n)(
  is_alfa_zero,
    bye,
    god, andor,
  epoll_ctl_del_out, and)

SarS(stdout_not, writable_t)(s->readable ? stdout_not_n: got)

S(is_fully_written) {
  R(Q_t, off);
  R(Q_t, len);
  A2(len, off) C(len == 0);
}
Sar(cant_write_eagain)(
  unset_writeable, epoll_ctl_mod_out, and)
S(loop_write);
Sar(queue_loop_write)(
  loop_write, ο, os_queue)
Sar(loop_write_4)(
  is_fully_written,
    chunk_free,
    queue_chunk_head, andor,
  queue_loop_write, and)
Sar(loop_write_3)(
  STDOUT_FILENO, l_write,
    loop_write_4,
    cant_write_eagain, andor)

S(close_stdout) { Α(STDOUT_FILENO, l_close, got, and) O; }
S(is_eof) { R(Q_t, off); R(Q_t, len); Α(len, off) C(len == 0 && off == 0); }

Sar(loop_write_2)(
  is_eof,
    close_stdout, chunk_free, and,
    loop_write_3, 0031, nar)
Sar(loop_write_n)(
  dequeue_chunk, 
    loop_write_2,
    ensure_producer_is_unmuted, andor)
SarS(loop_write, writable_t)(s->is_writeable ? loop_write_n : epoll_ctl_mod_out)
Sar(on_epoll_out)(
  set_writeable, loop_write, and)
N(stdout_set){
  R(p_t*, oο);
  writable_t *s = (writable_t *)&oο[7];
  s->on_epoll_event = on_epoll_out;
  s->readable = 0;
  s->is_writeable = 0;
  QUEUE_INIT(&s->q);
  s->is_readable_muted = 1;
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
