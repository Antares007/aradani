#include "arsi.h"

void* pages[0x1000];

N(tail) __attribute__((section(".text.end")));
N(tail) {};

N(head) __attribute__((section(".text.begin")));
N(head) { Α(&pages[0], &pages[sizeof(pages) / sizeof(*pages)], tail) C(1); }
