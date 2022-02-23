#include "arsi.h"
#include "gotgod.h"
// clang-format off
IBS(                L)IN(L,
nar,                L)IN(L,
os_create,          L)IN(L,
os_create_psn,      L)IN(L,
os_hrtime,          L)IN(L,
os_new,             L)IN(L,
os_new_psn,         L)IN(L,
os_queue,           L)IN(L,
os_wordump,         L)IN(L,
//
and,                L)IN(L,
and2,               L)IN(L,
and3or,             L)IN(L,
and5,               L)IN(L,
not,                L)IN(L,
or,                 L)IN(L,
//
debug_init,         L)IN(L,
debug_οdump,        L)IN(L,
debug_σdump,  imports)

#define MAX_TIMEOUTS 1024
typedef struct timeout_t {
  Q_t due_time;
  p_t ο;
} timeout_t;
static timeout_t timeouts[MAX_TIMEOUTS];
static Q_t timeouts_count;

S(binary_search_rightmost) {
  R(Q_t, t);
  Q_t l = 0;
  Q_t r = timeouts_count;
  while (l < r) {
    Q_t m = (l + r) / 2;
    if (t < timeouts[m].due_time) r = m;
    else l = m + 1;
  }
  A(r - 1) C(1);
}

N(insert_timeout) {}
SP(init) {
  timeouts_count = 0;
  for(Q_t i = 0; i < MAX_TIMEOUTS; i++) timeouts[i].due_time = 0;
  timeouts[0].due_time = 0;
  timeouts[1].due_time = 0;
  timeouts[2].due_time = 0;
  timeouts[3].due_time = 2;
  timeouts_count = 4;
  Α(exports, debug_init) O;
}
N(drop) { α--, C(1); }
NP(test0) { Α(0, binary_search_rightmost, os_wordump, and, drop, and) O; }
NP(test1) { Α(1, binary_search_rightmost, os_wordump, and, drop, and) O; }
NP(test2) { Α(2, binary_search_rightmost, os_wordump, and, drop, and) O; }
NP(test3) { Α(3, binary_search_rightmost, os_wordump, and, drop, and) O; }

NP(test_n) { Α(test0, test1, and, test2, and, test3, and) O; }

NP(got_p) { C(2); }
NP(god_p) { C(1); }
NP(gor_p) { C(0); }
// oor exec sentence,  stop timer & C(0)
// and exec sentence, renew timer & C(1)
// not                 stop timer & C(2)
Sar(
  timer,
  gor,
  got_p, got_p, not, got_p, not, got_p, not,
  god_p, god_p, and, god_p, and, god_p, and,
  gor_p, gor_p,  or, gor_p,  or, gor_p,  or,
  0777, os_create, os_queue, and
)
S(hello) { print("hello\n"), C(1); }
Nar(test9, hello, gor, and, 1000, timer)






















S(addQQ)   { R(Q_t, r); R(Q_t, l); Α(l + r) C(1); }
S(subQQ)   { R(Q_t, r); R(Q_t, l); Α(l - r) C(1); }
S(ltQQ)    { R(Q_t, r); R(Q_t, l); C(l < r); }
S(rotate3) { R(void *, c); R(void *, b); R(void *, a); Α(b, c, a) C(1); }
S(dup)     { R(void *, a); Α(a, a) C(1); }
SP(prnQ)   { R(Q_t, v); print("%lu\n", v); C(1); }

S(setTimeout_n) {
  R(Q_t, time);
  R(p_t*, oο);
  Α(  os_hrtime, time, ltQQ, and2,
      oο, time, setTimeout_n,
      dot,
      and3or, oο, os_queue) O;
}
Nar(setTimeout, os_hrtime, addQQ, and, setTimeout_n, and)

Sar(s10,
    debug_οdump, os_hrtime, and,
    dup, and,
    rotate3, and,
    subQQ, and,
    prnQ, and,
    s10, and,
    ο, 3000, setTimeout
  )
Nar(მთავარი, os_hrtime, s10, and)
// მთავარი
// clang-format off
EN(tail,
binary_search_rightmost,
                    L)EN(L,
drop,               L)EN(L,
test0,              L)EN(L,
test1,              L)EN(L,
test2,              L)EN(L,
test3,              L)EN(L,
მთავარი,            L)EN(L,
test9,        exports)
