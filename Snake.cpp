//Snake Implementation File

#include <deque>
#include <iostream>

#include "Snake.h"

using namespace std;

// Constructors----------------------------------------------------------------------------------------------
Snake::Snake(deque<Vector2> body, Vector2 direction, bool addSegment,
             Color color, bool isSlowed, double slowEffectTime,
             float normalSpeed, float slowedSpeed, bool subtractSegment) {
  this->body = body;
  this->direction = direction;
  this->addSegment = addSegment;
  this->color = color;
  this->isSlowed = isSlowed;
  this->slowEffectTime = slowEffectTime;
  this->normalSpeed = normalSpeed;
  this->slowedSpeed = slowedSpeed;
  this->subtractSegment = subtractSegment;
}
Snake::Snake() {
  this->body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
  this->direction = {1, 0};
  this->addSegment = false;
  this->subtractSegment = false;
  this->color = {0, 100, 0, 255};
  this->isSlowed = false;
  this->slowEffectTime = 0;
  this->normalSpeed = 0.1f;
  this->slowedSpeed = 0.3f;
}

// Behaviours----------------------------------------------------------------------------------------------
// Getters
Color Snake::getColor() { return color; }
bool Snake::getAddSegment() { return addSegment; }
bool Snake::getSubtractSegment() {return subtractSegment; }
Vector2 Snake::getDirection() { return direction; }
const deque<Vector2>& Snake::getBody() { return body; }
bool Snake::getIsSlowed() { return isSlowed; }

// Setters
void Snake::setColor(Color color) {
  this->color = color;
  return;
}
void Snake::setAddSegment(bool addSegment) {
  this->addSegment = addSegment;
  return;
}
void Snake::setDirection(Vector2 direction) {
  this->direction = direction;
  return;
}
void Snake::setBody(deque<Vector2> body) {
  this->body = body;
  return;
}
void Snake::setIsSlowed(bool isSlowed) {
  this->isSlowed = isSlowed;
  return;
}
void Snake::setSubtractSegment(bool subtractSegment){
  this->subtractSegment = subtractSegment;
}
// User Interface and
// Interactions----------------------------------------------------------------------------

void Snake::draw(int cellSize) {
  for (int i = 0; i < body.size(); i++) {
    int x = body[i].x;
    int y = body[i].y;
    if (i == 0 && !isSlowed) {  // Changes colour of head
      color = {0, 150, 0, 255};
      DrawRectangle(x * cellSize, y * cellSize, cellSize, cellSize, color);
    } else if (i == 0 && isSlowed) {
      color = {70, 100, 255, 255};
      DrawRectangle(x * cellSize, y * cellSize, cellSize, cellSize, color);
    } else {
      if (!isSlowed) {  // Changes Color of Snake
        color = {0, 100, 0, 255};
      } else {
        color = {50, 60, 90, 255};
      }
      DrawRectangle(x * cellSize, y * cellSize, cellSize, cellSize, color);
    }
  }
}

void Snake::Update() {
  Vector2 newHead = {(body[0].x + direction.x), (body[0].y + direction.y)};
  if (addSegment == true) {
    body.push_front(newHead);
    addSegment = false;
  } else {
    body.pop_back();
    body.push_front(newHead);
  }
  if(subtractSegment == true){
    body.pop_back();
    PushBack = false;
  }


}

void Snake::Reset() {
  body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
  direction = {1, 0};
  isSlowed = false;
}

// Effect from Slow Apple
void Snake::applySlowEffect(float duration) {
  isSlowed = true;
  slowEffectTime = GetTime() + duration;
}
void Snake::updateSlowApple() {
  if (isSlowed && GetTime() >= slowEffectTime) {
    isSlowed = false;
  }
}
// Destructor----------------------------------------------------------------------------------------------
Snake::~Snake() {}
