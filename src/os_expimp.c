#include "aradani.h"
#include "os.h"
#include "os_exports.h"
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
N(ara);
N(arada);
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

struct impexp {
  n_t import, export;
  p_t *uσ, *dσ;
  int done;
};
N(impexp_or_ray) {
  printf("%s\n", __func__);
  struct impexp *s = S(impexp, σ);
  R(p_t *, oσ);
  s->dσ = oσ;
  A5(σ, gor, s->uσ, 2, os_queue) X;
}
N(retreat3) {
  printf("%s\n", __func__);
  α -= 3;
  C(1);
}
static N(impexp_and_ray_next) {
  printf("%s\n", __func__);
  R(n_t, import);
  R(n_t *, importaddress);
  R(char *, imprtname);
  R(n_t, export);
  R(n_t, exportaddress);
  R(char *, exportname);
  int r = cmp(exportname, imprtname);
  if (r < 0) {
    printf("<\n");
    A7(exportname, exportaddress, export, import, retreat3, impexp_and_ray_next,
       arada)
    O;
  } else if (r == 0) {
    printf("==\n");
    *importaddress = exportaddress;
    A7(exportname, exportaddress, export, import, retreat3, impexp_and_ray_next,
       arada)
    O;
  } else {
    printf(">\n");
    A8(export, imprtname, importaddress, import, impexp_and_ray_next, daaaa,
       god, ara)
    O;
  }
}
N(impexp_and_ray) {
  printf("%s\n", __func__);
  struct impexp *s = S(impexp, σ);
  R(n_t, export);
  A7(export, s->import, da, impexp_and_ray_next, da, retreat3, ara) X;
}
N(impexp_not_ray_next) {
  printf("%s\n", __func__);
  R(n_t, import);
  R(n_t *, address);
  R(char *, name);
  if (*address)
    A4(import, god, impexp_not_ray_next, arada) O;
  else
    A(name) C(2);
}
N(os_ie_not_next2) {
  printf("%s\n", __func__);
  struct impexp *s = S(impexp, σ);
  A5(s->export, god, s->dσ, 2, os_queue) X;
}
N(sendend) {
  printf("%s\n", __func__);
  struct impexp *s = S(impexp, σ);
  A4(got, s->dσ, 1, os_queue) O;
}
N(sendexport) {
  printf("%s\n", __func__);
  struct impexp *s = S(impexp, σ);
  A7(s->export, god, s->dσ, 2, os_queue, sendend, da) O;
}
N(senderror) {
  printf("%s\n", __func__);
  struct impexp *s = S(impexp, σ);
  Q_t a = α + 1;
  A4(got, s->dσ, a, os_queue) O;
}
N(impexp_not_ray) {
  printf("%s\n", __func__);
  struct impexp *s = S(impexp, σ);
  if (α) {
    Q_t a = α + 1;
    A4(got, s->dσ, a, os_queue) X;
  } else
    A7(s->import, god, impexp_not_ray_next, arada, senderror, sendexport, arada)
  X;
}
static N(impexp_pith) {
  A6(impexp_or_ray, impexp_and_ray, impexp_not_ray, 128,
     wordCountOf(struct impexp), os_new)
  O;
}
static N(os_ie_setσ) {
  printf("os_ie_setσ\n");
  R(p_t *, sσ);
  R(p_t *, uσ);
  R(n_t, export);
  R(n_t, import);
  struct impexp *s = S(impexp, sσ);
  s->export = export;
  s->import = import;
  s->uσ = uσ;
  s->done = 0;
  A(sσ) C(1);
}
N(os_ie) {
  R(n_t, tail);
  R(n_t, export);
  R(n_t, import);
  A8(import, export, os_ie, tail, impexp_pith, da, os_ie_setσ, da) O;
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
  A8(os_ie_sink, gor, os_ie, arsi, დააა, 2, os_queue, დაა)
  O;
}
N(ღრმაარსი) {
  R(n_t, impexp);
  A4(got, os_exports, არაწყარო, impexp) O;
}
