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
  
 public:

 // Contructors------------------------------------------------------------------------------------------
  Snake(deque<Vector2> body, Vector2 direction, bool addSegment, Color color);
  Snake();

  // Behaviours----------------------------------------------------------------------------------------------
  // Getters
  Vector2 getDirection();
  bool getAddSegment();
  Color getColor();
  const deque<Vector2>& getBody();

  // Setters
  void setColor(Color color);
  void setAddSegment(bool addSegment);
  void setDirection(Vector2 direction);
  void setBody(deque<Vector2> body);

  // User
  // Interface----------------------------------------------------------------------------------------------
  void draw(int cellSize);
  void Update();
  void Reset();

  // Destructor----------------------------------------------------------------------------------------------
  ~Snake();
};

#endif
