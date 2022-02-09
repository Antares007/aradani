#include "arsi.h"
#include "gotgod.h"
#include "os/queue.h"
#include <stdarg.h>
#include <stdio.h>

void os_hrtime_init();
void init_os_next();
void *mapfile(const char *filename, void *pith);

N(os_queue);
N(os_next);
N(os_new);
N(ada);

// clang-format off
void enderr(αos_t *o) { o->o(o); }
E(enderr,
"", 0,              L)E(L,
"", 0,              L)E(L,
"printf", printf,   L)EN(L,
ada,                L)EN(L,
os_new,             L)EN(L,
os_next,            L)EN(L,
os_queue,        root);
// clang-format on

S(and) { A(010) ada(T()); }
SP(ray_not) {}
SP(ray_oor) {}
SP(next) { O; }
N(os_bark);

void init_queue();
int main(int argc, char **argv) {
  if (argc < 2)
    return printf("Would you mind adding the 'file_name' as an argument?\n"), 6;
  init_queue();
  p_t σ[512], ο[512];
  Q_t α = 0, ρ = sizeof(ο) / sizeof(*ο);

  ο[--ρ].c = ray_not;
  ο[--ρ].c = os_next;
  ο[--ρ].c = ray_oor;

  ο[0].v = ο, ο[1].Q = ρ, QUEUE_INIT((QUEUE *)&ο[2]), ο[4].v = "m";

  A5(argv[1], root, os_bark, next, and) O;
  return 0;
}
