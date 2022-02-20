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
void init() {}

NP(p_or) {
  R(p_t *, oο);
  AS(ο, gor, oο, os_queue) O;
}
NP(p_and_log) {}
N(p_and) {
  R(p_t *, oο);
  R(Q_t, c);
  if (c % 100000000 == 0)
    p_and_log(T());
  AS(c + 1, ο, god, oο, os_queue) O;
}
NP(p_not) {}
NP(mproducer) { AS(p_or, p_and, p_not, ο, 512, "prod", os_new_psn) O; }

NP(c_or) {
  R(p_t *, oο);
  AS(ο, god, oο, os_queue) O;
}
NP(c_and_log) {}
N(c_and) {
  R(p_t *, oο);
  R(Q_t, c);
  if (c % 100000000 == 1)
    c_and_log(T());
  AS(c + 1, ο, god, oο, os_queue) O;
}
NP(c_not) {}
NP(mconsumer) { AS(c_or, c_and, c_not, ο, 512, "cons", os_new_psn) O; }

N(counter_n) {
  R(p_t *, pο);
  R(p_t *, cο);
  AS(cο, gor, pο, os_queue, pο, god, and2) O;
}

NP(counter) { AS(mconsumer, mproducer, and, counter_n, and) O; }
NP(მთავარი) { AS(0, counter) O; }

// clang-format off
EN(tail, 
მთავარი,      exports);
