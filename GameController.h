
#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include <deque>
#include <iostream>
#include "raylib.h"
#include "Food.h"
#include "Snake.h"

using namespace std;

class GameController {
 private:
  int cellSize;
  int cellNum;
  float inputCooldown;
  double lastInputTime;
  int score;

 public:
  // Attributes
  Snake snake;
  Food food;
  bool running;

  // Contructors
  GameController();
  GameController(int score, Snake snake, Food food, bool running);

  // Behaviors
  int getScore();
  int getCellSize();
  int getcellNum();
  void setScore(int score);
  
  void draw(int cellSize);

  void Update();

  void checkCollisionWithEdges(int cellCount);

  void GameOver(int cellNum);

  void checkCollisionWithFood();

  void HandleInput(Vector2 &direction);

  void checkCollisionWithHead();
};

#endif