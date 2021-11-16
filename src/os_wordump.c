#include "aradani.h"
#include <stdio.h>
N(os_wordump) {
  printf("ο:%p α:%02ld               ρ: %02ld σ: %p\n", ο, α, ρ, σ);
  long i = 0;
  while (i < α) {
    printf("%016lx ", ο[i].Q);
    if (++i < α)
      printf("%016lx\n", ο[i].Q);
    else
      printf("\n");
    i++;
  }
  C(1);
}
N(aaa_aaa_aaa) { A4(printf, 2, 3, 4) O; }
N(print_cstring) {
  R(const char *, str);
  puts(str);
  C(1);
}
// print_string daa ab sizeof(void*) 5 2 for_each
N(for_each) {
  R(Q_t, wc);
  R(Q_t, n);
  R(Q_t, s);
  R(char *, b);
  p_t o[7];
  α -= wc;
  for (Q_t a = 0; a < wc; a++)
    o[a].v = ο[α + a].v;
  for (Q_t a = 0; a < n; a += s) {
    ο[α++].v = &b[a];
    for (Q_t a = 0; a < wc; a++)
      ο[α++].v = o[a].v;
  }
}
