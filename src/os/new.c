#include "../oars.h"
#include "pith_coords.h"
#include "queue.h"
#include <stdlib.h>
void*page_alloc();
void page_free(void*);
// clang-format off
N(os_new_pith) {
  R(Q_t,              nρ);
  (void)nρ;
  p_t *nο           = page_alloc();
  if (nο == 0) return C(2);
  nο               += 5;
  nο[Ǎ].Q           = 3; 
  nο[Σ].Q           = nρ; 
  nο[Ψ+0].p         = &nο[Ψ];
  nο[Ψ+1].p         = &nο[Ψ];
  R(n_t,              ray_not);
  R(n_t,              ray_and);
  R(n_t,              ray_oor);
  nο[2].c           = ray_not;
  nο[1].c           = ray_and;
  nο[0].c           = ray_oor;
  R(Q_t,              wc);
  while(wc) {
    R(void*,          v);
    nο[--wc + 7].v  = v;
  }
  R(p_t *,            oο);
  nο[Φ].p           = oο;
  A(nο) C(1);
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
