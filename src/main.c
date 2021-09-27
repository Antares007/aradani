#include "aradani.h"
#include <stdio.h>
#include <stdlib.h>
#define ISPAGE(lx)                                                             \
  ((unsigned long)lx & (unsigned long)0xFFF) == 3 * sizeof(void *)
N(os_აფურცელი) {
  p_t *lx = σ[1].v;
  p_t *nο = (void *)(((unsigned long)lx | ((unsigned long)0xFFF)) + 1);
  nο += 3;
  if (σ < nο)
    return C(, 2);
  nο[-3].v = lx, nο[-2].v = σ, nο[-1].Q = 0;
  lx[-2].v = nο, σ[1].v = nο;
  A(nο) C(, 1);
}
N(os_აგულგული) {
  R(unsigned long, pc);
  R(unsigned long, wc);
  p_t *lx = σ[1].v;
  p_t *nσ = &lx[(ISPAGE(lx) ? 506 : 512) + pc * 512];
  if (σ <= nσ)
    return A2(wc, pc) C(, 2);
  long nρ = 0;
  while (wc--)
    nσ[--nρ].v = ο[--α].v;
  nσ[0].q = nρ, nσ[1].v = lx, nσ[2].v = σ;
  lx[-2].v = nσ, σ[1].v = nσ;
  A(nσ) C(, 1);
}
N(os_ამოწერე) {
  R(unsigned long, wc);
  R(p_t *, pο);
  long pα = (pο[-1].q = pο[-1].q + wc);
  for (long i = 1; i <= wc; i++)
    pο[pα - i].v = ο[--α].v;
  A(pο) C(, 1);
}
#include "queue.h"
typedef struct {
  QUEUE q;
  p_t *ο;
  p_t *σ;
} rigis_elementi_t;
#define MAX_RIGIS_ELEMENTI 1024
rigis_elementi_t rigis_elementebi[MAX_RIGIS_ELEMENTI];
QUEUE rigis_tavi;
static void init_rigi() {
  for (int i = 0; i < MAX_RIGIS_ELEMENTI; i++)
    rigis_elementebi[i].q[0] = 0;
  QUEUE_INIT(&rigis_tavi);
}
static int shemdegi_rigis_nomeri() {
  static int last = 0;
  int i;
  for (i = last + 1; i < MAX_RIGIS_ELEMENTI; i++)
    if (rigis_elementebi[i].q[0] == 0)
      return last = i, i;
  for (i = 1; i < last; i++)
    if (rigis_elementebi[i].q[0] == 0)
      return last = i, i;
  return 0;
}
N(os_წერტილი) {
  R(p_t *, nσ);
  R(p_t *, nο);
  int nomeri = shemdegi_rigis_nomeri();
  if (nomeri == 0)
    return A2(nο, nσ) C(, 2);
  rigis_elementebi[nomeri].ο = nο, rigis_elementebi[nomeri].σ = nσ;
  QUEUE_INSERT_TAIL(&rigis_tavi, &rigis_elementebi[nomeri].q);
  C(, 1);
}
N(os_შემდეგი) {
  ο[-1].Q = α;
  if (α == 0 && ο[-3].v != 0) {
    p_t *l = ο[-3].v, *r = ο[-2].v;
    l[ISPAGE(l) ? -2 : 2].v = r;
    r[ISPAGE(r) ? -3 : 1].v = l;
  }
  QUEUE *q;
  if (&rigis_tavi != (q = QUEUE_NEXT(&rigis_tavi))) {
    QUEUE_REMOVE(q);
    rigis_elementi_t *e = (void *)q;
    e->q[0] = 0;
    p_t *eο = e->ο, *eσ = e->σ;
    long eα = eο[-1].q, eρ = eσ[0].q;
    eο[eα - 1].c(eο, eα - 1, eρ, eσ);
  }
}
n_t opcode_map[] = {os_აფურცელი, os_აგულგული, os_ამოწერე, os_წერტილი,
                    os_შემდეგი};
N(os_ოპკოდით_გადამრთველი) {
  R(unsigned long, opcode);
  opcode_map[opcode](T());
}
N(main1);
N(os_არა) { printf("os_არა\n"), os_შემდეგი(T()); }
N(os_და) { printf("os_და\n"), os_შემდეგი(T()); }
N(os_ან) { printf("os_ან\n"), os_შემდეგი(T()); }
int main() {
  init_rigi();
  // |.b..........|............|.e..........|............
  void *b = malloc(100 << 12);
  void *e = b + (100 << 12);
  p_t *ο = (void *)((unsigned long)b | ((unsigned long)0xFFF)) + 1,
      *σ = (void *)((unsigned long)e & ~((unsigned long)0xFFF));
  printf("mem   %p %p\n", b, e);
  printf("grid  %p %p\n", ο, σ);
  printf("pages %ld\n", ((unsigned long)σ >> 12) - ((unsigned long)ο >> 12));
  ο += 3, σ -= 3;
  printf("tree  %p %p\n", ο, σ);

  long α = 0, ρ = 0;

  ο[-3].Q = 0, ο[-2].v = σ, ο[-1].Q = 0;

  σ[--ρ].c = os_ოპკოდით_გადამრთველი;
  σ[--ρ].c = os_არა;
  σ[--ρ].c = os_და;
  σ[--ρ].c = os_ან;
  σ[0].q = ρ, σ[1].v = ο, σ[2].v = 0;

  main1(ο, α, ρ, σ);

  free(b);
}
