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
E(got,
printf, printf,           L)EN(L,
ο,                   export);

N(ray_not) { printf("ray_not %lu %lu\n", α, ρ); }
N(ray_and) { printf("ray_and %lu %lu\n", α, ρ); }
N(ray_or ) { printf("ray_or  %lu %lu\n", α, ρ); }
N(run    ) {
  α -= 3;
  printf("run     %lu %lu %d\n", α, ρ, ο[α+1].v == ο); O;
}
int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Would you mind adding the 'file_name' as an argument?\n");
    return 8;
  }
  const char *file_name = argv[1];
  Q_t α =  3;
  Q_t ρ =  sizeof(ο) / sizeof(*ο);

  ο[α++].c = god;

  ο[--ρ].c = ray_not;
  ο[--ρ].c = ray_and;
  ο[--ρ].c = ray_or;

  ο[0].v = ο, ο[1].Q = α, ο[2].Q = ρ;
  A5(file_name, export, map_arsi, run, anδ) O;
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
