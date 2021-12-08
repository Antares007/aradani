#pragma once
#define M(name) void name(void *state, void(and_ray)(), void(or_ray)())
#define L CAT(expimp_, __LINE__)
#define E(Tail, Name, Addr, Head) M(Head) { and_ray(state, #Name, Addr, Tail); }
#define I(Tail, Name, Addr, Head) M(Head) { and_ray(state, #Name, &Addr, Tail); }
#define IN(Tail, Name, Head) n_t Name; I(Tail, Name, Name, Head)
#define EN(Tail, Name, Head) E(Tail, Name, Name, Head)
