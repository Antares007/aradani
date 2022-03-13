#include "../oars.h"
#include <stdio.h>
#include <stdlib.h>

static Q_t is_debugging = 0;
static char pchr = 0xa;
N(debugger) { is_debugging = 1, C(1); }
const char *os_debug_find_name(void *a);
#define SCLOOP                                                                 \
  if (is_debugging) {                                                          \
    char chr;                                                                  \
    Q_t line_size = 1024;                                                      \
    q_t chars_count = 0;                                                       \
    char *buffer = malloc(line_size);                                          \
    while ((chars_count = (printf("\n%s %3lu/%3lu a/o/s/c>", ο[Ν].cs, α, ρ),   \
                           getline(&buffer, &line_size, stdin)))) {            \
      chr = buffer[0];                                                         \
      if (chr == 0xa)                                                          \
        chr = pchr;                                                            \
      else                                                                     \
        pchr = chr;                                                            \
      if (chr == 'a') {                                                        \
        for (Q_t i = 0; i < α; i++) {                                          \
          const char *n = os_debug_find_name(σ[i].v);                          \
          if (n)                                                               \
            printf("%s ", n);                                                  \
          else                                                                 \
            printf("%016lx ", σ[i].q);                                         \
        }                                                                      \
      } else if (chr == 'o') {                                                 \
        for (Q_t i = ρ; i < ο[Σ].Q; i++) {                                     \
          if (ο[i].v == nar_oor) {                                             \
            printf("%04loΨ ", ο[i + 3].Q);                                     \
            i += 3;                                                            \
          } else {                                                             \
            const char *n = os_debug_find_name(ο[i].v);                        \
            if (n)                                                             \
              printf("%s ", n);                                                \
            else                                                               \
              printf("%016lx ", ο[i].q);                                       \
          }                                                                    \
        }                                                                      \
      } else if (chr == 's') {                                                 \
        break;                                                                 \
      } else if (chr == 'c') {                                                 \
        is_debugging = 0;                                                      \
        break;                                                                 \
      }                                                                        \
    }                                                                          \
    free(buffer);                                                              \
  }
#define DEBUGGING(WC)                                                          \
  if (WC) {                                                                    \
    while (WC) {                                                               \
      if (is_debugging) {                                                      \
        const char *n = os_debug_find_name(ο[ρ].v);                            \
        if (n)                                                                 \
          printf("%s ", n);                                                    \
        else                                                                   \
          printf("%p ", ο[ρ].v);                                               \
      }                                                                        \
      WC--, σ[α++].v = ο[ρ++].v;                                               \
    }                                                                          \
    pchr = 0xa;                                                                \
    SCLOOP                                                                     \
  }
#define SCLOOP2 is_debugging = 0;

#define DESTRUCTJ                                                              \
  nc = ((j & 0700) >> 6), ac = ((j & 0070) >> 3), oc = ((j & 0007) >> 0)
#define DESTRUCT                                                               \
  ρ += 3;                                                                      \
  Q_t j = ο[ρ++].Q, DESTRUCTJ
N(nar_oor);
N(nar_not) {
  DESTRUCT, f = nc;
  DEBUGGING(nc);
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
  DEBUGGING(oc);
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
