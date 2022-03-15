#include "arsi.h"
IBS(                L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
os_new_psn,         L)IN(L,
os_queue,           L)IN(L,
os_queue_n,         L)IN(L,
os_win,             L)IN(L,
//
and2,               L)IN(L,
and5,         imports)
Sar(init)(god)

SP(c_oor) {
  R(p_t *, oο);
  ο[8].p = oο;
  C(1);
  //Α(Inc, Dec, and, Sum, and) O;
}
SP(c_and) { C(1); }
SP(c_not) { C(1); }
NarP(c)(c_not, c_and, c_oor, ο, 512, "c", os_new_psn);
Sar(expample)(c, gor, os_win, and2, 2, os_queue_n, and2)

Sar(Increase)('+', 'txt', god, ο, os_queue)
Sar(Decrease)('-', 'txt', god, ο, os_queue)
Nar(Counter)(
  Increase, 'btn', god, ο, os_queue,
  Decrease, 'btn', god, ο, os_queue, and5,
       '0', 'txt', god, ο, os_queue, and5
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
