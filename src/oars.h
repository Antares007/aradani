#pragma once
/*
               init                           next
   ...........................................................
        α|            |ρ        .             fXXe
     ο - 0123456789abcdef - σ   .             dXXc
         XXXXXXXXXXXXXXXX       .           α|    |ρ
               fXXe             .   ο - 0123456789abcdef - σ
               dXXc             .       XXXXXXXXXXXXXXXX
               bXXa             .             bXXa
               9XX8             .             9XX8
               7XX6             .             7XX6
               5XX4             .             5XX4
               3XX2             .             3XX2
               1XX0             .             1XX0
                          ο + α <= σ + ρ
                          σ[ρ+2] = არა
                          σ[ρ+1] = და
                          σ[ρ+0] = ან

M-word        - Any instruction from the CPU instruction set.
M-text space  - Continuous space in the random access memory (RAM) of a computer.
                Let's visualize it as a vertical line of a cross.
M-text        - A bunch of M-words in the M-text space.
OarS          - M-text space is used as two stack-like structures facing each other.
                From "ο" to "α" let's call it the N-text space,
                and from "σ" down to "ρ" let's call it the execution space
                or pith of the sentence or dot.
                Let's visualize is as a horizontal line of a cross.
N-text        - A bunch of N-words is composed of syntax rules.
N-word        - Void C function (let's stay above low-level definitions of
                ABI and use the C function in our description) with four
                parameters "ο," "α," "ρ," and "σ." Or just OarS with
                only parameter. That means that the M-text defines
                the N-word. Its definition can include any M-word by
                which it can write or take N-words from the N-text space
                or the execution space (or modify OarS).
                Finally, the N-word must answer the question
                to act as a whole word of the N-text. That means that
                the last M-word must be a goto (jump) to σ[ρ + (0 or 1 or 2)] ray.
Keep in mind.
We will consider the composition with "return" (functional composition)
as a harmful thing!
Think about it.
There is no point in returning to what you already left behind!
In our cross, the vertical line represents the M-text space.
The horizontal line is the OarS.
So these are the three dimensions of "Aradani."
Why aradani? Those are three rays of execution space.
And from mathematics, particularly from logic,
we know to have a choice all we need is "and," "or" and "not" junctions.
"ara", "da" and "an" in Georgian sounds like "not", "and", and "or" in English.
So we can call our three-dimensional composition unit "aradan," a.k.a. "notandor."
What kind of pros it has?
It will fly like a bullet because we don't use conditional branching.
It is a complete (whole) unit of composition. Therefore, we can express specifications like executable definitions.
...
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
#define T(n) n##ο, n##α, n##ρ, n##σ
#define R(T, n) T n = (T)ο[--α].v
#define As(T, n)                                                               \
  struct T n =                                                                 \
      (α += wordCountOf(struct T), (struct T *)&ο[α - wordCountOf(struct T)])
#define Rs(T, n) struct T n = ((struct T *)&ο[α -= wordCountOf(struct T)])

#define C(r) σ[ρ + (r)].c(ο, α, ρ, σ)
#define O ο[α - 1].c(ο, α - 1, ρ, σ)
#define A(a) ο[α++].v = (void *)(a),
#define X A2(os_next, და) O
#define S(T, σ) ((T *)&σ[-wordCountOf(T)])

typedef void (*n_t)(OARS);
typedef unsigned long Q_t;
typedef long q_t;
typedef unsigned int W_t;

#define wordCountOf(T)                                                         \
  ((sizeof(T) +                                                                \
    ((sizeof(void *) - (sizeof(T) % sizeof(void *))) % sizeof(void *))) /      \
   sizeof(void *))
/*
console.log(
  Array(21).fill()
           .map((_, a) => String.fromCharCode(a+0x61))
           .map((v, i, a) => `#define A${i}(${a.slice(0,i)})
${a.slice(0,i).map(v=>`A(${v})`).join('')}`) .slice(2) .join('\n')
)
*/
#define A2(a, b) A(a) A(b)
#define A3(a, b, c) A(a) A(b) A(c)
#define A4(a, b, c, d) A(a) A(b) A(c) A(d)
#define A5(a, b, c, d, e) A(a) A(b) A(c) A(d) A(e)
#define A6(a, b, c, d, e, f) A(a) A(b) A(c) A(d) A(e) A(f)
#define A7(a, b, c, d, e, f, g) A(a) A(b) A(c) A(d) A(e) A(f) A(g)
#define A8(a, b, c, d, e, f, g, h) A(a) A(b) A(c) A(d) A(e) A(f) A(g) A(h)
#define A9(a, b, c, d, e, f, g, h, i)                                          \
  A(a) A(b) A(c) A(d) A(e) A(f) A(g) A(h) A(i)
#define A10(a, b, c, d, e, f, g, h, i, j)                                      \
  A(a) A(b) A(c) A(d) A(e) A(f) A(g) A(h) A(i) A(j)
#define A11(a, b, c, d, e, f, g, h, i, j, k)                                   \
  A(a) A(b) A(c) A(d) A(e) A(f) A(g) A(h) A(i) A(j) A(k)
#define A12(a, b, c, d, e, f, g, h, i, j, k, l)                                \
  A(a) A(b) A(c) A(d) A(e) A(f) A(g) A(h) A(i) A(j) A(k) A(l)
#define A13(a, b, c, d, e, f, g, h, i, j, k, l, m)                             \
  A(a) A(b) A(c) A(d) A(e) A(f) A(g) A(h) A(i) A(j) A(k) A(l) A(m)
#define A14(a, b, c, d, e, f, g, h, i, j, k, l, m, n)                          \
  A(a) A(b) A(c) A(d) A(e) A(f) A(g) A(h) A(i) A(j) A(k) A(l) A(m) A(n)
#define A15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o)                       \
  A(a) A(b) A(c) A(d) A(e) A(f) A(g) A(h) A(i) A(j) A(k) A(l) A(m) A(n) A(o)
#define A16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p)                    \
  A(a)                                                                         \
  A(b) A(c) A(d) A(e) A(f) A(g) A(h) A(i) A(j) A(k) A(l) A(m) A(n) A(o) A(p)
#define A17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q)                 \
  A(a)                                                                         \
  A(b)                                                                         \
  A(c) A(d) A(e) A(f) A(g) A(h) A(i) A(j) A(k) A(l) A(m) A(n) A(o) A(p) A(q)
#define A18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r)              \
  A(a)                                                                         \
  A(b)                                                                         \
  A(c)                                                                         \
  A(d) A(e) A(f) A(g) A(h) A(i) A(j) A(k) A(l) A(m) A(n) A(o) A(p) A(q) A(r)
#define A19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s)           \
  A(a)                                                                         \
  A(b)                                                                         \
  A(c)                                                                         \
  A(d)                                                                         \
  A(e) A(f) A(g) A(h) A(i) A(j) A(k) A(l) A(m) A(n) A(o) A(p) A(q) A(r) A(s)
#define A20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t)        \
  A(a)                                                                         \
  A(b)                                                                         \
  A(c)                                                                         \
  A(d)                                                                         \
  A(e)                                                                         \
  A(f) A(g) A(h) A(i) A(j) A(k) A(l) A(m) A(n) A(o) A(p) A(q) A(r) A(s) A(t)
