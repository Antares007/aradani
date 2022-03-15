#include "gotgod.h"
#include "oars.h"
#include "raylib.h"

N(os_new_psn);
N(os_queue_n);
N(nar);
Sar(and)(010, nar);
typedef struct win_t {
  W_t width;
  W_t height;
} win_t;
#define State(T, O) T *s = (T *)&(O)[7]

S(win_oor) {
  R(p_t *, oο);
  ο[8].p = oο;
  Α(ο, gor, oο, 2, os_queue_n) O;
}
S(win_and) {
  R(Q_t, m);
  switch (m) {
  case 'beg':
    C(1);
    break;
  case 'cls':
    C(1);
    break;
  case 'win':
    C(1);
    break;
  case 'end':
    C(1);
    break;
  default:
    C(2);
    break;
  }
}
S(win_not) {}
S(win_set) {
  R(p_t *, oο);
  InitWindow(800, 450, "Window");
  SetTargetFPS(0);
  Α(oο) C(1);
}
Nar(win)(win_not, win_and, win_oor, ο, 512, "ωin", os_new_psn, win_set, and);

S(counter_oor) {
  R(p_t *, oο);
  ο[7].p = oο;
  //Α(Inc, Dec, and, Sum, and) O;
}
S(counter_and) { C(1); }
S(counter_not) { C(1); }
Nar(counter)(counter_not, counter_and, counter_oor, ο, 512, "counter",
             os_new_psn);
