// Main Game Loop

#include <deque>
#include <iostream>

#include "Fruit.h"
#include "GameController.h"
#include "Snake.h"
#include "raylib.h"

using namespace std;

// Background + Text Colours
Color green = {173, 204, 96, 255};
Color darkGreen = {43, 51, 24, 255};

// Game Timing Variables
double lastUpdateTime = 0;
float updateInterval;

//=============================================================================
// MAIN PROGRAM
//=============================================================================

int main(void) {
  cout << "Game loading...." << endl;

  // Initialize game controller
  GameController game;

  // Create game window (25x25 grid, 30px cells = 750x750 window)
  InitWindow(game.getCellSize() * game.getcellNum(),
             game.getCellSize() * game.getcellNum(), "Snake");
  SetTargetFPS(60);

  //===========================================================================
  // MAIN GAME LOOP
  //===========================================================================
  while (WindowShouldClose() == false) {
    BeginDrawing();

    // Adjust game speed based on slow effect
    // Slowed: 0.3s between updates, Normal: 0.1s
    if (game.getSnake().getIsSlowed()) {
      updateInterval = 0.3f;
    } else {
      updateInterval = 0.1f;
    }

    // Update game logic
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= updateInterval) {
      game.Update();  // Move snake, check collisions, update apples
      lastUpdateTime = currentTime;
    }

    // Handle player input
    Vector2 tempDirection = game.getSnake().getDirection();
    game.HandleInput(tempDirection);

    // Drawing
    ClearBackground(green);

    // Draw UI elements
    DrawText("SNAKE GAME", 20, 40, 20, darkGreen);
    DrawText(TextFormat("Score: %i", game.getScore()), 600, 40, 30, darkGreen);

    // Show slow effect indicator
    if (game.getSnake().getIsSlowed()) {
      DrawText("SLOWED!", 20, 60, 25, BLUE);
    }

    // Draw game objects (snake and apples)
    game.draw(game.getCellSize());


    EndDrawing();
  }

  // Cleanup and close window
  CloseWindow();
  return 0;
}