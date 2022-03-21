#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
nar,                L)IN(L,
os_new,             L)IN(L,
os_next,            L)IN(L,
os_queue_and,       L)IN(L,
and,                L)IN(L,
and2,               L)IN(L,
not,                L)IN(L,
or,           imports);
// clang-format on
SarP(init)(god)

SP(p_or) {
  R(p_t *, oο);
  R(Q_t, c);
  Α(god, c, ο, gor, oο, 3, os_queue_and) O;
}
S(p_and) {
  R(p_t *, oο);
  R(Q_t, c);
  if (c % 100000000 == 0)
    print("%p p_and %lu\n", σ, c);
  Α(god, c + 1, ο, god, oο, 3, os_queue_and) O;
}
S(p_not) {}
SP(mproducer) { Α(p_not, p_and, p_or, os_new) O; }

SP(c_or) {
  R(p_t *, oο);
  R(Q_t, c);
  Α(god, c, ο, god, oο, 3, os_queue_and) O;
}
S(c_and) {
  R(p_t *, oο);
  R(Q_t, c);
  if (c % 100000000 == 1)
    print("%p c_and %lu\n", σ, c);
  Α(god, c + 1, ο, god, oο, 3, os_queue_and) O;
}
S(c_not) {}
SP(mconsumer) { Α(c_not, c_and, c_or, os_new) O; }

SP(counter_n) {
  R(p_t *, pο);
  R(p_t *, cο);
  R(Q_t, c);
  Α(god, c, cο, gor, pο, 3, os_queue_and) O;
}

S(counter) { AS(mconsumer, mproducer, and, counter_n, and) O; }
S(მთავარი) { AS(0, counter) O; }

// clang-format off
EN(tail, 
მთავარი,      exports);
