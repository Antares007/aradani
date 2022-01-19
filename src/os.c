#include "import_export.h"
#include "oars.h"
#include <stdio.h>

N(run_arsi);
N(os_wordump);

// clang-format off
N(run);
IN(run, 
and,                           L)IN(L,
and2,                          L)IN(L,
and3,                          L)p_t *oo;I(L,
"ο", oo,                  import);
// clang-format on

N(run) {
  α -= 3;
  printf("run     %lu %lu %d\n", α, ρ, ο[α + 1].v == ο);
  O;
}
p_t ο[512];

// clang-format off
E(got,
"", 0,                         L)E(L,
"printf", printf,              L)EN(L,
ο,                        export);
N(thend       ) { printf("the end!\n"); }
N(ray_dump_not) { printf("\nnot\n"), os_wordump(T()); }
N(ray_dump_and) { printf("\nand\n"), os_wordump(T()); }
N(ray_dump_or ) { printf("\nor \n"), os_wordump(T()); }
N(ray_cb_not  ) { ρ += 6, ο[ρ - 1].c(T()); }
N(ray_cb_and  ) { ρ += 6, ο[ρ - 2].c(T()); }
N(ray_cb_or   ) { ρ += 6, ο[ρ - 3].c(T()); }

// clang-format on

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Would you mind adding the 'file_name' as an argument?\n");
    return 8;
  }
  const char *file_name = argv[1];
  Q_t α = 3, ρ = sizeof(ο) / sizeof(*ο);
  ο[--ρ].c = thend;
  ο[--ρ].c = 0;
  ο[--ρ].c = ray_dump_not;
  ο[--ρ].c = ray_dump_and;
  ο[--ρ].c = ray_dump_or;
  ο[--ρ].c = ray_cb_not;
  ο[--ρ].c = ray_cb_and;
  ο[--ρ].c = ray_cb_or;
  ο[0].v = ο, ο[1].Q = α, ο[2].Q = ρ;

  ο[α++].c = god;
  printf("god:%p\n", god);

  A4(file_name, export, import, run_arsi) O;
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
