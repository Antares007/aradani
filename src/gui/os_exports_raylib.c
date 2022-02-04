#include "export_fun.h"
#include "arsi.h"
#include <raylib.h>
#include <stdio.h>

N(exports);

#define ED(Tail, Pref, Name, Body, Head)                                       \
  N(Pref##Name) Body EN(Tail, Pref##Name, Head)
#undef L
#define L CAT(export_raylib_, __LINE__)
bool WindowShouldKeepAlive() { return !WindowShouldClose(); }
// clang-format off
EVF0(exports,
rl_, BeginDrawing, L)EVF1(L,
rl_, ClearBackground, Σ, Color, color, L)EVF0(L,
rl_, CloseWindow, L)EVF6(L,
rl_, DrawLineBezierCubic, Σ, Vector2, startPos, Σ, Vector2, endPos, Σ, Vector2, startControlPos, Σ, Vector2, endControlPos, Σ, float, thick, Σ, Color, color, L)EVF4(L,
rl_, DrawLineEx, Σ, Vector2, startPos, Σ, Vector2, endPos, Σ, float, thick, Σ, Color, color, L)EVF0(L,
rl_, EndDrawing, L)EVF3(L,
rl_, InitWindow, Ϋ, Q_t, width, Ϋ, Q_t, height, Ϋ, const char *, title, L)EBF0(L,
rl_, WindowShouldClose, L)EBF0(L,
rl_, WindowShouldKeepAlive, exports_raylib)
