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
and2or,             L)IN(L,
and3,               L)IN(L,
and3or,             L)IN(L,
and4,               L)IN(L,
and5,               L)IN(L,
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
S(switch_ray) { R(Q_t, r); C(r); }
S(srun) {
  R(p_t *, oο);
  Q_t oρ = oο[7].Q;
  while(oρ) σ[α++].v = oο[--oρ + 8].v;
  α--;
  Α(oο, os_queue) O;
}
// S(timer_n) {
//   R(p_t *, oο);
//   Q_t oρ = 7;
//   oο[oρ++].Q = α;
//   while (α) oο[oρ++].v = σ[--α].v;
//   A(oο) C(1);
// }
S(run_timeouts_n) {
  R(Q_t, time);
  q_t pos = binary_search_rightmost(time) + 1;
  for(Q_t i = pos; i < timeouts_count; i++) timeouts[i - pos] = timeouts[i];
  for(Q_t i = pos; i < timeouts_count; i++)    piths[i - pos] = piths[i];
  timeouts_count -= pos;
  A(god) 0; for(Q_t i = 0; i < pos; i++) A3(piths[i], srun, and2) 0;
  O;
}
Sar(run_timeouts, os_hrtime, run_timeouts_n, and)
S(queue_timeout_run  );
S(check_queue_timeout) { A(0 < timeouts_count ? queue_timeout_run : god) O; }
S(queue_timeout_run  ) { A5(run_timeouts, check_queue_timeout, and, ο, os_queue) O; }
S(insert_timeout     ) { A3(insert_timeout_n, (1 == timeouts_count ? queue_timeout_run : god), and) O; }

SP(printtimeouts) {
  for (Q_t i = 0; i < timeouts_count; i++)
    print("%lu %p\n", timeouts[i], piths[i]);
  C(1);
}
SP(init) {
  timeouts_count = 0;

  Α(exports, debug_init) O;
}
N(drop) { α--, C(1); }
NP(got_p) { C(2); }
NP(god_p) { C(1); }
NP(gor_p) { C(0); }
// oor exec sentence,  stop timer & C(0)
// and exec sentence, renew timer & C(1)
// not                 stop timer & C(2)
S(addQQ) {
  R(Q_t, r);
  R(Q_t, l);
  Α(l + r) C(1);
}

Sar(reset_timer, god)
Sar(create_timer_pith, reset_timer, 0010, ο, 512, "timer", os_create_psn)
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
SarP(timer, (Q_t)(timeouts_count < MAX_TIMEOUTS), switch_ray, got, or,
     create_timer_pith, and, timer_n, and, insert_timer_pith, and)

S(hello) { print("hello\n"); C(1); }
S(prnQ) { R(Q_t, v); print("%lu\n", v); C(1); }

Nar(test9,
    hello, 1000, timer,
    hello, 2000, timer, and3,
    hello, 3000, timer, and3,
    hello, 4000, timer, and3,
    hello, 5000, timer, and3,
    hello, 6000, timer, and3,
    hello, 7000, timer, and3,
    printtimeouts, and)

S(subQQ) {
  R(Q_t, r);
  R(Q_t, l);
  Α(l - r) C(1);
}
S(ltQQ) {
  R(Q_t, r);
  R(Q_t, l);
  C(l < r);
}
S(rotate3) {
  R(void *, c);
  R(void *, b);
  R(void *, a);
  Α(b, c, a) C(1);
}
S(dup) {
  R(void *, a);
  Α(a, a) C(1);
}
S(setTimeout_n) {
  R(Q_t, time);
  R(p_t *, oο);
  Α(os_hrtime, time, ltQQ, and2, oο, time, setTimeout_n, dot, and3or, oο,
    os_queue)
  O;
}
Nar(setTimeout, os_hrtime, addQQ, and, setTimeout_n, and)

Sar(s10, debug_οdump, os_hrtime, and, dup, and, rotate3, and, subQQ, and,
    prnQ, and, s10, and, ο, 3000, setTimeout)
    Nar(მთავარი, os_hrtime, s10, and)

// clang-format off
EN(tail,
binary_search_rightmost,  L)EN(L,
drop,                     L)EN(L,
insert_timeout,           L)EN(L,
printtimeouts,            L)EN(L,
მთავარი,                  L)EN(L,
test9,              exports)
