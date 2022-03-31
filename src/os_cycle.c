#include "oars.h"
#include "gotgod.h"
// clang-format off
void nar(OARS);
void os_new(OARS);
void os_next(OARS);
void os_queue(OARS);
Nargo(and )(0010, nar)
Nargo(and2)(0020, nar)
Nargo(not )(0100, nar)
Nargo(or  )(0001, nar)
// clang-format on
N(p_or) { PLog;
  R(p_t *, oο);
  Α(ο, gor, oο, os_queue) O;
}
N(p_and) {
  R(p_t *, oο);
  R(Q_t, c);
  if (c % 100000000 == 0)
    printf("%p p_and %lu\n", σ, c);
  Α(c + 1, ο, god, oο, os_queue) O;
}
N(p_not) {}
N(mproducer) { PLog; Α(p_not, p_and, p_or, os_new) O; }

N(c_or) { PLog;
  R(p_t *, oο);
  Α(ο, god, oο, os_queue) O;
}
N(c_and) {
  R(p_t *, oο);
  R(Q_t, c);
  if (c % 100000000 == 1)
    printf("%p c_and %lu\n", σ, c);
  Α(c + 1, ο, god, oο, os_queue) O;
}
N(c_not) {}
N(mconsumer) { PLog; Α(c_not, c_and, c_or, os_new) O; }

N(counter_n) { PLog;
  R(p_t *, pο);
  R(p_t *, cο);
  Α(cο, gor, pο, os_queue) O;
}

N(counter) { Α(mconsumer, mproducer, and, counter_n, and) O; }
N(os_cycle) { Α(0, counter) O; }
