#pragma once
/*                       Notandor / არადანი
                                  .
               init               .           next
    .......................................................
           σ[α]  C   ο[ρ]         .            C
             |   C     |          .            C
       σ→NNNn○○○ ο→○○○○OAN        .     σ[α]   C ο[ρ]
                 C                .       |    C |
                 C                .  σ→NNN○○○○ ο→OANnOAN
                 C                .            C
                 C                .            C
                 C                .            C
        ο[ρ+2] = არა/not | ο[ρ+1] = და/and | ο[ρ+0] = ან/or
*/
typedef struct p_s {
  union {
    void (*c)(struct p_s *, unsigned long, unsigned long);
    struct p_s *p;
    void *v;
    char b;
    short w;
    int d;
    long q;
    unsigned char B;
    unsigned short W;
    unsigned int D;
    unsigned long Q;
  };
} p_t;
#define OARS p_t *ο, unsigned long α, unsigned long ρ
#define CAT_(a, b) a##b
#define CAT(a, b) CAT_(a, b)

#define N(n) void n(OARS)
#define NP(n)                                                                  \
  N(n##p);                                                                     \
  N(n) {                                                                       \
    printf("%p %ld\t%ld\t%s:%s\n", ο, α, ρ, __FILE_NAME__, __FUNCTION__);       \
    n##p(T());                                                                 \
  }                                                                            \
  N(n##p)
#define T(n) n##ο, n##α, n##ρ
#define R(T, n) T n = (T)ο[--α].v
#define Sa(T, ...) ((*((T *)&ο[α]) = ((T)__VA_ARGS__)), (α += wordCountOf(T))),
#define Sr(T, n) T *n = ((T *)&ο[α -= wordCountOf(T)])

#define C(r) ο[ρ + (r)].c(ο, α, ρ)
#define O ο[α - 1].c(ο, α - 1, ρ)
#define A(a) ο[α++].v = (void *)(a),
#define X A2(os_next, and) O
#define S(T, σ) ((T *)&σ[-wordCountOf(T)])

#include "a21.h"
#include "sa21.h"

typedef void (*n_t)(OARS);
typedef unsigned long Q_t;
typedef long q_t;
typedef unsigned int W_t;

#define wordCountOf(T)                                                         \
  ((sizeof(T) +                                                                \
    ((sizeof(void *) - (sizeof(T) % sizeof(void *))) % sizeof(void *))) /      \
   sizeof(void *))
