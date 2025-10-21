
// Main Game Loop

#include <deque>
#include <iostream>

#include "TitlePage.h"
#include "raylib.h"

using namespace std;

int main(void) {
  cout << "Game loading...." << endl;

  // Create game window (25x25 grid, 30px cells = 750x750 window)
  int screenWidth = 750;
  int screenHeight = 750;
  InitWindow(screenWidth, screenHeight, "Snake Game");
  SetTargetFPS(60);

  // Initialising Game State
  GameState currentState = GAME_OVER;
  TitlePage titlePage(screenWidth, screenHeight);

  // Testing Game Over and Enter_Name Pages -------------------------
  while (WindowShouldClose() == false) {
    BeginDrawing();

    // Wiping Background
    ClearBackground(RAYWHITE);

    int finalScore = 200;
    bool isHighScore =
        true;  //--------------------> Ensures testing of ENTER_NAME PAGE

    if (currentState == TITLE) {
      titlePage.drawTitleScreen();
      currentState = titlePage.handleTitleInput(currentState);
    } else if (currentState == GAME_OVER) {
      titlePage.drawGameOverScreen(finalScore, isHighScore);

      // If high score, go to name entry
      if (IsKeyPressed(KEY_ENTER)) {
        if (isHighScore) {
          currentState = ENTER_NAME;
          std::cout
              << "SUCCESSFULLY ADDED AND SAVED HIGH SCORES TO SCOREBOARD\n";
        } else {
          currentState = PLAY;
          std::cout << "SUCCESSFULLY NAVIGATED TO PLAY SECTION OF GAME\n";
        }
      }
      //Navigating To Title Page
      if (IsKeyPressed(KEY_T)) {
        currentState = TITLE;
        std::cout << "SUCCESSFULLY NAVIGATED TO TITLE PAGE OF GAME\n";
      }
      
    } else if (currentState == ENTER_NAME) {
      titlePage.drawNameEntryScreen(finalScore);
      currentState = titlePage.handleNameEntry(currentState, finalScore);
    }
    EndDrawing();
  }

  CloseWindow();
  return 0;
}