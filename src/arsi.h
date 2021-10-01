#pragma once
#include "evalmap.h"

#define CAT_(a, b) a##b
#define CAT(a, b) CAT_(a, b)
#define L CAT(n, __LINE__)
#define And(t, name, n)                                                        \
  void n(o_t o, e_t e, r_t r) { o(#name, name, t); }

typedef void (*o_t)(char *, void *, void *);
typedef void (*e_t)();
typedef void (*r_t)();
typedef void (*b_t)(o_t, e_t, r_t);

#define ToStr(a) #a,
#define ArgsToStr(...) EVAL(MAP(ToStr, __VA_ARGS__))
#define ToNar(a) n_t a;
#define ArgsToNar(...) EVAL(MAP(ToNar, __VA_ARGS__))

#define Imports(...)                                                           \
  char *imports[] = {ArgsToStr(__VA_ARGS__)};                                  \
  struct i_s {                                                                 \
    ArgsToNar(__VA_ARGS__)                                                     \
  };                                                                           \
  struct i_s im = {};                                                          \
  Impl

#define Impl                                                                   \
  static o_t uo = 0;                                                           \
  static b_t no = 0;                                                           \
  static e_t ue = 0;                                                           \
  static r_t ur = 0;                                                           \
  int cmp(const char *p1, const char *p2) {                                    \
    const unsigned char *s1 = (const unsigned char *)p1;                       \
    const unsigned char *s2 = (const unsigned char *)p2;                       \
    unsigned char c1, c2;                                                      \
    do {                                                                       \
      c1 = (unsigned char)*s1++;                                               \
      c2 = (unsigned char)*s2++;                                               \
      if (c1 == '\0')                                                          \
        return c1 - c2;                                                        \
    } while (c1 == c2);                                                        \
    return c1 - c2;                                                            \
  }                                                                            \
  void tail() __attribute__((section(".text.end")));                           \
  void tail(o_t o, e_t e, r_t r) {}                                            \
  void nextf(o_t o, e_t e, r_t r);                                             \
  void mo(char *name, void *addr, void *next) {                                \
    no = next;                                                                 \
    for (long i = 0; i < sizeof(imports); i++)                                 \
      if (cmp(name, imports[i]))                                               \
        ((p_t *)&im)[i].v = addr;                                              \
    uo(name, addr, nextf);                                                     \
  }                                                                            \
  void export(o_t, e_t, r_t);                                                  \
  void me() {                                                                  \
    for (long i = 0; i < sizeof(imports); i++)                                 \
      if (((p_t *)&im)[i].v == 0) {                                            \
        return ur();                                                           \
      }                                                                        \
    export(uo, ue, ur);                                                        \
  }                                                                            \
  void head() __attribute__((section(".text.begin")));                         \
  void head(o_t o, e_t e, r_t r) {                                             \
    uo = o, ue = e, ur = r;                                                    \
    volatile b_t t = tail;                                                     \
    t(mo, me, r);                                                              \
  }                                                                            \
  void nextf(o_t o, e_t e, r_t r) {                                            \
    uo = o, ue = e, ur = r;                                                    \
    volatile b_t t = no;                                                       \
    t(mo, me, r);                                                              \
  }
#define Exports(fn, n) And(ue, fn, n)
#define End(t, n) And(t, n, export)
