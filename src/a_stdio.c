#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
os_new_n,           L)IN(L,
os_queue,           L)IN(L,
and,                L)IN(L,
and2,               L)IN(L,
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
S(greet) { R(p_t*, cο); R(p_t*, pο); Α(cο, gor, pο, os_queue) O; }

SarP(trans_oor)(gor)
SarP(trans_and)(god)
SarP(trans_not)(got)
SarP(trans)(trans_not, trans_and, trans_oor, "T", os_new_n)

Nar(example)(stdinο, trans, greet, and
             //, stdoutο, greet, and2
             );

EN(tail,
example,      exports)
