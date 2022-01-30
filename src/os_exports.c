#include "import_export.h"
#include "oars.h"
#include <stdio.h>
#include <stdlib.h>

#define RAY_GOF(Name, Index)                                                   \
  static N(ray_gof_##Name) {                                                   \
    p_t *σ = ο[-1].v;                                                          \
    p_t *pσ = σ[3].v;                                                          \
    p_t *pο = pσ[0].v;                                                         \
    pο[pσ[2].Q + Index].c(pο, pσ[1].Q, pσ[2].Q);                               \
  }
#define RAY_ALG(Name, Index)                                                   \
  static N(ray_alg_##Name) { ρ += 6, ο[ρ - 3 + Index].c(T()); }
RAY_GOF(not, 2)
RAY_GOF(and, 1)
RAY_GOF(oor, 0)
RAY_ALG(not, 2)
RAY_ALG(and, 1)
RAY_ALG(oor, 0)
NP(os_init_pith) {
  R(p_t *, pσ);
  R(p_t *, nσ);
  R(Q_t, sc);
  R(Q_t, wc);
  p_t *nο = &nσ[5 + sc];
  Q_t nρ = wc;
  nο[--nρ].c = ray_gof_not, nο[--nρ].c = ray_gof_and, nο[--nρ].c = ray_gof_oor;
  nο[--nρ].c = ο[--α].c, nο[--nρ].c = ο[--α].c, nο[--nρ].c = ο[--α].c;
  nο[--nρ].c = ray_alg_not, nο[--nρ].c = ray_alg_and, nο[--nρ].c = ray_alg_oor;
  nσ[0].v = nο;
  nσ[1].Q = 0;
  nσ[2].Q = nρ;
  nσ[3].v = pσ;
  nσ[4 + sc].v = nσ;
  C(1);
}
NP(os_new) {
  R(Q_t, sc);
  R(Q_t, wc);
  R(n_t, not );
  R(n_t, and);
  R(n_t, oor);
  p_t *nσ = malloc((wc + sc + 5) * sizeof(void *));
  A9(nσ, oor, and, not, wc, sc, nσ, ο[-1].v, os_init_pith) O;
}
N(os_delete) {
  R(p_t *, σ);
  free(σ);
  C(1);
}
N(os_wordump) {
  printf("ο:%p α:%02ld               ρ: %02ld\n", ο, α, ρ);
  long i = 0;
  while (i < α) {
    printf("%016lx ", ο[i].Q);
    if (++i < α)
      printf("%016lx\n", ο[i].Q);
    else
      printf("\n");
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
os_init_pith,               L) EN(L,
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
