
#ifndef TESTSCOREBOARD_H
#define TESTSCOREBOARD_H

#include <iostream>
#include "Scoreboard.h"
using namespace std;

class TestScoreboard {
 public:
  void runTests() {
    testAddAndRetrieveScores();
    cout << "\n \n \n";
    testIsHighScore();
        cout << "\n \n \n";
    testFileSaveAndLoad();
  }

  // TESTING addScore() & getTopScores()
  void testAddAndRetrieveScores() {
    cout << "Testing addScore() and getTopScores() \n";

    Scoreboard sb("test_highscores.txt", 10);
    sb.addScore("Lev", 100, "Easy");
    sb.addScore("Connor", 200, "Hard");
    sb.addScore("Jonty", 150, "Medium");

    vector<ScoreFinal> top = sb.getTopScores(3);

    if (top.size() == 3)
      cout << "Scores successfully added\n";
    else
      cout << "Incorrect number of scores: " << top.size() << "\n";

    if (top[0].playerName == "Connor" && top[0].score == 200)
      cout << "Scores sorted correctly (highest first)\n";
    else
      cout << "Scores not sorted correctly\n";
  }
  //Tests isHighScore() 
  void testIsHighScore() {
    cout << "Testing isHighScore() \n";

    Scoreboard sb("test_highscores.txt", 5);
    sb.addScore("Player1", 50, "Easy");
    sb.addScore("Player2", 100, "Hard");

    bool high1 = sb.isHighScore(200);
    bool high2 = sb.isHighScore(10);

    if (high1)
      cout << "All good: 200 is the high score\n";
    else
      cout << "NOT good: 10 is not the high score\n";

    if (!high2)
      cout << "All good: 10 is not the high score\n";
    else
      cout << "Not good: 10 is the lowest score\n";
  }

  void testFileSaveAndLoad() {
    cout << "Testing saveFile() and loadFile()\n";

    Scoreboard sb("test_highscores.txt", 5);
    sb.addScore("Tester", 1203, "Medium");
    sb.saveFile();

    // Create a new scoreboard and load from the saved file
    Scoreboard sbLoaded("test_highscores.txt", 5);
    sbLoaded.loadFile();

    vector<ScoreFinal> loaded = sbLoaded.getTopScores(1);
    if (!loaded.empty() && loaded[0].playerName == "Tester")
      cout << "File save and load working correctly\n";
    else
      cout << "File save/load failed\n";
  }
};

#endif
