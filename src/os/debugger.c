#include "../oars.h"
#include <stdio.h>
static void *names[0x1000][2];
static Q_t count;
const char *os_debug_find_name(void *a) {
  for (Q_t i = 0; i < count; i++)
    if (names[i][1] == a)
      return names[i][0];
  return 0;
}
void nar(OARS);
static N(and   ) { Α(010, nar) O; };
static N(notand) { Α(0110, nar) O; };
static N(os_debug_init_end) {
  R(Q_t, c);
  count = c;
  C(1);
}
static N(os_debug_init_n) {
  R(n_t, e);
  R(void *, addr);
  R(const char *, name);
  R(Q_t, c);
  if (c == 0x1000)
    c = 0;
  names[c][0] = (void *)name, names[c][1] = addr;
  Α(c + 1, e, os_debug_init_end, os_debug_init_n, notand) O;
}
N(os_debug_init) {
  R(n_t, e);
  Α(count, e, os_debug_init_n, and) O;
}
