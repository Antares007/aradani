#include "queue.h"
#include "../gotgod.h"
#include "../oars.h"
#include "pith_coords.h"
#include <stdlib.h>
void nar(OARS);
void os_soll_n(OARS);
void os_soll(OARS);
p_t *soll_alloc();
No(os_queue_soll)(
  R(p_t *, oο);
  R(p_t *, sοll);
  QUEUE_INSERT_TAIL((QUEUE *)&ο[Ψ], (QUEUE *)&sοll[Ψ]);
  sοll[Φ].p = oο;
  C(1);
)
No(os_call_n_n)(
  R(p_t *, oο);
  R(p_t *, cσ);
  p_t *rσ = σ;
  σ = soll_alloc();
  if (σ == 0)
    return (σ = rσ, C(2));
  α = 0;
  ρ = σ[-2].Q;
  cσ[-3].p = rσ;
  Α(cσ, oο, os_queue_soll) O;
)
No(os_call_n)(
  R(Q_t, wc);
  R(p_t *, oο);
  Α(wc, os_soll_n, oο, os_call_n_n, 020, nar) O;
)
No(os_queue_n)(
  R(Q_t, wc);
  R(p_t *, oο);
  Α(wc, os_soll_n, oο, os_queue_soll, 020, nar) O;
)
No(os_queue)(
  R(p_t *, oο);
  Α(os_soll, oο, os_queue_soll, 020, nar) O;
)
