#include "import_export.h"
#include "oars.h"
#include <stdio.h>

N(os_run_arsi);
N(exports_next);
N(os_wordump);
N(os_new);
N(os_queue);
N(os_next);
N(ada);

N(ray_not) { printf("NOT\n"); }
N(ray_and) {
  R(p_t *, oο);
  printf("AND\n");
  A3(got, oο, os_queue) O;
}
N(ray_oor) { printf("OOR\n"); }

void os_hrtime_init();
void init_ada();
void init_os_next();

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Would you mind adding the 'file_name' as an argument?\n");
    return 8;
  }
  const char *file_name = argv[1];
  p_t σ[512], *ο = σ + 256;
  Q_t α = 0, ρ = 256;

  ο[--ρ].c = ray_not;
  ο[--ρ].c = os_next;
  ο[--ρ].c = ray_oor;

  ο[0].v = ο, ο[1].Q = ρ;

  init_ada();
  init_os_next();
  os_hrtime_init();

  A10(ray_oor, os_next, ray_not, os_new, os_wordump, 010, ada, ray_and, 010,
      ada)
  O;
  return 0;
}
