// SNAKE CLASS HEADER FILE

#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include "raylib.h"
#include <deque>

using namespace std;

class Snake{

    private:
    // Snake Attributes
    deque<Vector2> body;
    Vector2 direction;
    bool addSegment;
    Color color;

    public:
    Snake(deque<Vector2> body, Vector2 direction, bool addSegment, Color color);
    Snake();



    // Snake Behaviour
    Vector2 getDirection();
    const deque<Vector2>& getBody(); //-----------------------------------------------
    bool getAddSegment();
    Color getColor();
    void setColor(Color color);
    void setAddSegment(bool addSegment);
    void setDirection(Vector2 direction);
    void setBody(deque<Vector2> body);

    void draw(int cellSize);
    void Update();
    void Reset();

    ~Snake();

};

#endif 
