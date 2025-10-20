#include "Banana.h"
#include <cmath>


//Setters 
void Banana::setOutsideColour(Color _bananaOutline){this->_bananaOutline = {255, 235, 59, 255};}
void Banana::setInsideColour(Color _bananaYellow){this->_bananaYellow = {218, 165, 32, 255};}
//getters
Color Banana::getOutsideColour(){return _bananaOutline;}
Color Banana::getInsideColour(){return _bananaYellow;}
//drawing Banana
void Banana::BananaDraw(int cellsize, int cellnum, Color _bananaYellow, Color _bananaOutline, Vector2 position){
     // Curved body
    for (int i = 0; i < 10; i++) {
        float offset = sinf((float)i / 10 * PI) * 4 * cellsize;
        DrawEllipse(position.x + i * 2 * cellsize, position.y - offset, cellnum, cellnum, _bananaYellow);
    }

    // Outline (a bit darker curve)
    for (int i = 0; i < 10; i++) {
        float offset = sinf((float)i / 10 * PI) * 4 * cellsize;
        DrawEllipseLines(position.x + i * 2 * cellsize, position.y - offset, cellnum, cellnum, _bananaOutline);
    }
}