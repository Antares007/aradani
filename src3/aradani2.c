typedef signed char b_t;
typedef signed short w_t;
typedef signed int d_t;
typedef signed long q_t;
typedef unsigned char B_t;
typedef unsigned short W_t;
typedef unsigned int D_t;
typedef unsigned long Q_t;
typedef struct p_t {
  union {
    struct p_t *p;
    void (*c)(struct p_t *ο, Q_t α, Q_t ρρ, struct p_t *σρ, Q_t ρδ,
              struct p_t *σδ, Q_t ρα, struct p_t *σα);
    void *v;
    const char *cs;
    b_t b;
    w_t w;
    d_t d;
    q_t q;
    B_t B;
    W_t W;
    D_t D;
    Q_t Q;
  };
} p_t;
#define OARS p_t *ο, Q_t α, Q_t ρρ, p_t *σρ, Q_t ρδ, p_t *σδ, Q_t ρα, p_t *σα
typedef void (*n_t)(OARS);
#define T ο, α, ρρ, σρ, ρδ, σδ, ρα, σα

#define N(n) void n(OARS)
N(ara5da3an) {
  σρ[--ρρ].v = ο[--α].v;
  σρ[--ρρ].v = ο[--α].v;
  σρ[--ρρ].v = ο[--α].v;
  σρ[--ρρ].v = ο[--α].v;
  σρ[--ρρ].v = ο[--α].v;
  σδ[--ρδ].v = ο[--α].v;
  σδ[--ρδ].v = ο[--α].v;
  σδ[--ρδ].v = ο[--α].v;
  σα[--ρα].v = ο[--α].v;
  ο[α - 1].c(ο, α - 1, ρρ, σρ, ρδ, σδ, ρα, σα);
}
