#include "import_export.h"
#include "oars.h"
#include <raylib.h>

N(exports);

#define ED(Tail, Name, Body, Head) N(Name) Body EN(Tail, Name, Head)
#undef L
#define L CAT(export_raylib_, __LINE__)
// clang-format off
ED(exports,

rl_InitWindow, {
  R(Q_t, width);
  R(Q_t, height);
  R(const char *, title);
  (InitWindow(width, height, title), C(1));
}, L)ED(L,

rl_WindowShouldClose, {
  C(!!WindowShouldClose());
}, L)ED(L,

rl_BeginDrawing, {
  (BeginDrawing(), C(1));
}, L)ED(L,

rl_EndDrawing, {
  (EndDrawing(), C(1));
}, L)ED(L,

rl_ClearBackground, {
  struct Color *color = (void *)&ο[--α];
  (ClearBackground(*color), C(1));
}, L)ED(L,

rl_CloseWindow, {
  (CloseWindow(), C(1));
}, exports_raylib)
