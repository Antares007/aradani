#include "arsi.h"
// clang-format off
int(*print)(const char*, ...);I(0,
printf, print,                          import);
// clang-format on

N(მთავარი) { A7(7, 7, 7, 7, 7, 7, 7) C(1);           }
N(ray_not) { print("ray_not %p %lu %ld\n", σ, α, ρ); }
N(ray_and) { print("ray_and %p %lu %ld\n", σ, α, ρ); }
N(ray_or ) { print("ray_or  %p %lu %ld\n", σ, α, ρ); }

p_t ο[512];
void init() {
  p_t *σ = ο + sizeof(ο) / sizeof(*ο) - 3;
  Q_t α = 0;
  q_t ρ = 0;
  ο[α++].v = მთავარი;
  σ[--ρ].v = ray_not, σ[--ρ].v = ray_and, σ[--ρ].v = ray_or;
  σ[0].v = ο, σ[1].Q = α, σ[2].q = ρ;
}

// clang-format off
E(tail,
s_pith, ο + sizeof(ο) / sizeof(*ο) - 3, export)
