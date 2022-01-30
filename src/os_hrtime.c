#include "oars.h"
#include <stdint.h>
#include <time.h>

static clock_t clock_id;

N(os_hrtime) {
  struct timespec t;
  A((clock_gettime(clock_id, &t) ? 0 : t.tv_sec * (uint64_t)1e9 + t.tv_nsec))
  C(1);
}
N(os_hrtime_init) {
  struct timespec t;
  clock_id = (0 == clock_getres(CLOCK_MONOTONIC_COARSE, &t)) &&
                     (t.tv_nsec <= 1 * 1000 * 1000)
                 ? CLOCK_MONOTONIC_COARSE
                 : CLOCK_MONOTONIC;
  C(1);
}
