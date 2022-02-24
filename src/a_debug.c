#include "arsi.h"
#include "gotgod.h"
// clang-format off
IBS(                L)IN(L,
nar_oor,            L)IN(L,
//
and,                L)IN(L,
notand,       imports);
// clang-format on
static void *names[2048][2];
static Q_t count;
static const char *find_name(void *a) {
  for (Q_t i = 0; i < count; i++)
    if (names[i][1] == a)
      return names[i][0];
  return 0;
}
SP(init) { C(1); }
S(debug_init_end) {
  R(Q_t, c);
  count = c, C(1);
}
S(debug_init_n) {
  R(n_t, e);
  R(void *, addr);
  R(const char *, name);
  R(Q_t, c);
  names[c][0] = (void *)name, names[c][1] = addr;
  Α(c + 1, e, debug_init_end, debug_init_n, notand) O;
}
S(debug_init) {
  R(n_t, e);
  Α(0, e, debug_init_n, and) O;
}
S(debug_σdump) {
  print("<debug_σdump>");
  for (Q_t i = 0; i < α; i++) {
    const char *n = find_name(σ[i].v);
    if (n)
      print("%s ", n);
    else
      print("%016lx ", σ[i].q);
  }
  print("</debug_σdump>\n");
  O;
}
S(debug_οdump) {
  print("<debug_οdump>");
  for (Q_t i = ρ; i < ο[Σ].Q; i++) {
    if (ο[i].v == nar_oor) {
      print("%01lx%01lx%01lxΨ ", ο[i+3+2].Q, ο[i+3+1].Q, ο[i+3+0].Q);
      i += 5;
    } else {
      const char *n = find_name(ο[i].v);
      if (n)
        print("%s ", n);
      else
        print("%016lx ", ο[i].q);
    }
  }
  print("</debug_οdump>\n");
  C(1);
}
SP(Main) { Α(exports, debug_init) O; }
// clang-format off
EN(tail,
debug_init,         L)EN(L,
debug_οdump,        L)EN(L,
debug_σdump,        L)EN(L,
Main,         exports)
