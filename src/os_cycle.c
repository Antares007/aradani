#include "gotgod.h"
#include "oars.h"
#include <stdio.h>

N(os_queue);
N(os_new);
N(ada);
S(and) { A(010) ada(T()); }
S(and2) { A(020) ada(T()); }

SP(p_or) {
  R(p_t *, oο);
  A4(ο, gor, oο, os_queue) O;
}
S(p_and) {
  R(p_t *, oο);
  R(Q_t, c);
  if (c % 100000000 == 0)
    printf("p_and %p %lu %p %lu %lu\n", σ, α, ο, ρ, c);
  A5(c + 1, ο, god, oο, os_queue) O;
}
SP(p_not) {}
SP(mproducer) { A4(p_or, p_and, p_not, os_new) O; }

SP(c_or) {
  R(p_t *, oο);
  A4(ο, god, oο, os_queue) O;
}
S(c_and) {
  R(p_t *, oο);
  R(Q_t, c);
  if (c % 100000000 == 1)
    printf("c_and %p %lu %p %lu %lu\n", σ, α, ο, ρ, c);
  A5(c + 1, ο, god, oο, os_queue) O;
}
SP(c_not) {}
SP(mconsumer) { A4(c_or, c_and, c_not, os_new) O; }
//                 mconsumer, gor, mproducer, os_queue
SP(counter) { A6(mconsumer, gor, mproducer, and2, os_queue, and) O; }
N(cycle) { A2(0, counter) O; }
