#include "arsi.h"
// clang-format off
IN(iε,
os_new,                     L)IN(L,
os_wordump,                 L)IF(L,
printf, print,              L, int, const char*, ...)IN(L,
//
rl_BeginDrawing,            L)IN(L,
rl_ClearBackground,         L)IN(L,
rl_CloseWindow,             L)IN(L,
rl_DrawLineBezierCubic,     L)IN(L,
rl_DrawLineEx,              L)IN(L,
rl_EndDrawing,              L)IN(L,
rl_InitWindow,              L)IN(L,
rl_WindowShouldClose,       L)IN(L,
//
os_queue_and,               L)p_t *oο;I(L,
"ο", oο,                    L)IN(L,
//
and,                        L)IN(L,
and2,                       L)IN(L,
and3,                       L)IN(L,
and4,                       L)IN(L,
andor,                      L)IN(L,
notand,                     L)IN(L,
or,                         L)IN(L,
//
os_ls,                imports);
// clang-format on
#include <raylib.h>

SarP(init)(god)

// clang-format off
E(tail,
"ο", oο,              exports);
