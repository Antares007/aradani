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
rl_WindowShouldKeepAlive,   L)IN(L,
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
N(drawline) {
  Sa6(Vector2, {100 ξ 100}, //
      Vector2, {400 ξ 100}, //
      Vector2, {100 ξ 200}, //
      Vector2, {400 ξ 200}, //
      float, 2,             //
      Color, {0 ξ 0 ξ 0 ξ 255}) A(rl_DrawLineBezierCubic) O;
}
N(mn) {
  A3(rl_WindowShouldKeepAlive, rl_BeginDrawing, and) //
  Sa(Color, {255, 100, 100, 255})                    //
      A2(rl_ClearBackground, and2)                   //
      A2(drawline, and)                              //
      A2(rl_EndDrawing, and)                         //
      A2(mn, and) O;                                 //
}
N(მთავარი) {
  A8(800, 600, "mami", rl_InitWindow, mn, rl_CloseWindow, or, and3) O;
}

SP(init) {
  print("init\n");
  oο[oο[1].Q++].v = მთავარი, C(1);
}

// clang-format off
E(tail,
"ο", oο,              exports);
