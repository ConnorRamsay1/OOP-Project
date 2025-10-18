

// GameController Implementation File
#include <deque>
#include <iostream>

#include "GameController.h"
#include "Food.h"
#include "Snake.h"
#include "raylib.h"

using namespace std;

// Contructors----------------------------------------------------------------------------------------------
GameController::GameController() {
  Snake snake;
  Food food;
  lastInputTime = 0;
  inputCooldown = 0.135f;
  cellNum = 25;
  cellSize = 30;
  running = true;
  score = 0;
}
GameController::GameController(int score, Snake snake, Food food,
                               bool running) {
  this->score = score;
  this->snake = snake;
  this->food = food;
  this->inputCooldown = inputCooldown;
  this->lastInputTime = lastInputTime;
  this->running = running;
  lastInputTime = 0;
  inputCooldown = 0.135f;
  cellNum = 25;
  cellSize = 30;
}

// Behaviours--------------------------------------------------------------------------------------------


// Getters
int GameController::getcellNum() { return cellNum; }
int GameController::getCellSize() { return cellSize; }
int GameController::getScore() { return score; }
float GameController::getInputCooldown() { return inputCooldown; }
double GameController::getLastInputTime() { return lastInputTime; }

//Setters
void GameController::setScore(int score) {
  this->score = score;
  return;
}
void GameController::setCellSize(int size) {
  this->cellSize = size;
  return;
}
void GameController::setCellNum(int num) {
  this->cellNum = num;
  return;
}
void GameController::setInputCooldown(float coolDown) {
  this->inputCooldown = coolDown;
  return;
}
double GameController::setLastInputTime(double input) {
  this->lastInputTime = input;
  return;
}

//Other Functions
void GameController::draw(int cellSize) {
  food.draw(cellSize);
  snake.draw(cellSize);
}

void GameController::Update() {
  if (running == true) {
    snake.Update();
    checkCollisionWithFood();
    checkCollisionWithEdges(cellNum);
    checkCollisionWithHead();
  }
}

void GameController::checkCollisionWithEdges(int cellNum) {
  if (snake.getBody()[0].x == cellNum || snake.getBody()[0].x == -1) {
    GameOver(cellNum);
  }
  if (snake.getBody()[0].y == cellNum || snake.getBody()[0].y == -1) {
    GameOver(cellNum);
  }
}

void GameController::GameOver(int cellNum) {
  snake.Reset();
  food.GenerateRandomPos(cellNum, snake);
  running = false;
  score = 0;
}

void GameController::checkCollisionWithFood() {
  if ((snake.getBody()[0].x == food.getPosition().x) &&
      (snake.getBody()[0].y == food.getPosition().y)) {
    food.setPosition(food.GenerateRandomPos(cellNum, snake));
    snake.setAddSegment(true);
    score = score + 1;
  }
}

void GameController::HandleInput(Vector2& direction) {
  double currentTime = GetTime();  // stores last time a key was pressed
  // Only accept input if cooldown time has passed
  if (currentTime - lastInputTime >= inputCooldown) {
    if (IsKeyPressed(KEY_UP) && direction.y != 1) {
      direction = {0, -1};
      snake.setDirection(direction);
      lastInputTime = currentTime;  // reset cooldown timer
      running = true;
    } else if (IsKeyPressed(KEY_DOWN) && direction.y != -1) {
      direction = {0, 1};
      snake.setDirection(direction);
      lastInputTime = currentTime;
      running = true;
    } else if (IsKeyPressed(KEY_LEFT) && direction.x != 1) {
      direction = {-1, 0};
      snake.setDirection(direction);
      lastInputTime = currentTime;
      running = true;
    } else if (IsKeyPressed(KEY_RIGHT) && direction.x != -1) {
      direction = {1, 0};
      snake.setDirection(direction);
      lastInputTime = currentTime;
      running = true;
    }
  }
}

void GameController::checkCollisionWithHead() {
  for (int i = 1; i < snake.getBody().size(); i++) {
    if ((snake.getBody()[0].x == snake.getBody()[i].x) &&
        (snake.getBody()[0].y == snake.getBody()[i].y)) {
      GameOver(cellNum);
      return;
    }
  }
  return;
}

//--------------------------------------------------------------------------------------------------------