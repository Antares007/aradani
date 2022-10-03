#include "arsi_ie.h"
#include "oant.h"
#include "oant_logn.h"
#include <stdio.h>

void Got(OANT);
void God(OANT);
void Gor(OANT);
void map_pith(OANT);
extern n_t ψ[01000];
extern n_t δ[32];
extern void *ρ[];
extern void *σ[];
// clang-format off
                      E(Got,
"God", God,         L)E(L,
"Gor", Gor,         L)E(L,
"Got", Got,         L)E(L,
"δ", &δ,            L)E(L,
"ρ", &ρ,            L)E(L,
"σ", &σ,            L)E(L,
"ψ", &ψ,            ε);
// clang-format on

N(root) { A1(ε) C(1); }

N(ls_exports) {
  RN(const char *, fname);
  RN(n_t, exp);
  RN(n_t, nar);
  (void)nar;
  RN(const char *, name);
  printf("%s:%s\n", fname, name);
  A3(exp, ls_exports, ψ[010]) O;
}
N(run_epoll) {
  τ -= 1;
  RN(n_t, export);
  RN(n_t, nar);
  RN(const char *, name);
  if (name[0] == '_')
    printf(">>> %s %lu\n", name, τ), A3(export, run_epoll, ψ[010]) O;
  else
    nar(T);
}
N(run_bark) { A5(map_pith, ψ[0], ψ[010], run_epoll, ψ[010]) O; }
#include "raylib.h"

void queue_init();
void next(OANT);
// clang-format off
N(ray_not) {}
N(ray_and) { if (τ) printf("%lu\n", ν[τ - 1].q); else printf("\n"); α -= 3, next(T); }
N(ray_oor) {}
int main(int argc, char **argv) {
  if (argc < 2)
    return printf("Would you mind adding the 'file_name' as an argument?\n"), 6;
  queue_init();
  p_t ο[0x1000];
  Q_t α = sizeof(ο) / sizeof(*ο);
  p_t ν[0x1000];
  Q_t τ = 0;
  ο[--α].v = ray_not;
  ο[--α].v = ray_and;
  ο[--α].v = ray_oor;
  A3(argv[1], root, run_bark) O;
  return 0;
}
