#include "arsi.h"
IBS(                L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
os_new_ps,          L)IN(L,
os_queue_and,       L)IN(L,
os_queue_n,         L)IN(L,
os_win,             L)IN(L,
//
and2,               L)IN(L,
and5,         imports)
SarP(init)(god)

SP(c_oor) {
  R(p_t *, oο);
  ο[8].p = oο;
  C(1);
  //Α(Inc, Dec, and, Sum, and) O;
}
SP(c_and) { C(1); }
SP(c_not) { C(1); }
NarP(c)(c_not, c_and, c_oor, ο, 512, os_new_ps);
Sar(expample)(c, gor, os_win, and2, 2, os_queue_n, and2)

Sar(Increase)('+', 'txt', god, ο, 3, os_queue_n)
Sar(Decrease)('-', 'txt', god, ο, 3, os_queue_n)
Nar(Counter)(
  Increase, 'btn', god, ο, 3, os_queue_n,
  Decrease, 'btn', god, ο, 3, os_queue_and,
       '0', 'txt', god, ο, 3, os_queue_and
)
S(Increase2) {
  Α('+', 'txt', god) O;
}
S(Decrease2) {
  Α('-', 'txt') C(1);
}
N(Counter2) {
  Α(Increase2, 'btn') C(1);
  Α(Decrease2, 'btn') C(1);
  Α("0", 'txt') C(1);
}

EN(tail,
expample,     exports)
