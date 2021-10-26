#pragma once
#include "evalmap.h"
#include "oars.h"
#define ToStr(a) #a,
#define ArgsToStr(...) EVAL(MAP(ToStr, __VA_ARGS__))
#define ToNar(a) n_t a;
#define ToNar2(a) a,
#define ArgsToNar(...) EVAL(MAP(ToNar, __VA_ARGS__))
#define ArgsToNar2(...) EVAL(MAP(ToNar2, __VA_ARGS__))
#define Imports(...)                                                           \
  N(tail);                                                                     \
  static N(imports);                                                           \
  static N(exports);                                                           \
  static void adjustaddresses();                                               \
  char *nαmes[] = {ArgsToStr(__VA_ARGS__)};                                    \
  void head() __attribute__((section(".text.begin")));                         \
  N(head) {                                                                    \
    R(n_t, cb);                                                                \
    adjustaddresses();                                                         \
    A4(imports, exports, tail, cb) O;                                          \
  }                                                                            \
  void tail() __attribute__((section(".text.end")));                           \
  N(tail) {}                                                                   \
  struct ο_s {                                                                 \
    ArgsToNar(__VA_ARGS__)                                                     \
  };                                                                           \
  struct ο_s o = {};                                                           \
  static N(imports) { A3(nαmes, &o, (sizeof(nαmes) / sizeof(*nαmes))) C(1); }
#define Exports(...)                                                           \
  char *νames[] = {ArgsToStr(__VA_ARGS__)};                                    \
  n_t νars[] = {ArgsToNar2(__VA_ARGS__)};                                      \
  static N(exports) {                                                          \
    A3(νames, νars, (sizeof(νames) / sizeof(*νames))) C(1);                    \
  }                                                                            \
  static void adjustaddresses() {                                              \
    for (long i = 0; i < sizeof(nαmes) / sizeof(*nαmes); i++)                  \
      nαmes[i] = (void *)((unsigned long)&head + ((unsigned long *)nαmes)[i]); \
    for (long i = 0; i < sizeof(νames) / sizeof(*νames); i++)                  \
      νames[i] = (void *)((unsigned long)&head + ((unsigned long *)νames)[i]); \
    for (long i = 0; i < sizeof(νars) / sizeof(*νars); i++)                    \
      νars[i] = (void *)((unsigned long)&head + ((unsigned long *)νars)[i]);   \
  }
