#include "arsi.h"

// clang-format off
IBS(                              L)IF(L,
printf, print,              imports, int, const char*, ...)
// clang-format on

static void init() { print("%s %s\n", __FILE__, __func__); }
static p_t ο[512];
S(seven) { A(7) C(1); }

// clang-format off
EBS(mod_empty,                 root)EN(root,
seven,                            L)EN(L,
ο,                          exports);
// clang-format on
