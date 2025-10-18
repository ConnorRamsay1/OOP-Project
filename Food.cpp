
#include "Food.h"
#include "Snake.h"
#include <deque>
#include <iostream>


using namespace std;

// Constructors------------------------------------------------------------------------------------
Food::Food(Color color, Vector2 position) {
  this->position = position;
  this-> color = color;
}

Food::Food(){
    position = {6,6};
    color = { 255, 0, 0, 255 };
}

// Behaviours--------------------------------------------------------------------------------------

//Getters--------------------------------------------------------------------------------------
    Color Food::getColor(){
        return color;
    }
    Vector2 Food::getPosition(){
        return position;
    }


//Setters--------------------------------------------------------------------------------------
    void Food::setColor(Color color){
        this-> color = color;
    }
    void Food::setPosition(Vector2 position){
        this-> position = position;
    }



//User Interface & Interaction

void Food::draw(int cellSize) {
  DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize,
                cellSize, getColor());
}

bool Food::elementInDeque(Vector2 position, deque<Vector2> deque) {
  for (int i = 0; i < deque.size(); i++) {
    if((deque[i].x == position.x) && (deque[i].y == position.y)){
      return true;
    }
  }
  return false;
}

Vector2 Food::GenerateRandomCell(int cellNum) {
  float x = GetRandomValue(0, cellNum - 1);
  float y = GetRandomValue(0, cellNum - 1);
  return Vector2{x, y};
}

Vector2 Food::GenerateRandomPos(int cellNum, Snake snake) {
  Vector2 position = GenerateRandomCell(cellNum);
  while (elementInDeque(position, snake.getBody())) {
    position = GenerateRandomCell(cellNum);
  }
  return position;
}

