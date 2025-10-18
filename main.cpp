
#include "raylib.h"
#include <deque>
#include <iostream>


#include "Food.h"
#include "Snake.h"
#include "GameController.h"


using namespace std;

// Background Colours
Color green = {173, 204, 96, 255};
Color darkGreen = {43, 51, 24, 255};



// Controls speed of the Game
double lastUpdateTime = 0;
bool eventTriggered(double interval){
    double currentTime = GetTime();
    if(currentTime-lastUpdateTime >=interval){
        lastUpdateTime =currentTime;
        return true;
    }
    return false;

}


//------------------------------------------------------------------------------------
// MAIN PROGRAM LOOP
//------------------------------------------------------------------------------------

int main(void){
cout << "Game loading...." << endl;

    // Creating GameWindow, Setting FPS, Instantiating Control Class
    GameController game;
    InitWindow(game.getCellSize()*game.getcellNum(), game.getCellSize()*game.getcellNum(), "Snake" );
    SetTargetFPS(60);

    // GAME LOOP
    while(WindowShouldClose() == false){
        BeginDrawing(); // Produces black canvas that can be drawn on

        //Event Handling
        if(eventTriggered(0.2)){
            game.Update(); // Checks collisions, allows snake to move, etc. 
        }

        Vector2 tempDirection = game.snake.getDirection();
        game.HandleInput(tempDirection);

        

        // Clears old Background and resets colour to green
        ClearBackground(green);
   

        
        // Draw Title and Score
        DrawText("SNAKE GAME", 20, 40, 20, darkGreen);
        DrawText(TextFormat("%i", game.getScore()), 40, 40, 40, darkGreen);

        game.draw(game.getCellSize());
        EndDrawing();
    }


    // Closing GameWindow
    CloseWindow();


    return 0;
}