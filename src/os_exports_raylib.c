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
  RS(Color, c);
  (ClearBackground(*c), C(1));
}, L)ED(L,

rl_CloseWindow, {
  (CloseWindow(), C(1));
}, L)ED(L,

rl_DrawLineBezierCubic, {
  RS(Color, color);
  RS(float, thick);
  RS(Vector2, endControlPos);
  RS(Vector2, startControlPos);
  RS(Vector2, endPos);
  RS(Vector2, startPos);
  (DrawLineBezierCubic(*startPos, *endPos, *startControlPos, *endControlPos, *thick, *color), C(1));
}, L)ED(L,

rl_DrawLineEx, {
  RS(Color, color);
  RS(float, thick);
  RS(Vector2, endPos);
  RS(Vector2, startPos);
  (DrawLineEx(*startPos, *endPos, *thick, *color), C(1));
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
