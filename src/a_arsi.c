#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
os_next,            L)IN(L,
os_queue_n,       L)IN(L, //
and,                L)IN(L,
and2,         imports);
// clang-format on
NP(sgod) {
  R(Q_t, c);
  if (c > 4)
    C(1);
  else
    Α(c + 1, sgod, ο, 2, os_queue_n) O;
}
SP(ayr_not) {
  if (α == 3) {
    R(n_t, e);
    R(void *, a);
    R(const char *, n);
    print("%s %p %p\n", n, a, e);
  } else
    Α(god, ο[7].p, 1, os_queue_n) O;
}
SP(ayr_oor) {
  R(p_t *, oο);
  ο[7].p = oο;
  Α(0, sgod) O;
}
NP(ayr_and) { os_next(T()); }
p_t oο[512];
SP(init) {
  Q_t oρ = oο[Σ].Q = sizeof(oο) / sizeof(*oο);
  oο[--oρ].c = ayr_not;
  oο[--oρ].c = os_next;
  oο[--oρ].c = ayr_oor;
  oο[Φ].p = oο, oο[Ρ].Q = oρ, oο[Ψ + 0].p = &oο[Ψ], oο[Ψ + 1].p = &oο[Ψ],
  oο[Ι].Q = 0;
  C(1);
}
Nar(example1)(oο, gor, ο, 2, os_queue_n);
Nar(example0)(0, sgod, ο, 2, os_queue_n);
Nar(example)(example1, example0, and);
// clang-format off
EN(tail,
example,      exports)
