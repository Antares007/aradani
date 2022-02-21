#include "arsi.h"
#include "gotgod.h"
// clang-format off
IBS(          imports);
// clang-format on
static void *names[2048][2];
static Q_t count;
static void add_name(αos_t *o, const char *n, void *a, void (*nexp)(αos_t *)) {
  void **na = names[count++];
  na[0] = (void *)n;
  na[1] = a;
  nexp(o);
}
static void add_name_done(αos_t *o, const char *mn, const char *in) { count--; }
static void init() {}
static const char *find_name(void *a) {
  for (Q_t i = 0; i < count; i++)
    if (names[i][1] == a)
      return names[i][0];
  return 0;
}
static void debug_init(ε_t e) {
  count = 0;
  e(&(αos_t){.a = add_name, .o = add_name_done});
}
S(debug_σdump) {
  print("debug_σdump:\n");
  for (Q_t i = 0; i < α; i++) {
    const char *n = find_name(σ[i].v);
    if (n)
      print("%s ", n);
    else
      print("%016lx ", σ[i].q);
  }
  print("\n");
  O;
}
S(debug_οdump) {
  print("debug_οdump:\n");
  for (Q_t i = ρ; i < 512; i++) {
    const char *n = find_name(ο[i].v);
    if (n)
      print("%s ", n);
    else
      print("%016lx ", ο[i].q);
  }
  print("\n");
  C(1);
}
// clang-format off
EN(tail,
debug_init,         L)EN(L,
debug_οdump,        L)EN(L,
debug_σdump,  exports)
