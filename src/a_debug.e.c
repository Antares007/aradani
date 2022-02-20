#include "oars.h"
typedef struct αos_t {
  void (*a)(struct αos_t *, const char *, void *, void (*)(struct αos_t *));
  void (*o)(struct αos_t *, const char *, const char *);
  struct αos_t *s;
  const char *mn;
  const char *in;
  void *d;
} αos_t;
typedef void (*ε_t)(αos_t *);

static void dot(p_t *σ, Q_t α, p_t *ο, Q_t ρ);
static void got(p_t *σ, Q_t α, p_t *ο, Q_t ρ) {
  (void)dot, ο[ρ + (2)].c(σ, α, ο, ρ);
}
static void god(p_t *σ, Q_t α, p_t *ο, Q_t ρ) {
  (void)got, ο[ρ + (1)].c(σ, α, ο, ρ);
}
static void gor(p_t *σ, Q_t α, p_t *ο, Q_t ρ) {
  (void)god, ο[ρ + (0)].c(σ, α, ο, ρ);
}
static void dot(p_t *σ, Q_t α, p_t *ο, Q_t ρ) {
  (void)gor, σ[α - (1)].c(σ, α - 1, ο, ρ);
}

static int cmp(const char *s1, const char *s2) {
  while (*s1 == *s2++)
    if (*s1++ == 0)
      return (0);
  return (*(unsigned char *)s1 - *(unsigned char *)--s2);
}
static void exports(αos_t *);
static void imports(αos_t *, const char *, void *, void (*)(αos_t *));
static int imported = 0;
static void init();
static void iff(αos_t *o, const char *n, void *a, void(e)(αos_t *)) {
  imported = 1, init(), exports(o->s);
}
static void error(αos_t *o, const char *mn, const char *in) {
  o->s->o(o->s, mn, in);
}
void tail(αos_t *o) __attribute__((section(".text.end")));
void tail(αos_t *o){};
void head(αos_t *o) __attribute__((section(".text.begin")));
void head(αos_t *o) {
  volatile ε_t t = tail;
  if (imported)
    exports(o);
  else
    t(&(αos_t){.a = imports, .o = error, .s = o, .mn = "src/a_debug.c"});
}
static int (*print)(const char *, ...);
static void expimp_4(αos_t *o, const char *n, void *a, void(e)(αos_t *)) {
  if (cmp(n, "printf") == 0)
    print = a, o->a = iff;
  o->in = "printf";
  e(o);
}
static n_t nar;
static void expimp_5(αos_t *o, const char *n, void *a, void(e)(αos_t *)) {
  if (cmp(n, "nar") == 0)
    nar = a, o->a = expimp_4;
  o->in = "nar";
  e(o);
}
static n_t os_ls;
static void expimp_6(αos_t *o, const char *n, void *a, void(e)(αos_t *)) {
  if (cmp(n, "os_ls") == 0)
    os_ls = a, o->a = expimp_5;
  o->in = "os_ls";
  e(o);
}
static n_t os_new;
static void expimp_7(αos_t *o, const char *n, void *a, void(e)(αos_t *)) {
  if (cmp(n, "os_new") == 0)
    os_new = a, o->a = expimp_6;
  o->in = "os_new";
  e(o);
}
static n_t os_queue;
static void expimp_8(αos_t *o, const char *n, void *a, void(e)(αos_t *)) {
  if (cmp(n, "os_queue") == 0)
    os_queue = a, o->a = expimp_7;
  o->in = "os_queue";
  e(o);
}
static n_t os_wordump;
static void expimp_9(αos_t *o, const char *n, void *a, void(e)(αos_t *)) {
  if (cmp(n, "os_wordump") == 0)
    os_wordump = a, o->a = expimp_8;
  o->in = "os_wordump";
  e(o);
}
static n_t and;
static void expimp_11(αos_t *o, const char *n, void *a, void(e)(αos_t *)) {
  if (cmp(n, "and") == 0)
    and = a, o->a = expimp_9;
  o->in = "and";
  e(o);
}
static n_t not ;
static void expimp_12(αos_t *o, const char *n, void *a, void(e)(αos_t *)) {
  if (cmp(n, "not") == 0)
    not = a, o->a = expimp_11;
  o->in = "not";
  e(o);
}
static n_t or ;
static void imports(αos_t *o, const char *n, void *a, void(e)(αos_t *)) {
  if (cmp(n, "or") == 0)
    or = a, o->a = expimp_12;
  o->in = "or";
  e(o);
};
void init() {}

static void Main(p_t *σ, Q_t α, p_t *ο, Q_t ρ) {
  σ[α++].v = (void *)(7), σ[α++].v = (void *)(os_wordump),
  σ[α - (1)].c(σ, α - 1, ο, ρ);
}

static void exports(αos_t *o) { o->a(o, "Main", Main, tail); };
