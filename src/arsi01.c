#include "arsi.h"
Imports(ან_გადასვლა, მთავარი);

N(ან_გადასვლა) { o.ან_გადასვლა(T()); }
N(და_გადასვლა) { σ[ρ + 1].c(T()); }
N(არა_გადასვლა) { σ[ρ + 2].c(T()); }

N(მთავარი) { A(2) o.მთავარი(T()); }

Exports(მთავარი);