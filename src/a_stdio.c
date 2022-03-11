#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
and,                L)IN(L,
//
greet,              L)IN(L,
mk_stdin,           L)IN(L,
mk_stdout,    imports)

static p_t* stdinο;
static p_t* stdoutο;

S(set) {
  R(p_t*, outο);
  R(p_t*, inο);
  stdinο = inο, stdoutο = outο, C(1);
}
Sar(init)(
  mk_stdin, mk_stdout, and,
  set, and)

Nar(example)(stdoutο, stdinο, greet);

// clang-format off
EN(tail,
example,      exports)
