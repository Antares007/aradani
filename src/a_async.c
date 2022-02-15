#include "arsi.h"
#include "gotgod.h"
// clang-format off
IBS(                L)IN(L,
os_hrtime,          L)IN(L,
os_new,             L)IN(L,
os_queue,           L)IN(L,
//
and,                L)IN(L,
and2,               L)IN(L,
and3or,             L)IN(L,
and5,         imports);

S(addQQ)   { R(Q_t, r); R(Q_t, l); A(l + r) C(1); }
S(subQQ)   { R(Q_t, r); R(Q_t, l); A(l - r) C(1); }
S(ltQQ)    { R(Q_t, r); R(Q_t, l); C(l < r); }
S(rotate3) { R(void *, c); R(void *, b); R(void *, a); A3(b, c, a) C(1); }
S(dup)     { R(void *, a); A2(a, a) C(1); }
S(prnQ)    { R(Q_t, v); print("%lu\n", v); C(1); }

S(setTimeout_n) {
  R(Q_t, time);
  R(p_t*, oο);
  A11(os_hrtime, time, ltQQ, and2,
      oο, time, setTimeout_n,
      dot,
      and3or, oο, os_queue) O;
}
S(setTimeout) { A5(os_hrtime, addQQ, and, setTimeout_n, and) O; }
S(s10) { A14( os_hrtime, dup, and,
              rotate3, and,
              subQQ, and,
              prnQ, and,
              s10, and,
              ο, 1000, setTimeout) O; }

S(მთავარი) { A3(os_hrtime, s10, and) O; }

void init() { print("\ninit %s\n", __FILE__); }

// clang-format off
EN(tail,
მთავარი,      exports);
