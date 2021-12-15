#pragma once
#define M(name) void name(void *s, void(and_ray)(), void(or_ray)())
typedef M((*m_t));
#define L CAT(expimp_, __LINE__)
#define E(Tail, Name, Addr, Head)                                              \
  M(Head) { and_ray(s, #Name, Addr, Tail); }
#define EN(Tail, Name, Head) E(Tail, Name, Name, Head)
