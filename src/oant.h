/*                   Notandor / არადანი
                              .
               init           .           next
        .............................................
          ν      ○ ← ο        .            ○ ← ο
          ↓     \○/           .            ○
          nnn○○○○○○○○○○○○     .     ν      ○
             ↑  /○\           .     ↓     \○/
           ν[τ]  ○            .     nnn○○○○○○○○○○○○
                 o ← ο[α]     .        ↑  /o\ ← ο[α]
                 a            .      ν[τ]  a
                 n            .            n
                              .
    ο[α+2] = არა/Not | ο[α+1] = და/And | ο[α+0] = ან/Or

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
    void (*c)(struct p_t *ο, Q_t α, struct p_t *ν, Q_t τ, void **ψ, void **δ);
    void *v;
    const char *cs;
    b_t b; w_t w; d_t d; q_t q;
    B_t B; W_t W; D_t D; Q_t Q;
  };
} p_t;
#define OANT p_t *ο, Q_t α, p_t *ν, Q_t τ, void **ψ, void **δ
typedef void (*n_t)(OANT);
#define T ο, α, ν, τ, ψ, δ 

#define N(n) void n(OANT)
#define A(vs) ν[τ++].v = (void *)(vs),
#define R ν[--τ]
#define G(Ray) ο[α + Ray].c(ο, α + 3, ν, τ, ψ, δ)
#define O ν[τ - 1].c(ο, α, ν, τ - 1, ψ, δ)

#define C G

#define RN(Type, Name) Type Name = (Type)R.v

#define ALIGN(O, A) ((Q_t)(((O) + ((A) - 1)) / (A))) * (A)
#define wordCountOf(T) ALIGN(sizeof(T), sizeof(void*))
#define CAT_(a, b) a##b
#define CAT(a, b) CAT_(a, b)
#include "oant_a26.h"
