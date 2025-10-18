#include "Snake.h"
#include <deque>
#include <iostream>


using namespace std;

    Vector2 Snake::getDirection(){
        return direction;
    }
    const deque<Vector2>& Snake::getBody(){
        return body;
    }
    Color Snake::getColor(){
        return color;
    }
    bool Snake::getAddSegment(){
        return addSegment;
    }
    void Snake:: setColor(Color color){
        this->color = color;
        return;
    }
    void Snake::setAddSegment(bool addSegment){
        this->addSegment = addSegment;
        return;
    }
    void Snake::setDirection(Vector2 direction){
        this->direction = direction;
        return;
    }
    void Snake::setBody(deque<Vector2> body){
        this->body = body;
        return;
    }


Snake::Snake(deque<Vector2> body, Vector2 direction, bool addSegment, Color color){
    this-> body = body;
    this-> direction = direction;
    this-> addSegment = addSegment;
    this-> color = color;

}
Snake::Snake(){
    this-> body = {Vector2{6,9}, Vector2{5,9}, Vector2{4,9}};
    this-> direction = {1,0};
    this-> addSegment = false; 
    this-> color = {43, 51, 24, 255};
    
}

void Snake::draw(int cellSize) {
  for (int i = 0; i < body.size(); i++) {
    int x = body[i].x;
    int y = body[i].y;
    DrawRectangle(x * cellSize, y * cellSize, cellSize, cellSize, color);
  }
}

void Snake::Update() {
  Vector2 newHead = {(body[0].x + direction.x),(body[0].y + direction.y)};
  if (addSegment == true) {
    body.push_front(newHead);
    addSegment = false;
  } else {
    body.pop_back();
    body.push_front(newHead);
  }
}

void Snake::Reset() {
  body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
  direction = {1, 0};
}

Snake::~Snake(){

}