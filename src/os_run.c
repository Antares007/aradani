#include "arsi_ie.h"
#include "gotgod.h"
#include "oars.h"
#include "os/pith_coords.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
// clang-format off
E(got, "0", 0,      L)E(L,
"0", 0,             L)E(L,
"printf", printf,   L)END(L,
debugger,           L)END(L,
dot,                L)END(L,
god,                L)END(L,
gor,                L)END(L,
got,                L)END(L,
l_accept,           L)END(L,
l_address,          L)END(L,
l_bind,             L)END(L,
l_close,            L)END(L,
l_epoll_create,     L)END(L,
l_epoll_ctl,        L)END(L,
l_epoll_wait,       L)END(L,
l_free,             L)END(L,
l_listen,           L)END(L,
l_malloc,           L)END(L,
l_read,             L)END(L,
l_setnoblock,       L)END(L,
l_socket,           L)END(L,
l_write,            L)END(L,
nar,                L)END(L,
nar_and,            L)END(L,
nar_not,            L)END(L,
nar_oor,            L)END(L,
os_bark,            L)END(L,
os_hrtime,          L)END(L,
os_ls,              L)END(L,
os_new,             L)END(L,
os_new_n,           L)END(L,
os_new_psn,         L)END(L,
os_next,            L)END(L,
os_queue,           L)END(L,
os_queue_and,       L)END(L,
os_queue_n,         L)END(L,
os_roll_n,          L)END(L,
os_seed,            L)END(L,
os_soll_a,          L)END(L,
os_soll_free,       L)END(L,
os_soll_n,          L)END(L,
os_unroll,          L)END(L,
os_unsoll,          L)END(L,
os_unsoll_apply,    L)END(L,
os_unsoll_free,     L)END(L,
os_unsoll_free_apply,L)END(L,
os_win,             L)END(L,
os_wordump,      root);

SP(ray_not) {
  if(α == 3) {
    R(n_t,e); R(void*,a); R(const char*,n); printf("%s %p %p\n", n, a, e);
  } long i = 0; while (i < α) { printf("%016lx ", σ[i].Q); if (++i < α) printf("%016lx\n", σ[i].Q); else printf("\n"); i++; }
}
SP(ray_oor) { R(p_t*, oο); Α(ο, gor, oο, 2, os_queue_n) O; }
NP(ray_and) { os_next(T()); }
void os_hrtime_init(); void page_init(); void *page_alloc();
int main(int argc, char **argv) {
  if (argc < 2)
    return printf("Would you mind adding the 'file_name' as an argument?\n"), 6;
  os_hrtime_init(); page_init();
  p_t *σ = page_alloc();
  Q_t α = 0;
  p_t ο[512];
  Q_t ρ = ο[Σ].Q = sizeof(ο) / sizeof(*ο);
  ο[--ρ].c = ray_not;
  ο[--ρ].c = os_next;
  ο[--ρ].c = ray_oor;
  ο[Φ].p = ο, ο[Ρ].Q = ρ, ο[Ψ + 0].p = &ο[Ψ], ο[Ψ + 1].p = &ο[Ψ], ο[Ν].v = "ο";
  Α(argv[1], root, ο, os_bark) O;
  return 0;
}
