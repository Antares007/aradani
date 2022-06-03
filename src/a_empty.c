#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
nar,          imports)

Sargo(init)(god)
N(one) { 
  σ[α++].Q = 1;
  ο[1].c(ο, α, ρ, σ);
}
N(plus) {
  q_t r = σ[--α].q;
  q_t l = σ[--α].q;
  σ[α++].q = l + r;
  ο[1].c(ο, α, ρ, σ);
}
N(and) {
}
N(ο0) {
  σ[α-1].c(ο, α-1, ρ, σ);
}
N(ο1) {
  σ[ρ+1].c(ο, α, ρ, σ);
}
N(two) {
  σ[α++].c = one;
  σ[α++].c = one;
  σ[α++].c = and;
  σ[α++].c = plus;
  σ[α++].c = and;
  ο[0].c(ο, α, ρ, σ);
}
N(g0d) { σ[ρ + 1].c(ο, α, ρ, σ); }

N(Main) { A(god) ο[0].c(T()); }

void Main_(p_t *ο, Q_t α, Q_t ρ, p_t *σ) {
  σ[α++].v = (void *)(god), ο[0].c(ο, α, ρ, σ);
}

EN(tail,
Main, exports)
