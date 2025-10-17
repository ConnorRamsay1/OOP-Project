#ifndef CONRTOL_H
#define CONTROL_H
#include "Map.h"

class control{
    protected:
    Map _Map;
    public:
    control(int width, int height);
    void Run_Map();

};

#endif