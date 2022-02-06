#include "oars.h"
#include "queue.h"
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
N(os_new) {
  Q_t nρ = 512;
  p_t *nο = malloc(nρ * sizeof(void *));

  nο[--nρ].c = ray_gof_not, nο[--nρ].c = ray_gof_and, nο[--nρ].c = ray_gof_oor;
  nο[--nρ].c = σ[--α].c, nο[--nρ].c = σ[--α].c, nο[--nρ].c = σ[--α].c;
  nο[--nρ].c = ray_alg_not, nο[--nρ].c = ray_alg_and, nο[--nρ].c = ray_alg_oor;

  nο[0].v = ο, nο[1].Q = nρ;
  QUEUE_INIT((QUEUE *)&nο[2]);

  A(nο) C(1);
}
N(os_delete) {
  R(p_t *, oσ);
  free(oσ);
  C(1);
}
