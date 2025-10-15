#ifndef BANANA_H
#define BANANA_H
#include "Fruit.h"

class Banana: public Fruit{
    private:
    int _shape;
    int _colour;
    protected:
    int effect;
    int spawnrate;

};

#endif