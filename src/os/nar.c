#include "../oars.h"
#include <stdio.h>
static Q_t is_debugging = 0;
N(debugger) { is_debugging = 1, C(1); }
const char *os_debug_find_name(void *a);
#define DESTRUCTJ                                                              \
  nc = ((j & 0700) >> 6), ac = ((j & 0070) >> 3), oc = ((j & 0007) >> 0)
#define DESTRUCT                                                               \
  ρ += 3;                                                                      \
  Q_t j = ο[ρ++].Q, DESTRUCTJ
#define DEBUGGING(ac)                                                          \
  while (ac) {                                                                 \
    if (is_debugging) {                                                        \
      const char *n = os_debug_find_name(ο[ρ].v);                              \
      if (n)                                                                   \
        printf("%s ", n);                                                      \
      else                                                                     \
        printf("%p ", ο[ρ].v);                                                 \
    }                                                                          \
    ac--, σ[α++].v = ο[ρ++].v;                                                 \
  }                                                                            \
  if (is_debugging) printf("...\n"), getchar();
N(nar_not) {
  DESTRUCT, f = nc;
  while (nc)
    nc--, σ[α++].v = ο[ρ++].v;
  ρ += ac + oc;
  f ? O : C(2);
}
N(nar_and) {
  DESTRUCT, f = ac;
  ρ += nc;
  DEBUGGING(ac);
  ρ += oc;
  f ? O : C(1);
}
N(nar_oor) {
  DESTRUCT, f = oc;
  ρ += nc + ac;
  while (oc)
    oc--, σ[α++].v = ο[ρ++].v;
  f ? O : C(0);
}

N(nar) {
  Q_t j = σ[--α].Q, DESTRUCTJ, tc = nc + ac + oc;
  while (tc)
    tc--, ο[--ρ].v = σ[--α].v;
  ο[--ρ].Q = j;
  ο[--ρ].c = nar_not, ο[--ρ].c = nar_and, ο[--ρ].c = nar_oor;
  O;
}
#undef DESTRUCT
#undef DESTRUCTJ
