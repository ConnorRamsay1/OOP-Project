#include "testTitlePage.h"

int main() {
  // Testing Fucntions in TitlePage via terminal
  TestTitlePage test;
  test.runTests();

  // Testing 2D Implementation of Title Page

  InitWindow(800, 600, "TitlePage Visual Test");
  SetTargetFPS(60);

  TitlePage testPage(800, 600);

  while (!WindowShouldClose()) {
    BeginDrawing();
    testPage.drawTitleScreen();  // Try swapping with drawRulesScreen(), etc.
    EndDrawing();
  }

  CloseWindow();

  return 0;
}