#include "import_export.h"
#include "oars.h"
#include <stdio.h>

N(ray_not) { printf("NOT\n"); }
N(ray_and) {
  printf("AND\n");
  --α;
  R(p_t *, σ);
  --α;
  σ[0].p[σ[1].Q - 1].c(σ[0].p, σ[1].Q - 1, σ[2].Q);
}
N(ray_oor) { printf("OR\n"); }

N(os_run_arsi);
N(exports_next);
const char *file_name;
N(runner) { A3(file_name, exports_next, os_run_arsi) O; }

N(os_hrtime_init);
N(init_ada);
N(init_next);
int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Would you mind adding the 'file_name' as an argument?\n");
    return 8;
  }
  file_name = argv[1];
  p_t ο[512];
  Q_t α = 0, ρ = sizeof(ο) / sizeof(*ο);

  ο[--ρ].c = ray_not;
  ο[--ρ].c = ray_and;
  ο[--ρ].c = ray_oor;

  A7(init_ada, os_hrtime_init, anδ, init_next, anδ, runner, anδ) O;
  return 0;
}
