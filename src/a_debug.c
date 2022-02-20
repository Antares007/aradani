#include "arsi.h"
#include "gotgod.h"
// clang-format off
IBS(                L)IN(L,
nar,                L)IN(L,
os_ls,              L)IN(L,
os_new,             L)IN(L,
os_queue,           L)IN(L,
os_wordump,         L)IN(L,
//
and,                L)IN(L,
not,                L)IN(L,
or,           imports);
// clang-format on
static void* names[2048][2];
static Q_t count;
void add_name(αos_t *o, const char *n, void *a,
                     void (*nexp)(αos_t *)) {
  void** na = names[count++];
  na[0] = (void*)n;
  na[1] = a;
  if(a) nexp(o);
}
void add_name_done(αos_t *o, const char *mn, const char *in) {
  count--;
}
void init() {
  count = 0;
  αos_t o = { .a = add_name, .o = add_name_done};
  volatile ε_t e = exports;                                                     \
  e(&o);
  print("count: %lu\n", count);
  for(Q_t i = 0; i < count; i++)
    print("%p %s\n", names[i][1],names[i][0]);
}

//S(M) { C(1); }
N(Main) { 
  Α(7, os_wordump) O; }
// clang-format off
EN(tail,
Main,         exports);
