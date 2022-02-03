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
#define E(Tail, Name, Addr, Head)                                              \
  void Head(αos_t *o) { o->a(o, Name, Addr, Tail); }
#define I(Tail, Name, Addr, Head)                                              \
  void Head(αos_t *o, const char *n, void *a, void(e)(αos_t *)) {              \
    if (cmp(n, Name) == 0)                                                     \
      Addr = a, o->a = Tail;                                                   \
    e(o);                                                                      \
  }
#define L CAT(expimp_, __LINE__)
#define EN(Tail, Name, Head) E(Tail, #Name, Name, Head)
#define IN(Tail, Name, Head)                                                   \
  n_t Name;                                                                    \
  I(Tail, #Name, Name, Head)
#define IF(Tail, IName, Name, Head, Ret, ...)                                  \
  Ret (*Name)(__VA_ARGS__);                                                    \
  I(Tail, #IName, Name, Head)
static void νοπ();
static int cmp(const char *s1, const char *s2) {
  (void)νοπ;
  while (*s1 == *s2++)
    if (*s1++ == 0)
      return (0);
  return (*(unsigned char *)s1 - *(unsigned char *)--s2);
}
static void νοπ() { (void)cmp; }
