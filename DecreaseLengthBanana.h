#ifndef DECREASELENGTHBANANA_H
#define DECREASELENGTHBANANA_H

#include <deque>
#include <iostream>

#include "Fruit.h"
#include "raylib.h"
#include "Banana.h"

using namespace std;

class SlowingApple;


class DecreaseLengthBanana : public Banana{
private:
int _DecreaseAmount;

public:
 // Constructors-------------c-------------------------------------------------------------------------------------
  DecreaseLengthBanana();
  DecreaseLengthBanana(Color color1,Color color2, Vector2 position, int _DecreaseAmount);

  // Behaviours--------------------------------------------------------------------------------------------------
  // Getters--------------------------------------------------------------------------------------------------
  int getDecreaseAmount();
  Vector2 getPosition() override;

  // Setters--------------------------------------------------------------------------------------------------
  void setDecreaseAmount(int _DecreaseAmount);  
  void setPosition(Vector2 position) override;

  // Drawing Object & Generating Object Position
  void draw(int cellSize) override;
  Vector2 GenerateRandomPos(int cellNum, const Snake& snake) override;
};

#endif