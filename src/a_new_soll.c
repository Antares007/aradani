#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
dot,                L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
os_new_ps,          L)IN(L,
os_soll_free,       L)IN(L,
os_unsoll,          L)IN(L,

and,                L)IN(L,
and2,               L)IN(L,
and4,               L)IN(L,
and5,               L)IN(L,
not,          imports)
SarP(init)(god)
Sargo(free_sols_and_got)(
  ο[ 7].p, os_soll_free,
  ο[ 8].p, os_soll_free, and2,
  ο[ 9].p, os_soll_free, and2,
  ο[10].p, os_soll_free, and2,
                    got, and)
Sargo(new_soll_not)(ο[ 8].p, os_unsoll, dot, and, free_sols_and_got, not)
Sargo(new_soll_and)(ο[ 9].p, os_unsoll, dot, and)
Sargo(new_soll_oor)(ο[10].p, os_unsoll, dot, and)
S5(new_soll_set)(oο,        p_t*,
                 set_soll,  p_t*,
                 not_soll,  p_t*,
                 and_soll,  p_t*,
                 oor_soll,  p_t*)(
  oο[ 7].p = set_soll;
  oο[ 8].p = not_soll;
  oο[ 9].p = and_soll;
  oο[10].p = oor_soll;
  A(oο) C(1);)
Sarg6(new_soll_ps)(not_soll, p_t*,
                    and_soll, p_t*,
                    oor_soll, p_t*,
                    set_soll, p_t*,
                    oο,       p_t*,
                    size,     Q_t)(
  new_soll_not, new_soll_and, new_soll_oor, oο, size, os_new_ps,
  set_soll, not_soll, and_soll, oor_soll, new_soll_set, and5)
Sargo(new_soll_ps_a)(new_soll_ps, and4)

EN(tail,
new_soll_ps,       L)EN(L,
new_soll_ps_a,     exports)
