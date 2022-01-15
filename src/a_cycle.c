#include "arsi.h"
// clang-format off
IN(0,
os_delete,                L)IN(L,
os_new,                   L)IF(L,
printf, print,            L, int, const char*, ...)IN(L,
//
and,                      L)IN(L,
and2,                     L)IN(L,
or,                       L)IN(L,
//
os_next,                  L)IN(L,
os_queue,                 L)IN(L,
//
s_pith,              import);

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
N(mproducer) { A6(p_or, p_and, p_not, 0x700, 0x0, os_new) O; }

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
N(mconsumer) { A6(c_or, c_and, c_not, 0x700, 0x0, os_new) O; }

N(მთავარი) { A7(mconsumer, gor, mproducer, and2, 3, os_queue, and2) O; }

N(init) {
  A3(0, მთავარი, and2) C(1);
}

EN(tail,
s_pith,              export);
