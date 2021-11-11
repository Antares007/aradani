#include "oars.h"
#include <stdio.h>
N(os_wordump);
N(da);

static N(gc) { fgetc(stdin); C(1); }
N(debugger) { A3(os_wordump, gc, da) O; }
