#pragma once
/*                       Notandor / არადანი
                                  .
               init               .           next
     .......................................................
           σ[α]  M   ο[ρ]         .            M
             ↓   M     ↓          .            M
       σ→NNNn○○○ ο→○○○○OAN        .            M
                 M                .            M
                 M                .            M
                 M                .  σ→NNN○○○○ ο→OANnOAN
                 M                .       ↑    M ↑
                 M                .     σ[α]   M ο[ρ]
                                  .
        ο[ρ+2] = არა/not | ο[ρ+1] = და/and | ο[ρ+0] = ან/or

"Notandor/არადანი" gives us the power to specify everything
in the M-language. We need to do so because the M-language
is the only language we have from the beginning. */

// clang-format off
#include <stdint.h>
typedef  int8_t  b_t; typedef  int16_t w_t; typedef  int32_t d_t; typedef  int64_t q_t;
typedef uint8_t  B_t; typedef uint16_t W_t; typedef uint32_t D_t; typedef uint64_t Q_t;
typedef struct p_s {
  union {
    struct p_s *p;
    void (*c)(struct p_s *σ, Q_t α, struct p_s *ο, Q_t ρ);
    void *v;
    const char *cs;
    b_t b; w_t w; d_t d; q_t q;
    B_t B; W_t W; D_t D; Q_t Q;
  };
} p_t;
#define OARS p_t *σ, Q_t α, p_t *ο, Q_t ρ
typedef void (*n_t)(OARS);
#define N(n) void n(OARS)
#define A(a) σ[α++].v = (void *)(a),
#define R(T, n) T n = (T)σ[--α].v
#define G(r) ο[ρ + (r)].c(σ, α,     ο, ρ)
#define O    σ[α - (1)].c(σ, α - 1, ο, ρ)
#define S(n) static N(n)
#define T(n) n##σ, n##α, n##ο, n##ρ
#define C(r) G(r)

#define Sa(T, ...) (*((T *)&σ[α]) = ((T)__VA_ARGS__), α += wordCountOf(T)),
#define Sr(T, n) T *n = (T *)&σ[α -= wordCountOf(T)]

//#define Error (A3(__FILE__, __FUNCTION__, __LINE__) C(2))
#define Error C(2)

#define ALIGN(O, A) ((Q_t)(((O) + ((A) - 1)) / (A))) * (A)
#define wordCountOf(T) ALIGN(sizeof(T), sizeof(void*))

#define CAT_(a, b) a##b
#define CAT(a, b) CAT_(a, b)

#include "oars_nars.h"
#include "oars_a21.h"
#include "oars_as.h"
#include "oars_sa21.h"
#include "oars_np.h"
