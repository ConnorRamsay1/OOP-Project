#include "DecreaseLengthBanana.h"
#include "Fruit.h"
#include "GameController.h"
#include "Snake.h"
#include <iostream>
#include <deque>
#include <cmath>
#include "Snake.h"

// Constructors
DecreaseLengthBanana::DecreaseLengthBanana() {
    position = {10, 10};
    _bananaYellow = YELLOW;
    _bananaOutline = BLACK;
    _DecreaseAmount = 2;
}

DecreaseLengthBanana::DecreaseLengthBanana(Color color1,Color color2, Vector2 position, int _DecreaseAmount) {
    this->_bananaYellow = color1;
    this->_bananaOutline = color2;
    this->position = position;
    this->_DecreaseAmount = _DecreaseAmount;

}

// Getters-------------------------------------------
int DecreaseLengthBanana::getDecreaseAmount() { return _DecreaseAmount; }
Vector2 DecreaseLengthBanana::getPosition(){ return position;}
// Setters-----------------------------------------
void DecreaseLengthBanana::setDecreaseAmount(int  _DecreaseAmount) { this->_DecreaseAmount =  _DecreaseAmount; }
void DecreaseLengthBanana::setPosition(Vector2 position) {this->position = position;}


// Draw
void DecreaseLengthBanana::draw(int cellSize) {
     //DrawRectangle(screenPos.x - cellSize/2, screenPos.y - cellSize/2, cellSize, cellSize, YELLOW);
     setInsideColour({255, 235, 59, 255});
     setOutsideColour({218, 165, 32, 255});
   Vector2 screenPos = { position.x * cellSize, position.y * cellSize };
   //std::cout << "Drawing banana at pixel: " << screenPos.x << ", " << screenPos.y << std::endl;
    BananaDraw(cellSize, cellSize / 2, getInsideColour(), getOutsideColour(), screenPos);
}

// Random position avoiding snake
Vector2 DecreaseLengthBanana::GenerateRandomPos(int cellNum, const Snake& snake) {
    Vector2 newPos = Fruit::GenerateRandomCell(cellNum);
    std::deque<Vector2> emptyDeque;
    while (Fruit::elementInDeque(newPos, snake.getBody(), emptyDeque)) {
        newPos = Fruit::GenerateRandomCell(cellNum);
    }
    return newPos;
}

// Behavior when eaten
void DecreaseLengthBanana::DecreaseLength(int _DecreaseAmount, GameController& controller) {
    controller.DecreaseSnake(_DecreaseAmount);
}
