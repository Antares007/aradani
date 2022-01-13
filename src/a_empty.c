#include "arsi.h"

IN(0,
and,         L)IN(L,
and1,        L)IN(L,
and2,        L)IN(L,
and3,        L)IN(L,
and4,        L)IN(L,
and5,        L)IN(L,
and6,        L)IN(L,
and7,        L)IO(L);

N(seven) { A7(7, 7, 7, 7, 7, 7, 7) C(1); }

void init() { ο[ο[1].Q++].c = seven; }

EO(tail);
