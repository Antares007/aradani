#include "arsi.h"
// clang-format off
IN(0,
os_delete,             L)IN(L,
os_new,                L)int(*print)(const char*, ...);I(L,
printf, print,         L)IN(L,
//
os_next,               L)IN(L,
os_queue,              L)IN(L,
//
and,                   L)IN(L,
and2,                  L)IN(L,
or,                    L)IN(L,
//
s_pith,           import);

N(god) { C(1); }
N(gor) { C(1); }

N(p_or) {
  R(p_t *, oσ);
  print("p_or\n");
  A5(σ, gor, oσ, 3, os_queue) X;
}
N(p_and) {
  R(p_t *, oσ);
  R(Q_t, c);
  if (c % 10000000 == 0) print("p_and %ld\n", c);
  A6(c + 1, σ, god, oσ, 3, os_queue) X;
}
N(p_not) { print("p_not\n"); }
N(mproducer) { A6(p_or, p_and, p_not, 0x700, 0x0, os_new) O; }

N(c_or) {
  R(p_t *, oσ);
  print("c_or\n");
  A5(σ, god, oσ, 3, os_queue) X;
}
N(c_and) {
  R(p_t *, oσ);
  R(Q_t, c);
  if (c % 10000000 == 1) print("c_and %ld\n", c);
  A6(c + 1, σ, god, oσ, 3, os_queue) X;
}
N(c_not)     { print("c_not\n"); }
N(mconsumer) { A6(c_or, c_and, c_not, 0x700, 0x0, os_new) O; }

N(მთავარი) { A8(0, mconsumer, gor, mproducer, and2, 3, os_queue, and2) O; }

N(updater) { A2(მთავარი, and) C(1); }
void init() { updateσ(s_pith, updater); }

EN(tail,
s_pith,              export);
