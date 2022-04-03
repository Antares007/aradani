#include "../oars.h"
#include "pith_coords.h"
#include "queue.h"
#include <stdlib.h>
void*os_soll_alloc();
// clang-format off
N(os_new_pith) {
  R(Q_t,              nρ);
  (void)nρ;
  p_t *sο           = os_soll_alloc();
  if (sο == 0) return C(2);
  R(n_t,              ray_not);
  R(n_t,              ray_and);
  R(n_t,              ray_oor);
  sο[2].c           = ray_not;
  sο[1].c           = ray_and;
  sο[0].c           = ray_oor;
  R(Q_t,              wc);
  while (wc) {
    R(void*,          v);
    sο[--wc + 7].v  = v;
  }
  R(p_t *,            oο);
  sο[Φ].p           = oο;
  A(sο) C(1);
}
N(os_new_ps) {  
  R(Q_t,  nρ);
  R(p_t*, oο);
  R(n_t,  ray_oor);
  R(n_t,  ray_and);
  R(n_t,  ray_not);
  Α(oο, 0, ray_oor, ray_and, ray_not, nρ, os_new_pith) O;
}
N(os_new   ) {
  Α(ο[Φ].p, 512, os_new_ps) O;
}
