#include "Map.h"
#include "raylib.h"

Map::Map(const int screenWidth, const int screenHeight){
     InitWindow(screenWidth, screenHeight, "raylib [core] example - input keys");
     SetTargetFPS(60);
     CloseWindow();
}