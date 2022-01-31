// clang-format off
#include "import_export.h"
#include "oars.h"
#include <stdio.h>
#include <stdlib.h>

#define RAY_GOF(Name, Index)                                                   \
  static N(ray_gof_##Name) {                                                   \
    p_t *pο = ο[0].p;                                                          \
    Q_t pρ = pο[1].Q;                                                          \
    pο[pρ + (Index)].c(σ, α, pο, pρ);                                          \
  }
#define RAY_ALG(Name, Index)                                                   \
  static N(ray_alg_##Name) { ρ += 6, ο[ρ - 3 + Index].c(T()); }
RAY_GOF(not, 2)
RAY_GOF(and, 1)
RAY_GOF(oor, 0)
RAY_ALG(not, 2)
RAY_ALG(and, 1)
RAY_ALG(oor, 0)
NP(os_new) {
  Q_t nρ = 512;
  p_t *nο = malloc(nρ * sizeof(void *));

  nο[--nρ].c = ray_gof_not, nο[--nρ].c = ray_gof_and, nο[--nρ].c = ray_gof_oor;
  nο[--nρ].c = ο[--α].c   , nο[--nρ].c = ο[--α].c   , nο[--nρ].c = ο[--α].c;
  nο[--nρ].c = ray_alg_not, nο[--nρ].c = ray_alg_and, nο[--nρ].c = ray_alg_oor;

  nο[0].v = ο, nο[1].Q = nρ;

  A(nο) C(1);
}
NP(os_delete) {
  R(p_t *, oσ);
  free(oσ);
  C(1);
}
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
N(os_run_arsi);
N(os_hrtime);

#undef L
#define L CAT(exports_, __LINE__)

// clang-format off
E(got,
"", 0,                      L) EN(L,
os_hrtime,                  L) EN(L,
os_new,                     L) EN(L,
os_run_arsi,                L) EN(L,
os_wordump,                 L)  E(L,
"printf", printf,     exports);
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
