#include "arsi.h"
#include "import_export.h"
#include <stdarg.h>
#include <stdio.h>

N(os_run_arsi);
N(os_wordump);
N(os_new);
N(os_queue);
N(os_next);
N(ada);
N(exports_next);


void os_hrtime_init();
void init_os_next();
void *mapfile(const char *filename, void *pith);
static int cmp(const char *s1, const char *s2) {
  while (*s1 == *s2++)
    if (*s1++ == 0)
      return (0);
  return (*(unsigned char *)s1 - *(unsigned char *)--s2);
}
// clang-format off
static void run();
IN(run, ο,                 imports);

void enderr(αos_t *o) { o->o(o); }
// #define EB(Head, Imports, Exports, Tail)
E(enderr,
"", 0,                                  L) E(L,
"printf", printf,                       L)EN(L,
os_next,                                L)EN(L,
os_queue,                               L)EN(L,
os_wordump, exports);
// clang-format on

void root(αos_t *o) { exports(o); }
static void run() { printf("aaa\n"); }
void e_or(αos_t *o) { printf("error mn:%s\n", o->mn); }
void mod_empty2(αos_t *o);
int main(int argc, char **argv) {
  if (argc < 2)
    return printf("Would you mind adding the 'file_name' as an argument?\n"), 8;
  ε_t e = mapfile(argv[1], root);
  //ε_t e = mod_empty2;
  e(&(αos_t){.a = imports, .o = e_or, .mn = __FILE__});
  return 0;
}
// return os(7, argv[1], ray_oor, os_next, ray_not, os_new, ray_and, and), 0;
//S(ray_not) {}
//S(ray_oor) {}
//static void os(Q_t s, ...) {
//  va_list args;
//  va_start(args, s);
//  p_t σ[512], ο[512];
//  Q_t α = 0, ρ = 512;
//
//  ο[--ρ].c = ray_not;
//  ο[--ρ].c = os_next;
//  ο[--ρ].c = ray_oor;
//
//  ο[0].v = ο, ο[1].Q = ρ;
//
//  init_os_next();
//  os_hrtime_init();
//  while (s)
//    A(va_arg(args, void *)) s--;
//  va_end(args);
//  O;
//}
