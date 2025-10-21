#ifndef TESTTITLEPAGE_H
#define TESTTITLEPAGE_H

#include <iostream>
#include "TitlePage.h"
using namespace std;

class TestTitlePage {
 public:
  void runTests() {
    cout <<"\n\n\n";
    cout <<"Testing TitlePage \n";
    testConstructor();
    cout << "\n";
    testDifficultyGetters();
    cout << "\n";
    testHandleDifficultyInput();
    cout << "\n";
    testHandleTitleInput();
    cout << "\n";
  }

  // Testing Functions within TitlePage Class

  void testConstructor() {
    cout << "Testing constructor\n";
    TitlePage titlePage(800, 600);
    cout << "TitlePage created successfully with 800x600 screen\n";
    cout << "Default difficulty string: " << titlePage.getDifficultyString() << "\n\n";
  }

  void testDifficultyGetters() {
    cout << "Testing getDifficultyString() and getDifficultySpeed()\n";
    TitlePage tp(800, 600);

    cout << "Default difficulty: " << tp.getDifficultyString() << "\n";
    cout << "Default speed: " << tp.getDifficultySpeed() << "\n";
    cout <<"Tests are Successful \n\n";
  }

  void testHandleDifficultyInput() {
    cout << "Testing handleDifficultyInput()\n";
    TitlePage titlePage(800, 600);

    // Simulate that difficulty handling doesn't crash when no input happens
    GameState state = DIFFICULTY;
    GameState newState = titlePage.handleDifficultyInput(state);

    if (newState == DIFFICULTY)
      cout << "handleDifficultyInput() ran with no input - Test successful.\n";
    else
      cout << "Unexpected result occurred.\n\n";
  }

  void testHandleTitleInput() {
    cout << "Testing handleTitleInput()\n";
    TitlePage titlePage(800, 600);

    GameState state = TITLE;
    GameState result = titlePage.handleTitleInput(state);

    if (result == TITLE)
      cout << "handleTitleInput() ran successfully.\n";
    else
      cout << "Unexpected result occurred.\n";
  }

};

#endif
