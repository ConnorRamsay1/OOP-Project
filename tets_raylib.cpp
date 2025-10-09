#include "raylib.h"
#include <string>

int main() {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Raylib + C++ Example");

    Vector2 ballPosition = { static_cast<float>(screenWidth)/2, static_cast<float>(screenHeight)/2 };
    float ballRadius = 30.0f;
    Color ballColor = RED;

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()) {
        // Update
        if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 3.0f;
        if (IsKeyDown(KEY_LEFT))  ballPosition.x -= 3.0f;
        if (IsKeyDown(KEY_UP))    ballPosition.y -= 3.0f;
        if (IsKeyDown(KEY_DOWN))  ballPosition.y += 3.0f;

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Move the ball with arrow keys", 240, 20, 20, DARKGRAY);
        DrawCircleV(ballPosition, ballRadius, ballColor);
        EndDrawing();
    }

    // De-Initialization
    CloseWindow();
    return 0;
}