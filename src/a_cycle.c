#include "arsi.h"
#include "gotgod.h"
// clang-format off
IBS(                L)IN(L,
nar,                L)IN(L,
os_new_psn,         L)IN(L,
os_queue,           L)IN(L,

and,                L)IN(L,
and2,               L)IN(L,
not,                L)IN(L,
or,           imports);
// clang-format on
N(init) { C(1); }

S(p_or) {
  R(p_t *, oο);
  AS(ο, gor, oο, os_queue) O;
}
SP(p_and_log) {}
S(p_and) {
  R(p_t *, oο);
  R(Q_t, c);
  if (c % 100000000 == 0)
    p_and_log(T());
  AS(c + 1, ο, god, oο, os_queue) O;
}
S(p_not) {}
S(mproducer) { AS(p_or, p_and, p_not, ο, 512, "prod", os_new_psn) O; }

S(c_or) {
  R(p_t *, oο);
  AS(ο, god, oο, os_queue) O;
}
SP(c_and_log) {}
S(c_and) {
  R(p_t *, oο);
  R(Q_t, c);
  if (c % 100000000 == 1)
    c_and_log(T());
  AS(c + 1, ο, god, oο, os_queue) O;
}
S(c_not) {}
S(mconsumer) { AS(c_or, c_and, c_not, ο, 512, "cons", os_new_psn) O; }

S(counter_n) {
  R(p_t *, pο);
  R(p_t *, cο);
  AS(cο, gor, pο, os_queue, pο, god, and2) O;
}

S(counter) { AS(mconsumer, mproducer, and, counter_n, and) O; }
S(მთავარი) { AS(0, counter) O; }

// clang-format off
EN(tail, 
მთავარი,      exports);
