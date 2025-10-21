// Slowing Apple Implementation File

#include "SlowingApple.h"

#include <deque>
#include <iostream>

#include "Fruit.h"
#include "Snake.h"
#include "raylib.h"

// Constructors-------------------------------------------------------------------
SlowingApple::SlowingApple(Color color, Vector2 position) {
  this->position = position;
  this->color = color;
  this->direction = {1, 0};
  this->lastMoveTime = 0;
  this->moveInterval = 0.5f;
}
SlowingApple::SlowingApple() {
  position = {18, 18};
  color = {0, 0, 255, 255};
  direction = {1, 0};
  lastMoveTime = 0;
  moveInterval = 0.5f;
}

// Behaviours--------------------------------------------------------------------
//  Getters----------------------------------------------------------------------
Color SlowingApple::getColor() { return color; }
Vector2 SlowingApple::getPosition() { return position; }

// Setters----------------------------------------------------------------------
void SlowingApple::setColor(Color color) { this->color = color; }
void SlowingApple::setPosition(Vector2 position) { this->position = position; }

// Drawing Object & Setting Object's
// Position---------------------------------------------------------------
void SlowingApple::draw(int cellSize) {
  DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize,
                cellSize, getColor());
  DrawCircle(position.x * cellSize + cellSize / 2,
             position.y * cellSize + cellSize / 2, cellSize / 4, WHITE);
}

Vector2 SlowingApple::GenerateRandomPos(int cellNum, const Snake& snake) {
  Vector2 position = GenerateRandomCell(cellNum);
  deque<Vector2> emptyDeque;
  while (elementInDeque(position, snake.getBody(), emptyDeque)) {
    position = GenerateRandomCell(cellNum);
  }
  return position;
}
