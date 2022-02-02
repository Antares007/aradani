#include "import_export.h"
#include "oars.h"
#include <stdio.h>

N(os_run_arsi);
N(os_wordump);
N(os_new);
N(os_queue);
N(os_next);
N(ada);
N(exports_next);

SP(ray_not) {}
//SP(run) {
//  --α;
//  R(n_t, nar);
//  --α;
//  nar(T());
//}

N(seven);

S(and) { A(010) ada(T()); }

SP(ray_and) {
  R(p_t *, oο);
  R(const char *, file_name);
  (void)file_name;
  A3(seven, oο, os_queue) O;
}
SP(ray_oor) {}

void os_hrtime_init();
void init_os_next();

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Would you mind adding the 'file_name' as an argument?\n");
    return 8;
  }
  const char *file_name = argv[1];
  p_t σ[512], ο[512];
  Q_t α = 0, ρ = 512;

  ο[--ρ].c = ray_not;
  ο[--ρ].c = os_next;
  ο[--ρ].c = ray_oor;

  ο[0].v = ο, ο[1].Q = ρ;

  init_os_next();
  os_hrtime_init();

  A7(file_name, ray_oor, os_next, ray_not, os_new, ray_and, and) O;
  return 0;
}
