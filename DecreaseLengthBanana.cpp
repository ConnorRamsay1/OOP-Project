#include "DecreaseLengthBanana.h"
#include "Fruit.h"
#include "GameController.h"
#include "Snake.h"
#include <iostream>
#include <deque>
#include <cmath>

// Constructors
DecreaseLengthBanana::DecreaseLengthBanana() {
    Fruit::position = {6, 6};
    Fruit::color = {255, 235, 59, 255};
    _DecreaseAmount = 2;
}

DecreaseLengthBanana::DecreaseLengthBanana(Color color, Vector2 position, int _DecreaseAmount) {
    Fruit::color = color;
    Fruit::position = position;
    this->_DecreaseAmount = 2;
}

// Getters / Setters
Color DecreaseLengthBanana::getColor() { return Fruit::color; }
Vector2 DecreaseLengthBanana::getPosition() { return Fruit::position; }
void DecreaseLengthBanana::setColor(Color color) { Fruit::color = color; }
void DecreaseLengthBanana::setPosition(Vector2 position) { Fruit::position = position; }
void DecreaseLengthBanana::setDecreaseAmount(int amount) { _DecreaseAmount = amount; }
int DecreaseLengthBanana::getDecreaseAmount(int _DecreaseAmount) { return _DecreaseAmount; }

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
