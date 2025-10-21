// Main Game Loop

#include <deque>
#include <iostream>

#include "Fruit.h"
#include "GameController.h"
#include "Snake.h"
#include "TitlePage.h"
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

  // Create game window (25x25 grid, 30px cells = 750x750 window)
  const int screenWidth = 750;
  const int screenHeight = 750;
  InitWindow(screenWidth, screenHeight, "Snake Game");
  SetTargetFPS(60);

  // Initialising Game State
  GameState currentState = TITLE;
  TitlePage titlePage(screenWidth, screenHeight);
  // Initialize game controller
  GameController game;

  int finalScore = 0;
  bool isHighScore = false;

  //===========================================================================
  // MAIN GAME LOOP
  //===========================================================================
  while (WindowShouldClose() == false) {
    BeginDrawing();

    // Wiping Background
    ClearBackground(green);

    if (currentState == TITLE) {
      titlePage.drawTitleScreen();
      currentState = titlePage.handleTitleInput(currentState);
      if (currentState == PLAY) {
        game = GameController();  // Resets Game
        lastUpdateTime = GetTime();
      }

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

    } else if (currentState == PLAY) {
      float baseSpeed = titlePage.getDifficultySpeed();

      // Adjust game speed based on slow effect
      // Slowed: 0.3s between updates, Normal: 0.1s
      if (game.getSnake().getIsSlowed()) {
        updateInterval = baseSpeed * 2.0f;
      } else {
        updateInterval = baseSpeed;
      }

      // Update game logic
      double currentTime = GetTime();
      if (currentTime - lastUpdateTime >= updateInterval) {
        game.Update();  // Move snake, check collisions, update apples
        lastUpdateTime = currentTime;
      }
      // checking if length of snake is zero
      if (game.getSnake().getBody().size() == 0) {
        game.setisRunning(false);
      }

      // Check if Game over
      if (!game.getisRunning()) {
        finalScore = game.getScore();
        isHighScore = titlePage.getScoreboard().isHighScore(finalScore);
        currentState = GAME_OVER;
      }

      // Handle player input
      Vector2 tempDirection = game.getSnake().getDirection();
      game.HandleInput(tempDirection);

      // Draw UI elements
      DrawText("SNAKE GAME", 20, 40, 20, darkGreen);
      DrawText(TextFormat("Score: %i", game.getScore()), 600, 40, 30,
               darkGreen);

      // Show slow effect indicator
      if (game.getSnake().getIsSlowed()) {
        DrawText("SLOWED!", 20, 60, 25, BLUE);
      }

      // Draw game objects (snake and apples and bananas)
      game.draw(game.getCellSize());

      // T pauses/returns to menu
      if (IsKeyPressed(KEY_T)) {
        currentState = TITLE;
      }
    } else if (currentState == GAME_OVER) {
      titlePage.drawGameOverScreen(finalScore, isHighScore);

      // If high score, go to name entry
      if (IsKeyPressed(KEY_ENTER)) {
        if (isHighScore) {
          currentState = ENTER_NAME;
        } else {
          game = GameController();  // Reset game
          lastUpdateTime = GetTime();
          currentState = PLAY;
        }
      }

      if (IsKeyPressed(KEY_T)) {
        currentState = TITLE;
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