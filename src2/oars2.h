#pragma once
// clang-format off
#include <stdint.h>

typedef  int8_t  b_t; typedef  int16_t w_t; typedef  int32_t d_t; typedef  int64_t q_t;
typedef uint8_t  B_t; typedef uint16_t W_t; typedef uint32_t D_t; typedef uint64_t Q_t;

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
#define Α(vs) σ[α++].v = (void *)(vs),
#include "evalmap.h"
#define A(...) EVAL(MAP(Α, __VA_ARGS__))
#define R σ[--α]
#define RN(Type, Name) Type Name = (Type)R.v
#define O σ[α - 1].c(ο, α - 1, ρ, σ)

#define ALIGN(O, A) ((Q_t)(((O) + ((A) - 1)) / (A))) * (A)
#define wordCountOf(T) ALIGN(sizeof(T), sizeof(void*))
#define CAT_(a, b) a##b
#define CAT(a, b) CAT_(a, b)

// clang-format on
static N(σ4);
static N(σ0) { σ[0].c(T), (void)σ4; }
static N(σ1) { σ[1].c(T); }
static N(σ2) { σ[2].c(T); }
static N(σ3) { σ[3].c(T); }
static N(σ4) { σ[4].c(T), (void)σ0, (void)σ1, (void)σ2, (void)σ3; }
