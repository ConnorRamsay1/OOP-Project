#ifndef FRUIT_H
#define FRUIT_H
#include "Map.h"

class Fruit{
    private:
    Map& map;
    int _size;
    protected:
    int size(const int screenWidth, const int screenHeight);
};

#endif