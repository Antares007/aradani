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
co0,                L)END(L,
co1,                L)END(L,
co2,                L)END(L,
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
os_call_n,          L)END(L,
os_hrtime,          L)END(L,
os_ls,              L)END(L,
os_new,             L)END(L,
os_new_pith,        L)END(L,
os_new_ps,          L)END(L,
os_next,            L)END(L,
os_queue,           L)END(L,
os_queue_clear,     L)END(L,
os_queue_n,         L)END(L,
os_queue_soll,      L)END(L,
os_seed,            L)END(L,
os_soll,            L)END(L,
os_soll_dup,        L)END(L,
os_soll_free,       L)END(L,
os_soll_n,          L)END(L,
os_unsoll,          L)END(L,
os_unsoll_apply,    L)END(L,
os_unsoll_free,     L)END(L,
os_unsoll_free_apply,L)END(L,
os_wordump,      root);

void os_hrtime_init();
void os_queue_init();
void os_soll_init();
p_t *os_soll_alloc();

int main(int argc, char **argv) {
  if (argc < 2)
    return printf("Would you mind adding the 'file_name' as an argument?\n"), 6;
  (void)root;
  os_hrtime_init();
  os_soll_init();
  os_queue_init();
  p_t *ο = os_soll_alloc(), *σ = os_soll_alloc();
  ο[Φ].v = ο;
  Q_t  α = 0, ρ = σ[Σ].Q;
  Α(argv[1], root, ο, os_bark) O;
  return 0;
}
