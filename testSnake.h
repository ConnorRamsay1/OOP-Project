#include <deque>
#include <iostream>

#include "Snake.h"
#include "raylib.h"

class TestSnake {
 public:
  void runTests() {
    testAddSegment();
    testMovement();
    testSubtractSegment();
    testSlowEffect();
  }

  // Testing Functions within Snake
 private:
  Snake snake;
  int initialLength = snake.getBody().size();
  deque<Vector2> initialPosition = snake.getBody();

  void testAddSegment() {
    std::cout << "Testing addSegment()\n";
    std::cout << "Initial Length of snake was: " << initialLength << std::endl;
    snake.setAddSegment(true);
    snake.Update();
    if (initialLength < snake.getBody().size()) {
      std::cout << "New length is: " << snake.getBody().size() << std::endl;
      std::cout << "Test was SUCCESSFULL\n";
    } else {
      std::cout << "Test was UNSUCCESSFULL\n";
    }
  }

  void testMovement() {
    std::cout << "\nTesting Update() i.e. Snake's Movement\n";


    // Setting Attributes such that snake.Update() only moves the snake
    snake.setAddSegment(false);
    snake.setSubtractSegment(false);
    snake.setDirection({1, 1});

    //Moving the Snake
    snake.Update();
    deque<Vector2> newPosition = snake.getBody();

    //Comparing Position 
    bool moved = true;
    for(int i =0; i<snake.getBody().size(); i++){
        if((initialPosition[i].x == newPosition[i].x) &&(initialPosition[i].y == newPosition[i].y)){
            moved = false;
            break;
        }
    }

    if (moved) {
      std::cout << "Test was SUCCESSFULL\n";
    } else {
      std::cout << "Test was UNSUCCESSFULL\n";
    }
  }

  void testSubtractSegment() {
        std::cout << "\nTesting subtractSegment() \n";
    std::cout << "Initial Length of snake was: " << initialLength << std::endl;
    snake.setSubtractSegment(true);
    snake.removeSegments(2);
    if (initialLength > snake.getBody().size()) {
    std::cout << "New length is: " << snake.getBody().size() << std::endl;
      std::cout << "Test was SUCCESSFULL\n";
    } else {
      std::cout << "Test was UNSUCCESSFULL\n";
    }
  }

  void testSlowEffect() {
        std::cout << "\nTesting slowingEffect\n";
    snake.applySlowEffect(1.0f);
    if (snake.getIsSlowed() == true) {
      std::cout << "Test was SUCCESSFULL\n";
    } else {
      std::cout << "Test was UNSUCCESSFULL\n";
    }
  }
};
