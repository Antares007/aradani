#include "arsi.h"
// clang-format off
IF(iε,
printf, print,            L, int, const char*, ...)IN(L,
os_new,                   L)IN(L,
//
and,                      L)IN(L,
and2,                     L)IN(L,
//
os_queue,                 L)p_t *oο;I(L,
//
"ο", oο,             imports);

N(p_or) {
  R(p_t *, oο);
  print("p_or\n");
  A5(ο, gor, oο, 3, os_queue) O;
}
N(p_and) {
  R(p_t *, oο);
  R(Q_t, c);
  if (c % 100000000 == 0) print("p_and %ld\n", c);
  A6(c + 1, ο, god, oο, 3, os_queue) O;
}
N(p_not) { print("p_not\n"); }
N(mproducer) { A5(p_or, p_and, p_not, 512, os_new) O; }

N(c_or) {
  R(p_t *, oο);
  print("c_or\n");
  A5(ο, god, oο, 3, os_queue) O;
}
N(c_and) {
  R(p_t *, oο);
  R(Q_t, c);
  if (c % 100000000 == 1) print("c_and %ld\n", c);
  A6(c + 1, ο, god, oο, 3, os_queue) O;
}
N(c_not)     { print("c_not\n"); }
N(mconsumer) { A5(c_or, c_and, c_not, 512, os_new) O; }

N(counter) { A7(mconsumer, gor, mproducer, and2, 3, os_queue, and2) O; }
N(მთავარი) { A5(0, counter, 0, counter, and2) O; }

N(init) { oο[oο[1].Q++].v = მთავარი, oο[oο[1].Q++].v = and, C(1); }

E(tail,
"ο", oο,              exports);
