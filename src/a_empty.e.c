#include "oars.h"
typedef struct αos_t {
  void (*a)(struct αos_t *, const char *, void *, void (*)(struct αos_t *));
  void (*o)(struct αos_t *);
  struct αos_t *s;
  const char *mn;
  void *d;
} αos_t;
typedef void (*ε_t)(αos_t *);

static int imported = 0;

void init2();

static void expimp_5(αos_t *o, const char *n, void *a, void(e)(αos_t *)) {
  imported = 1, init2(o->s), ((ε_t)o->d)(o->s);
}
static int cmp(const char *s1, const char *s2) {
  while (*s1 == *s2++)
    if (*s1++ == 0)
      return (0);
  return (*(unsigned char *)s1 - *(unsigned char *)--s2);
}
int (*print)(const char *, ...);
static void expimp_6(αos_t *o, const char *n, void *a, void(e)(αos_t *)) {
  if (cmp(n, "printf") == 0)
    print = a, o->a = expimp_5;
  e(o);
}
n_t os_queue;
static void imp(αos_t *o, const char *n, void *a, void(e)(αos_t *)) {
  if (cmp(n, "os_queue") == 0)
    os_queue = a, o->a = expimp_6;
  e(o);
};

void init2() { print("%s\n", __func__); }
p_t ο[512];
static void seven(p_t *σ, Q_t α, p_t *ο, Q_t ρ) {
  σ[α++].v = (void *)(7), ο[ρ + (1)].c(σ, α, ο, ρ);
}

static void exps(αos_t *);
void expimp_16(αos_t *o) __attribute__((section(".text.end")));
void expimp_16(αos_t *o) {}
void Headexpimp_16(αos_t *o) __attribute__((section(".text.begin")));
void Headexpimp_16(αos_t *o) {
  volatile ε_t t = expimp_16;
  if (imported)
    exps(o);
  else
    t(&(αos_t){.a = imp, .o = o->o, .s = o, .mn = "src/a_empty.c", .d = exps});
}
static void expimp_17(αos_t *o) { o->a(o, "seven", seven, expimp_16); }
static void exps(αos_t *o) { o->a(o, "ο", ο, expimp_17); };
