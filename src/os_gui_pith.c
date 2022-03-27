#include "gotgod.h"
#include "oars.h"
#include "raylib.h"

N(os_new_ps);
N(os_queue_n);
N(nar);
Sar(and)(010, nar);
typedef struct win_t {
  W_t width;
  W_t height;
} win_t;
#define State(T, O) T *s = (T *)&(O)[7]

SP(win_oor) {
  R(p_t *, oο);
  ο[8].p = oο;
  Α(ο, gor, oο, 2, os_queue_n) O;
}
SP(win_and) {
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
SP(win_not) {}
SP(win_set) {
  R(p_t *, oο);
  SetTraceLogLevel(LOG_ERROR | LOG_WARNING | LOG_DEBUG); //LOG_INFO
  InitWindow(800, 450, "Window");

  SetTargetFPS(0);
  Α(oο) C(1);
}
NarP(os_win)(win_not, win_and, win_oor, ο, 512, os_new_ps, win_set, and);
