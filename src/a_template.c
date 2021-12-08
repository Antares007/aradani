#include "importexportmacros.h"
#include "oars.h"
M(import);
M(export);
void tail() __attribute__((section(".text.end")));
void head() __attribute__((section(".text.begin")));

M(tail) {}
struct impexp_s {
  struct impexp_s *state;
  M((*and_ray));
  M((*or_ray));
  const char *iname;
  n_t *iaddr;
  M((*import));
  const char *ename;
  n_t eaddr;
  M((*export));
};
static int cmp(const char *s1, const char *s2) {
  while (*s1 == *s2++)
    if (*s1++ == 0)
      return (0);
  return (*(unsigned char *)s1 - *(unsigned char *)--s2);
}
void do_export_do_cmp_pith(struct impexp_s *s, const char *name, n_t addr,
                           M((export)));
void do_import_do_cmp_pith(struct impexp_s *s, const char *name, n_t *addr,
                           M((import))) {
  s->iname = name;
  s->iaddr = addr;
  s->import = import;
  if (cmp(s->iname, s->ename) == 0) {
    *s->iaddr = s->eaddr;
    s->import(s, do_import_do_cmp_pith, s->or_ray);
  } else {
    s->export(s, do_export_do_cmp_pith, s->or_ray);
  }
}
void do_export_do_cmp_pith(struct impexp_s *s, const char *name, n_t addr,
                           M((export))) {
  s->ename = name;
  s->eaddr = addr;
  s->export = export;
  if (cmp(s->iname, s->ename) == 0) {
    *s->iaddr = s->eaddr;
    s->import(s, do_import_do_cmp_pith, s->or_ray);
  } else {
    s->export(s, do_export_do_cmp_pith, s->or_ray);
  }
}
void do_import_do_export_pith(struct impexp_s *s, const char *name, n_t *addr,
                              M((import))) {
  s->iname = name;
  s->iaddr = addr;
  s->import = import;
  s->export(s, do_export_do_cmp_pith, s->or_ray);
}
M(head) {
  static int imported = 0;
  if (imported)
    export(state, and_ray, or_ray);
  else
    import(
        &(struct impexp_s){
            .state = state,
            .and_ray = and_ray,
            .or_ray = or_ray,
            .export = tail,
        },
        do_import_do_export_pith, or_ray);
}

// clang-format off
static M(m_got) { or_ray(state); }
IN(m_got,
and,                      L)IN(L,
and2,                     L)IN(L,
or,                       L)IN(L,
//
ls_export,                L)IN(L,
os_new,                   L)IN(L,
os_next,                  L)IN(L,
os_queue,                 L)int(*print)(const char*, ...);I(L,

printf, print,       import);

N(მთავარი) {
  print("hey\n");
  A2(export, ls_export) O;
}

EN(tail,
მთავარი,             export);
