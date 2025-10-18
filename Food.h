
// FOOD PARENT CLASS

#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include "raylib.h"
#include <deque>

class Snake; 

using namespace std;

class Food{

    protected:
     // Attributes
    Vector2 position;
    Color color;
     // Might add a Texture2D texture;

    public:
    // Constructor
    Food();
    Food(Color color, Vector2 position);

    // Behaviour
    Color getColor();
    Vector2 getPosition();
    
    void setColor(Color color);
    void setPosition(Vector2 position);
    
    void draw(int cellSize);
    bool elementInDeque(Vector2 element, deque<Vector2> deque);
    Vector2 GenerateRandomCell(int cellNum);
    Vector2 GenerateRandomPos(int cellNum, Snake snake);
};

// Destructor
// Food::~Food(){
//   // UnloadTexture(texture); ---> used when texture is loaded in instead of
//   // DrawRectangle(), use DrawTexture();
// }

#endif