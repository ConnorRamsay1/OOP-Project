//Game Controller HEADER FILE

#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <deque>
#include <iostream>
#include <vector>

#include "Fruit.h"
#include "IncreaseLengthApple.h"
#include "SlowingApple.h"
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
  bool isRunning;

  Snake snake;
  vector<IncreaseLengthApple*> lengthApples;
  vector<SlowingApple*> slowApples;

  // Controls spawnRate of Apples
  int maxLengthApples;
  int maxSlowApples;
  double lastSpawnTime;
  float spawnRate;

  // Public
  // Attributes---------------------------------------------------------------------------------
 public:
  // Contructors--------------------------------------------------------------------------------------
  GameController();
  GameController(int score, Snake snake, bool running);

  // Behaviors-----------------------------------------------------------------------------------------
  // Getters
  int getCellSize();
  int getcellNum();
  float getInputCooldown();
  double getLastInputTime();
  int getScore();
  bool getisRunning();

  Snake getSnake();
  vector<IncreaseLengthApple*> getLengthApples();
  vector<SlowingApple*> getSlowApples();

  // Controls spawnRate of Apples
  int getMaxLengthApples();
  int getMaxSlowApples();
  double getLastSpawnTime();
  float getSpawnRate();

  // Setters--------------------------------------------------------------------------------------------
  void setScore(int score);
  void setCellSize(int size);
  void setCellNum(int num);
  void setInputCooldown(float coolDown);
  void setLastInputTime(double input);
  void setisRunning(bool isRunning);
  void setSnake(Snake snake);

  // Controls spawnRate of Apples
  void setLengthApples(vector<IncreaseLengthApple*> lengthApples);
  void setSlowApples(vector<SlowingApple*> SlowApples);
  void setMaxLengthApples(int maxLengthApples);
  void setMaxSlowApples(int maxSlowApples);
  void setLastSpawnTime(double lastSpawnTime);
  void setSpawnRate(float spawnRate);

  // Other
  // Functions----------------------------------------------------------------------------------------
  // Check Collisions
  void checkCollisionWithEdges(int cellCount);
  void checkCollisionWithHead();
  void checkCollisionWithLengthApple();
  void checkCollisionWithSlowApple();

  // Input Handling & User Interface
  void draw(int cellSize);
  void Update();
  void HandleInput(Vector2& direction);
  void GameOver(int cellNum);

  // Spawning Apples
  void spawnLengthApple();
  void spawnSlowApple();
  void updateAppleSpawning();
  void removeApples();

  // Destructor-----------------------------------------------------------------
  ~GameController();
};

#endif