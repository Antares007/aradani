#pragma once
#include "oars.h"
typedef struct αos_t {
  void (*a)(struct αos_t *, const char *, void *, void (*)(struct αos_t *));
  void (*o)(struct αos_t *);
  struct αos_t *s;
  const char *mn;
  void *d;
} αos_t;
typedef void (*ε_t)(αos_t *);
#ifdef ARSI
#define TAIL_BODY                                                              \
  {}
#define TAIL_ATTR __attribute__((section(".text.end")));
#else
#define TAIL_BODY ;
#define TAIL_ATTR ;
#endif
#define E(Tail, Name, Addr, Head)                                              \
  static void Head(αos_t *o) { o->a(o, Name, Addr, Tail); }
#define I(Tail, Name, Addr, Head)                                              \
  static void Head(αos_t *o, const char *n, void *a, void(e)(αos_t *)) {       \
    if (cmp(n, Name) == 0)                                                     \
      Addr = a, o->a = Tail;                                                   \
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
#define EB(Head, Imports, Exports, Tail)                                       \
  static void Exports(αos_t *);                                                \
  void Tail(αos_t *o) TAIL_ATTR;                                               \
  void Tail(αos_t *o) TAIL_BODY;                                               \
  void Head(αos_t *o) __attribute__((section(".text.begin")));                 \
  void Head(αos_t *o) {                                                        \
    volatile ε_t t = Tail;                                                     \
    if (imported)                                                              \
      Exports(o);                                                              \
    else                                                                       \
      t(&(αos_t){                                                              \
          .a = Imports, .o = o->o, .s = o, .mn = __FILE__, .d = Exports});     \
  }
#define IB(Init, Head)                                                         \
  static int imported = 0;                                                     \
  static void Init();                                                          \
  static void Head(αos_t *o, const char *n, void *a, void(e)(αos_t *)) {       \
    imported = 1, Init(o->s), ((ε_t)o->d)(o->s);                               \
  }                                                                            \
  static int cmp(const char *s1, const char *s2) {                             \
    while (*s1 == *s2++)                                                       \
      if (*s1++ == 0)                                                          \
        return (0);                                                            \
    return (*(unsigned char *)s1 - *(unsigned char *)--s2);                    \
  }

#undef NP
#define NP(n)                                                                  \
  N(n##p);                                                                     \
  N(n) {                                                                       \
    print("%p %p %ld\t%ld\t%s:%s\n", σ, ο, α, ρ, __FILE__, __FUNCTION__);      \
    n##p(T());                                                                 \
  }                                                                            \
  N(n##p)
