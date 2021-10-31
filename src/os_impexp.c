#include "os_impexp.h"
#include "aradani.h"
#include "os.h"
#include "os_queue.h"
#include <stdio.h>
static N(gor) { C(0); }
static N(god) { C(1); }
static N(got) { C(2); }
static int cmp(const char *s1, const char *s2) {
  while (*s1 == *s2++)
    if (*s1++ == 0)
      return (0);
  return (*(unsigned char *)s1 - *(unsigned char *)--s2);
}
struct impexp {
  n_t import, export;
  p_t *uσ, *dσ;
  int done;
};
static N(impexp_or_ray) {
  printf("%s\n", __func__);
  struct impexp *s = S(impexp, σ);
  R(p_t *, oσ);
  s->dσ = oσ;
  A5(σ, gor, s->uσ, 2, os_queue) X;
}
static N(retreat3) {
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
static N(impexp_and_ray) {
  printf("%s\n", __func__);
  struct impexp *s = S(impexp, σ);
  R(n_t, export);
  A7(export, s->import, da, impexp_and_ray_next, da, retreat3, ara) X;
}
static N(impexp_not_ray_next) {
  printf("%s\n", __func__);
  R(n_t, import);
  R(n_t *, address);
  R(char *, name);
  if (*address)
    A4(import, god, impexp_not_ray_next, arada) O;
  else
    A(name) C(2);
}
static N(sendend) {
  printf("%s\n", __func__);
  struct impexp *s = S(impexp, σ);
  A4(got, s->dσ, 1, os_queue) O;
}
static N(sendexport) {
  printf("%s\n", __func__);
  struct impexp *s = S(impexp, σ);
  A7(s->export, god, s->dσ, 2, os_queue, sendend, da) O;
}
static N(senderror) {
  printf("%s\n", __func__);
  struct impexp *s = S(impexp, σ);
  Q_t a = α + 1;
  A4(got, s->dσ, a, os_queue) O;
}
static N(impexp_not_ray) {
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
N(os_impexp) {
  R(n_t, tail);
  R(n_t, export);
  R(n_t, import);
  A8(import, export, os_impexp, tail, impexp_pith, da, os_ie_setσ, da) O;
}
