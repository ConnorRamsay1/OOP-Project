#include <iostream>

#include "Scoreboard.h"
#include "TitlePage.h"

int main(void) {
  std::cout << "Game loading...." << std::endl;

  // Create game window (25x25 grid, 30px cells = 750x750 window)
  int screenWidth = 750;
  int screenHeight = 750;
  InitWindow(screenWidth, screenHeight, "Snake Game");
  SetTargetFPS(10);

  // Initialising Game State
  GameState currentState = TITLE;
  TitlePage titlePage(screenWidth, screenHeight);


  // Testing Basic Navigation Through Title Pages
  while (WindowShouldClose() == false) {
    BeginDrawing();

    // Wiping Background
    ClearBackground(RAYWHITE);

    if (currentState == TITLE) {
      titlePage.drawTitleScreen();
      currentState = titlePage.handleTitleInput(currentState);

    } else if (currentState == RULES) {
      titlePage.drawRulesScreen();
      currentState = titlePage.handlePageInput(currentState);

    } else if (currentState == SCOREBOARD) {
      titlePage.drawScoreboardScreen();
      currentState = titlePage.handlePageInput(currentState);

    } else if (currentState == DIFFICULTY) {
      titlePage.drawDifficultyScreen();
      currentState = titlePage.handleDifficultyInput(currentState);
      currentState = titlePage.handlePageInput(currentState);
    }
    EndDrawing();
  }

  CloseWindow();

  return 0;
}