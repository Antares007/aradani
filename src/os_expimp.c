#include "aradani.h"
#include "os.h"
#include "os_exports.h"
#include "os_impexp.h"
#include "os_queue.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

static int cmp(const char *s1, const char *s2) {
  while (*s1 == *s2++)
    if (*s1++ == 0)
      return (0);
  return (*(unsigned char *)s1 - *(unsigned char *)--s2);
}

static N(gor) { σ[ρ + 0].c(T()); }
static N(god) { σ[ρ + 1].c(T()); }
static N(got) { σ[ρ + 2].c(T()); }

static N(os_ie_sink_or) { assert(0); }

static n_t მთავარი;
static N(nextf) {
  R(n_t, export);
  R(n_t, address);
  R(char *, name);
  if (cmp(name, "მთავარი") == 0)
    მთავარი = address, C(1);
  else
    A4(export, god, nextf, arada) O;
}
static N(os_ie_sink_and) {
  R(n_t, export);
  A3(export, nextf, da) X;
}
static N(os_ie_sink_not) {
  if (α)
    printf("erroraaa\n");
  else {
    printf("next\n");
    p_t *oσ = σ[-1].v;
    მთავარი(oσ[0].v, 0, oσ[2].q, oσ);
  }
}
Nd(set) {
  R(p_t *, oσ);
  oσ[-1].v = σ;
  A(oσ) C(1);
}
static N(os_ie_sink) {
  A8(os_ie_sink_or, os_ie_sink_and, os_ie_sink_not, 128, 1, os_new, set, da) O;
}

static N(არაწყაროს_ან) {
  R(p_t *, kσ);
  A4(got, kσ, 1, os_queue) X;
}
static N(არაწყარო) {
  --α;
  A6(არაწყაროს_ან, 0, 0, 128, 0, os_new) O;
}
N(არსი) {
  R(n_t, arsi);
  A8(os_ie_sink, gor, os_impexp, arsi, დააა, 2, os_queue, დაა)
  O;
}
N(ღრმაარსი) {
  R(n_t, impexp);
  A4(got, os_exports, არაწყარო, impexp) O;
}
