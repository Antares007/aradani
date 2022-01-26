#include "import_export.h"
#include "oars.h"
#include <stdio.h>

// clang-format off
N(ray_not) { printf("NOT\n"); }
N(ray_and) { printf("AND\n");
  --α; R(p_t *, oο); --α;
  --oο[1].Q; oο[oο[1].Q].c(oο, oο[1].Q, oο[2].Q);
}
N(ray_oor) { printf("OR\n"); }

N(os_run_arsi);
N(exports_raylib);

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Would you mind adding the 'file_name' as an argument?\n");
    return 8;
  }
  const char *file_name = argv[1];
  p_t ο[512];
  Q_t α = 0, ρ = sizeof(ο) / sizeof(*ο);

  ο[--ρ].c = ray_not;
  ο[--ρ].c = ray_and;
  ο[--ρ].c = ray_oor;

  A3(file_name, exports_raylib, os_run_arsi) O;
}
