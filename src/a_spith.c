#include "arsi.h"
// clang-format off
IN(0,
and,                      L)IN(L,
and2,                     L)IN(L,
//
ls_export,                L)int(*print)(const char*, ...);I(L,
printf, print,            L)IN(L,
//
debugger,            import);

N(მთავარი) { A7(7, 7, 7, 7, 7, 7, 7) C(1); }

void export_მთავარი(void *s, void(and_ray)(), void(or_ray)()) {
  and_ray(s, "მთავარი", მთავარი, tail);
}
void export(void *s, void(and_ray)(), void(or_ray)()) {
  and_ray(s, "s_pith", 0, export_მთავარი);
}
