#include "../oars.h"
#include "pith_coords.h"
#include "queue.h"
#include <stdlib.h>
// clang-format off
No(os_new_pith)(
  R(Q_t,              nρ);
  p_t *nο           = malloc(nρ * sizeof(void *));
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
)
Narg5(os_new_ps)( 
  ray_not,   n_t,          
  ray_and,   n_t,          
  ray_oor,   n_t,          
  oο,        p_t *,        
  nρ,        Q_t)(
  oο, 0, ray_oor, ray_and, ray_not, nρ, os_new_pith
)
Nargo(os_new   )(
  ο[Φ].p, 512, os_new_ps
)
