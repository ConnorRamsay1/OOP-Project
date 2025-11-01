#include "TitlePage.h"

#include <cstring>
#include <iostream>
using namespace std;

// Constructor---------------------------------------------------------------------
TitlePage::TitlePage(int screenWidth, int screenHeight) {
  this->screenWidth = screenWidth;
  this->screenHeight = screenHeight;
  currentDifficulty = MEDIUM;
  nameLength = 0;
  memset(playerName, 0, sizeof(playerName));
  strcpy(playerName, "Player");  // Default name
  nameLength = 6;

  // Setup button Positions
  int buttonWidth = 190;
  int buttonHeight = 50;
  int buttonX = (screenWidth - buttonWidth) / 2;
  int buttonSpacing = 70;

  playButton = {(float)buttonX, 150, (float)buttonWidth, (float)buttonHeight};
  rulesButton = {(float)buttonX, (float)150 + buttonSpacing, (float)buttonWidth,
                 (float)buttonHeight};
  scoreboardButton = {(float)buttonX, (float)150 + buttonSpacing * 2,
                      (float)buttonWidth, (float)buttonHeight};
  difficultyButton = {(float)buttonX, (float)150 + buttonSpacing * 3,
                      (float)buttonWidth, (float)buttonHeight};
  backButton = {20, (float)(screenHeight - 70), 100, 40};

  // Setup Difficulty Buttons
  easyButton = {(float)(screenWidth / 2 - 100), 150, 200, 50};
  mediumButton = {(float)(screenWidth / 2 - 100), 220, 200, 50};
  hardButton = {(float)(screenWidth / 2 - 100), 290, 200, 50};

  // Load scoreboard
  scoreboard = Scoreboard("highscores.txt", 10);
}

// Behaviours----------------------------------------------------------
// Getters

string TitlePage::getDifficultyString() const {
  if (currentDifficulty == EASY) {
    return "Easy";
  } else if (currentDifficulty == MEDIUM) {
    return "Medium";
  } else {
    return "Hard";
  }
}

float TitlePage::getDifficultySpeed() const {
  if (currentDifficulty == EASY) {
    return 0.1f;
  } else if (currentDifficulty == MEDIUM) {
    return 0.08f;
  } else {
    return 0.05f;
  }
}

// TitlePage
void TitlePage::drawTitleScreen() {
  ClearBackground(RAYWHITE);

  Vector2 mouse = GetMousePosition();
  // Title
  DrawText("SNAKE GAME", screenWidth / 2 - MeasureText("SNAKE GAME", 50) / 2,
           50, 50, DARKGREEN);

  // Play button
  Color playColor;
  if (CheckCollisionPointRec(mouse, playButton)) {
    playColor = LIGHTGRAY;
  } else {
    playColor = GRAY;
  }
  DrawRectangleRec(playButton, playColor);
  DrawText("Play",
           playButton.x + (playButton.width - MeasureText("Play", 30)) / 2,
           playButton.y + 10, 30, BLACK);

  // Rules button
  Color rulesColor;
  if (CheckCollisionPointRec(mouse, rulesButton)) {
    rulesColor = LIGHTGRAY;
  } else {
    rulesColor = GRAY;
  }
  DrawRectangleRec(rulesButton, rulesColor);
  DrawText("Rules",
           rulesButton.x + (rulesButton.width - MeasureText("Rules", 30)) / 2,
           rulesButton.y + 10, 30, BLACK);

  // Scoreboard button
  Color scoreColor;
  if (CheckCollisionPointRec(mouse, scoreboardButton)) {
    scoreColor = LIGHTGRAY;
  } else {
    scoreColor = GRAY;
  }
  DrawRectangleRec(scoreboardButton, scoreColor);
  DrawText("Scoreboard",
           scoreboardButton.x +
               (scoreboardButton.width - MeasureText("Scoreboard", 30)) / 2,
           scoreboardButton.y + 10, 30, BLACK);

  // Difficulty button
  Color diffColor;
  if (CheckCollisionPointRec(mouse, difficultyButton)) {
    diffColor = LIGHTGRAY;
  } else {
    diffColor = GRAY;
  }
  DrawRectangleRec(difficultyButton, diffColor);
  DrawText("Difficulty",
           difficultyButton.x +
               (difficultyButton.width - MeasureText("Difficulty", 30)) / 2,
           difficultyButton.y + 10, 30, BLACK);

  DrawText("USE MOUSE TO NAVIGATE PAGES", screenWidth / 2 - 175,
           screenHeight - 30, 20, RED);
}

// Rules Page
void TitlePage::drawRulesScreen() {
  ClearBackground(RAYWHITE);

  DrawText("GAME RULES", screenWidth / 2 - MeasureText("GAME RULES", 40) / 2,
           50, 40, DARKBLUE);

  int positionY = 150;
  int spacing = 40;

  DrawText("- Use ARROW KEYS to move the snake", 100, positionY, 25, BLACK);
  positionY = positionY + spacing;
  DrawText("- Eat RED APPLES to grow and score points", 100, positionY, 25,
           BLACK);
  positionY = positionY + spacing;
  DrawText("- Avoid YELLOW BANANAS (they shrink you)", 100, positionY, 25,
           BLACK);
  positionY = positionY + spacing;
  DrawText("- Avoid BLUE Apples (they slow you down)", 100, positionY, 25,
           BLACK);
  positionY = positionY + spacing;
  DrawText("- Don't hit walls or yourself!", 100, positionY, 25, RED);

  // BackButton
  Vector2 mouse = GetMousePosition();
  Color backColor;

  if (CheckCollisionPointRec(mouse, backButton)) {
    backColor = LIGHTGRAY;
  } else {
    backColor = GRAY;
  }
  DrawRectangleRec(backButton, backColor);
  DrawText("Back", backButton.x + 20, backButton.y + 10, 20, BLACK);

  DrawText("Press T to return", screenWidth / 2 - 100, screenHeight - 30, 20,
           DARKGRAY);
}

// Scoreboard Page
void TitlePage::drawScoreboardScreen() {
  ClearBackground(RAYWHITE);
  DrawText("HIGH SCORES", screenWidth / 2 - MeasureText("HIGH SCORES", 40) / 2,
           50, 40, DARKGREEN);

  // Drawing Scoreboard
  scoreboard.draw(screenWidth, screenHeight);

  // Back button
  Vector2 mouse = GetMousePosition();
  Color backColor;
  if (CheckCollisionPointRec(mouse, backButton)) {
    backColor = LIGHTGRAY;
  } else {
    backColor = GRAY;
  }
  DrawRectangleRec(backButton, backColor);
  DrawText("Back", backButton.x + 20, backButton.y + 10, 20, BLACK);

  DrawText("Press T to return", screenWidth / 2 - 100, screenHeight - 30, 20,
           DARKGRAY);
}

// Difficulty Screen
void TitlePage::drawDifficultyScreen() {
  ClearBackground(RAYWHITE);

  DrawText("SELECT DIFFICULTY",
           screenWidth / 2 - MeasureText("SELECT DIFFICULTY", 40) / 2, 50, 40,
           ORANGE);

  Vector2 mouse = GetMousePosition();
  // Easy button
  Color easyColor;
  if (currentDifficulty == EASY) {
    easyColor = DARKGREEN;  // once selected
  } else if (CheckCollisionPointRec(mouse, easyButton)) {
    easyColor = LIGHTGRAY;  // If Hovering over
  } else {
    easyColor = GREEN;
  }
  DrawRectangleRec(easyButton, easyColor);
  DrawText("Easy", easyButton.x + 60, easyButton.y + 10, 30,
           currentDifficulty == EASY ? WHITE : BLACK);

  // Medium button
  Color mediumColor;
  if (currentDifficulty == MEDIUM) {
    mediumColor = ORANGE;  // Selected
  } else if (CheckCollisionPointRec(mouse, mediumButton)) {
    mediumColor = LIGHTGRAY;
  } else {
    mediumColor = {255, 200, 100, 255};  // Light Orange
  }
  DrawRectangleRec(mediumButton, mediumColor);
  DrawText("Medium", mediumButton.x + 40, mediumButton.y + 10, 30,
           currentDifficulty == MEDIUM ? WHITE : BLACK);

  // Hard button
  Color hardColor;
  if (currentDifficulty == HARD) {
    hardColor = {139, 0, 0, 255};  // Selected
  } else if (CheckCollisionPointRec(mouse, hardButton)) {
    hardColor = LIGHTGRAY;
  } else {
    hardColor = RED;
  }
  DrawRectangleRec(hardButton, hardColor);
  DrawText("Hard", hardButton.x + 60, hardButton.y + 10, 30,
           currentDifficulty == HARD ? WHITE : BLACK);

  // Back button
  Color backColor;
  if (CheckCollisionPointRec(mouse, backButton)) {
    backColor = LIGHTGRAY;
  } else {
    backColor = GRAY;
  }
  DrawRectangleRec(backButton, backColor);
  DrawText("Back", backButton.x + 20, backButton.y + 10, 20, BLACK);

  DrawText("Press T to return", screenWidth / 2 - 100, screenHeight - 30, 20,
           DARKGRAY);
};

// GameOver Screen
void TitlePage::drawGameOverScreen(int finalScore, bool isHighScore) {
  ClearBackground(RAYWHITE);

  DrawText("GAME OVER", screenWidth / 2 - MeasureText("GAME OVER", 50) / 2, 150,
           50, RED);

  char scoreText[50];
  sprintf(scoreText, "Final Score: %d", finalScore);
  DrawText(scoreText, screenWidth / 2 - MeasureText(scoreText, 40) / 2, 250, 40,
           BLACK);

  // Asking for user input for name and Save High Score
  string diffText = "Difficulty: " + getDifficultyString();
  DrawText(diffText.c_str(),
           screenWidth / 2 - MeasureText(diffText.c_str(), 25) / 2, 310, 25,
           GRAY);

  if (isHighScore) {
    DrawText("NEW HIGH SCORE!",
             screenWidth / 2 - MeasureText("NEW HIGH SCORE!", 35) / 2, 360, 35,
             GOLD);
    DrawText("Press ENTER to save your score", screenWidth / 2 - 160, 410, 23,
             DARKGRAY);
  } else {
    DrawText("Press ENTER to play again", screenWidth / 2 - 140, 380, 25,
             DARKGRAY);
  }

  DrawText("Press T for main menu", screenWidth / 2 - 130, 450, 25, DARKGRAY);
}

// EntryNameScreen
void TitlePage::drawNameEntryScreen(int finalScore) {
  ClearBackground(RAYWHITE);

  char scoreText[50];
  sprintf(scoreText, "Score: %d", finalScore);
  DrawText(scoreText, screenWidth / 2 - MeasureText(scoreText, 35) / 2, 180, 35,
           BLACK);

  DrawText("Enter your name:", screenWidth / 2 - 120, 250, 30, DARKGRAY);

  // Draw name input box
  Rectangle nameBox = {(float)(screenWidth / 2 - 150), 300, 300, 50};
  DrawRectangleRec(nameBox, LIGHTGRAY);
  DrawRectangleLines(nameBox.x, nameBox.y, nameBox.width, nameBox.height,
                     DARKGRAY);

  // Draw entered name
  DrawText(playerName, nameBox.x + 10, nameBox.y + 10, 30, BLACK);

  // Draw cursor
  if ((int)(GetTime() * 2) % 2 == 0) {  // Blinking cursor
    int cursorX = nameBox.x + 10 + MeasureText(playerName, 30);
    DrawText("_", cursorX, nameBox.y + 10, 30, BLACK);
  }

  DrawText("Press ENTER to save", screenWidth / 2 - 100, 400, 23, DARKGRAY);
}

// Handle Mouse Inputs & Navigating through game

GameState TitlePage::handleDifficultyInput(GameState currentState) {
  if (currentState != DIFFICULTY) return currentState;

  Vector2 mouse = GetMousePosition();

  // Check difficulty button clicks
  if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
    if (CheckCollisionPointRec(mouse, easyButton)) {
      currentDifficulty = EASY;
      cout << "Difficulty set to EASY" << endl;
    } else if (CheckCollisionPointRec(mouse, mediumButton)) {
      currentDifficulty = MEDIUM;
      cout << "Difficulty set to MEDIUM" << endl;
    } else if (CheckCollisionPointRec(mouse, hardButton)) {
      currentDifficulty = HARD;
      cout << "Difficulty set to HARD" << endl;
    } else if (CheckCollisionPointRec(mouse, backButton)) {
      return TITLE;
    }
  }
  if (IsKeyPressed(KEY_T)) {
    return TITLE;
  }
  return DIFFICULTY;
}

GameState TitlePage::handleNameEntry(GameState currentState, int finalScore) {
  // Get character input
  int key = GetCharPressed();
  while (key > 0) {
    // Only allow Alphabet Letters & Space
    if ((key >= 32) && (key <= 125) && (nameLength < 19)) {
      playerName[nameLength] = (char)key;
      playerName[nameLength + 1] = '\0';
      nameLength++;
    }
    key = GetCharPressed();
  }

  // Handle backspace
  if (IsKeyPressed(KEY_BACKSPACE) && nameLength > 0) {
    nameLength--;
    playerName[nameLength] = '\0';
  }

  // Save score on ENTER
  if (IsKeyPressed(KEY_ENTER) && nameLength > 0) {
    scoreboard.addScore(string(playerName), finalScore, getDifficultyString());
    cout << "Score saved: " << playerName << " - " << finalScore << endl;

    // Reset name for next time
    nameLength = 0;
    memset(playerName, 0, sizeof(playerName));
    strcpy(playerName, "Player");
    nameLength = 6;

    return TITLE;
  }
  return ENTER_NAME;
}

GameState TitlePage::handleTitleInput(GameState currentState) {
  if (currentState != TITLE) return currentState;

  Vector2 mouse = GetMousePosition();

  if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
    if (CheckCollisionPointRec(mouse, playButton)) return PLAY;
    if (CheckCollisionPointRec(mouse, rulesButton)) return RULES;
    if (CheckCollisionPointRec(mouse, scoreboardButton)) return SCOREBOARD;
    if (CheckCollisionPointRec(mouse, difficultyButton)) return DIFFICULTY;
  }

  return TITLE;
}

GameState TitlePage::handlePageInput(GameState currentState) {
  Vector2 mouse = GetMousePosition();

  // Back button or T returns to title
  if (IsKeyPressed(KEY_T) || (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
                              CheckCollisionPointRec(mouse, backButton))) {
    return TITLE;
  }
  return currentState;
}