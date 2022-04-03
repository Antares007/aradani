#include "arsi.h"
IBS(                L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
os_new_ps,          L)IN(L,
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
N(c) { Α(c_not, c_and, c_oor, ο, 512, os_new_ps) O; }
S(expample) { Α(c, gor, os_win, and2, 2, os_queue_n, and2) O; }

typedef struct dom_t {
  n_t element;
  n_t text;
} dom_t;
S(Increase2) {
  dom_t *o = (dom_t *)&ο[7];
  Α('+', o->text) O;
}
S(Decrease2) {
  dom_t *o = (dom_t *)&ο[7];
  Α('-', o->text) O;
}
N(Counter2) {
  dom_t *o = (dom_t *)&ο[7];
  Α(Increase2, "button", o->element) O;
  Α(Decrease2, "button", o->element) O;
  Α("0", o->text) O;
}

EN(tail,
expample,     exports)
