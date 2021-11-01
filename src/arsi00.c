#include "arsi.h"
// clang-format off
IN(gor,
os_next, import);
// clang-format on

N(s2) { A(7) C(1); }
N(mmain) { A(9) C(1); }

// clang-format off
E(Tail,
"m2",       mmain, L)E(L,
"M",  mmain, export);
// clang-format on

/*
long a[10];

// clang-format off
static N(r3) { α -= 3, C(1); }
I(gor,
"a",  a[0], L)I(L,
"bb", a[1], L)I(L,
"cc", a[2],ti);
// clang-format on
// clang-format off
E(gor,
"a",  'a', L)E(L,
"bb", 'b', L)E(L,
"cc", 'c', L)E(L,
"d",  'd', te);
// clang-format on

static N(do_import_next) {
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
    A8(import, exportname, exportaddress, export, do_import_next, daaaa, god,
       an)
    O;
  } else {
    A8(imprtname, importaddress, import, export, do_import_next, da, r3, an) O;
  }
}
N(do_import) {
  R(n_t, export);
  R(n_t, import);
  A7(import, export, da, do_import_next, da, r3, an) O;
}
N(puta) { A3(a[0], a[1], a[2]) C(1); }
N(mmain) {
  // A5(ti, te, do_import, puta, da) O;
  A(puta) O;
}

N(s1) { A('s1') C(1); }
N(s2) { A('s2') C(1); }
N(s3) { A('s3') C(1); }

*/
