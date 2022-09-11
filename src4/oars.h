/*                       Notandor / არადანი
                                  .
               init               .           next
        .................................................
             ο → ○                .            ○ ← ο
                 ○                .            ○
      σ → NNN○○○○○○○○○○○○         .            ○
             ↑   ○                .            ○
           σ[α]  ○                . σ → NNN○○○○○○○○○○○○
                 Ο ← o[ρ]         .        ↑   Ο ← o[ρ]
                 Α                .      σ[α]  Α
                 Ν                .            Ν
                                  .
        ο[ρ+2] = არა/Not | ο[ρ+1] = და/And | ο[ρ+0] = ან/Or

  The protocol of "Notandor/არადანი" gives us the power to specify
  everything in the M-words. We need to do so because the M-words
  are the only language we have from the beginning within the CPU.
  We need to start to specify things using language and not data
  structures. */
#pragma once
// clang-format off
typedef   signed char   b_t;
typedef   signed short  w_t;
typedef   signed int    d_t;
typedef   signed long   q_t;
typedef unsigned char   B_t;
typedef unsigned short  W_t;
typedef unsigned int    D_t;
typedef unsigned long   Q_t;
typedef struct p_t {
  union {
    struct p_t *p;
    void (*c)(struct p_t *ο, Q_t α, Q_t ρ, struct p_t *σ);
    void *v;
    const char *cs;
    b_t b; w_t w; d_t d; q_t q;
    B_t B; W_t W; D_t D; Q_t Q;
  };
} p_t;
#define OARS p_t *ο, Q_t α, Q_t ρ, p_t *σ 
typedef void (*n_t)(OARS);
#define T ο, α, ρ, σ 

#define N(n) void n(OARS)
#define A(vs) σ[α++].v = (void *)(vs),
#define R σ[--α]
#define G(Ray) ο[ρ + Ray].c(ο, α, ρ + 3, σ)
#define O σ[α - 1].c(ο, α - 1, ρ, σ)

#define C G

#define RN(Type, Name) Type Name = (Type)R.v

#define ALIGN(O, A) ((Q_t)(((O) + ((A) - 1)) / (A))) * (A)
#define wordCountOf(T) ALIGN(sizeof(T), sizeof(void*))
#define CAT_(a, b) a##b
#define CAT(a, b) CAT_(a, b)
#include "oars_a26.h"
