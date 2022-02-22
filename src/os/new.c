#include "../oars.h"
#include "pith_coords.h"
#include "queue.h"
#include <stdlib.h>
// clang-format off
#define RAY_ALG(Index)                                                         \
  S(ray_al_##Index) { ρ += 6, ο[ρ - 3 + Index].c(T()); }
#define Co(o, r) (o)[(o)[1].Q + r].c(σ, α, (o), (o)[1].Q)

RAY_ALG(2)
RAY_ALG(1)
RAY_ALG(0)
S(raygof_2) {
  p_t *pο = ο[Φ].p;
  free(ο);
  Co(pο, 2);
}
static void append_to_parent_queue(QUEUE *my_q, QUEUE *parent_q) {
  QUEUE *q;
  if (my_q != (q = QUEUE_NEXT(my_q)))
    QUEUE_PREV(q) = QUEUE_PREV(parent_q), QUEUE_PREV_NEXT(my_q) = parent_q,
    QUEUE_PREV_NEXT(parent_q) = q, QUEUE_PREV(parent_q) = QUEUE_PREV(my_q),
    QUEUE_INIT(my_q);
}
S(raygof_1) { append_to_parent_queue((QUEUE *)&ο[Ψ], (QUEUE *)&ο[Φ].p[Ψ]), Co(ο[Φ].p, 1); }
S(raygof_0) { append_to_parent_queue((QUEUE *)&ο[Ψ], (QUEUE *)&ο[Φ].p[Ψ]), Co(ο[Φ].p, 0);  }
N(os_new_psn) { // TODO: change os_new to be more composable word
  R(const char *, name);
  R(Q_t, nρ);
  R(p_t *, oο);
  p_t *nο = malloc(nρ * sizeof(void *));
  nο[Σ].Q = nρ; 
  nο[--nρ].c = raygof_2, nο[--nρ].c = raygof_1, nο[--nρ].c = raygof_0;
  nο[--nρ].c = σ[--α].c, nο[--nρ].c = σ[--α].c, nο[--nρ].c = σ[--α].c;
  nο[--nρ].c = ray_al_2, nο[--nρ].c = ray_al_1, nο[--nρ].c = ray_al_0;

  nο[Φ].p = oο, nο[Ρ].Q = nρ, QUEUE_INIT((QUEUE *)&nο[Ψ]),
  nο[Ν].cs = name;

  A(nο) C(1);
}

N(os_new) { A4(ο[Φ].p, 512, "os_new", os_new_psn) O; }
#define OS_CREATE_RAY_TEMPLATE(Ray, Off)                                       \
  S(os_create_##Ray##_r) {                                                     \
    ο[ρ + 0].c = os_create_0_s;                                                \
    ο[ρ + 1].c = os_create_1_s;                                                \
    ο[ρ + 2].c = os_create_2_s;                                                \
    raygof_##Ray(T());                                                         \
  }                                                                            \
  S(os_create_##Ray##_s) {                                                     \
    Q_t count = ο[ρ + 3 + Ray].Q;                                              \
    for (Q_t i = 0; i < count; i++)                                            \
      σ[α++].v = ο[ρ + i + (Off)].v;                                           \
    if (count) {                                                               \
      ο[ρ + 0].c = os_create_0_r;                                              \
      ο[ρ + 1].c = os_create_1_r;                                              \
      ο[ρ + 2].c = os_create_2_r;                                              \
      O;                                                                       \
    } else                                                                     \
      raygof_##Ray(T());                                                       \
  }

S(os_create_2_s); S(os_create_1_s); S(os_create_0_s);
S(os_create_2_r); S(os_create_1_r); S(os_create_0_r);

OS_CREATE_RAY_TEMPLATE(2, 6);
OS_CREATE_RAY_TEMPLATE(1, 6 + ο[ρ + 3 + 2].Q);
OS_CREATE_RAY_TEMPLATE(0, 6 + ο[ρ + 3 + 1].Q + ο[ρ + 3 + 2].Q);

N(os_create_psn) { // TODO: use os_new to create pith
  R(const char *, name); R(Q_t, nρ); R(p_t *, oο); R(Q_t, j);
  Q_t nc = ((j & 0700) >> 6), ac = ((j & 0070) >> 3), oc = ((j & 0007) >> 0), tc = nc + ac + oc;
  p_t *nο = malloc(nρ * sizeof(void *));
  nο[Σ].Q = nρ; 
  while (tc) tc--, nο[--nρ].v = σ[--α].v;
  nο[--nρ].Q = nc;
  nο[--nρ].Q = ac;
  nο[--nρ].Q = oc;
  nο[--nρ].c = os_create_2_s;
  nο[--nρ].c = os_create_1_s;
  nο[--nρ].c = os_create_0_s;
  nο[Φ].p = oο, nο[Ρ].Q = nρ, QUEUE_INIT((QUEUE *)&nο[Ψ]), nο[Ν].cs = name;
  A(nο) C(1);
}

N(os_create) { Α(ο[Φ].p, 512, "ξ", os_create_psn) O; }
