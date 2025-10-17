#include "Map.h"
#include "raylib.h"

Map::Map(const int screenWidth, const int screenHeight)
     : screenWidth(screenWidth), screenHeight(screenHeight){
     InitWindow(screenWidth, screenHeight, "Snake");
     SetTargetFPS(60);
}

void Map::Draw(){
     BeginDrawing();
     ClearBackground(RAYWHITE);
     DrawText("Snake game window!", 650, 200, 35, LIGHTGRAY);
     EndDrawing();
}