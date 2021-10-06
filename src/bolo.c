#include "aradani.h"
#include "arsi.h"
void head() __attribute__((section(".text.begin")));
void head(o_t o, e_t e, r_t r) { e(); }
void tail() __attribute__((section(".text.end")));
void tail(o_t o, e_t e, r_t r) {}
