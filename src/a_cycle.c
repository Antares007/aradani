#include "arsi.h"
#include "gotgod.h"
// clang-format off
IBS(                L)IN(L,
nar,                L)IN(L,
os_new,             L)IN(L,
os_next,            L)IN(L,
os_queue,           L)IN(L,

and,                L)IN(L,
and2,               L)IN(L,
not,                L)IN(L,
or,           imports);
// clang-format on
N(init) { C(1); }

SP(p_or) {
  R(p_t *, oο);
  Α(ο, gor, oο, os_queue) O;
}
SP(p_and_log) {}
S(p_and) {
  R(p_t *, oο);
  R(Q_t, c);
  if (c % 100000000 == 0)
    p_and_log(T());
  Α(c + 1, ο, god, oο, os_queue) O;
}
S(p_not) {}
SP(mproducer) { Α(p_or, p_and, p_not, os_new) O; }

SP(c_or) {
  R(p_t *, oο);
  Α(ο, god, oο, os_queue) O;
}
SP(c_and_log) {}
S(c_and) {
  R(p_t *, oο);
  R(Q_t, c);
  if (c % 100000000 == 1)
    c_and_log(T());
  Α(c + 1, ο, god, oο, os_queue) O;
}
S(c_not) {}
SP(mconsumer) { Α(c_or, c_and, c_not, os_new) O; }

SP(counter_n) {
  R(p_t *, pο);
  R(p_t *, cο);
  Α(cο, gor, pο, os_queue) O;
}

S(counter) { AS(mconsumer, mproducer, and, counter_n, and) O; }
S(მთავარი) { AS(0, counter) O; }

// clang-format off
EN(tail, 
მთავარი,      exports);
