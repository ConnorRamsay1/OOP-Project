// SNAKE CLASS HEADER FILE

#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include <iostream>
#include "raylib.h"

using namespace std;

class Snake {
  // Private
  // Attributes---------------------------------------------------------------------------------
 private:
  deque<Vector2> body;
  Vector2 direction;
  bool addSegment;
  Color color;
  bool PushBack;

  // For slowed Effect
  bool isSlowed;
  double slowEffectTime;
  float normalSpeed;
  float slowedSpeed;

 public:
  // Contructors------------------------------------------------------------------------------------------
  Snake(deque<Vector2> body, Vector2 direction, bool addSegment, Color color,
        bool isSlowed, double slowEffectTime, float normalSpeed,
        float slowedSpeed);
  Snake();

  // Behaviours----------------------------------------------------------------------------------------------
  // Getters
  Vector2 getDirection();
  bool getAddSegment();
  Color getColor();
  const deque<Vector2>& getBody();
  bool getIsSlowed();

  // Setters
  void setColor(Color color);
  void setAddSegment(bool addSegment);
  void setDirection(Vector2 direction);
  void setBody(deque<Vector2> body);
  void setIsSlowed(bool isSlowed);

  // User
  // Interface----------------------------------------------------------------------------------------------
  void draw(int cellSize);
  void Update();
  void Reset();

  // Effects from Slow Apple
  void applySlowEffect(float duration);
  void updateSlowApple();

  // Destructor----------------------------------------------------------------------------------------------
  ~Snake();
};

#endif
