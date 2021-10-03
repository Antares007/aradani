#include "aradani.h"
#include "mmap.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

typedef unsigned long Q_t;
typedef unsigned int W_t;

#define ISPAGE(lx) ((Q_t)lx & (Q_t)0xFFF) == 3 * sizeof(void *)

static N(os_აფურცელი) {
  p_t *lx = σ[1].v;
  p_t *nο = (void *)(((Q_t)lx | ((Q_t)0xFFF)) + 1);
  nο += 3;
  if (σ < nο)
    return C(, 2);
  nο[-3].v = lx, nο[-2].v = σ, nο[-1].Q = 0;
  lx[ISPAGE(lx) ? -2 : 2].v = nο, σ[1].v = nο;
  A(nο) C(, 1);
}
static N(os_აგულგული) {
  R(Q_t, pc);
  R(Q_t, wc);
  p_t *lx = σ[1].v;
  p_t *nσ = &lx[(ISPAGE(lx) ? 506 : 512) + pc * 512];
  if (σ <= nσ)
    return A2(wc, pc) C(, 2);
  long nρ = 0;
  while (wc--)
    nσ[--nρ].v = ο[--α].v;
  nσ[0].q = nρ, nσ[1].v = lx, nσ[2].v = σ;
  lx[ISPAGE(lx) ? -2 : 2].v = nσ, σ[1].v = nσ;
  A(nσ) C(, 1);
}
static N(os_ამოწერე) {
  R(Q_t, wc);
  R(p_t *, pο);
  long pα = (pο[-1].q = pο[-1].q + wc);
  for (long i = 1; i <= wc; i++)
    pο[pα - i].v = ο[--α].v;
  A(pο) C(, 1);
}

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
static N(os_რიგშიჩააყენე) {
  R(p_t *, nσ);
  R(p_t *, nο);
  int nomeri = shemdegi_rigis_nomeri();
  if (nomeri == 0)
    return A2(nο, nσ) C(, 2);
  rigis_elementebi[nomeri].ο = nο, rigis_elementebi[nomeri].σ = nσ;
  QUEUE_INSERT_TAIL(&rigis_tavi, &rigis_elementebi[nomeri].q);
  C(, 1);
}
static N(os_შემდეგი) {
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
static N(os_წერტილი) {
  printf("os_წერტილი\n");
  R(Q_t, wc);
  R(void *, pith);
  A7(os_აფურცელი, wc, os_ამოწერე, დაა, pith, os_რიგშიჩააყენე, დაა) O;
}
////////////////////////////
typedef long int intptr_t;
int printf(const char *, ...);
// ο123456789α
// iosaaudfio
// ------o[0]------- ------o[1]-------
// 00010203.04050607 08090a0b0.c0d0e0f
// ------o[2]------- ------o[3]-------
// 00010203.04050607 08090a0b0.c0d0e0f
static N(wordump) {
  printf("ο:%p α:%02ld               ρ: %02ld σ: %p\n", (void *)((Q_t)ο >> 12),
         α, ρ, (void *)((Q_t)σ >> 12));
  long i = 0;
  while (i < α) {
    printf("%016lx ", ο[i].Q);
    if (++i < α)
      printf("%016lx\n", ο[i].Q);
    else
      printf("\n");
    i++;
  }
  C(, 1);
}
static N(os_ჩიხი) {}
static N(os_არა) {
  printf("os_არა\n");
  A3(wordump, os_ჩიხი, და) O;
}
static N(os_და) {
  printf("os_და\n");
  A3(wordump, os_შემდეგი, და) O;
}
static N(os_ან) {
  printf("ანარხი\n");
  A3(wordump, os_შემდეგი, და) O;
}
N(tail) { A3(1, 2, 3) wordump(T()); }
int main() {
  init_rigi();
  // |.b..........|............|.e..........|............
  void *b = malloc(100 << 12);
  void *e = b + (100 << 12);
  p_t *ο = (void *)((Q_t)b | ((Q_t)0xFFF)) + 1,
      *σ = (void *)((Q_t)e & ~((Q_t)0xFFF));
  printf("mem   %p %p\n", b, e);
  printf("grid  %p %p\n", ο, σ);
  printf("pages %ld\n", ((Q_t)σ >> 12) - ((Q_t)ο >> 12));

  ο += 3, σ -= 3;
  printf("tree  %p %p\n\n", ο, σ);

  long α = 0, ρ = 0;

  ο[-3].Q = 0, ο[-2].v = σ, ο[-1].Q = 0;

  σ[--ρ].c = os_წერტილი;
  σ[--ρ].c = os_არა;
  σ[--ρ].c = os_და;
  σ[--ρ].c = os_ან;
  σ[0].q = ρ, σ[1].v = ο, σ[2].v = 0;

  // if (argc < 2) {
  //  printf("%s filenameToRun\n", argv[0]);
  //  return -1;
  //}
  unsigned long size;
  n_t arsi = mapfile("src/arsi.arsi", &size);
  *(void **)((char *)arsi + size - 10) = tail;
  arsi(T());
  printf("done %p %ld\n", arsi, size);

  free(b);
}
