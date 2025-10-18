#ifndef TITLEPAGE_H
#define TITLEPAGE_H

#include "raylib.h"

// Enum for game states
enum GameState { TITLE, PLAY, RULES, SCOREBOARD, DIFFICULTY };

// Function to run the title page
inline GameState runTitlePage(GameState currentState)
{
    // Only run if we are in TITLE state
    if (currentState != TITLE) return currentState;

    const int screenWidth = 800;
    const int screenHeight = 600;

    // Button settings
    const int buttonWidth = 190;
    const int buttonHeight = 50;
    const int buttonX = (screenWidth - buttonWidth) / 2;
    const int buttonSpacing = 70;

    Rectangle playButton       = { buttonX, 150, buttonWidth, buttonHeight };
    Rectangle rulesButton      = { buttonX, 150 + buttonSpacing, buttonWidth, buttonHeight };
    Rectangle scoreboardButton = { buttonX, 150 + buttonSpacing * 2, buttonWidth, buttonHeight };
    Rectangle difficultyButton = { buttonX, 150 + buttonSpacing * 3, buttonWidth, buttonHeight };

    Vector2 mouse = GetMousePosition();

    BeginDrawing();
    ClearBackground(RAYWHITE);

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

    EndDrawing();

    return currentState;
}

#endif
