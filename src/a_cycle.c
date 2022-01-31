#include "arsi.h"
// clang-format off
IN(iε,
os_new,                   L)IF(L,
printf, print,            L, int, const char*, ...)IN(L,
os_queue,                 L)IN(L,
and,                      L)IN(L,
and2,                     L)IN(L,
os_ls,              imports);
// clang-format on

NP(p_or) {
  R(p_t *, oο);
  A4(ο, gor, oο, os_queue) O;
}
N(p_and) {
  R(p_t *, oο);
  R(Q_t, c);
  if (c % 100000000 == 0)
    print("p_and %lu %lu %lu\n", α, ρ, c);
  A5(c + 1, ο, god, oο, os_queue) O;
}
NP(p_not) {}
NP(mproducer) { A4(p_or, p_and, p_not, os_new) O; }

NP(c_or) {
  R(p_t *, oο);
  A4(ο, god, oο, os_queue) O;
}
N(c_and) {
  R(p_t *, oο);
  R(Q_t, c);
  if (c % 100000000 == 1)
    print("c_and %lu %lu %lu\n", α, ρ, c);
  A5(c + 1, ο, god, oο, os_queue) O;
}
NP(c_not) {}
NP(mconsumer) { A4(c_or, c_and, c_not, os_new) O; }
//                 mconsumer, gor, mproducer, os_queue
NP(counter) { A6(mconsumer, gor, mproducer, and2, os_queue, and) O; }
NP(მთავარი) { A2(0, counter) O; }

NP(list) { A2(exports, os_ls) O; }
NP(init) { C(1); }

// clang-format off
EN(tail,
list,                    L)EN(L,
მთავარი,           exports);
