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
static N(r3) {
  printf("%s\n", __func__);
  α -= 3;
  C(1);
}
static N(impexp_and_ray_next) {
  printf("%s\n", __func__);
  R(n_t, export);
  R(n_t, exportaddress);
  R(char *, exportname);
  R(n_t, import);
  R(n_t *, importaddress);
  R(char *, imprtname);
  int r = cmp(exportname, imprtname);
  if (r <= 0) {
    if (r == 0)
      *importaddress = exportaddress;
    A8(import, exportname, exportaddress, export, impexp_and_ray_next, daaaa,
       god, an)
    O;
  } else {
    A7(imprtname, importaddress, import, export, r3, impexp_and_ray_next, anda)
    O;
  }
}
static N(impexp_and_ray) {
  printf("%s\n", __func__);
  struct impexp *s = S(impexp, σ);
  R(n_t, export);
  A6(s->import, export, da, god, impexp_and_ray_next, anda) X;
}
static N(senderror) {
  printf("%s\n", __func__);
  struct impexp *s = S(impexp, σ);
  Q_t a = α + 1;
  A4(got, s->dσ, a, os_queue) O;
}
static N(impexp_not_ray_next) {
  printf("%s\n", __func__);
  R(n_t, import);
  R(n_t *, address);
  R(char *, name);
  if (*address)
    A4(import, god, impexp_not_ray_next, anda) O;
  else
    A(name) C(2);
}
static N(sendend) {
  printf("%s\n", __func__);
  struct impexp *s = S(impexp, σ);
  A4(got, s->dσ, 1, os_queue) O;
}
static N(send_export_and_end) {
  printf("%s\n", __func__);
  struct impexp *s = S(impexp, σ);
  A7(s->export, god, s->dσ, 2, os_queue, sendend, da) O;
}
static N(impexp_not_ray) {
  printf("%s\n", __func__);
  struct impexp *s = S(impexp, σ);
  if (α) {
    Q_t a = α + 1;
    A4(got, s->dσ, a, os_queue) X;
  } else
    A6(s->import, send_export_and_end, impexp_not_ray_next, anda, senderror,
       ara)
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
