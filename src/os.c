#include "import_export.h"
#include "oars.h"
#include <stdio.h>

// clang-format off
E(got,
"", 0,                  L)  E(L,
"printf", printf,       L)FEN(L,
os_new,                 L)FEN(L,
os_wordump,       exports)

N(ray_not) { printf("NOT\n"); }
N(ray_and) { printf("AND\n");
  --α; R(p_t *, oο); --α;
  --oο[1].Q; oο[oο[1].Q].c(oο, oο[1].Q, oο[2].Q);
}
N(ray_oor) { printf("OR\n"); }

N(run_arsi);

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

  A3(file_name, exports, run_arsi) O;
}

// EN(got,
// bark,                     L)FEN(L,
// l_accept,                 L)FEN(L,
// l_address,                L)FEN(L,
// l_bind,                   L)FEN(L,
// l_epoll_create,           L)FEN(L,
// l_epoll_ctl,              L)FEN(L,
// l_epoll_wait,             L)FEN(L,
// l_listen,                 L)FEN(L,
// l_read,                   L)FEN(L,
// l_setnoblock,             L)FEN(L,
// l_socket,                 L)FEN(L,
// la_stdin,                 L)FEN(L,
// ls_export,                L)FEN(L,
// os_delete,                L)FEN(L,
// os_new,                   L)FEN(L,
// os_wordump,               L) E (L,
// printf, printf,           L)
