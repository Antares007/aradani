#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
co0,                L)IN(L,
co1,                L)IN(L,
co2,                L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
nar,                L)IN(L,
os_new,             L)IN(L,
os_next,            L)IN(L,
os_queue,           L)IN(L, //
and,                L)IN(L,
and2,               L)IN(L,
not,                L)IN(L,
or,           imports);
// clang-format on
SarP(init)(god)

SP(p_or) {
  R(p_t *, oο);
  Α(ο, co0, oο, os_queue) O;
}
S(p_and) {
  R(p_t *, oο);
  R(Q_t, c);
  if (c % 100000000 == 0)
    print("%p p_and %lu\n", σ, c);
  Α(c + 1, ο, co1, oο, os_queue) O;
}
S(p_not) {}
SP(mproducer) { Α(p_not, p_and, p_or, os_new) O; }

SP(c_or) {
  R(p_t *, oο);
  Α(ο, co1, oο, os_queue) O;
}
S(c_and) {
  R(p_t *, oο);
  R(Q_t, c);
  if (c % 100000000 == 1)
    print("%p c_and %lu\n", σ, c);
  Α(c + 1, ο, co1, oο, os_queue) O;
}
S(c_not) {}
SP(mconsumer) { Α(c_not, c_and, c_or, os_new) O; }

SP(counter_n) {
  R(p_t *, pο);
  R(p_t *, cο);
  Α(cο, co0, pο, os_queue) O;
}

S(counter) { Α(mconsumer, mproducer, and, counter_n, and) O; }
S(მთავარი) { Α(0, counter) O; }

// clang-format off
EN(tail, 
მთავარი,      exports);
