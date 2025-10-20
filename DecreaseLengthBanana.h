#ifndef DECREASELENGTHBANANA_H
#define DECREASELENGTHBANANA_H

#include <deque>
#include <iostream>

#include "Fruit.h"
#include "raylib.h"
#include "Banana.h"

using namespace std;

class SlowingApple;


class DecreaseLengthBanana : public virtual Fruit, public Banana{
private:
int _DecreaseAmount;

public:
 // Constructors--------------------------------------------------------------------------------------------------
  DecreaseLengthBanana();
  DecreaseLengthBanana(Color color, Vector2 position, int );

  // Behaviours--------------------------------------------------------------------------------------------------
  // Getters--------------------------------------------------------------------------------------------------
  Color getColor() override;
  Vector2 getPosition() override;
  int getDecreaseAmount(int _DecreaseAmount);

  // Setters--------------------------------------------------------------------------------------------------
  void setColor(Color color) override;
  void setPosition(Vector2 position) override;
  void setDecreaseAmount(int _DecreaseAmount);

  // Drawing Object & Generating Object Position
  void draw(int cellSize) override;
  Vector2 GenerateRandomPos(int cellNum, Snake snake) override;
  void DecreaseLength(int _DecreaseAmount);
};

#endif