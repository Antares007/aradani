#include "oars.h"
#include <stdio.h>

N(os_wordump) {
  printf("σ:%p α:%02lu      ο:%p ρ:%02lu\n", σ, α, ο, ρ);
  long i = 0;
  while (i < α) {
    printf("%016lx ", σ[i].Q);
    if (++i < α) printf("%016lx\n", σ[i].Q);
    else printf("\n");
    i++;
  }
  C(1);
}
