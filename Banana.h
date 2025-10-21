#ifndef BANANA_H
#define BANANA_H

#include "Fruit.h"

class GameController;

class Banana : public virtual Fruit{
protected:
Color _bananaYellow; 
Color _bananaOutline; 

public:
//setters--------------------------
void setOutsideColour(Color bananaOutline);
void setInsideColour(Color bananaYellow);
//getters---------------
Color getOutsideColour();
Color getInsideColour();
//Draw Banana---------------
void BananaDraw(int cellsize, int cellnum, Color _bananaYellow, Color _bananaOutline, Vector2 position);

};

#endif