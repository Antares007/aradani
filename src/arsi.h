#pragma once
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
#define IB(Head)                                                               \
  static void exports(αos_t *);                                                \
  static void imports(αos_t *, const char *, void *, void (*)(αos_t *));       \
  static int imported = 0;                                                     \
  static void init();                                                          \
  static void Head(αos_t *o, const char *n, void *a, void(e)(αos_t *)) {       \
    imported = 1, init(), exports(o->s);                                       \
  }                                                                            \
  static void error(αos_t *o, const char *mn, const char *in) {                \
    o->s->o(o->s, mn, in);                                                     \
  }                                                                            \
  void tail(αos_t *o) __attribute__((section(".text.end")));                   \
  void tail(αos_t *o){};                                                       \
  void head(αos_t *o) __attribute__((section(".text.begin")));                 \
  void head(αos_t *o) {                                                        \
    volatile ε_t t = tail;                                                     \
    if (imported)                                                              \
      exports(o);                                                              \
    else                                                                       \
      t(&(αos_t){.a = imports, .o = error, .s = o, .mn = __FILE__});           \
  }
#define IBS(Head)                                                              \
  static int cmp(const char *s1, const char *s2) {                             \
    while (*s1 == *s2++)                                                       \
      if (*s1++ == 0)                                                          \
        return (0);                                                            \
    return (*(unsigned char *)s1 - *(unsigned char *)--s2);                    \
  }                                                                            \
  IB(iff) IF(iff, printf, print, Head, int, const char *, ...)
#define E(Tail, Name, Addr, Head)                                              \
  static void Head(αos_t *o) { o->a(o, Name, Addr, Tail); }
#define I(Tail, Name, Addr, Head)                                              \
  static void Head(αos_t *o, const char *n, void *a, void(e)(αos_t *)) {       \
    if (cmp(n, Name) == 0)                                                     \
      Addr = a, o->a = Tail;                                                   \
    o->in = Name;                                                              \
    e(o);                                                                      \
  }
#define L CAT(expimp_, __LINE__)
#define EN(Tail, Name, Head) E(Tail, #Name, Name, Head)
#define IN(Tail, Name, Head)                                                   \
  static n_t Name;                                                             \
  I(Tail, #Name, Name, Head)
#define IF(Tail, IName, Name, Head, Ret, ...)                                  \
  static Ret (*Name)(__VA_ARGS__);                                             \
  I(Tail, #IName, Name, Head)
