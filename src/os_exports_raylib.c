#include "import_export.h"
#include "oars.h"
#include <raylib.h>
#include <stdio.h>

N(exports);

#define ED(Tail, Name, Body, Head) N(Name) Body EN(Tail, Name, Head)
#undef L
#define L CAT(export_raylib_, __LINE__)
// clang-format off
ED(exports,

rl_BeginDrawing, {
  (BeginDrawing(), C(1));
}, L)ED(L,

rl_ClearBackground, {
  struct Color *c = (void*)&ο[--α]; (ClearBackground(*c), C(1));
}, L)ED(L,

rl_CloseWindow, {
  (CloseWindow(), C(1));
}, L)ED(L,

rl_EndDrawing, {
  (EndDrawing(), C(1));
}, L)ED(L,

rl_InitWindow, {
  R(const char *, title);
  R(Q_t, height);
  R(Q_t, width);
  (InitWindow(width, height, title), C(1));
}, L)ED(L,

rl_WindowShouldClose, {
  C(!WindowShouldClose());
}, exports_raylib)
