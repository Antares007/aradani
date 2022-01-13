#include "exportmacros.h"
#include "oars.h"
#include <stdio.h>

void bark(const char *name, void *tail, void(ok)(), void(err)());

N(bark_n) {
  R(m_t, export);
  R(n_t, name);
  export(0, 0, 0);
  name(T());
}

p_t ο[512];

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
os_wordump,               L) E (L,
printf, printf,           L) EO(L);
// clang-format on

void ok(p_t *σ) {
  p_t *ο = σ[0].v;
  Q_t α = σ[1].Q;
  q_t ρ = σ[2].q;
  O;
}
void err() { printf("error\n"); }

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Would you mind adding the 'filename' as an argument?\n");
    return 8;
  }
  const char *filename = argv[1];
  //ο[0].v = ο;
  //Q_t α = ο[1].Q = 0;
  //Q_t ρ = ο[2].Q = ο[3].Q = sizeof(ο) / sizeof(*ο);

  bark(filename, export, ok, err);
}
