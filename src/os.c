#include "import_export.h"
#include "oars.h"
#include <stdarg.h>
#include <stdio.h>

N(os_run_arsi);
N(os_wordump);
N(os_new);
N(os_queue);
N(os_next);
N(ada);
N(exports_next);

// SP(run) {
//   --α;
//   R(n_t, nar);
//   --α;
//   nar(T());
// }

N(seven);

S(and) { A(010) ada(T()); }

SP(ray_not) {}
SP(ray_and) {
  R(p_t *, oο);
  R(const char *, file_name);
  (void)file_name;
  A3(seven, oο, os_queue) O;
}
SP(ray_oor) {}

void os_hrtime_init();
void init_os_next();
void os(Q_t s, ...) {
  va_list args;
  va_start(args, s);
  p_t σ[512], ο[512];
  Q_t α = 0, ρ = 512;

  ο[--ρ].c = ray_not;
  ο[--ρ].c = os_next;
  ο[--ρ].c = ray_oor;

  ο[0].v = ο, ο[1].Q = ρ;

  init_os_next();
  os_hrtime_init();
  while (s)
    A(va_arg(args, void *)) s--;
  va_end(args);
  O;
}

int main(int argc, char **argv) {
  if (argc < 2)
    return printf("Would you mind adding the 'file_name' as an argument?\n"), 8;
  return os(7, argv[1], ray_oor, os_next, ray_not, os_new, ray_and, and), 0;
}
