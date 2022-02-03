#include "oars.h"
#include <stdint.h>
#include <time.h>

static clock_t clock_id;

struct timespec t;
N(os_hrtime) {
  A((clock_gettime(clock_id, &t) ? 0 : t.tv_sec * (uint64_t)1e9 + t.tv_nsec))
  C(1);
}
void os_hrtime_init() {
  clock_id = (0 == clock_getres(CLOCK_MONOTONIC_COARSE, &t)) &&
                     (t.tv_nsec <= 1 * 1000 * 1000)
                 ? CLOCK_MONOTONIC_COARSE
                 : CLOCK_MONOTONIC;
}
