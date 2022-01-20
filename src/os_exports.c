#include "oars.h"
#include <stdio.h>
#include <stdlib.h>
// clang-format off
static N(cont_fathers_not_ray) { p_t *pο = ο[0].v; pο[pο[2].Q + 2].c(pο, pο[1].Q, pο[2].Q); }
static N(cont_fathers_and_ray) { p_t *pο = ο[0].v; pο[pο[2].Q + 1].c(pο, pο[1].Q, pο[2].Q); }
static N(cont_fathers_oor_ray) { p_t *pο = ο[0].v; pο[pο[2].Q + 0].c(pο, pο[1].Q, pο[2].Q); }
static N(ray_cb_not) { ρ += 6, ο[ρ - 1].c(T()); }
static N(ray_cb_and) { ρ += 6, ο[ρ - 2].c(T()); }
static N(ray_cb_oor) { ρ += 6, ο[ρ - 3].c(T()); }
N(os_new) {
  R(Q_t, word_count);
  p_t    *nο = malloc(word_count * sizeof(void *));
  Q_t     nα = 0, nρ = word_count;

  nο[--nρ].c = cont_fathers_not_ray;
  nο[--nρ].c = cont_fathers_and_ray;
  nο[--nρ].c = cont_fathers_oor_ray;

  nο[--nρ].c = ο[--α].c;
  nο[--nρ].c = ο[--α].c;
  nο[--nρ].c = ο[--α].c;

  nο[--nρ].c = ray_cb_not;
  nο[--nρ].c = ray_cb_and;
  nο[--nρ].c = ray_cb_oor;

  nο[nα++].v = ο;
  nο[nα++].Q = 0001;
  nο[nα++].Q = nρ;
  nο[nα++].Q = word_count;
  nο[0001].Q = nα;

  A(nο) C(1);
}
N(os_delete) { R(p_t *, nο); free(nο[0].v), C(1); }
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
