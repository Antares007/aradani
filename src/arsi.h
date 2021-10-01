#pragma once
#define Oars()                                                                 \
  void head() __attribute__((section(".text.begin")));                         \
  void tail() __attribute__((section(".text.end")));                           \
  void tail(o_t o, e_t e) {}                                                   \
  void head(o_t o, e_t e)
#define CAT_(a, b) a##b
#define CAT(a, b) CAT_(a, b)
#define L CAT(n, __LINE__)
#define E(t, name, n)                                                          \
  void n(o_t o, e_t e) { o(#name, name, t); }

typedef void (*o_t)(char *, void *, void *);
typedef void (*e_t)();
typedef void (*b_t)(o_t, e_t);

void head(o_t o, e_t e);
void nextf(o_t o, e_t e);
