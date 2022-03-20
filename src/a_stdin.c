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
os_queue,           L)IN(L, //
and,                L)IN(L,
and2,               L)IN(L,
and3or3,            L)IN(L,
andor,              L)IN(L,
andor3,             L)IN(L,
not,                L)IN(L,
or,                 L)IN(L,
or3,                L)IN(L, //
epoll_ctl_add_in,   L)IN(L,
epoll_ctl_del_in,   L)IN(L,
epoll_ctl_mod_in, imports);

#define	STDIN_FILENO	0	/* Standard input.  */

SarP(init)(god)

typedef struct rd_t {
  n_t on_epoll_event;
  Q_t fd;
  p_t* writeable;
  Q_t is_unmuted:1;
  Q_t is_readable:1;
} rd_t;
S(on_epoll_in);
S(stdin_set) {
  R(p_t *, oο);
  rd_t *s = (rd_t *)&oο[7];
  s->on_epoll_event = on_epoll_in;
  s->fd = STDIN_FILENO;
  s->writeable = 0;
  s->is_unmuted = 0;
  s->is_readable = 0;
  A(oο) C(1);
}
SS(activate,           rd_t)( R(p_t *, oο); s->writeable = oο, C(1); )
SS(deactivate,         rd_t)( s->writeable = 0, C(1); )
SS(hi,                 rd_t)( Α(ο, gor, s->writeable, os_queue) O; )
SS(bye,                rd_t)( Α(ο, got, s->writeable, os_queue) O; )
SS(is_active,          rd_t)( C(s->writeable != 0); )
SS(is_readable,        rd_t)( C(s->is_readable != 0); )
SS(is_unmuted,         rd_t)( C(s->is_unmuted != 0); )
SS(set_unmuted,        rd_t)( s->is_unmuted = 1, C(1); )
SS(set_muted,          rd_t)( s->is_unmuted = 0, C(1); )
SS(set_readable,       rd_t)( s->is_readable = 1, C(1); )
SS(set_unreadable,     rd_t)( s->is_readable = 0, C(1); )
SS(is_goodbye,         rd_t)( R(p_t*, arg); A(arg) C(arg == s->writeable); )

SarS(queue_chunk_send, rd_t)('CNK', god, s->writeable, os_queue)

Sar(activate_and_greet)(activate, hi, and)
Sar(bye_and_deactivate)(bye, deactivate, and)

S(is_alfa_zero) { C(α == 0); }

Sar(stdin_oor)(
  is_active,
    bye_and_deactivate,
    epoll_ctl_add_in, andor,
  activate_and_greet, and)

S(loop_read);
Sar(unmute_n)(
  set_unmuted, is_readable, and,
    loop_read,
    god, andor)
Sar(unmute)(
    is_unmuted, unmute_n, or)

S(match) { R(n_t, n); R(Q_t, m); R(Q_t, l); if (l == m) n(T()); else A(l) C(0); }
Sar(stdin_and_n)(
  is_alfa_zero,
  'MUT', set_muted, match, or3,
  'UNM', unmute, match, or3,
  got, or)
Sar(stdin_and)(
  is_active,
    stdin_and_n,
    got, andor)

Sar(stdin_not_nn)(
  is_goodbye,
    deactivate,
    got, andor)
Sar(stdin_not_n)(
  epoll_ctl_del_in,
  is_alfa_zero, and,
    bye_and_deactivate,
    stdin_not_nn, andor)
Sar(stdin_not)(
  is_active,
    stdin_not_n,
    got, andor)

S(drop) { α--, C(1); }
Sar(free_chunk)(drop, l_free, and)
S(read_chunk_n) {
  R(void *, buffer);
  Α(buffer, 0x10000, ο[8].Q, l_read, free_chunk, not) O; // o[8].Q == fd
}
Sar(read_chunk)(0x10000, l_malloc, read_chunk_n, and)
S(is_eof) { R(Q_t, num); R(void*, buff); Α(buff, num) C(num == 0); };

Sar(queue_loop_read_if_unmuted)(
  loop_read, ο, os_queue)
Sar(cont_or_stop_reading)(
  is_eof,
    free_chunk, got, and,
    queue_chunk_send, queue_loop_read_if_unmuted, and, and3or3)
Sar(loop_read_send_chunks_n)(
  read_chunk,
    cont_or_stop_reading,
    set_unreadable, epoll_ctl_mod_in, and, andor3)
Sar(loop_read)(
  is_unmuted,
    loop_read_send_chunks_n,
    god, andor)
Sar(on_epoll_in)(
  set_readable, loop_read, and)

Sar(mk_stdin)(
     stdin_not, stdin_and, stdin_oor, "≫", os_new_n,
     stdin_set, and,
     STDIN_FILENO, l_setnoblock, and2)

EN(tail,
activate,           L)EN(L,
bye,                L)EN(L,
is_alfa_zero,       L)EN(L,
match,              L)EN(L,
mk_stdin,     exports);
