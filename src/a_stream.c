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

Nargo(example)(got)
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
