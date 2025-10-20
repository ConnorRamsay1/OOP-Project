#ifndef BANANA_H
#define BANANA_H

#include "Fruit.h"
#include "GameController.h"

class Banana : public virtual Fruit, public GameController{
private:
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