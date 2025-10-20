#include "Scoreboard.h"

#include <iostream>
#include <sstream>

// Constructors---------------------------------------------------------
Scoreboard::Scoreboard() {
  filename = "highscores.txt";
  maxEntries = 20;
  loadFile();
}

Scoreboard::Scoreboard(string filename, int maxEntries) {
  this->filename = filename;
  this->maxEntries = maxEntries;
  loadFile();
}

// Other Behaviours------------------------------------------------------
// Saving Scores

void Scoreboard::saveFile() {
  ofstream file(filename);

  if (file.is_open()) {
    for (int i = 0; i < highscores.size(); i++) {
      file << highscores[i].playerName << "," << highscores[i].score << ","
           << highscores[i].difficulty << "\n";
    }
    file.close();
    std::cout << "Scores saved to " << filename << std::endl;
  }
}

void Scoreboard::loadFile() {
  ifstream file(filename);
  highscores.clear();

  if (file.is_open()) {
    string line;
    while (getline(file, line)) {
      stringstream ss(line);
      string name, difficulty;
      int score;

      // Parse "Name,Score,Difficulty" format
      if (getline(ss, name, ',') && ss >> score) {
        ss.ignore();  // Skip comma
        getline(ss, difficulty);

        ScoreFinal entry;
        entry.playerName = name;
        entry.score = score;
        entry.difficulty = difficulty;
        highscores.push_back(entry);
      }
    }
    file.close();
    // Sort Scores'
    sort(highscores.begin(), highscores.end(), greater<ScoreFinal>());
  }
}

void Scoreboard::addScore(string playerName, int score, string difficulty) {
  ScoreFinal newEntry;
  newEntry.playerName = playerName;
  newEntry.score = score;
  newEntry.difficulty = difficulty;

  highscores.push_back(newEntry);
  // Sort and keep only top scores

  sort(highscores.begin(), highscores.end(), greater<ScoreFinal>());

  if (highscores.size() > maxEntries) {
    highscores.resize(maxEntries);
  }
  saveFile();
}

// Check if score is a high score
bool Scoreboard::isHighScore(int score) {
  // Check if no. of Scores < max no. of scores
  if (highscores.size() < maxEntries) {
    return true;
  }

  // Get the lowest score
  ScoreFinal lastEntry = highscores.back();
  int lastScore = lastEntry.score;

  // If the new score is higher than the last one, it's a high score
  if (score > lastScore) {
    return true;
  } else {
    return false;
  }
}

// Return top scores
vector<ScoreFinal> Scoreboard::getTopScores(int count) {
  int numScores = min(count, (int)highscores.size());
  return vector<ScoreFinal>(highscores.begin(), highscores.begin() + numScores);
}

// Draw Scoreboard on page
void Scoreboard::draw(int screenWidth, int screenHeight) {
  int positionY = 150;
  int spacing = 45;

  if (highscores.empty()) {
    DrawText("No high scores Yet!", screenWidth / 2 - 100, positionY, 25,
             GRAY);
    return;
  }
  int count = min(10, (int)highscores.size());

  for (int i = 0; i < count; i++) {
    string rankText = to_string(i + 1) + ".";
    string nameText = highscores[i].playerName;
    string scoreText = to_string(highscores[i].score);
    string diffText = "[" + highscores[i].difficulty + "]";

    // Draw Ranking
    DrawText(rankText.c_str(), 100, positionY, 25, DARKGRAY);

    // Draw Name
    DrawText(nameText.c_str(), 150, positionY, 25, DARKGRAY);

    // Draw Difficulty
    Color diffColor = GRAY;
    if (highscores[i].difficulty == "Easy")
      diffColor = GREEN;
    else if (highscores[i].difficulty == "Medium")
      diffColor = ORANGE;
    else if (highscores[i].difficulty == "Hard")
      diffColor = RED;
    DrawText(diffText.c_str(), 350, positionY, 20, diffColor);

    // Draw score
    DrawText(scoreText.c_str(), 600, positionY, 25, DARKGREEN);
    positionY = positionY + spacing;
  }
}