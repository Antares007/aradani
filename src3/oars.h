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
    void (*c)(struct p_t *ο, Q_t α, Q_t ρ, Q_t σ);
    void *v;
    const char *cs;
    b_t b; w_t w; d_t d; q_t q;
    B_t B; W_t W; D_t D; Q_t Q;
  };
} p_t;
#define OARS p_t *ο, Q_t α, Q_t ρ, Q_t σ 
typedef void (*n_t)(OARS);
#define T ο, α, ρ, σ 

#define N(n) void n(OARS)
#define A(vs) ο[α++].v = (void *)(vs),
#define R ο[--α]
#define G(Ray) ο[ρ - σ * (Ray)].c(ο, α, ρ + 1, σ)
#define O ο[α - 1].c(ο, α - 1, ρ, σ)

#define C G

#define RN(Type, Name) Type Name = (Type)R.v

#define ALIGN(O, A) ((Q_t)(((O) + ((A) - 1)) / (A))) * (A)
#define wordCountOf(T) ALIGN(sizeof(T), sizeof(void*))
#define CAT_(a, b) a##b
#define CAT(a, b) CAT_(a, b)
#include "oars_a26.h"
