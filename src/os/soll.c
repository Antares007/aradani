#include "../gotgod.h"
#include "../oars.h"
#include <stdlib.h>
N(nar); p_t *page_alloc();
void page_free(p_t *);
N(os_soll) {
  p_t *sοll = σ;
  sοll[-1].Q = α;
  σ = page_alloc();
  α = 0;
  Α(sοll) C(1);
}
N(os_soll_n) {
  R(Q_t, sa);
  if (sa == α) return os_soll(T());
  if (α  < sa) return C(2);

  p_t *sοll = page_alloc();
  if (sοll == 0) return C(2);
  if (sοll[-2].Q < sa) return page_free(sοll), C(2);

  α -= sοll[-1].Q = sa;
  for (Q_t i = 0; i < sa; i++)
    sοll[i].v = σ[α + i].v;
  Α(sοll) C(1);
}
N(os_unsoll) {
  R(p_t *, sοll);
  if (σ[-2].Q < (α + sοll[-1].Q)) return C(2);
  for (Q_t i = 0; i < sοll[-1].Q; i++) σ[α + i].v = sοll[i].v;
  α += sοll[-1].Q, C(1);
}
N(os_soll_dup) {
  R(p_t *, sοll);
  p_t *dsοll = page_alloc();
  if (dsοll[-2].Q < sοll[-1].Q) return C(2);
  dsοll[-1].Q = sοll[-1].Q;
  for (Q_t i = 0; i < sοll[-1].Q; i++) dsοll[i].v = sοll[i].v;
  Α(sοll, dsοll) C(1);
}
N(os_soll_free) {
  R(p_t *, sοll);
  page_free(sοll), C(1);
}
NP(os_unsoll_free) {
  R(p_t *, sοll);
  Α(sοll, os_unsoll,
    sοll, os_soll_free, 020, nar) O;
}
N(os_unsoll_apply) {
  R(p_t *, sοll);
  Α(sοll, os_unsoll, dot, 010, nar) O;
}
N(os_unsoll_free_apply) {
  R(p_t *, sοll);
  Α(sοll, os_unsoll_free, dot, 010, nar) O;
}
