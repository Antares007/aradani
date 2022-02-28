#include "arsi.h"
#include "gotgod.h"
// clang-format off
IBS(                L)IN(L,
nar,                L)IN(L,
os_hrtime,          L)IN(L,
os_ls,              L)IN(L,
os_new,             L)IN(L,
os_new_j,           L)IN(L,
os_queue,           L)IN(L,
os_wordump,         L)IN(L,
//
and,                L)IN(L,
and2,               L)IN(L,
and2or,             L)IN(L,
and3,               L)IN(L,
and3or,             L)IN(L,
and4,               L)IN(L,
and5,               L)IN(L,
and6,               L)IN(L,
andor,              L)IN(L,
not,                L)IN(L,
or,                 L)IN(L,
//
debug_init,         L)IN(L,
debug_οdump,        L)IN(L,
debug_σdump,  imports)

#define MAX_TIMEOUTS 1024
static Q_t timeouts[MAX_TIMEOUTS];
static p_t *piths[MAX_TIMEOUTS];
static Q_t timeouts_count;

static q_t binary_search_rightmost(Q_t t) {
  Q_t l = 0;
  Q_t r = timeouts_count;
  while (l < r) {
    Q_t m = (l + r) / 2;
    if (t < timeouts[m])
      r = m;
    else
      l = m + 1;
  }
  return r - 1;
}
S(insert_timeout_n) {
  R(p_t *, oο);
  R(Q_t, time);
  q_t pos = binary_search_rightmost(time);
  for (q_t lpos = timeouts_count; pos < lpos; lpos--)
    timeouts[lpos] = timeouts[lpos - 1];
  for (q_t lpos = timeouts_count; pos < lpos; lpos--)
    piths[lpos] = piths[lpos - 1];
  timeouts_count++;
  timeouts[pos + 1] = time;
  piths[pos + 1] = oο;
  C(1);
}
S(srun) {
  R(p_t *, oο);
  Q_t oρ = oο[7].Q;
  while(oρ) σ[α++].v = oο[--oρ + 8].v;
  α--;
  Α(oο, os_queue) O;
}
S(run_timeouts_n) {
  R(Q_t, time);
  (void)time;
  q_t pos   = binary_search_rightmost(time) + 1;
  σ[α++].c  = god;
  for(Q_t i = 0  ; i < pos           ; i++) σ[α++].p = piths[i], σ[α++].c = srun, σ[α++].c = and2;
  for(Q_t i = pos; i < timeouts_count; i++) timeouts[i - pos] = timeouts[i];
  for(Q_t i = pos; i < timeouts_count; i++)    piths[i - pos] =    piths[i];
  timeouts_count -= pos;
  O;
}
Sar(run_timeouts, os_hrtime, run_timeouts_n, and)
S(queue_timeout_run  );
S(check_queue_timeout) { A(timeouts_count ? queue_timeout_run : god) O; }
S(queue_timeout_run  ) { A5(run_timeouts, check_queue_timeout, and, ο, os_queue) O; }
S(insert_timeout     ) { A3(insert_timeout_n, timeouts_count ? god : queue_timeout_run, and) O; }

S(printtimeouts) {
  for (Q_t i = 0; i < timeouts_count; i++)
    print("%lu %p\n", timeouts[i], piths[i]);
  C(1);
}
SP(init) {
  timeouts_count = 0;
  Α(exports, debug_init) O;
}
S(drop) { α--, C(1); }
SP(got_p) { C(2); }
SP(god_p) { C(1); }
SP(gor_p) { C(0); }
// oor exec sentence,  stop timer & C(0)
// and exec sentence, renew timer & C(1)
// not                 stop timer & C(2)
S(addQQ) {
  R(Q_t, r);
  R(Q_t, l);
  Α(l + r) C(1);
}
S(insert_timer_pith);
Sar(reset_timer, ο, insert_timer_pith, ο[0].p, os_queue) 
Sar(create_timer_pith, reset_timer, 0010, os_new_j)
S(timer_n) {
  R(p_t *, oο);
  Q_t oρ = 7;
  oο[oρ++].Q = α;
  while (α)
    oο[oρ++].v = σ[--α].v;
  A(oο) C(1);
}
S(insert_timer_pith) {
  R(p_t *, oο);
  Α(oο[8].Q, os_hrtime, addQQ, and, oο, insert_timeout, and2) O;
}
Sar(timer,
    create_timer_pith, timer_n, and,
    insert_timer_pith, and)

S(hello) {
  R(Q_t, i);
  print("hello %lu\n", i), C(1);
}

NarP(test9_,
    debug_οdump,
    1, hello, god, and, 1000, timer, and6,
    2, hello, god, and, 2000, timer, and6,
    3, hello, god, and, 3000, timer, and6,
    4, hello, god, and, 4000, timer, and6,
    5, hello, god, and, 5000, timer, and6,
    6, hello, god, and, 6000, timer, and6,
    7, hello, god, and, 7000, timer, and6,
    printtimeouts, and)
static Q_t counter[3];
SP(n0) { counter[0]++, C(1); }
SP(n1) { counter[1]++, C(1); }
SP(n2) { counter[2]++, C(1); }
S(mkpith0) {
  Α(
    n2, n2, and,
    n1, n1, and, n1, and,
    n0, n0, and, n0, and, n0, and,
    0357, os_new_j) O; 
}
SP(test99) {
  R(p_t *, oο);
  Α(gor_p, oο, os_queue,
    god_p, oο, os_queue, and3,
    got_p, oο, os_queue, and3,
  ) O;
  print("0. %lu\n", counter[0] == 4);
  print("1. %lu\n", counter[1] == 3);
  print("2. %lu\n", counter[2] == 2);
}
NarP(test9, mkpith0, test99, and)
Nar(ls, exports, os_ls)

// clang-format off
EN(tail,
binary_search_rightmost,  L)EN(L,
drop,                     L)EN(L,
god,                      L)EN(L,
hello,                    L)EN(L,
insert_timeout,           L)EN(L,
printtimeouts,            L)EN(L,
timer,                    L)EN(L,
test9_,              exports)
