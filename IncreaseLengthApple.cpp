// Increase Length Apple HEADER FILE

#include "IncreaseLengthApple.h"

#include <deque>
#include <iostream>

#include "Fruit.h"
#include "Snake.h"
#include "raylib.h"

class SlowingApple;  // Just tells the compiler SlowingApple exists

using namespace std;

// Constructors------------------------------------------------------------------------------------
IncreaseLengthApple::IncreaseLengthApple(Color color, Vector2 position) {
  this->position = position;
  this->color = color;
}
IncreaseLengthApple::IncreaseLengthApple() {
  position = {6, 6};
  color = {255, 0, 0, 255};
}

// Behaviours--------------------------------------------------------------------------------------

// Getters--------------------------------------------------------------------------------------
Color IncreaseLengthApple::getColor() { return color; }
Vector2 IncreaseLengthApple::getPosition() { return position; }

// Setters--------------------------------------------------------------------------------------
void IncreaseLengthApple::setColor(Color color) { this->color = color; }
void IncreaseLengthApple::setPosition(Vector2 position) {
  this->position = position;
}

// Drawing and Setting lengthApple's
// Position----------------------------------------------------------------------------

void IncreaseLengthApple::draw(int cellSize) {
  DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize,
                cellSize, getColor());
}

Vector2 IncreaseLengthApple::GenerateRandomPos(int cellNum,
                                               const Snake& snake) {
  Vector2 position = GenerateRandomCell(cellNum);
  deque<Vector2> emptyDeque;
  while (elementInDeque(position, snake.getBody(), emptyDeque)) {
    position = GenerateRandomCell(cellNum);
  }
  return position;
}
