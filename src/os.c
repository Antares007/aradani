#include "aradani.h"
#include "mmap.h"
#include "os_expimp.h"
#include "queue.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define ISPAGE(lx) ((Q_t)lx & (Q_t)0xFFF) == 3 * sizeof(void *)

static void init_rigi();
static int shemdegi_rigis_nomeri();
typedef struct {
  QUEUE q;
  p_t *ο;
  p_t *σ;
} rigis_elementi_t;
rigis_elementi_t rigis_elementebi[1024];

N(os_აფურცელი) {
  p_t *lx = σ[1].v;
  p_t *nο = (void *)(((Q_t)lx | ((Q_t)0xFFF)) + 1);
  nο += 3;
  if (σ < nο)
    return C(, 2);
  nο[-3].v = lx, nο[-2].v = σ, nο[-1].Q = 0;
  lx[ISPAGE(lx) ? -2 : 2].v = nο, σ[1].v = nο;
  A(nο) C(, 1);
}
N(os_აგულგული) {
  R(Q_t, pc);
  R(Q_t, wc);
  p_t *lx = σ[1].v;
  p_t *nσ = &lx[(ISPAGE(lx) ? 504 : 512) + pc * 512];
  if (σ <= nσ)
    return A2(wc, pc) C(, 2);

  long nρ = -wc;
  nσ[--nρ].c = ο[--α].c;
  nσ[--nρ].c = ο[--α].c;
  nσ[--nρ].c = ο[--α].c;

  QUEUE_INIT((QUEUE *)&nσ[3]);
  nσ[0].q = nρ, nσ[1].v = lx, nσ[2].v = σ;
  lx[ISPAGE(lx) ? -2 : 2].v = nσ, σ[1].v = nσ;
  A(nσ) C(, 1);
}
N(os_ამოწერე) {
  R(Q_t, wc);
  R(p_t *, pο);
  long pα = (pο[-1].q = pο[-1].q + wc);
  for (long i = 1; i <= wc; i++)
    pο[pα - i].v = ο[--α].v;
  A(pο) C(, 1);
}
N(os_რიგშიჩააყენე) {
  R(p_t *, nσ);
  R(p_t *, nο);
  int nomeri = shemdegi_rigis_nomeri();
  if (nomeri == 0)
    return A2(nο, nσ) C(, 2);
  rigis_elementebi[nomeri].ο = nο, rigis_elementebi[nomeri].σ = nσ;
  QUEUE_INSERT_TAIL((QUEUE *)&σ[3], &rigis_elementebi[nomeri].q);
  C(, 1);
}
p_t *stack[1024];
long sp = 0;
static void next_(p_t *σ) {
  QUEUE *q;
  if ((QUEUE *)&σ[3] != (q = QUEUE_NEXT((QUEUE *)&σ[3]))) {
    QUEUE_REMOVE(q);
    rigis_elementi_t *e = (void *)q;
    e->q[0] = 0;
    p_t *eο = e->ο, *eσ = e->σ;
    long eα = eο[-1].q, eρ = eσ[0].q;
    if (σ != eσ)
      stack[sp++] = σ;
    assert(sp <= sizeof(stack) / sizeof(void *));
    eο[eα - 1].c(eο, eα - 1, eρ, eσ);
  } else if (sp > 0) {
    next_(stack[--sp]);
  } else
    printf("end\n");
}
N(os_შემდეგი) {
  printf("os\n");
  ο[-1].Q = α;
  if (α == 0 && ο[-3].v != 0) {
    p_t *l = ο[-3].v, *r = ο[-2].v;
    l[ISPAGE(l) ? -2 : 2].v = r;
    r[ISPAGE(r) ? -3 : 1].v = l;
  }
  next_(σ);
}
static N(os_წერტილი_next) {
  R(Q_t, wc);
  R(void *, pith);
  if (wc == α)
    ο[-1].Q = α, A3(ο, pith, os_რიგშიჩააყენე) O;
  else
    A7(os_აფურცელი, wc, os_ამოწერე, დაა, pith, os_რიგშიჩააყენე, დაა) O;
}
N(os_წერტილი) {
  // A4("os_წერტილი", loog, os_წერტილი_next, და) O;
  os_წერტილი_next(T());
}
static N(os_არა) {
  printf("os_არა\n");
  os_შემდეგი(T());
}
static N(os_და) {
  printf("os_და\n");
  os_შემდეგი(T());
}
static N(os_ან) {
  printf("os_ან\n");
  os_შემდეგი(T());
}
static N(test);
static N(test2) {
  printf("test2\n");
  A(test) A3(σ, 1, os_წერტილი) O;
}
static N(test) {
  printf("test\n");
  A(test2) A3(σ, 1, os_წერტილი) O;
}

int main() {
  init_rigi();
  // |.b..........|............|.e..........|............
  void *b = malloc(100 << 12);
  void *e = b + (100 << 12);
  p_t *ο = (void *)((Q_t)b | ((Q_t)0xFFF)) + 1,
      *σ = (void *)((Q_t)e & ~((Q_t)0xFFF));

  ο += 3, σ -= 5;
  long α = 0, ρ = 0;

  ο[-3].Q = 0, ο[-2].v = σ, ο[-1].Q = 0;

  σ[--ρ].c = os_არა;
  σ[--ρ].c = os_და;
  σ[--ρ].c = os_ან;

  QUEUE_INIT((QUEUE *)&σ[3]);
  σ[0].q = ρ, σ[1].v = ο, σ[2].v = 0;

  // if (argc < 2) {
  // printf("%s filenameToRun\n", argv[0]);
  // return -1;
  //}
  unsigned long size;
  n_t arsi = mapfile("src/arsi2.arsi", &size);
  *(void **)((char *)arsi + size - 10) = ღრმაარსი;
  A2(arsi, არსი) O;
  // test(T());
  free(b);
}
static void init_rigi() {
  for (int i = 0; i < sizeof(rigis_elementebi) / sizeof(*rigis_elementebi); i++)
    rigis_elementebi[i].q[0] = 0;
}
static int shemdegi_rigis_nomeri() {
  static int last = 0;
  int i = last + 1;
  for (; i < sizeof(rigis_elementebi) / sizeof(*rigis_elementebi); i++)
    if (rigis_elementebi[i].q[0] == 0)
      return last = i, i;
  for (i = 1; i < last; i++)
    if (rigis_elementebi[i].q[0] == 0)
      return last = i, i;
  return 0;
}
