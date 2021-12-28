#include "exportmacros.h"
#include "oars.h"
#include <stdio.h>

void bark(const char *name, void *tail, n_t nargo, p_t *σ);

// clang-format off
static void m_gor(void *s, void(a)(), void(o)()) { o(s); }
E(m_gor,
bark, bark,               L)FEN(L,
l_accept,                 L)FEN(L,
l_address,                L)FEN(L,
l_bind,                   L)FEN(L,
l_epoll_create,           L)FEN(L,
l_epoll_ctl,              L)FEN(L,
l_epoll_wait,             L)FEN(L,
l_listen,                 L)FEN(L,
l_read,                   L)FEN(L,
l_setnoblock,             L)FEN(L,
l_socket,                 L)FEN(L,
la_stdin,                 L)FEN(L,
ls_export,                L)FEN(L,
os_delete,                L)FEN(L,
os_new,                   L)FEN(L,
os_wordump,               L)E(L,
printf, printf,  os_exports);
// clang-format on


N(Main) { printf("Main\n"), O; }
N(print_error) { printf("error\n"); }

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Would you mind adding the 'filename' as an argument?\n");
    return 8;
  }
  const char *filename = argv[1];
  p_t ο[4], *σ = ο + sizeof(ο) / sizeof(*ο) - 3;
  q_t α = 0, ρ = 0;
  ο[α++].v = print_error;
  σ[0].v = ο, σ[1].Q = α, σ[2].q = ρ;
  bark(filename, os_exports, Main, σ);
}
