#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
os_queue,           L)IN(L,
os_queue_n,   imports)

SarP(init)(god)


S(reject ) { R(p_t*, rο); R(p_t*, lο); Α(lο, got, rο, 2, os_queue_n) O; }
S(forward) { R(p_t*, oο);              Α(    god, oο,    os_queue  ) O; }
S(greet  ) { R(p_t*, rο); R(p_t*, lο); Α(rο, gor, lο, 2, os_queue_n) O; }
S(greet_b) { R(p_t*, rο); R(p_t*, lο); Α(lο, gor, rο, 2, os_queue_n) O; }

EN(tail,
forward,            L)EN(L,
greet,              L)EN(L,
greet_b,            L)EN(L,
reject,             L)EN(L,
god,          exports)
