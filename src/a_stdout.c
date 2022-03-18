#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
l_free,             L)IN(L,
l_setnoblock,       L)IN(L,
l_write,            L)IN(L,
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
or3,                L)IN(L,
//
q_for_each,         L)IN(L,
q_push,             L)IN(L,
q_shift,            L)IN(L,
q_soll_free,        L)IN(L,
q_soll_remove,      L)IN(L,
q_unshift,          L)IN(L,
//
epoll_ctl_add_out,  L)IN(L,
epoll_ctl_del_out,  L)IN(L,
epoll_ctl_mod_out,  L)IN(L,
//
is_alfa_zero,       L)IN(L,
match,        imports)

#define	STDOUT_FILENO	1	/* Standard output. */
#include "os/queue.h"

typedef struct wr_t {
  n_t on_epoll_event;
  Q_t fd;
  p_t readables_queue[4];
  p_t chunks_queue[4];
  Q_t queue_length;
  Q_t is_writeable:1;
  Q_t is_readables_unmuted:1;
} wr_t;

S(on_epoll_out);
N(stdout_set) {
  R(p_t*, oο);
  wr_t *s = (wr_t *)&oο[7];
  for(Q_t i = 0; i < wordCountOf(wr_t); i++)
    oο[7 + i].Q = 0;
  s->on_epoll_event = on_epoll_out;
  s->fd = STDOUT_FILENO;
  s->readables_queue[0].Q = 3;
  QUEUE_INIT((QUEUE*)&s->readables_queue[1]);
  s->chunks_queue[0].Q = 3;
  QUEUE_INIT((QUEUE*)&s->chunks_queue[1]);
  A(oο) C(1);
}
SS(is_writeable,              wr_t)( C(s->is_writeable != 0); )
SS(set_writeable,             wr_t)(   s->is_writeable = 1,   C(1); )
SS(unset_writeable,           wr_t)(   s->is_writeable = 0,   C(1); )
SS(readables_queue,           wr_t)(A(&s->readables_queue[1]) C(1); )
SS(chunks_queue,              wr_t)(A(&s->chunks_queue[1])    C(1); )
SSP(is_active,                wr_t)( C((QUEUE*)&s->readables_queue[1] !=
                            QUEUE_NEXT((QUEUE*)&s->readables_queue[1])); )
SS(is_overflow,               wr_t)( C(s->queue_length > 15); )
SS(q_cpp,                     wr_t)(   s->queue_length++, C(1); )
SS(q_cmm,                     wr_t)(   s->queue_length--, C(1); )
SS(is_readables_unmuted,      wr_t)( C(s->is_readables_unmuted != 0); )
SS(toggle_readables_unmuted,  wr_t)(   s->is_readables_unmuted =
                                      !s->is_readables_unmuted, C(1); )
S(bye) { R(p_t *, oο); Α(ο, got, oο, os_queue) O; }
S(bye_nar) {
  R(p_t *, sοll);
  Α(sοll[0].p, bye,
    sοll, q_soll_remove, and2,
    sοll, q_soll_free, and2) O;
}
Sar(bye_all)(
  bye_nar, readables_queue, 1, q_for_each, and2)
S(rem_nar) {
  R(p_t *, oο);
  R(p_t *, sοll);
  if (oο == sοll[0].p) A3(bye_nar, gor, and) O;
  else C(1);
}
Sar(remove_readable)(
  rem_nar, readables_queue,
    2, q_for_each,
    god, and2or)

Sar(add_to_readables_queue)(readables_queue, q_push, and)

Sar(chunk_shift  )(chunks_queue,   q_shift, and, q_cmm, and)
Sar(chunk_push   )(chunks_queue,    q_push, and, q_cpp, and)
Sar(chunk_unshift)(chunks_queue, q_unshift, and, q_cpp, and)
S(chunk_free     ){ α -= 2; R(char*, buff); Α(buff, l_free) O; }

S(mute_readable  ){ R(p_t *, sοll); Α('MUT', god, sοll[0].p, os_queue) O; }
S(unmute_readable){ R(p_t *, sοll); Α('UNM', god, sοll[0].p, os_queue) O; }
Sar(mute_all_readables)(
  mute_readable,   readables_queue, 1, q_for_each, and2)
Sar(unmute_all_readables)(
  unmute_readable, readables_queue, 1, q_for_each, and2)
Sar(ensure_all_readables_is_muted)(
  is_readables_unmuted,
    toggle_readables_unmuted,   mute_all_readables, and,
    god, and3or)
Sar(ensure_all_readables_is_unmuted)(
  is_readables_unmuted,
    god,
    toggle_readables_unmuted, unmute_all_readables, and, andor3)

S(loop_write);
SarP(on_chunk)(
  0, chunk_push, is_overflow, and,
    ensure_all_readables_is_muted,
    god, andor,
  loop_write, and)
Sar(stdout_and_n)(
  is_alfa_zero,
  'CNK', on_chunk,  match, or3,
  got, or)
SarP(stdout_and)(
  is_active,
    stdout_and_n,
    got, andor)

S(unmut) { R(p_t*, rο); Α('UNM', god, rο, os_queue) O; }
S(dup) { R(void*, v); A2(v, v) C(1); }
SarP(stdout_oor_n)(
  is_writeable,
    dup, unmut,
    god, and2or,
  add_to_readables_queue, and)
SarP(stdout_oor)(
  is_active, epoll_ctl_add_out, or, stdout_oor_n, and)

Sar(stdout_not_nn)(
  remove_readable,
    is_active, epoll_ctl_del_out, or,
    got, and3or)
Sar(stdout_not_n)(
  is_alfa_zero,
    bye_all, epoll_ctl_del_out, and,
    stdout_not_nn, and3or)
SarP(stdout_not)(
  is_active,
    stdout_not_n,
    got, andor)

S(is_fully_written) { R(Q_t, off); R(Q_t, len); A2(len, off) C(len == 0); }
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
SarP(loop_write)(
  is_writeable,
    loop_write_n,
    epoll_ctl_mod_out, andor)
SarP(on_epoll_out)(
  set_writeable, loop_write, and)

Sar(mk_stdout)(
  stdout_not, stdout_and, stdout_oor, "≪", os_new_n,
  STDOUT_FILENO, l_setnoblock, and2,
  stdout_set, and)

SarP(init)(god)

// clang-format off
EN(tail,
mk_stdout,      exports)
