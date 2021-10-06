#include "aradani.h"
//#include "arsi.h"
#include "os.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

int cmp(const char *s1, const char *s2) {
  while (*s1 == *s2++)
    if (*s1++ == 0)
      return (0);
  return (*(unsigned char *)s1 - *(unsigned char *)--s2);
}

static N(ან_გადასვლა) { σ[ρ + 0].c(T()); }
static N(და_გადასვლა) { σ[ρ + 1].c(T()); }
static N(არა_გადასვლა) { σ[ρ + 2].c(T()); }

static N(kal0) {
  printf("kal0\n");
  os_შემდეგი(T());
}

static n_t მთავარი;
static N(kal1) {
  printf("kal1\n");
  R(Q_t, exportsCount);
  R(n_t *, exports);
  R(char **, exportedNames);
  for (long i = 0; i < exportsCount; i++)
    if (cmp("მთავარი", exportedNames[i])==0)
      მთავარი = exports[i];
  os_შემდეგი(T());
}
static N(kal2) {
  if (α)
    printf("error\n");
  else {
    printf("next\n");
    მთავარი(T());
  }
}
static N(კალაპოტი) { A6(kal0, kal1, kal2, 0, 3, os_აგულგული) O; }

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
N(იმპორტექსპორტის_და) {
  R(Q_t, exportsCount);
  R(n_t *, exports);
  R(char **, exportedNames);
  printf("იმპორტექსპორტის_და %s %p %ld\n", exportedNames[0], exports[1],
         exportsCount);
  struct impexp *s = S(, impexp);
  for (long i = 0; i < s->isize; i++)
    for (long e = 0; e < exportsCount; e++)
      if (s->isize && cmp(s->inames[i], exportedNames[e]) == 0)
        s->imports[i] = exports[e];
  A7(exportedNames, exports, exportsCount, და_გადასვლა, s->dσ, 4, os_წერტილი) X;
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
N(იმპორტექსპორტი) {
  R(n_t, tail);
  R(n_t, exports);
  R(n_t, imports);
  A10(იმპორტექსპორტი, tail, imports, და, exports, და, იმპორტექსპორტისგულგული,
      და, uσ_set, და)
  O;
}
static N(imports) { A3(0, 0, 0) C(, 1); }
static N(არაწყაროს_ან) {
  printf("არაწყაროს_ან\n");
  R(p_t *, kσ);
  A4(არა_გადასვლა, kσ, 1, os_წერტილი) X;
}
static N(არაწყარო) {
  --α;
  A6(არაწყაროს_ან, 0, 0, 0, 3, os_აგულგული) O;
}
N(არსი) {
  R(n_t, arsi);
  A8(კალაპოტი, ან_გადასვლა, იმპორტექსპორტი, arsi, დააა, 2, os_წერტილი, დაა)
  O;
}
char *νames[] = {"os_წერტილი", "os_აგულგული", "os_შემდეგი"};
n_t νars[] = {os_წერტილი, os_აგულგული, os_შემდეგი};
static N(exports) { A3(νames, νars, (sizeof(νames) / sizeof(*νames))) C(, 1); }
N(ღრმაარსი) {
  R(n_t, cb);
  A4(imports, exports, არაწყარო, cb) O;
}
