#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
nar,                L)IN(L,
os_queue,           L)IN(L,
os_soll_a,          L)IN(L,
os_soll_n,          L)IN(L,
os_wordump,         L)IN(L,

and,                L)IN(L,
and2,               L)IN(L,
and3,               L)IN(L,
and3or,             L)IN(L,
and4,               L)IN(L,

new_soll_psn, imports);
SargoP(init)(god)

#define BUF ο[7].p[0].cs
#define POS ο[7].p[1].Q
#define LEN ο[7].p[2].Q
#define LHD ο[7].p[3].Q

Sarg2(parser)(inp, const char*,
              len, Q_t)(
  got,             1, os_soll_n,
  god,             1, os_soll_a,
  gor,             1, os_soll_a,
  inp, 0, len, -1, 4, os_soll_a,
  ο, 512, "p", new_soll_psn, and4
)
So(lookahead)( C((POS < LEN) ? (LHD = BUF[POS], 1) : 2); )
So(shift    )( Q_t lookahead = LHD; if (lookahead == -1) C(2); else LHD = -1, POS++, A(lookahead) C(1); )

Sargo(example)(
  lookahead,
  lookahead, and,
  shift,     and,
  lookahead, and,
  shift,     and,
  lookahead, and,
  shift,     and)

SargoP(მთავარი)(example, 2, god, 1, god, 0, god, 0222, nar, "sa", 3, parser, os_queue, and)

EN(tail,
lookahead,          L)EN(L,
parser,             L)EN(L,
shift,              L)EN(L,
მთავარი,      exports);
