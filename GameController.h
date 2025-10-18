
#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include <deque>
#include <iostream>

#include "Food.h"
#include "Snake.h"
#include "raylib.h"

using namespace std;

class GameController {
 private:
  // Private
  // Attributes---------------------------------------------------------------------------------
  int cellSize;
  int cellNum;
  float inputCooldown;
  double lastInputTime;
  int score;

  // Public
  // Attributes---------------------------------------------------------------------------------
 public:
  Snake snake;
  Food food;
  bool running;

  // Contructors--------------------------------------------------------------------------------------
  GameController();
  GameController(int score, Snake snake, Food food, bool running);

  // Behaviors-----------------------------------------------------------------------------------------
  // Getters
  int getScore();
  int getCellSize();
  int getcellNum();
  float getInputCooldown();
  double getLastInputTime();

  // Setters--------------------------------------------------------------------------------------------
  void setScore(int score);
  void setCellSize(int size);
  void setCellNum(int num);
  void setInputCooldown(float coolDown);
  double setLastInputTime(double input);

  // Other
  // Functions----------------------------------------------------------------------------------------
  // Collisions
  void checkCollisionWithEdges(int cellCount);
  void checkCollisionWithHead();
  void checkCollisionWithFood();

  // Input Handling & User Interface

  void draw(int cellSize);
  void Update();
  void HandleInput(Vector2& direction);
  void GameOver(int cellNum);
};

#endif