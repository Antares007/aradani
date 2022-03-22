#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
dot,                L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
os_new_psn,         L)IN(L,
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

epoll_ctl_add_in,   L)IN(L,
epoll_ctl_del_in,   imports)


Sargo(init)(god)

Sarg2(reject )(lο,p_t*, rο,p_t*)(lο, got, rο, 2, os_queue_n)
Sarg2(greet  )(lο,p_t*, rο,p_t*)(rο, gor, lο, 2, os_queue_n)
Sarg2(greet_b)(lο,p_t*, rο,p_t*)(lο, gor, rο, 2, os_queue_n)
Sarg1(forward)(oο,p_t*         )(god, oο, os_queue)

So(set_alfa_zero)( α = 0, C(1); )

Sargo(free_sols_and_got)(
  ο[ 7].p, os_soll_free,
  ο[ 8].p, os_soll_free, and2,
  ο[ 9].p, os_soll_free, and2,
  ο[10].p, os_soll_free, and2,
                    got, and)
Sargo(new_soll_not)(ο[ 8].p, os_unsoll, dot, and, free_sols_and_got, not)
Sargo(new_soll_and)(ο[ 9].p, os_unsoll, dot, and)
Sargo(new_soll_oor)(ο[10].p, os_unsoll, dot, and)
S5(new_soll_set)(oο,        p_t*,
                 set_soll,  p_t*,
                 not_soll,  p_t*,
                 and_soll,  p_t*,
                 oor_soll,  p_t*)(
  oο[ 7].p = set_soll;
  oο[ 8].p = not_soll;
  oο[ 9].p = and_soll;
  oο[10].p = oor_soll;
  A(oο) C(1);)
Sarg7(new_soll_psn)(not_soll, p_t*,
                    and_soll, p_t*,
                    oor_soll, p_t*,
                    set_soll, p_t*,
                    oο,       p_t*,
                    size,     Q_t,
                    name,     const char*)(
  new_soll_not, new_soll_and, new_soll_oor, oο, size, name, os_new_psn,
  set_soll, not_soll, and_soll, oor_soll, new_soll_set, and5)
Sargo(new_soll_psn_a)(new_soll_psn, and4)

So(tos)( print("-> %lu\n", ο[7].p[4]); C(1); )
Sarg4(s_readable)(construct_soll, p_t*,
                  read_soll,      p_t*,
                  destroy_soll,   p_t*,
                  set_soll,       p_t*)(
  tos, tos, and, tos, and, 5, os_soll_n,
  tos, tos, and, god, and, 5, os_soll_a,
  tos, god, and, god, and, 5, os_soll_a,
  set_soll, construct_soll, read_soll, destroy_soll, 4, os_soll_a,
  ο, 512, "Š", new_soll_psn_a)
Nargo(s_stdin)(
  epoll_ctl_del_in, 1, os_soll_n,
  tos, tos, and, god, and, 5, os_soll_a,
  epoll_ctl_add_in, 1, os_soll_a,
  1,   2,   3,   4,   5,   5, os_soll_a,
  s_readable, and)

Nargo(s_writeable)(os_wordump, set_alfa_zero, and)
Sargo(nsoll)(
  tos, tos, and, tos, and, 5, os_soll_n,
  tos, tos, and, god, and, 5, os_soll_a,
  tos, god, and, god, and, 5, os_soll_a,
  1,   2,   3,   4,   5,   5, os_soll_a,
  ο, 512, "Š", new_soll_psn_a)

Sargo(example)(god, nsoll, os_queue, and)

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
