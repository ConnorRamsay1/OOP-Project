#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

#include "raylib.h"

using namespace std;

struct ScoreFinal {
  string playerName;
  int score;
  string difficulty;

  bool operator>(const ScoreFinal& other) const { return score > other.score; }
};

class Scoreboard {
 private:
  vector<ScoreFinal> highscores;
  string filename;
  int maxEntries;

 public:
  Scoreboard();
  Scoreboard(string filename, int maxEntries);

  // Storing and Loading Files
  void saveFile();
  void loadFile();

  // Managing Scores
  void addScore(string playerName, int score, string difficulty);
  bool isHighScore(int score);
  vector<ScoreFinal> getTopScores(int count);

  void draw(int screenWidth, int screenHeight);
};

#endif