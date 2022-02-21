#include "oars.h"
#include "arsi_ie.h"
#include "gotgod.h"
#include "os/queue.h"
#include <stdarg.h>
#include <stdio.h>
// clang-format off
E(got,
"0", 0,             L)E(L,
"0", 0,             L)E(L,
"printf", printf,   L)END(L,
l_accept,           L)END(L,
l_address,          L)END(L,
l_bind,             L)END(L,
l_epoll_create,     L)END(L,
l_epoll_ctl,        L)END(L,
l_epoll_wait,       L)END(L,
l_listen,           L)END(L,
l_read,             L)END(L,
l_setnoblock,       L)END(L,
l_socket,           L)END(L,
nar,                L)END(L,
nar_and,            L)END(L,
nar_not,            L)END(L,
nar_oor,            L)END(L,
os_bark,            L)END(L,
os_create,          L)END(L,
os_create_psn,      L)END(L,
os_hrtime,          L)END(L,
os_ls,              L)END(L,
os_new,             L)END(L,
os_new_psn,         L)END(L,
os_next,            L)END(L,
os_queue,           L)END(L,
os_wordump,      root);
SP(ray_not) {}
SP(ray_oor) {
  R(const char *, in);
  R(const char *, mn);
  printf("Can't satisfy imports:\n%s\n%s\n\n", mn, in), C(1);
}
void os_queue_init();
void os_hrtime_init();
int main(int argc, char **argv) {
  if (argc < 2)
    return printf("Would you mind adding the 'file_name' as an argument?\n"), 6;
  os_queue_init();
  os_hrtime_init();
  p_t σ[512], ο[512];
  Q_t α = 0, ρ = sizeof(ο) / sizeof(*ο);
  ο[--ρ].c = ray_not;
  ο[--ρ].c = os_next;
  ο[--ρ].c = ray_oor;
  ο[0].v = ο, ο[1].Q = ρ, QUEUE_INIT((QUEUE *)&ο[2]), ο[4].v = "š";
  Α(argv[1], root, ο, os_bark) O;
  return 0;
}
