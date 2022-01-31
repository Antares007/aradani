#include "import_export.h"
#include "oars.h"
#include <stdio.h>

N(ray_not) { printf("NOT\n"); }
N(ray_and) { printf("AND\n"); }
N(ray_oor) { printf("OOR\n"); }

N(os_run_arsi);
N(exports_next);
N(os_wordump);

void os_hrtime_init();
void init_ada();
void init_os_next();

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Would you mind adding the 'file_name' as an argument?\n");
    return 8;
  }
  const char* file_name = argv[1];
  p_t σ[512], *ο = σ + 256;
  Q_t α = 0, ρ = 256;

  ο[--ρ].c = ray_not;
  ο[--ρ].c = ray_and;
  ο[--ρ].c = ray_oor;
  A2(file_name, os_wordump) O;
  //A3(file_name, exports_next, os_run_arsi) O;
  return 0;
}
