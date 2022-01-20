#include "import_export.h"
#include "oars.h"
#include <stdio.h>

N(run_arsi);
N(os_wordump);

// clang-format off
p_t ο[512];

// clang-format off
E(got,
"", 0,                         L)  E(L,
"printf", printf,              L)FEN(L,
os_new,                        L) EN(L,
ο,                        export);

N(thend       ) { printf("the end!\n"); }
N(ray_dump_not) { printf("\nnot\n"), os_wordump(T()); }
N(ray_dump_and) { printf("\nand\n"), os_wordump(T()); }
N(ray_dump_oor) { printf("\nor \n"), os_wordump(T()); }

// clang-format on

N(run) {
  R(n_t, export);
  R(p_t *, oο);
  R(const char *, name);
  (void)name, (void)export;
  printf("run   %p  %lu %lu\n", ο, α, ρ);
  printf("oo    %p  %lu %lu\n", oο, oο[1].Q, oο[2].Q);
  --oο[1].Q;
  oο[oο[1].Q].c(oο, oο[1].Q, oο[2].Q);
}

static N(ray_cb_not) { ρ += 6, ο[ρ - 1].c(T()); }
static N(ray_cb_and) { ρ += 6, ο[ρ - 2].c(T()); }
static N(ray_cb_oor) { ρ += 6, ο[ρ - 3].c(T()); }

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Would you mind adding the 'file_name' as an argument?\n");
    return 8;
  }
  const char *file_name = argv[1];
  Q_t α = 0, ρ = sizeof(ο) / sizeof(*ο);

  ο[--ρ].c = 0;
  ο[--ρ].c = thend;
  ο[--ρ].c = 0;

  ο[--ρ].c = ray_dump_not;
  ο[--ρ].c = ray_dump_and;
  ο[--ρ].c = ray_dump_oor;

  ο[--ρ].c = ray_cb_not;
  ο[--ρ].c = ray_cb_and;
  ο[--ρ].c = ray_cb_oor;

  ο[α++].v = ο;
  ο[α++].Q = 001;
  ο[α++].Q = ρ;
  ο[001].Q = α;

  A4(file_name, export, run, run_arsi) O;
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
