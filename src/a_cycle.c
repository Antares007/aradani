#include "arsi.h"
// clang-format off
IN(iε,
os_new,                   L)IF(L,
printf, print,            L, int, const char*, ...)IN(L,
//
os_queue,                 L)p_t *σ;I(L,
"σ", σ,                   L)IN(L,
//
and,                      L)IN(L,
and2,                     L)IN(L,
os_ls,              imports);

NP(p_or ) { R(p_t *, oο); A4(ο, gor, oο, os_queue) O; }
N (p_and) {
  R(p_t *, oο); R(Q_t, c);
  if (c % 100000000 == 0) print("p_and %lu %lu %lu\n", α, ρ, c);
  A6(c + 1, ο[-1].v, god, oο, 3, os_queue) O;
}
NP(p_not) {}
NP(mproducer) { A5(p_or, p_and, p_not, 512, os_new) O; }

NP(c_or ) { R(p_t *, oο); A5(ο[-1].v, god, oο, 3, os_queue) O; }
N (c_and) {
  R(p_t *, oο); R(Q_t, c);
  if (c % 100000000 == 1) print("c_and %lu %lu %lu\n", α, ρ, c);
  A6(c + 1, ο[-1].v, god, oο, 3, os_queue) O;
}
NP(c_not) {}
NP(mconsumer) { A5(c_or, c_and, c_not, 512, os_new) O; }
//                 mconsumer, gor, mproducer, os_queue
NP(counter) { A7(mconsumer, gor, mproducer, and2, 3, os_queue, and2) O; }
NP(მთავარი) { A5(0, counter, 0, counter, and2) O; }
NP(seven) { A(7) C(1); }
NP(init) { σ[0].p[σ[1].Q++].v = მთავარი, C(1); }

EN(tail,
σ,                  exports);
