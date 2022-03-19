#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
os_hrtime,          L)IN(L,
os_ls,              L)IN(L,
os_new,             L)IN(L,
os_queue,           L)IN(L,
os_soll_free,       L)IN(L,
os_soll_n,          L)IN(L,
os_unsoll,          L)IN(L,
and,                L)IN(L,
and2,               L)IN(L,
and6,               L)IN(L,
not,          imports);

#define MAX_TIMEOUTS 1024

static Q_t timeouts[MAX_TIMEOUTS];
static p_t *piths[MAX_TIMEOUTS];
static Q_t timeouts_count;

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
Sar(run_timeouts)(os_hrtime, run_timeouts_n, and)
S(queue_timeout_run);
Sar(check_queue_timeout)(
  timeouts_count ?
    queue_timeout_run :
    god)
Sar(queue_timeout_run)(
  run_timeouts, check_queue_timeout, and, ο, os_queue)
Sar(insert_timeout)(
  insert_timeout_n,
  timeouts_count ?
    god :
    queue_timeout_run, and)
SP(init) {
  timeouts_count = 0;
  C(1);
}
S(drop) { α--, C(1); }
S(addQQ) {
  R(Q_t, r);
  R(Q_t, l);
  Α(l + r) C(1);
}
S(insert_timer_pith);
Sar(reset_timer)(ο, insert_timer_pith, ο[0].p, os_queue)
Sar(timer_oor)(ο[7].p, os_soll_free)
Sar(timer_not)(ο[7].p, os_soll_free, got, and)
Sar(create_timer_pith)(timer_not, reset_timer, timer_oor, os_new)
S(insert_timer_pith) {
  R(p_t *, oο);
  Α(oο[8].Q, os_hrtime, addQQ, and, oο, insert_timeout, and2) O;
}
S(srun) {
  R(p_t *, oο);
  p_t *sοll = oο[7].p;
  Α(sοll, os_unsoll, oο, os_queue, and2) O;
}
S(timer_set) {
  R(Q_t  , delay);
  R(p_t *, oο);
  R(p_t *, sοll);
  oο[7].p = sοll;
  oο[8].Q = delay;
  A(oο) C(1);
}
S(timer_n) {
  R(Q_t, wc);
  R(Q_t, delay);
  Α(    wc, os_soll_n,
    create_timer_pith, and,
     delay, timer_set, and2,
    insert_timer_pith, and) O;
}
S(timer) { Q_t β = α - 1; Α(β, timer_n) O; }
S(printtimeouts) {
  for (Q_t i = 0; i < timeouts_count; i++)
    print("%lu %p\n", timeouts[i], piths[i]);
  C(1);
}
S(hello) { R(Q_t, i); print("hello %lu\n", i), C(1); }
Nar(timers)(
  1, hello, god, and, 1000, timer,
  2, hello, god, and, 2000, timer, and6,
  3, hello, god, and, 3000, timer, and6,
  4, hello, god, and, 4000, timer, and6,
  5, hello, god, and, 5000, timer, and6,
  6, hello, god, and, 6000, timer, and6,
  7, hello, god, and, 7000, timer, and6)
Nar(ls)(exports, os_ls)
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
