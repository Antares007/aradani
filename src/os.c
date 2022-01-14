#include "exportmacros.h"
#include "oars.h"
#include <stdio.h>

void *mapfile(const char *file_name, void *pith);

N(map_arsi) {
  R(void *, pith);
  R(const char *, file_name);
  printf("%s %p\n", file_name, pith);
  n_t arsi = mapfile(file_name, pith);
  if (arsi)
    arsi(T());
  else
    C(2);
}

p_t ο[512];

// clang-format off
static N(got) { C(2); }
EN(got, ο, export)

N(ray_not) { printf("ray_not %lu %lu\n", α, ρ); }
N(ray_and) { printf("ray_and %lu %lu\n", α, ρ); }
N(ray_or ) { printf("ray_or  %lu %lu\n", α, ρ); }

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Would you mind adding the 'file_name' as an argument?\n");
    return 8;
  }
  const char *file_name = argv[1];
  ο[0].v = ο;
  Q_t α = ο[1].Q = 0;
  Q_t ρ = ο[2].Q = sizeof(ο) / sizeof(*ο);
  ο[--ρ].c = ray_not;
  ο[--ρ].c = ray_and;
  ο[--ρ].c = ray_or;
  A3(file_name, export, map_arsi) O;
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
