#include "arsi.h"
// clang-format off
IN(gor,
and,                   L)IN(L,
and2,                  L)IN(L,
or,                    L)IN(L,
//
os_new,                L)IN(L,
os_next,               L)IN(L,
os_queue,              L)int(*print)(const char*, ...);I(L,
printf, print,         L)IN(L,
debugger,         import);

// this is nice example where we can
// see execution "line" (like line from Chess game).
N(p_or) {
  R(p_t *, oσ);
  print("p_or\n");
  A5(σ, gor, oσ, 3, os_queue) X;
}
N(p_and) {
  R(p_t *, oσ);
  R(Q_t, c);
  if (c % 100000000 == 0) print("p_and %ld\n", c);
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
  if (c % 100000000 == 1) print("c_and %ld\n", c);
  A6(c + 1, σ, god, oσ, 3, os_queue) X;
}
N(c_not)     { print("c_not\n"); }
N(mconsumer) { A6(c_or, c_and, c_not, 0x700, 0x0, os_new) O; }

N(pipe) {
}
p_t o[1024], *s = o + sizeof(o) / sizeof(*o);
q_t a = 0, p = 0;
N(მთავარი2) {
  // (mproducer, mconsumer, pipe) X; 
}
N(მთავარი) {
  A8(0, mconsumer, gor, mproducer, and2, 3, os_queue,  and2) X; 
}
// clang-format off
EN(Tail,
მთავარი,          export);
