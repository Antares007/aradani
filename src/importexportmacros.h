#pragma once
#define L CAT(e, __LINE__)
#define E(t, name, addr, n)                                                    \
  N(n) { A3(name, addr, t) C(1); }
#define I(t, name, addr, n)                                                    \
  N(n) { A3(name, &addr, t) C(1); }
#define IN(t, name, n)                                                         \
  n_t name;                                                                    \
  I(t, #name, name, n)
#define INT(t, name, T, n)                                                     \
  T name;                                                                      \
  I(t, #name, name, n)
#define EN(t, name, n) E(t, #name, name, n)
