//Very basic title page. No play functionality or scoreboard, very basic rules, no difficulty functionality but proof of concept
#include "raylib.h"

enum GameState { TITLE, PLAY, RULES, SCOREBOARD, DIFFICULTY };

int main()
{
    // Window setup
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Snake Game");
    SetTargetFPS(60);

    GameState currentState = TITLE;

    // Button settings
    const int buttonWidth = 190;
    const int buttonHeight = 50;
    const int buttonX = (screenWidth - buttonWidth) / 2; // centered
    const int buttonSpacing = 70; // vertical space between buttons

    Rectangle playButton       = { buttonX, 150, buttonWidth, buttonHeight };
    Rectangle rulesButton      = { buttonX, 150 + buttonSpacing, buttonWidth, buttonHeight };
    Rectangle scoreboardButton = { buttonX, 150 + buttonSpacing * 2, buttonWidth, buttonHeight };
    Rectangle difficultyButton = { buttonX, 150 + buttonSpacing * 3, buttonWidth, buttonHeight };

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        Vector2 mouse = GetMousePosition();

        switch (currentState)
        {
            case TITLE:
                DrawText("Snake Game", 220, 50, 40, DARKGRAY);

                // Draw buttons with hover effect
                DrawRectangleRec(playButton, CheckCollisionPointRec(mouse, playButton) ? LIGHTGRAY : GRAY);
                DrawText("Play", playButton.x + (playButton.width - MeasureText("Play", 30)) / 2,
                         playButton.y + 10, 30, BLACK);

                DrawRectangleRec(rulesButton, CheckCollisionPointRec(mouse, rulesButton) ? LIGHTGRAY : GRAY);
                DrawText("Rules", rulesButton.x + (rulesButton.width - MeasureText("Rules", 30)) / 2,
                         rulesButton.y + 10, 30, BLACK);

                DrawRectangleRec(scoreboardButton, CheckCollisionPointRec(mouse, scoreboardButton) ? LIGHTGRAY : GRAY);
                DrawText("Scoreboard", scoreboardButton.x + (scoreboardButton.width - MeasureText("Scoreboard", 30)) / 2,
                         scoreboardButton.y + 10, 30, BLACK);

                DrawRectangleRec(difficultyButton, CheckCollisionPointRec(mouse, difficultyButton) ? LIGHTGRAY : GRAY);
                DrawText("Difficulty", difficultyButton.x + (difficultyButton.width - MeasureText("Difficulty", 30)) / 2,
                         difficultyButton.y + 10, 30, BLACK);

                // Check clicks
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    if (CheckCollisionPointRec(mouse, playButton)) currentState = PLAY;
                    else if (CheckCollisionPointRec(mouse, rulesButton)) currentState = RULES;
                    else if (CheckCollisionPointRec(mouse, scoreboardButton)) currentState = SCOREBOARD;
                    else if (CheckCollisionPointRec(mouse, difficultyButton)) currentState = DIFFICULTY;
                }
                break;

            case PLAY:
                DrawText("Game starts!", 300, 200, 40, RED);
                if (IsKeyPressed(KEY_ESCAPE)) currentState = TITLE;
                break;

            case RULES:
                DrawText("Rules: Use arrow keys", 200, 200, 30, BLUE);
                if (IsKeyPressed(KEY_ESCAPE)) currentState = TITLE;
                break;

            case SCOREBOARD:
                DrawText("Scoreboard: Top scores here", 200, 200, 30, GREEN);
                if (IsKeyPressed(KEY_ESCAPE)) currentState = TITLE;
                break;

            case DIFFICULTY:
                DrawText("Select difficulty (Easy/Medium/Hard)", 150, 200, 30, ORANGE);
                if (IsKeyPressed(KEY_ESCAPE)) currentState = TITLE;
                break;
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
