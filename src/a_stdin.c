#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
l_free,             L)IN(L,
l_malloc,           L)IN(L,
l_read,             L)IN(L,
l_setnoblock,       L)IN(L,
nar,                L)IN(L,
os_ls,              L)IN(L,
os_new_n,           L)IN(L,
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
epoll_ctl_add_in,   L)IN(L,
epoll_ctl_del_in,   L)IN(L,
epoll_ctl_mod_in, imports);
#include "unistd.h"
N(greet              ) { R(p_t*, pο); R(p_t*, cο); Α(cο, gor, pο, os_queue) O; }
SarP(init)(god)

S(drop) { α--, C(1); }
S(read_stdin_n) {
  R(void *, buffer);
  Α(buffer, 0x10000, STDIN_FILENO, l_read,
    drop, l_free, and, not3) O;
}
Sar(read_stdin)(0x10000, l_malloc, read_stdin_n, and)

typedef struct readable_t {
  n_t on_epoll_event;
  Q_t fd;
  p_t* writeable;
  Q_t is_unmuted:1;
  Q_t is_readable:1;
} readable_t;

S(is_eof               ) { R(Q_t, num); R(void*, buff); Α(buff, num) C(num == 0); };
S(match                ) { R(n_t, n); R(Q_t, m); R(Q_t, l); if (l == m) n(T()); else A(l) C(0); }
SS(activate, readable_t   )( R(p_t *, oο); s->writeable = oο, C(1); )
SS(deactivate, readable_t )( s->writeable = 0, C(1); )
SS(hi, readable_t         )( Α(ο, gor, s->writeable, os_queue) O; )
SS(bye, readable_t        )( Α(ο, got, s->writeable, os_queue) O; )
S(activate_and_greet ) { Α(activate, hi, and) O; }
S(stop_and_deactivate) { Α(bye, deactivate, and) O; }
SS(is_readable, readable_t   )( C(s->is_readable != 0); )
SS(is_active, readable_t     )( C(s->writeable != 0); )
SS(is_unmuted, readable_t    )( C(s->is_unmuted != 0); )
SS(set_unmuted, readable_t   )( s->is_unmuted = 1, C(1); )
SS(set_muted, readable_t     )( s->is_unmuted = 0, C(1); )
SS(set_readable, readable_t  )( s->is_readable = 1, C(1); )
SS(set_unreadable, readable_t)( s->is_readable = 0, C(1); )


S(loop_read_send_chunks);
Sar(queue_loop_read_send_chunks)(
  loop_read_send_chunks, ο, os_queue)

SarS(queue_chunk_send, readable_t)('CNK', god, s->writeable, os_queue)
Sar(cont_or_stop_reading)(
  is_eof,
    queue_chunk_send,
    queue_chunk_send, queue_loop_read_send_chunks, and, andor3)
Sar(loop_read_send_chunks_n)(
  read_stdin,
    cont_or_stop_reading,
    set_unreadable, epoll_ctl_mod_in, and, andor3)
Sar(loop_read_send_chunks)(
  is_unmuted,
    loop_read_send_chunks_n,
    god, andor)
S(is_alfa_zero) { C(α == 0); }

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
S(stdin_set) {
  R(p_t *, oο);
  readable_t *s = (readable_t *)&oο[7];
  s->on_epoll_event = on_epoll_in;
  s->fd = STDIN_FILENO;
  s->writeable = 0;
  s->is_unmuted = 0;
  s->is_readable = 0;
  A(oο) C(1);
}
Sar(mk_stdin)(
     stdin_not, stdin_and, stdin_oor, "≫", os_new_n,
     stdin_set, and,
     STDIN_FILENO, l_setnoblock, and2)
Nar(ls)(
  exports, os_ls)
// clang-format off
EN(tail,
activate,           L)EN(L,
bye,                L)EN(L,
greet,              L)EN(L,
is_active,          L)EN(L,
is_alfa_zero,       L)EN(L,
match,              L)EN(L,
mk_stdin,     exports);
