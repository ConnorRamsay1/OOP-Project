#include "raylib.h"
#include "control.h"


control::control(int width, int height) : _Map(width,height){

}
void control::Run_Map(){
    while (!WindowShouldClose())
    {
        _Map.Draw();
    }
    CloseWindow();
}