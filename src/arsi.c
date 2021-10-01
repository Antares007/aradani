#include "arsi.h"
#include "aradani.h"

Imports(წერტილი);

N(fun1) { A('fun1') C(, 1); }
N(fun2) { A('fun2') C(, 1); }
N(fun3) { A('fun3') C(, 1); }

// clang-format off
Exports(fun1, L)And(L,
        fun2, L)End(L,
        fun3);
// clang-format on
