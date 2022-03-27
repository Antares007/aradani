#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
dot,                L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
nar,                L)IN(L,
os_queue,           L)IN(L,
os_queue_n,         L)IN(L,
os_soll_a,          L)IN(L,
os_soll_free,       L)IN(L,
os_soll_n,          L)IN(L,
os_unsoll,          L)IN(L,
os_wordump,         L)IN(L,

and,                L)IN(L,
and2,               L)IN(L,
and4,               L)IN(L,
and5,               L)IN(L,
andor,              L)IN(L,
not,                L)IN(L,

new_soll_ps,        L)IN(L,
new_soll_ps_a,      L)IN(L,

epoll_ctl_add_in,   L)IN(L,
epoll_ctl_del_in,   imports)


Sargo(init)(god)

Sarg2(reject )(lο,p_t*, rο,p_t*)(lο, got, rο, 2, os_queue_n)
Sarg2(greet  )(lο,p_t*, rο,p_t*)(rο, gor, lο, 2, os_queue_n)
Sarg2(greet_b)(lο,p_t*, rο,p_t*)(lο, gor, rο, 2, os_queue_n)
Sarg1(forward)(oο,p_t*         )(god, oο, os_queue)

So(set_alfa_zero)( α = 0, C(1); )

So(tos)( print("-> %lu\n", ο[7].p[4]); C(1); )

Sargo(s_readable_not)(god)

Sargo(s_readable_and)(god)

// god, cβ, os_queue
Nargo(mk_construct_cb_pith)(
  god, 1, os_soll_n,
  god, 1, os_soll_a,
  god, 1, os_soll_a,
  god, 1, os_soll_a,
  ο, 64, new_soll_ps_a)

Sargo(unsoll_dot)(os_unsoll, dot, and)
Sargo(mkcb)(god)
Sarg2(s_readable_oor)(oο,               p_t*,
                      construct_soll,   p_t*)(
  oο,             1, os_soll_n, 
  construct_soll, 1, os_soll_a,
  mkcb,           and,
  construct_soll, and,
  unsoll_dot,     and)

Sarg4(s_readable)(construct_soll, p_t*,
                  read_soll,      p_t*,
                  destroy_soll,   p_t*,
                  set_soll,       p_t*)(
  s_readable_not, 1, os_soll_n,
  s_readable_and, 1, os_soll_a,
  construct_soll, s_readable_oor, 1, os_soll_a,
  set_soll,  read_soll, destroy_soll, 3, os_soll_a,
  ο, 512, new_soll_ps_a)

Nargo(s_stdin)(
  epoll_ctl_del_in, 1, os_soll_n,
  tos, tos, and, god, and, 5, os_soll_a,
  epoll_ctl_add_in, 1, os_soll_a,
  1,   2,   3,   4,   5,   5, os_soll_a,
  s_readable, and)

Nargo(s_writeable)(os_wordump, set_alfa_zero, and)
Sargo(nsoll)(
  tos, tos, and, got, and, 5, os_soll_n,
  tos, tos, and, god, and, 5, os_soll_a,
  tos, god, and, god, and, 5, os_soll_a,
  1,   2,   3,   4,   5,   5, os_soll_a,
  ο, 512, new_soll_ps_a)

Nargo(example)(got, nsoll, os_queue, and)


/*
  readable._construct(callback)  Call this function (optionally with an error argument) when the stream has finished initializing.
  readable._read(size)
  readable._destroy(err, callback) A callback function that takes an optional error argument.
  readable.push(chunk[, encoding]) Returns: <boolean> true if additional chunks of data may continue to be pushed; false otherwise.

  writable._construct(callback)
  writable._write(chunk, encoding, callback)
  writable._destroy(err, callback)
  writable._final(callback)

  transform._flush(callback) A callback function (optionally with an error argument and data) to be called when remaining data has been flushed.
  transform._transform(chunk, encoding, callback) A callback function (optionally with an error argument and data) to be called after the supplied chunk has been processed.
*/
EN(tail,
forward,            L)EN(L,
greet,              L)EN(L,
greet_b,            L)EN(L,
reject,             L)EN(L,
example,      exports)
