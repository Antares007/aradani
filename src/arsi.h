#pragma once
#define CAT_(a, b) a##b
#define CAT(a, b) CAT_(a, b)
#define L CAT(n, __LINE__)
#define E(t, name, n)                                                          \
  void n(o_t o, e_t e) { o(#name, name, t); }

typedef void (*o_t)(char *, void *, void *);
typedef void (*e_t)();
typedef void (*r_t)();
typedef void (*b_t)(o_t, e_t, r_t);

