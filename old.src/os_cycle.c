#include "oars.h"
#include "gotgod.h"
// clang-format off
void nar(OARS);
void os_new(OARS);
void os_queue(OARS);

N(and ) { Α(0010, nar) O; }
N(and2) { Α(0020, nar) O; }
N(not ) { Α(0100, nar) O; }
N(or  ) { Α(0001, nar) O; }

// clang-format on
N(co2) { ο[2].c(T()); }
N(co1) { ο[1].c(T()); }
N(co0) { ο[0].c(T()); }

NP(p_or) {
  R(p_t *, oο);
  Α(ο, co0, oο, os_queue) O;
}
N(p_and) {
  R(p_t *, oο);
  R(Q_t, c);
  if (c % 100000000 == 0)
    printf("%p p_and %lu\n", σ, c);
  Α(c + 1, ο, co1, oο, os_queue) O;
}
N(p_not) {}
NP(mproducer) { Α(p_not, p_and, p_or, os_new) O; }

NP(c_or) {
  R(p_t *, oο);
  Α(ο, co1, oο, os_queue) O;
}
N(c_and) {
  R(p_t *, oο);
  R(Q_t, c);
  if (c % 100000000 == 1)
    printf("%p c_and %lu\n", σ, c);
  Α(c + 1, ο, co1, oο, os_queue) O;
}
N(c_not) {}
NP(mconsumer) { Α(c_not, c_and, c_or, os_new) O; }

NP(counter_n) {
  R(p_t *, pο);
  R(p_t *, cο);
  Α(cο, co0, pο, os_queue) O;
}

NP( counter ) { Α(mconsumer, mproducer, and, counter_n, and) O; }

N(os_cycle) {
  PLog;
  Α(0, counter) O;
}

