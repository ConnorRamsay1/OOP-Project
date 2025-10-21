
#include <iostream>

#include "GameController.h"
#include "Snake.h"
#include "raylib.h"

using namespace std;

int main() {
  // Testing GameController Functions via terminal
  cout << "GameController Tests" << endl;

  // Testing Constructor
  GameController game;
  cout << "Initial score: " << game.getScore() << endl;
  cout << "Initial cell size: " << game.getCellSize() << endl;
  cout << "Initial cell num: " << game.getcellNum() << endl;

  // Test setters and getters
  game.setScore(10);
  if (game.getScore() == 10)
    cout << "Setters and Getters for Score ran SUCCESSFULLY\n\n";
  else
    cout << "Setters and Getters for Score ran UNSUCCESSFULLY\n\n ";

  game.setCellSize(40);
  if (game.getCellSize() == 40) {
    cout << "Setters and Getters for cellSize ran SUCCESSFULLY\n\n";
  } else {
    cout << "Setters and Getters for cellSize ran UNSUCCESSFULLY\n\n";
  }

  game.setInputCooldown(0.25f);
  if (game.getInputCooldown() == 0.25f) {
    cout << "Setters and Getters for inputCooldown ran SUCCESSFULLY\n\n";
  } else {
    cout << "Setters and Getters for inputCooldown ran SUCCESSFULLY\n\n";
  }

  // Test apple spawn
  cout << "Spawning apples and bananas" << endl;
  game.spawnLengthApple();
  game.spawnSlowApple();
  game.spawnDecreaseBanana();

  cout << "Length apples: " << game.getLengthApples().size() << endl;
  cout << "Slow apples: " << game.getSlowApples().size() << endl;
  cout << "Bananas: " << game.getDecreaseBananas().size() << "\n\n";

  // Test reset
  cout << "Testing Resseting Game\n";
  game.resetGame();
  cout << "After reset, score = " << game.getScore() << endl;
  cout << "After reset, isRunning = " << game.getisRunning() << endl;
  if((game.getScore() == 0) &&(game.getisRunning())){
    cout<<"resetGame() Ran SUCCESSFULLY\n";
}else{
    cout << "resetGame() Ran UNSUCCESSFULLY\n";
}
  

  cout << "\nTests Finished\n\n" << endl;

  // Testing 2D implementation of GameController Functions

  int screenWidth = 600;
  int screenHeight = 600;
  InitWindow(screenWidth, screenHeight, "GameController 2D Test");

  GameController controller;
  Vector2 direction = {1, 0};
  SetTargetFPS(10);

  while (!WindowShouldClose()) {
    controller.HandleInput(direction);
    controller.Update();

    BeginDrawing();
    ClearBackground(DARKGREEN);

    controller.draw(controller.getCellSize());

    DrawText(TextFormat("Score: %i", controller.getScore()), 10, 10, 20, WHITE);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
