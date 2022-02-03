#include "arsi.h"

// clang-format off
IB(init2,
                              L)IF(L,
printf, print,                L, int, const char*, ...)IN(L,
os_queue,                   imp);
// clang-format on

static void init2() { print("%s\n", __func__); }
p_t ο[512];
S(seven) { A(7) C(1); }

// clang-format off
EB(mod_empty, imp, exps,             
                                     L)EN(L,
seven,                               L)EN(L,
ο,                                exps);
// clang-format on
