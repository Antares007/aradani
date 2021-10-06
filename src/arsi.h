#pragma once
#include "evalmap.h"
#include "oars.h"
#define ImportsExports                                                         \
  N(tail);                                                                     \
  static N(imports);                                                           \
  static N(exports);                                                           \
  void head() __attribute__((section(".text.begin")));                         \
  N(head) {                                                                    \
    R(n_t, cb);                                                                \
    A4(imports, exports, tail, cb) O;                                          \
  }                                                                            \
  void tail() __attribute__((section(".text.end")));                           \
  N(tail) {}
#define ToStr(a) #a,
#define ArgsToStr(...) EVAL(MAP(ToStr, __VA_ARGS__))
#define ToNar(a) n_t a;
#define ToNar2(a) a,
#define ArgsToNar(...) EVAL(MAP(ToNar, __VA_ARGS__))
#define ArgsToNar2(...) EVAL(MAP(ToNar2, __VA_ARGS__))
#define Imports_(...)                                                          \
  char *nαmes[] = {ArgsToStr(__VA_ARGS__)};                                    \
  struct ο_s {                                                                 \
    ArgsToNar(__VA_ARGS__)                                                     \
  };                                                                           \
  struct ο_s o = {};                                                           \
  static N(imports) {                                                          \
    for (long i = 0; i < sizeof(nαmes) / sizeof(*nαmes); i++)                  \
      nαmes[i] = (void *)((unsigned long)&head + ((unsigned long *)nαmes)[i]); \
    A3(nαmes, &o, (sizeof(nαmes) / sizeof(*nαmes))) C(, 1);                    \
  }
#define Imports(...) ImportsExports Imports_(__VA_ARGS__)
#define Exports(...)                                                           \
  char *νames[] = {ArgsToStr(__VA_ARGS__)};                                    \
  n_t νars[] = {ArgsToNar2(__VA_ARGS__)};                                      \
  static N(exports) {                                                          \
    A3(νames, νars, (sizeof(νames) / sizeof(*νames))) C(, 1);                  \
  }
