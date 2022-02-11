#include "arsi.h"
#include "gotgod.h"
// clang-format off
IBS(                L)IN(L,
os_hrtime,          L)IN(L,
os_queue,           L)IN(L,
//
and,                L)IN(L,
and2,               L)IN(L,
and2or,       imports);

N(addQQ)   { R(Q_t, r); R(Q_t, l); A(l + r) C(1); }
N(subQQ)   { R(Q_t, r); R(Q_t, l); A(l - r) C(1); }
N(ltQQ)    { R(Q_t, r); R(Q_t, l); C(l < r); }
N(mulQQ)   { R(Q_t, r); R(Q_t, l); A(l * r) C(1); }
N(divQQ)   { R(Q_t, r); R(Q_t, l); A(l / r) C(1); }
N(rotate2) { R(void *, b); R(void *, a); A2(b, a) C(1); }
N(rotate3) { R(void *, c); R(void *, b); R(void *, a); A3(b, c, a) C(1); }
N(dup)     { R(void *, a); A2(a, a) C(1); }
N(prnQ)    { R(Q_t, v); print("%lu\n", v); C(1); }

S(setTimeout_n) {
  R(Q_t, time);
  A10(os_hrtime, time, ltQQ, and2, time, setTimeout_n, dot, and2or, ο, os_queue) O;
}
N(setTimeout) { A5(os_hrtime, addQQ, and, setTimeout_n, and) O; }

N(s10) { A13( os_hrtime, dup, and,
              rotate3, and,
              subQQ, and,
              prnQ, and,
              s10, and,
              1000, setTimeout) O; }

N(მთავარი) { A3(os_hrtime, s10, and) O; }

void init() { print("\ninit %s\n", __FILE__); }

// clang-format off
EN(tail,
მთავარი,      exports);
