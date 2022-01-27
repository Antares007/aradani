#pragma once
/*
               init                           next
   ...........................................................
          ο[α] MC   ο[ρ]        .           MC
             | MC   |           .           MC
     ο - NNNN○○○○○○○SSS - ο[σ]  .           MC
               MC               .      ο[ρ] MC
               MC               .         | MC
               MC               . ο - ○○○○SSSSSSSSSS - ο[σ]
               MC               .     |     MC
               MC               .     ο[α]  MC

   α <= ρ <= σ | ο[ρ+2] = არა/not | ο[ρ+1] = და/and | ο[ρ+0] = ან/or
M-word.       Any instruction from the CPU instruction set.
M-text space. Continuous space in the random access memory (RAM) of a computer.
M-text.       A bunch of M-words in the M-text space.
              Let's visualize it as a vertical line of a cross.
OarS.         M-text space is used as two stack-like structures facing each
other. From "ο[0]" to "ο[α]" let's call it the N-text space, and from "ο[ρ]" to
"ο[σ]" let's call it S-pith. Let's visualize it as a horizontal line of a cross.
N-text.       A bunch of N-words is composed according to syntax rules.
N-word.       Void C function with four fixed parameters "ο," "α," and "ρ."
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
    void (*c)(struct p_s *, unsigned long, unsigned long);
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
    printf("%p\t%ld\t%ld\t%s\n", ο, α, ρ, #n);                                 \
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
