#include "arsi.h"
// clang-format off
IN(iε,
os_hrtime,                  L)IN(L,
os_new,                     L)IN(L,
os_wordump,                 L)IF(L,
printf, print,              L, int, const char*, ...)IN(L,
//
os_queue,                   L)p_t *oο;I(L,
"ο", oο,                    L)IN(L,
//
and,                        L)IN(L,
and2,                       L)IN(L,
and3,                       L)IN(L,
and4,                       L)IN(L,
and5,                       L)IN(L,
and6,                       L)IN(L,
and7,                       L)IN(L,
andor,                      L)IN(L,
notand,                     L)IN(L,
or,                         L)IN(L,
//
os_ls,                imports);
// clang-format on

N(მთავარი) {
  print("hey\n");
  A10(os_hrtime, os_hrtime, and,
      os_hrtime, and,
      os_wordump, and,
      exports, os_ls, and2)
  O;
}
N(init) {
  print("\ninit %s\n", __FILE__);
  oο[oο[1].Q++].v = მთავარი, C(1);
}

// clang-format off
E(tail,
"ο", oο,              exports);
