// clang-format off
#include "import_export.h"
#include "oars.h"
#include <stdio.h>
#include <stdlib.h>

N(os_wordump) {
  printf("σ:%p α:%02lu      ο:%p ρ:%02lu\n", σ, α, ο, ρ);
  long i = 0;
  while (i < α) {
    printf("%016lx ", σ[i].Q);
    if (++i < α) printf("%016lx\n", σ[i].Q);
    else printf("\n");
    i++;
  }
  C(1);
}

#undef L
#define L CAT(exports_, __LINE__)

N(os_run_arsi);
N(os_hrtime);
N(ada);
N(os_queue);
N(os_new);

// clang-format off
E(got,
"", 0,                       L) EN(L,
os_hrtime,                   L) EN(L,
os_new,                      L) EN(L,
os_run_arsi,                 L) EN(L,
os_wordump,                  L)  E(L,
"printf", printf,            L) EN(L,
ada,                         L) EN(L,
os_queue,         exports_next);
// clang-format on

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
