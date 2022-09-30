/*                   Notandor / არადანი
                              .
               init           .           next
        .............................................
          ν      ○ ← ω        .            ○ ← ω
          ↓      ○            .            ○
          nnn○○○○○○○○○○○○     .     ν      ○
             ↑   ○            .     ↓      ○
           ν[τ]  ○            .     nnn○○○○○○○○○○○○
                 o ← ω[α]     .        ↑   o ← ω[α]
                 a            .      ν[τ]  a
                 n            .            n
                              .
    ω[α+2] = არა/Not | ω[α+1] = და/And | ω[α+0] = ან/Or

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
    void (*c)(struct p_t *ω, Q_t α, struct p_t *ν, Q_t τ);
    void *v;
    const char *cs;
    b_t b; w_t w; d_t d; q_t q;
    B_t B; W_t W; D_t D; Q_t Q;
  };
} p_t;
#define OANT p_t *ω, Q_t α, p_t *ν, Q_t τ 
typedef void (*n_t)(OANT);
#define T ω, α, ν, τ 

#define N(n) void n(OANT)
#define A(vs) ν[τ++].v = (void *)(vs),
#define R ν[--τ]
#define G(Ray) ω[α + Ray].c(ω, α + 3, ν, τ)
#define O ν[τ - 1].c(ω, α, ν, τ - 1)

#define C G

#define RN(Type, Name) Type Name = (Type)R.v

#define ALIGN(O, A) ((Q_t)(((O) + ((A) - 1)) / (A))) * (A)
#define wordCountOf(T) ALIGN(sizeof(T), sizeof(void*))
#define CAT_(a, b) a##b
#define CAT(a, b) CAT_(a, b)
#include "oant_a26.h"
