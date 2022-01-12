#pragma once
/*
               init                           next
   ...........................................................
               α   ρ      
               |   |             .            MCCM
     ο - NNNNNNBBBBSSSSSSS - σ   .          α MCCM ρ        
         NNNNNNBBBBSSSSSSS       .          |      |   
               MCCM              . ο - NNNNNBBBBBBBSSSSS - σ
               MCCM              .     NNNNNBBBBBBBSSSSS   
               MCCM              .            MCCM
               MCCM              .            MCCM
               MCCM              .            MCCM
               MCCM              .            MCCM
               MCCM              .            MCCM
   ο + α <= σ + ρ | σ[ρ+2] = არა/not | σ[ρ+1] = და/and | σ[ρ+0] = ან/or
M-word.       Any instruction from the CPU instruction set.
M-text space. Continuous space in the random access memory (RAM) of a computer.
M-text.       A bunch of M-words in the M-text space.
              Let's visualize it as a vertical line of a cross.
OarS.         M-text space is used as two stack-like structures facing each other.
              From "ο" to "α" let's call it the N-text space,
          and from "σ" down to "ρ" let's call it S-pith.
              Let's visualize it as a horizontal line of a cross.
N-text.       A bunch of N-words is composed according to syntax rules.
N-word.       Void C function with four fixed parameters "ο," "α," "ρ," and "σ."
              Next, the M-text defines the N-word, and finally,
              the N-word must answer the question to act as a whole word.
              That means that the last M-word must be a jump (goto) into S-pith.
              In other words, the N-word must decide which junction ray/adapter
              to use to continue the execution of the sentence.
  "My first remark is that, although the programmer's activity ends
  when he has constructed a correct program, the process taking
  place under control of his program is the true subject matter
  of his activity, for it is this process that has to accomplish
  the desired effect; it is this process that in its dynamic
  behavior has to satisfy the desired specifications." Edsger Wybe Dijkstra.
*/
typedef struct p_s {
  union {
    void (*c)(struct p_s *, unsigned long, long, struct p_s *);
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
#define OARS p_t *ο, unsigned long α, long ρ, p_t *σ
#define CAT_(a, b) a##b
#define CAT(a, b) CAT_(a, b)

#define N(n) void n(OARS)
#define NP(n) N(n##p); N(n) { printf("%p\t%ld\t%ld\t%s\n", σ, α, ρ, #n); n##p(T()); } N(n##p)
#define T(n) n##ο, n##α, n##ρ, n##σ
#define R(T, n) T n = (T)ο[--α].v
#define As(T, n)                                                               \
  struct T n =                                                                 \
      (α += wordCountOf(struct T), (struct T *)&ο[α - wordCountOf(struct T)])
#define Rs(T, n) struct T n = ((struct T *)&ο[α -= wordCountOf(struct T)])

#define C(r) σ[ρ + (r)].c(ο, α, ρ, σ)
#define O ο[α - 1].c(ο, α - 1, ρ, σ)
#define A(a) ο[α++].v = (void *)(a),
#define X A2(os_next, and) O
#define S(T, σ) ((T *)&σ[-wordCountOf(T)])
#include "a20.h"

typedef void (*n_t)(OARS);
typedef unsigned long Q_t;
typedef long q_t;
typedef unsigned int W_t;

#define wordCountOf(T)                                                         \
  ((sizeof(T) +                                                                \
    ((sizeof(void *) - (sizeof(T) % sizeof(void *))) % sizeof(void *))) /      \
   sizeof(void *))
