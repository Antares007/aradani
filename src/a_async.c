#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
co0,                L)IN(L,
co1,                L)IN(L,
co2,                L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
os_hrtime,          L)IN(L,
os_ls,              L)IN(L,
os_new,             L)IN(L,
os_queue_n,         L)IN(L,
os_soll_free,       L)IN(L,
os_soll_n,          L)IN(L,
os_unsoll,          L)IN(L,
and,                L)IN(L,
and2,               L)IN(L,
and3,               L)IN(L,
and6,               L)IN(L,
not,          imports);

#define MAX_TIMEOUTS 1024

static Q_t timeouts[MAX_TIMEOUTS];
static p_t *piths[MAX_TIMEOUTS];
static Q_t timeouts_count;

SP(init) { timeouts_count = 0; C(1); }

static q_t binary_search_rightmost(Q_t t) {
  Q_t l = 0, r = timeouts_count, m;
  while (l < r) 
    if (t < timeouts[m = (l + r) / 2]) r = m;
    else l = m + 1;
  return r - 1;
}
S(insert_timeout_n) {
  R(p_t *, oο);
  R(Q_t, time);
  q_t pos = binary_search_rightmost(time);
  for (q_t lpos = timeouts_count; pos < lpos; lpos--) timeouts[lpos] = timeouts[lpos - 1];
  for (q_t lpos = timeouts_count; pos < lpos; lpos--)    piths[lpos] = piths[lpos - 1];
  timeouts_count++;
  timeouts[pos + 1] = time;
  piths[pos + 1] = oο;
  C(1);
}
S(srun);
S(run_timeouts_n) {
  R(Q_t, time);
  (void)time;
  q_t pos = binary_search_rightmost(time) + 1;
  σ[α++].c = god;
  for (Q_t i = 0; i < pos; i++) σ[α++].p = piths[i], σ[α++].c = srun, σ[α++].c = and2;
  for (Q_t i = pos; i < timeouts_count; i++) timeouts[i - pos] = timeouts[i];
  for (Q_t i = pos; i < timeouts_count; i++)    piths[i - pos] = piths[i];
  timeouts_count -= pos;
  O;
}
S(queue_timeout_run  );
S(run_timeouts       ) { Α(os_hrtime, run_timeouts_n, and) O; }
S(check_queue_timeout) { Α(timeouts_count ? queue_timeout_run : god) O; }
S(queue_timeout_run  ) { Α(run_timeouts, check_queue_timeout, and, ο, 3, os_queue_n) O; }
S(insert_timeout     ) { Α(insert_timeout_n, timeouts_count ? god : queue_timeout_run, and) O; }
S(drop) { α--, C(1); }
S(addQQ) {
  R(Q_t, r);
  R(Q_t, l);
  Α(l + r) C(1);
}
S(insert_timer);
S(insert_timer) {
  R(p_t *, oο);
  Α(oο[8].Q, os_hrtime, addQQ, and, oο, insert_timeout, and2) O;
}
S(srun) {
  R(p_t *, oο);
  p_t *sοll = oο[7].p;
  Α(sοll, os_unsoll, oο, sοll[-1].Q, os_queue_n, and3) O;
}
S(timer_and) { Α(ο, insert_timer, ο[Φ].p, 2, os_queue_n) O; }
S(timer_oor) { Α(ο[7].p, os_soll_free) O; }
S(timer_not) { Α(ο[7].p, os_soll_free, got, and) O; }
S(timer_set) {
  R(Q_t  , delay);
  R(p_t *, oο);
  R(p_t *, sοll);
  oο[7].p = sοll;
  oο[8].Q = delay;
  A(oο) C(1);
}
S(mk_timer) { Α(timer_not, timer_and, timer_oor, os_new) O; }
S(timer_n) {
  R(Q_t, wc);
  R(Q_t, delay);
  Α(wc, os_soll_n, mk_timer, and, delay, timer_set, and2, insert_timer, and) O;
}
S(timer ) { Q_t β = α - 1; Α(β, timer_n) O; }
S(printtimeouts) {
  for (Q_t i = 0; i < timeouts_count; i++)
    print("%lu %p\n", timeouts[i], piths[i]);
  C(1);
}
S(hello ) { R(Q_t, i); print("hello %lu\n", i), C(1); }
N(timers) { Α(
  1, hello, co1, and, 1000, timer,
  2, hello, co1, and, 2000, timer, and6,
  3, hello, co1, and, 3000, timer, and6,
  4, hello, co1, and, 4000, timer, and6,
  5, hello, co1, and, 5000, timer, and6,
  6, hello, co1, and, 6000, timer, and6,
  7, hello, co1, and, 7000, timer, and6) O; }

N(ls    ) { Α(exports, os_ls) O; }

// clang-format off
EN(tail,
binary_search_rightmost,  L)EN(L,
drop,                     L)EN(L,
god,                      L)EN(L,
hello,                    L)EN(L,
insert_timeout,           L)EN(L,
printtimeouts,            L)EN(L,
timer,                    L)EN(L,
timers,             exports)
