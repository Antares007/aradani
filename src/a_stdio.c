#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
os_queue,           L)IN(L, //
and,                L)IN(L, //
mk_stdin,           L)IN(L,
mk_stdout,    imports)

static p_t* stdinο;
static p_t* stdoutο;

S(set) {
  R(p_t*, outο);
  R(p_t*, inο);
  stdinο = inο, stdoutο = outο, C(1);
}
SarP(init)(
  mk_stdin, mk_stdout, and,
  set, and)
S(greet) { R(p_t*, pο); R(p_t*, cο); Α(cο, gor, pο, os_queue) O; }
Nar(example)(stdoutο, stdinο, greet);

EN(tail,
example,      exports)
