#include "control.h"
#include <iostream>

int main(void){
    control controller (1600, 800);
    controller.Run_Map();
    return 0;
}