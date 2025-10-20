#include "DecreaseLengthBanana.h"
#include "Fruit.h"
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
   Vector2 screenPos = { position.x * cellSize, position.y * cellSize };
    BananaDraw(cellSize, cellSize / 2, getInsideColour(), getOutsideColour(), screenPos);
}

// Random position avoiding snake
Vector2 DecreaseLengthBanana::GenerateRandomPos(int cellNum, Snake snake) {
    Vector2 newPos = Fruit::GenerateRandomCell(cellNum);
    std::deque<Vector2> emptyDeque;
    while (Fruit::elementInDeque(newPos, snake.getBody(), emptyDeque)) {
        newPos = Fruit::GenerateRandomCell(cellNum);
    }
    return newPos;
}

// Behavior when eaten
void DecreaseLengthBanana::DecreaseLength(int _DecreaseAmount) {
    GameController::DecreaseSnake(_DecreaseAmount);
}
