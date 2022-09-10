/************************************************************************************
 *
 *   raylib [text] example - Input Box
 *
 *   This example has been created using raylib 3.5 (www.raylib.com)
 *   raylib is licensed under an unmodified zlib/libpng license (View raylib.h
 *   for details)
 *
 *   Copyright (c) 2017 Ramon Santamaria (@raysan5)
 *
 ************************************************************************************/
#include "oars.h"
#include "oars_logn.h"
#include "raylib.h"
void da(OARS);
void got(OARS);
void god(OARS);
void gor(OARS);
N(empty_ring) { A1(god); }
N(counter) {
  RN(p_t *, o);
  A3(empty_ring, o, o[0].c);
  A3(empty_ring, o, o[0].c);
  A3(empty_ring, o, o[0].c);
}
N(show_counter) {
  RN(p_t *, o);
  A3(counter, o, o[0].c);
  A3(empty_ring, o, o[0].c);
}
N(div) {
  //  RN(p_t *, o);
  //  RN(n_t, ring);
  A1(gor);
}
N(make_pith) { A2(1, god); }
N(sample) { A3(make_pith, show_counter, da); }
N(ray_not) {}
N(ray_and) {}
N(ray_oor) {}
int gui_sample(void);
int main() {
  p_t ο[4096];
  Q_t α = 0, ρ = sizeof(ο) / sizeof(*ο), σ = ρ / 4;
  ρ--;
  ο[ρ - σ * 2].c = ray_not;
  ο[ρ - σ * 1].c = ray_and;
  ο[ρ - σ * 0].c = ray_oor;
  div(T);
  const int screenWidth = 800;
  const int screenHeight = 450;
  InitWindow(screenWidth, screenHeight, "raylib [text] example - input box");
  SetTargetFPS(0);
  // Detect window close button or ESC key
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(GOLD);
    DrawText("PLACE MOUSE OVER INPUT BOX!", 240, 140, 20, BLACK);
    DrawText(TextFormat("fps: %i", GetFPS()), 315, 270, 40, BLACK);
    EndDrawing();
  }
  return 0;
}

#define MAX_INPUT_CHARS 99
int gui_sample(void) {
  //---------------------------------------------------------------------------------
  // Initialization
  //---------------------------------------------------------------------------------
  const int screenWidth = 800;
  const int screenHeight = 450;
  InitWindow(screenWidth, screenHeight, "raylib [text] example - input box");
  // NOTE: One extra space required for line ending char '\0'
  char name[MAX_INPUT_CHARS + 1] = "\0";
  int letterCount = 0;
  Rectangle textBox = {(int)(screenWidth / 2) - 100, 180, 225, 50};
  bool mouseOnText = false;
  int framesCounter = 0;
  SetTargetFPS(0); // Set our game to run at 10 frames-per-second
  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    //-------------------------------------------------------------------------------
    // Update
    //-------------------------------------------------------------------------------
    mouseOnText = CheckCollisionPointRec(GetMousePosition(), textBox);
    if (mouseOnText) {
      // Set the window's cursor to the I-Beam
      SetMouseCursor(MOUSE_CURSOR_IBEAM);
      // Get char pressed (unicode character) on the queue
      int key = GetCharPressed();
      // Check if more characters have been pressed on the same frame
      while (key > 0) {
        // NOTE: Only allow keys in range [32..125]
        if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS)) {
          name[letterCount] = (char)key;
          letterCount++;
        }
        key = GetCharPressed(); // Check next character in the queue
      }
      if (IsKeyPressed(KEY_BACKSPACE)) {
        letterCount--;
        if (letterCount < 0)
          letterCount = 0;
        name[letterCount] = '\0';
      }
    } else
      SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    if (mouseOnText)
      framesCounter++;
    else
      framesCounter = 0;
    //-------------------------------------------------------------------------------
    // Draw
    //-------------------------------------------------------------------------------
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("PLACE MOUSE OVER INPUT BOX!", 240, 140, 20, GRAY);
    DrawRectangleRec(textBox, LIGHTGRAY);
    DrawRectangleLines(textBox.x, textBox.y, textBox.width, textBox.height,
                       mouseOnText ? RED : DARKGRAY);
    DrawText(name, textBox.x + 5, textBox.y + 8, 30, MAROON);
    DrawText(TextFormat("INPUT CHARS: %i/%i", letterCount, MAX_INPUT_CHARS),
             315, 250, 20, DARKGRAY);
    DrawText(TextFormat("fps: %i", GetFPS()), 315, 270, 40, DARKGRAY);
    if (mouseOnText) {
      if (letterCount < MAX_INPUT_CHARS) {
        // Draw blinking underscore char
        if (((framesCounter / 20) % 2) == 0)
          DrawText("_", textBox.x + 8 + MeasureText(name, 30), textBox.y + 12,
                   30, MAROON);
      } else
        DrawText("Press BACKSPACE to delete chars...", 230, 300, 20, GRAY);
    }
    EndDrawing();
  }
  //---------------------------------------------------------------------------------
  // De-Initialization
  //---------------------------------------------------------------------------------
  CloseWindow(); // Close window and OpenGL context
  return 0;
}
// Check if any key is pressed
// NOTE: We limit keys check to keys between 32 (KEY_SPACE) and 126
bool IsAnyKeyPressed() {
  bool keyPressed = false;
  int key = GetKeyPressed();
  if ((key >= 32) && (key <= 126))
    keyPressed = true;
  return keyPressed;
}
