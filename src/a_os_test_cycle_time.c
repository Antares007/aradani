#include "gotgod.h"
#include "oars.h"
#include <stdio.h>
N(ada);
N(os_hrtime);
N(os_new);
N(os_queue);
N(os_wordump);

S(α0) {
  α = 0;
  C(1);
}

S(and) { A(010) ada(T()); }

S(print_time_n) {
  R(Q_t, time);
  printf("%lu\n", time / 1000);
  C(1);
}

S(print_time) { A5(os_hrtime, print_time_n, and, α0, and) O; }

SP(ray_not) { C(2); }
S(ray_and) { A3(print_time, ο, os_queue) O; }
SP(ray_oor) { C(0); }

NP(seven_cycle) { A7(god, ray_not, ray_and, ray_oor, os_new, os_queue, and) O; }
