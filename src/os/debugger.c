#include "../oars.h"
#include <stdio.h>
#define MAX_NAMES 0x1000
static void *names[MAX_NAMES][2];
static Q_t count;
const char *os_debug_find_name(void *a) {
  for (Q_t i = 0; i < count; i++)
    if (names[i][1] == a)
      return names[i][0];
  return 0;
}
void nar(OARS);
Sargo(and)(010, nar);
Sargo(notand)(0110, nar);

So(os_debug_init_end)(
  R(Q_t, c);
  count = c;
  //for (Q_t i = 0; i < count; i++)
  //  printf("%s\n", (char *)names[i][0]);
  C(1);
)
So(os_debug_init_n)(
  R(n_t, e);
  R(void *, addr);
  R(const char *, name);
  R(Q_t, c);
  if (c == MAX_NAMES)
    c = 0;
  names[c][0] = (void *)name, names[c][1] = addr;
  Α(c + 1, e, os_debug_init_end, os_debug_init_n, notand) O;
)
No(os_debug_init)(
  R(n_t, e);
  Α(count, e, os_debug_init_n, and) O;
)
