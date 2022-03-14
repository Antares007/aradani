#include "arsi.h"
IBS(                L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,          imports)

Sar(init)(god)
Sar(Increase)('+', 'txt', god, ο, os_queue)
Sar(Decrease)('-', 'txt', god, ο, os_queue)
Sar(Counter)(
  Increase, 'btn', god, ο, os_queue,
  Decrease, 'btn', god, ο, os_queue, and5,
  '0', 'txt', god, ο, os_queue, and5
)

EN(tail,
Counter,      exports)
