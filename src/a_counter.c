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
and5,         imports)
Sar(init)(god)
S(counter_oor) {
  R(p_t *, oο);
  ο[7].p = oο;
  //Α(Inc, Dec, and, Sum, and) O;
}
S(counter_and) { C(1); }
S(counter_not) { C(1); }
Nar(counter)(counter_not, counter_and, counter_oor, ο, 512, "counter",
             os_new_psn);
Sar(expample)(god)

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
