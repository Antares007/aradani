#include "../oars.h"
#include <stdio.h>
#include <stdlib.h>
void nar(OARS);
static Q_t is_debugging = 0;
static char pchr = 0xa;
N(debugger){ is_debugging = 1, C(1); }
const char *os_debug_find_name(void *a);
#define SCLOOP                                                                 \
  if (is_debugging) {                                                          \
    char chr;                                                                  \
    Q_t line_size = 1024;                                                      \
    q_t chars_count = 0;                                                       \
    char *buffer = malloc(line_size);                                          \
    while ((chars_count = (printf("\n%p %3lu/%3lu a/o/s/c>", ο, α, ρ),         \
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
        for (Q_t i = ρ; i < σ[-2].Q; i++) {                                    \
          if (σ[i].v == nar_oor) {                                             \
            printf("\n%04loΨ ", σ[i + 3].Q);                                   \
            i += 3;                                                            \
          } else {                                                             \
            const char *n = os_debug_find_name(σ[i].v);                        \
            if (n)                                                             \
              printf("%s ", n);                                                \
            else                                                               \
              printf("%016lx ", σ[i].q);                                       \
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
        const char *n = os_debug_find_name(σ[ρ].v);                            \
        if (n)                                                                 \
          printf("%s ", n);                                                    \
        else                                                                   \
          printf("%p ", σ[ρ].v);                                               \
      }                                                                        \
      WC--, σ[α++].v = σ[ρ++].v;                                               \
    }                                                                          \
    SCLOOP                                                                     \
  }
#define SCLOOP2 is_debugging = 0;

#define DESTRUCTJ                                                              \
  nc = ((j & 0700) >> 6), ac = ((j & 0070) >> 3), oc = ((j & 0007) >> 0)
#define DESTRUCT                                                               \
  ρ += 3;                                                                      \
  Q_t j = σ[ρ++].Q, DESTRUCTJ
void nar_oor(OARS);
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
    tc--, σ[--ρ].v = σ[--α].v;
  σ[--ρ].Q = j;
  σ[--ρ].c = nar_not, σ[--ρ].c = nar_and, σ[--ρ].c = nar_oor;
  O;
}
#undef DESTRUCT
#undef DESTRUCTJ
