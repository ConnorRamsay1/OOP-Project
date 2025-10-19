#ifndef INCREASELENGTHAPPLE_H
#define INCREASELENGTHAPPLE_H

#include <deque>
#include <iostream>

#include "Fruit.h"
#include "raylib.h"

class SlowingApple;

using namespace std;

class IncreaseLengthApple : public Fruit {
 public:
  // Constructors--------------------------------------------------------------------------------------------------
  IncreaseLengthApple();
  IncreaseLengthApple(Color color, Vector2 position);

  // Behaviours--------------------------------------------------------------------------------------------------
  // Getters--------------------------------------------------------------------------------------------------
  Color getColor() override;
  Vector2 getPosition() override;

  // Setters--------------------------------------------------------------------------------------------------
  void setColor(Color color) override;
  void setPosition(Vector2 position) override;

  // Drawing Object & Generating Object Position
  void draw(int cellSize) override;
  Vector2 GenerateRandomPos(int cellNum, Snake snake) override;
};

#endif