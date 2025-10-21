
// Fruit PARENT CLASS HEADER FILE

#ifndef FRUIT_H
#define FRUIT_H

#include <deque>
#include <iostream>

#include "raylib.h"

class Snake;

using namespace std;

class Fruit {
  // Protected
  // Attributes-----------------------------------------------------------------------------------------
 protected:
  // Attributes
  Vector2 position;
  Color color;

  // Behaviours--------------------------------------------------------------------------------------------------

  // Constructors--------------------------------------------------------------------------------------------------
  Fruit();
  Fruit(Color color, Vector2 position);

  // Behaviours--------------------------------------------------------------------------------------------------

  // Getters--------------------------------------------------------------------------------------------------
  virtual Color getColor();
  virtual Vector2 getPosition();

  // Setters--------------------------------------------------------------------------------------------------
  virtual void setColor(Color color);
  virtual void setPosition(Vector2 position);

  // User Interface & Interaction
  virtual bool elementInDeque(Vector2 element, deque<Vector2> deque1,
                              deque<Vector2> deque2);
  virtual void draw(int cellSize) = 0;
  virtual Vector2 GenerateRandomCell(int cellNum);
  virtual Vector2 GenerateRandomPos(int cellNum, const Snake& snake) = 0;
};

#endif