#include "aradani.h"
#include <stdio.h>
N(os_wordump) {
  printf("ο:%p α:%02ld               ρ: %02ld σ: %p\n", (void *)((Q_t)ο >> 12),
         α, ρ, (void *)((Q_t)σ >> 12));
  long i = 0;
  while (i < α) {
    (ο[i].Q & (Q_t)0xfe8) == (Q_t)0xfe8
        ? printf("%p      ", (void *)(ο[i].Q >> 12))
        : printf("%016lx ", ο[i].Q);
    if (++i < α)
      (ο[i].Q & (Q_t)0xfe8) == (Q_t)0xfe8
          ? printf("%p\n", (void *)(ο[i].Q >> 12))
          : printf("%016lx\n", ο[i].Q);
    else
      printf("\n");
    i++;
  }
  C(1);
}
