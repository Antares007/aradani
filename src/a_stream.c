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
os_soll_n,          L)IN(L,
os_unsoll,          L)IN(L,
os_wordump,         L)IN(L,

and,                L)IN(L,
and4,               L)IN(L,
and5,               L)IN(L,
andor,        imports)

SarP(init)(god)

S(reject ) { R(p_t*, rο); R(p_t*, lο); Α(lο, got, rο, 2, os_queue_n) O; }
S(forward) { R(p_t*, oο);              Α(    god, oο,    os_queue  ) O; }
S(greet  ) { R(p_t*, rο); R(p_t*, lο); Α(rο, gor, lο, 2, os_queue_n) O; }
S(greet_b) { R(p_t*, rο); R(p_t*, lο); Α(lο, gor, rο, 2, os_queue_n) O; }

S(set_alfa_zero) { α = 0, C(1); } 

Sar(new_soll_not)(ο[ 8].p, os_unsoll, dot, and)
Sar(new_soll_and)(ο[ 9].p, os_unsoll, dot, and)
Sar(new_soll_oor)(ο[10].p, os_unsoll, dot, and)
S(new_soll_set) {
  R(p_t *, not_soll);
  R(p_t *, and_soll);
  R(p_t *, oor_soll);
  R(p_t *, set_soll);
  R(p_t *, oο);
  oο[ 7].p = set_soll;
  oο[ 8].p = not_soll;
  oο[ 9].p = and_soll;
  oο[10].p = oor_soll;
  A(oο) C(1);
}
S(new_soll_psn) {
  R(const char*, name);
  R(Q_t, size);
  R(p_t *, oο);
  R(p_t *, set_soll);
  R(p_t *, oor_soll);
  R(p_t *, and_soll);
  R(p_t *, not_soll);
  Α(new_soll_not, new_soll_and, new_soll_oor, oο, size, name, os_new_psn,
    set_soll, oor_soll, and_soll, not_soll, new_soll_set, and5) O;
}
Sar(new_soll_psn_a)(new_soll_psn, and4)

Nar(s_readable )(os_wordump, set_alfa_zero, and)
Nar(s_writeable)(os_wordump, set_alfa_zero, and)
S(tos) {
  print("-> %lu\n", ο[7].p[4]);
  C(1);
}
Sar(nsoll)(
  tos, tos, and, tos, and, 5, os_soll_n,
  tos, tos, and, god, and, 5, os_soll_a,
  tos, god, and, god, and, 5, os_soll_a,
  1,   2,   3,   4,   5,   5, os_soll_a,
  ο, 512, "Š", new_soll_psn_a)

Sar(example)(
  god, nsoll, os_queue, and
)

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
