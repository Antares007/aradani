#include "arsi.h"
#include "gotgod.h"
// clang-format off
IBS(                L)IN(L,
os_new,             L)IN(L,
os_queue,           L)IN(L,

and,                L)IN(L,
and2,         imports);
// clang-format on
void init() {}
//p_t ο[512];
//void init() {
//  ο[0].v = ο;
//  ο[1].Q = sizeof(ο) / sizeof(*ο);
//  QUEUE_INIT((QUEUE *)&ο[2]);
//  ο[4].v = "a";
//
//  ο[--ο[1].Q].v = ray_not;
//  ο[--ο[1].Q].v = os_next;
//  ο[--ο[1].Q].v = os_next;
//}

NP(p_or) {
  R(p_t *, oο);
  A4(ο, gor, oο, os_queue) O;
}
N(p_and) {
  R(p_t *, oο);
  R(Q_t, c);
  if (c % 10000000 == 0) print("p_and %p %lu %p %lu %lu\n", σ, α, ο, ρ, c);
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
  if (c % 10000000 == 1) print("c_and %p %lu %p %lu %lu\n", σ, α, ο, ρ, c);
  A5(c + 1, ο, god, oο, os_queue) O;
}
NP(c_not) {}
NP(mconsumer) { A4(c_or, c_and, c_not, os_new) O; }
//                 mconsumer, gor, mproducer, os_queue
NP(counter) { A6(mconsumer, gor, mproducer, and2, os_queue, and) O; }

N(მთავარი) { 
  A2(0, counter) O; 
}

// clang-format off
EN(tail,
მთავარი,      exports);
