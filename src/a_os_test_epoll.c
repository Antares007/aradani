#include "oars.h"
#include "gotgod.h"
#include <stdio.h>
N(ada);
N(os_new);
N(os_queue);

S(α0) { α = 0, C(1); }

S(and) { A(010) ada(T()); }

S(print_time_n) {
  R(Q_t, time);
  printf("%lu\n", time / 1000);
  C(1);
}


SP(ray_not) { C(2); }
SP(ray_oor) { C(0); }

N(os_hrtime);
N(os_wordump);
S(print_time) { A5(os_hrtime, print_time_n, and, α0, and) O; }
S(ray_and) { A3(print_time, ο, os_queue) O; }
NP(seven) {A7(god, ray_not, ray_and, ray_oor, os_new, os_queue, and) O; }

