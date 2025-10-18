
// FOOD PARENT CLASS

#ifndef FOOD_H
#define FOOD_H

#include <deque>
#include <iostream>

#include "raylib.h"

class Snake;

using namespace std;

class Food {
  // Protected
  // Attributes-----------------------------------------------------------------------------------------
 protected:
  // Attributes
  Vector2 position;
  Color color;

 public:
  // Behaviours--------------------------------------------------------------------------------------------------

  // Constructors--------------------------------------------------------------------------------------------------
  Food();
  Food(Color color, Vector2 position);

  // Behaviours--------------------------------------------------------------------------------------------------
  
  // Getters--------------------------------------------------------------------------------------------------
  Color getColor();
  Vector2 getPosition();

  // Setters--------------------------------------------------------------------------------------------------
  void setColor(Color color);
  void setPosition(Vector2 position);

  // User Interface & Interaction
  void draw(int cellSize);
  bool elementInDeque(Vector2 element, deque<Vector2> deque);
  Vector2 GenerateRandomCell(int cellNum);
  Vector2 GenerateRandomPos(int cellNum, Snake snake);
};

#endif