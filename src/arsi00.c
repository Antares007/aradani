#include "arsi.h"
#include "queue.h"
// clang-format off
IN(gor,    
da,                                      L)IN(L,
da2,                                import);
// clang-format on

N(os_next) { C(1); }
N(os_queue) { C(1); }
N(os_queue_init) { C(1); }
N(მთავარი) { A(9) C(1); }

// clang-format off
EN(Tail,
os_next,                                 L)EN(L,
os_queue,                                L)EN(L,
მთავარი,                            export);
