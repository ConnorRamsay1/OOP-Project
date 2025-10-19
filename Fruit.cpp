//Fruit Implementation File

#include <deque>
#include <iostream>

#include "Fruit.h"
#include "raylib.h"


//Getters---------------------------------------------------------------
Color Fruit::getColor() { return color; }
Vector2 Fruit::getPosition() { return position; }

//Setters---------------------------------------------------------------
void Fruit::setColor(Color color) { this->color = color; }
void Fruit::setPosition(Vector2 position) {
  this->position = position;
}

//Other Behaviours---------------------------------------------------------------
// Searching elements in deques
bool Fruit::elementInDeque(Vector2 position, deque<Vector2> deque1, deque<Vector2> deuqe2) {
  for (int i = 0; i < deque1.size(); i++) {
    if((deque1[i].x == position.x) && (deque1[i].y == position.y)){
      return true;
    }
  }
    for (int i = 0; i < deuqe2.size(); i++) {
    if((deuqe2[i].x == position.x) && (deuqe2[i].y == position.y)){
      return true;
    }
  }
  return false;
}

//Generating Random Points for Objects to Spawn
Vector2 Fruit::GenerateRandomCell(int cellNum) {
  float x = GetRandomValue(0, cellNum - 1);
  float y = GetRandomValue(0, cellNum - 1);
  return Vector2{x, y};
}