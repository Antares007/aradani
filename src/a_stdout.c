#include "arsi.h"
#include "gotgod.h"
// clang-format off
IBS(                L)IN(L,
l_free,             L)IN(L,
l_malloc,           L)IN(L,
l_setnoblock,       L)IN(L,
l_write,            L)IN(L,
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
is_active,          L)IN(L,
is_alfa_zero,       L)IN(L,
match,        imports)

#include "unistd.h"
#include "os/queue.h"

S(is_writeable          ) { C(ο[9].Q != 0); }
S(set_writeable         ) {   ο[9].Q = 1, C(1); }
S(unset_writeable       ) {   ο[9].Q = 0, C(1); }

S(is_overflow           ) { C(ο[13].Q > 15); }

S(ensure_producer_is_muted     ) { if (!ο[12].Q) ο[12].Q = 1, Α('MUT', god, ο[8].p, os_queue) O; else C(1); }
S(ensure_producer_is_unmuted   ) { if ( ο[12].Q) ο[12].Q = 0, Α('UNM', god, ο[8].p, os_queue) O; else C(1); }

Sar(stdout_oor_n)(
  activate, ensure_producer_is_unmuted, and,
  epoll_ctl_add_out, and)
Sar(stdout_oor)(
    is_active,
      got,
      stdout_oor_n, andor)
N(chunk_free) {
  R(Q_t,   off);
  R(Q_t,   len);
  R(char*, buff);
  (void)len, (void)off;
  //print("%p %lu/%lu\n", buff, len, off);
  Α(buff, l_free) O;
}
S(dequeue_chunk) {
  p_t *q;
  if (&ο[10] == (q = (p_t *)QUEUE_NEXT((QUEUE *)&ο[10]))) C(0);
  else ο[13].Q--, QUEUE_REMOVE((QUEUE*)q), Α(q[2].v, q[3].Q, q[4].Q, q, l_free) O;
}
S(queue_chunk_tail_and_cpp) { R(p_t *, q); ο[13].Q++, QUEUE_INSERT_TAIL((QUEUE *)&ο[10], (QUEUE *)q), C(1); }
S(queue_chunk_head_and_cpp) { R(p_t *, q); ο[13].Q++, QUEUE_INSERT_HEAD((QUEUE *)&ο[10], (QUEUE *)q), C(1); }
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
Sar(stdout_and)(
  is_active,
    stdout_and_n,
    got, andor)

Sar(stdout_not_n)(
  is_alfa_zero,
    bye,
    god, andor,
  epoll_ctl_del_out, and)
Sar(stdout_not)(
  is_active,
    stdout_not_n,
    got, andor)
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
Sar(loop_write_nnn)(
  is_fully_written,
    chunk_free,
    queue_chunk_head, andor,
  queue_loop_write, and)
Sar(loop_write_nn)(
  STDOUT_FILENO, l_write,
    loop_write_nnn,
    cant_write_eagain, andor)
Sar(loop_write_n)(
  dequeue_chunk, 
    loop_write_nn,
    ensure_producer_is_unmuted, andor)
Sar(loop_write)(
  is_writeable,
    loop_write_n,
    epoll_ctl_mod_out, andor)
Sar(on_epoll_out)(
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
  stdout_not, stdout_and, stdout_oor, "≪", os_new_n,
  STDOUT_FILENO, l_setnoblock, and2,
  stdout_set, and)
Sar(init)(god)

// clang-format off
EN(tail,
mk_stdout,      exports)
