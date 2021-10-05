#include "aradani.h"
#include "mmap.h"
#include "queue.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned long Q_t;
typedef unsigned int W_t;

#define X A2(os_შემდეგი, და) O
#define ISPAGE(lx) ((Q_t)lx & (Q_t)0xFFF) == 3 * sizeof(void *)
#define S(ns, n) ((struct n *)&ns##σ[-wordCountOf(struct n)])
static N(ან_გადასვლა) { //
  σ[ρ + 0].c(T());
}
static N(და_გადასვლა) { //
  σ[ρ + 1].c(T());
}
static N(არა_გადასვლა) { //
  σ[ρ + 2].c(T());
}
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
// static N(გულგული_ან) { ρ += 6; σ[ρ - 3].c(T()); }
// static N(გულგული_და) { ρ += 6; σ[ρ - 2].c(T()); }
// static N(გულგული_არა) { ρ += 6; σ[ρ - 1].c(T()); }
static N(os_აგულგული) {
  R(Q_t, pc);
  R(Q_t, wc);
  p_t *lx = σ[1].v;
  p_t *nσ = &lx[(ISPAGE(lx) ? 503 : 512) + pc * 512];
  if (σ <= nσ)
    return A2(wc, pc) C(, 2);

  long nρ = -wc;
  nσ[--nρ].c = ο[--α].c;
  nσ[--nρ].c = ο[--α].c;
  nσ[--nρ].c = ο[--α].c;

  QUEUE_INIT((QUEUE *)&nσ[4]);
  nσ[0].q = nρ, nσ[1].v = lx, nσ[2].v = σ, nσ[3].v = σ;
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

static void init_rigi() {
  for (int i = 0; i < MAX_RIGIS_ELEMENTI; i++)
    rigis_elementebi[i].q[0] = 0;
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
  QUEUE_INSERT_TAIL((QUEUE *)&σ[4], &rigis_elementebi[nomeri].q);
  C(, 1);
}
static void next_(p_t *σ) {
  QUEUE *q;
  if ((QUEUE *)&σ[4] != (q = QUEUE_NEXT((QUEUE *)&σ[4]))) {
    QUEUE_REMOVE(q);
    rigis_elementi_t *e = (void *)q;
    e->q[0] = 0;
    p_t *eο = e->ο, *eσ = e->σ;
    long eα = eο[-1].q, eρ = eσ[0].q;
    eσ[3].v = σ;
    eο[eα - 1].c(eο, eα - 1, eρ, eσ);
  } else if (σ[3].v)
    next_(σ[3].v);
  else
    printf("end\n");
}
static N(os_შემდეგი) {
  printf("os\n");
  ο[-1].Q = α;
  if (α == 0 && ο[-3].v != 0) {
    p_t *l = ο[-3].v, *r = ο[-2].v;
    l[ISPAGE(l) ? -2 : 2].v = r;
    r[ISPAGE(r) ? -3 : 1].v = l;
  }
  next_(σ);
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
  C(, 1);
}
static N(loog) {
  R(char *, s);
  printf("\n%s\n", s);
  wordump(T());
}
static N(os_წერტილი_next) {
  R(Q_t, wc);
  R(void *, pith);
  A7(os_აფურცელი, wc, os_ამოწერე, დაა, pith, os_რიგშიჩააყენე, დაა) O;
}
static N(os_წერტილი) {
  // A4("os_წერტილი", loog, os_წერტილი_next, და) O;
  os_წერტილი_next(T());
}
static N(os_არა) { printf("os_არა\n"); }
static N(os_და) {
  printf("os_და\n");
  os_შემდეგი(T());
}
static N(os_ან) {
  printf("os_ან\n");
  os_შემდეგი(T());
}
struct impexp {
  n_t *imports, *exports;
  long isize, esize;
  p_t *uσ, *dσ;
  char **inames, **enames;
};
N(იმპორტექსპორტის_ან) {
  printf("იმპორტექსპორტის_ან\n");
  struct impexp *s = S(, impexp);
  R(p_t *, kσ);
  if (s->uσ == kσ) { // გაგიმარჯოს
    A5(σ, ან_გადასვლა, s->dσ, 2, os_წერტილი) X;
  } else { // გამარჯობა
    assert(s->dσ == 0);
    s->dσ = kσ;
    A5(σ, ან_გადასვლა, s->uσ, 2, os_წერტილი) X;
  }
}
#include <string.h>
int cmp(const char *s1, const char *s2) {
  while (*s1 == *s2++)
    if (*s1++ == 0)
      return (0);
  return (*(unsigned char *)s1 - *(unsigned char *)--s2);
}
N(იმპორტექსპორტის_და) {
  R(Q_t, exportsCount);
  R(n_t *, exports);
  R(char **, exportedNames);
  printf("იმპორტექსპორტის_და %s %p %ld\n", exportedNames[1], exports[0],
         exportsCount);
  struct impexp *s = S(, impexp);
  for (long i = 0; i < s->isize; i++)
    for (long e = 0; e < exportsCount; e++)
      if (s->isize && cmp(s->inames[i], exportedNames[e]) == 0)
        s->imports[i] = exports[e];
  A7(exportedNames, exports, exportsCount, და_გადასვლა, s->dσ, 4, os_წერტილი)
  A2(os_შემდეგი, და) O;
}
N(იმპორტექსპორტის_არა) {
  printf("იმპორტექსპორტის_არა\n");
  struct impexp *s = S(, impexp);
  if (α) {
    long a = α + 1;
    A4(არა_გადასვლა, s->dσ, a, os_წერტილი) X;
  } else {
    for (long i = 0; i < s->isize; i++)
      if (s->imports[i] == 0)
        return A5(s->inames[i], არა_გადასვლა, s->dσ, 2, os_წერტილი) X;
    if (s->esize) {
      A7(s->enames, s->exports, s->esize, და_გადასვლა, s->dσ, 4, os_წერტილი)
      A5(არა_გადასვლა, s->dσ, 1, os_წერტილი, დაააა)
      A2(os_შემდეგი, და) O;
    } else
      A4(არა_გადასვლა, s->dσ, 1, os_წერტილი) X;
  }
}
static N(იმპორტექსპორტისგულგული) {
  A6(იმპორტექსპორტის_ან, იმპორტექსპორტის_და, იმპორტექსპორტის_არა,
     wordCountOf(struct impexp), 3, os_აგულგული)
  O;
}
N(kal0) { printf("kal0\n"); }
N(kal1) { printf("kal1\n"); os_შემდეგი(T());}
N(kal2) { 
  printf("kal2\n");
}
static N(კალაპოტი) { A6(kal0, kal1, kal2, 0, 3, os_აგულგული) O; }

static N(uσ_set) {
  R(p_t *, sσ);
  struct impexp *s = S(s, impexp);
  memset(s, 0, sizeof(*s));
  R(Q_t, ec);
  R(n_t *, exports);
  R(char **, enames);
  R(Q_t, ic);
  R(n_t *, imports);
  R(char **, inames);
  R(p_t *, uσ);
  s->exports = exports;
  s->enames = enames;
  s->esize = ec;
  s->imports = imports;
  s->inames = inames;
  s->isize = ic;
  s->uσ = uσ;
  A(sσ) C(, 1);
}
static N(იმპორტექსპორტი) {
  R(n_t, tail);
  R(n_t, exports);
  R(n_t, imports);
  A10(იმპორტექსპორტი, tail, imports, და, exports, და, იმპორტექსპორტისგულგული,
      და, uσ_set, და)
  O;
}
#include "arsi.h"
static N(imports) { A3(0, 0, 0) C(, 1); }
Exports(os_წერტილი, os_აგულგული, os_შემდეგი);
N(არაწყაროს_ან) {
  printf("არაწყაროს_ან\n");
  R(p_t *, kσ);
  A4(არა_გადასვლა, kσ, 1, os_წერტილი) X;
}
N(არაწყარო) {
  --α;
  A6(არაწყაროს_ან, 0, 0, 0, 3, os_აგულგული) O;
}
N(tail) {
  R(n_t, cb);
  A4(imports, exports, არაწყარო, cb) O;
}
int main() {
  init_rigi();
  // |.b..........|............|.e..........|............
  void *b = malloc(100 << 12);
  void *e = b + (100 << 12);
  p_t *ο = (void *)((Q_t)b | ((Q_t)0xFFF)) + 1,
      *σ = (void *)((Q_t)e & ~((Q_t)0xFFF));

  ο += 3, σ -= 6;
  long α = 0, ρ = 0;

  ο[-3].Q = 0, ο[-2].v = σ, ο[-1].Q = 0;

  σ[--ρ].c = os_არა;
  σ[--ρ].c = os_და;
  σ[--ρ].c = os_ან;

  QUEUE_INIT((QUEUE *)&σ[4]);
  σ[0].q = ρ, σ[1].v = ο, σ[2].v = 0, σ[3].v = 0;

  // if (argc < 2) {
  //  printf("%s filenameToRun\n", argv[0]);
  //  return -1;
  // }
  unsigned long size;
  n_t arsi = mapfile("src/arsi2.arsi", &size);
  *(void **)((char *)arsi + size - 10) = tail;
  A8(კალაპოტი, ან_გადასვლა, იმპორტექსპორტი, arsi, დააა, 2, os_წერტილი, დაა)
  O;

  free(b);
}

N(s0) {
  R(p_t *, kσ);
  printf("s0 %p %p\n", (void *)((Q_t)kσ >> 12), (void *)((Q_t)σ >> 12));
  A5(σ, ან_გადასვლა, kσ, 2, os_წერტილი) A2(os_შემდეგი, და) O;
}
N(s1) {
  R(p_t *, sσ);
  printf("s1 %p %p\n", (void *)((Q_t)sσ >> 12), (void *)((Q_t)σ >> 12));
  A5(σ, და_გადასვლა, sσ, 2, os_წერტილი) A2(os_შემდეგი, და) O;
}
N(s2) {}
N(s) { A6(s0, s1, s2, 1, 3, os_აგულგული) O; }
N(k0) {
  R(p_t *, sσ);
  printf("k0 %p %p\n", (void *)((Q_t)sσ >> 12), (void *)((Q_t)σ >> 12));
  A5(σ, და_გადასვლა, sσ, 2, os_წერტილი) A2(os_შემდეგი, და) O;
}
N(k1) {
  R(p_t *, sσ);
  printf("k1 %p %p\n", (void *)((Q_t)sσ >> 12), (void *)((Q_t)σ >> 12));
  A5(σ, და_გადასვლა, sσ, 2, os_წერტილი) A2(os_შემდეგი, და) O;
}
N(k2) {
  R(p_t *, sσ);
  printf("k2 %p %p\n", (void *)((Q_t)sσ >> 12), (void *)((Q_t)σ >> 12));
}
N(k) { A6(k0, k1, k2, 1, 3, os_აგულგული) O; }
N(test) {
  A13(k, "kala", loog, დაა, ან_გადასვლა, s, დაა, "sou", loog, დაა, 2,
      os_წერტილი, დაა)
  O;
}
