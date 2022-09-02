#include "oars.h"
N(unroll_gor0) {}
N(unroll_gor1) {}
N(unroll_gor7) {}
n_t unroll_gor[8] = {unroll_gor0,unroll_gor1};
n_t unroll_god[8];
n_t unroll_got[8];
N(gor);
N(god);
N(got);
N(ara1da2an1) {
  ο[ρ - 1 - σ * 0].v = ο[--α].v;
  ο[ρ - 2 - σ * 0].v = unroll_gor[1];
  ο[ρ - 3 - σ * 0].v = gor;

  ο[ρ - 1 - σ * 1].v = ο[--α].v;
  ο[ρ - 2 - σ * 1].v = ο[--α].v;
  ο[ρ - 3 - σ * 1].v = unroll_god[2];

  ο[ρ - 1 - σ * 2].v = ο[--α].v;
  ο[ρ - 2 - σ * 2].v = unroll_got[1];
  ο[ρ - 3 - σ * 2].v = got;

  ο[α - 1].c(ο, α - 1, ρ - 3, σ);
}
