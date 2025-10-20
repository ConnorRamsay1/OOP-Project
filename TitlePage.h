#ifndef TITLEPAGE_H
#define TITLEPAGE_H

#include "raylib.h"
#include "Scoreboard.h"

//Game Status
enum GameState{
    TITLE, 
    PLAY, 
    GAME_OVER,
    RULES, 
    SCOREBOARD, 
    DIFFICULTY,
    ENTER_NAME
};

enum Difficulty{
    EASY,
    MEDIUM,
    HARD
};

class TitlePage{
    private:
    int screenWidth;
    int screenHeight;

    //Dimensions of Buttons
    Rectangle playButton;
    Rectangle rulesButton;
    Rectangle scoreboardButton;
    Rectangle difficultyButton;
    Rectangle backButton;

    //Difficulty Select Buttons
    Rectangle easyButton;
    Rectangle mediumButton;
    Rectangle hardButton;

    Difficulty currentDifficulty;
    Scoreboard scoreboard;

    //Playername Input
    char playerName[20];
    int nameLength;

    public:
    TitlePage(int screenWidth, int screenHeight);

    //Draw Different Pages
    void drawTitleScreen();
    void drawRulesScreen();
    void drawScoreboardScreen();
    void drawDifficultyScreen();
    void drawGameOverScreen(int finalScore, bool isHighScore);
    void drawNameEntryScreen(int finalScore);

        // Handle input and return new state
    GameState handleTitleInput(GameState currentState);
    GameState handlePageInput(GameState currentState);
    GameState handleDifficultyInput(GameState currentState);
    GameState handleNameEntry(GameState currentState, int finalScore);

    //Getters
    Difficulty getCurrentDifficulty() const { return currentDifficulty; }
    string getDifficultyString() const;
    float getDifficultySpeed() const;
    Scoreboard& getScoreboard() { return scoreboard; }

};

#endif