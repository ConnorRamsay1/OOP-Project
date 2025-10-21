// Slowing Appple HEADER FILE

#ifndef SLOWINGAPPLE_H
#define SLOWINGAPPLE_H

#include <deque>
#include <iostream>

#include "Fruit.h"
#include "raylib.h"

class IncreaseLengthApple;

class SlowingApple : public Fruit {
 private:
  Vector2 direction;
  double lastMoveTime;
  float moveInterval;

 public:
  // Constructors--------------------------------------------------------------------------------------------------
  SlowingApple();
  SlowingApple(Color color, Vector2 position);

  // Behaviours--------------------------------------------------------------------------------------------------
  // Getters--------------------------------------------------------------------------------------------------
  Color getColor() override;
  Vector2 getPosition() override;

  // Setters--------------------------------------------------------------------------------------------------
  void setColor(Color color) override;
  void setPosition(Vector2 position) override;

  // Drawing Object & Setting Object Position
  void draw(int cellSize) override;
  Vector2 GenerateRandomPos(int cellNum, const Snake& snake) override;
};

#endif