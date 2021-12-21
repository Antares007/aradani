#pragma once
#define L CAT(expimp_, __LINE__)
#define E(Tail, Name, Addr, Head)                                              \
  void Head(void *s, void(and_ray)(), void(or_ray)()) {                        \
    and_ray(s, #Name, Addr, Tail);                                             \
  }
#define EN(Tail, Name, Head) E(Tail, Name, Name, Head)
