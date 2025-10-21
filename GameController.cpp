// GameController Implementation File

#include "GameController.h"

#include <deque>
#include <iostream>
#include <vector>

#include "GameController.h"
#include "DecreaseLengthBanana.h"
#include "Snake.h"
#include "raylib.h"

using namespace std;

// Contructors----------------------------------------------------------------------------------------------
GameController::GameController() {
  Snake snake;
  IncreaseLengthApple lengthApple;
  SlowingApple slowApple;
  DecreaseLengthBanana DecreaseBananas;
  lastInputTime = 0;
  inputCooldown = 0.1f;
  cellNum = 25;
  cellSize = 30;
  isRunning = true;
  score = 0;

  // Apple Spawning
  // Max no. of Apples
  maxLengthApples = 3;
  maxSlowApples = 2;
  maxDecreaseBanana = 2;
  lastSpawnTime = 0;
  spawnRate = 3.0f;

  // Spawn Multiple Apples
  for (int i = 0; i < maxLengthApples; i++) {
    spawnLengthApple();
  }
  for (int i = 0; i < maxSlowApples; i++) {
    spawnSlowApple();
  }
  for (int i = 0; i < maxDecreaseBanana; i++){
    spawnDecreaseBanana();
  }
}

GameController::GameController(int score, Snake snake, bool isRunning) {
  this->score = score;
  this->snake = snake;
  this->inputCooldown = inputCooldown;
  this->lastInputTime = lastInputTime;
  this->isRunning = isRunning;
  lastInputTime = 0;
  inputCooldown = 0.135f;
  cellNum = 25;
  cellSize = 30;
}

// Behaviours--------------------------------------------------------------------------------------------

// Getters
int GameController::getcellNum() { return cellNum; }
int GameController::getCellSize() { return cellSize; }
int GameController::getScore() { return score; }
float GameController::getInputCooldown() { return inputCooldown; }
double GameController::getLastInputTime() { return lastInputTime; }
bool GameController::getisRunning() { return isRunning; }
Snake GameController::getSnake() { return snake; }

// Getters for SpawnRate
int GameController::getMaxLengthApples() { return maxLengthApples; }
int GameController::getMaxSlowApples() { return maxSlowApples; }
int GameController::getMaxDecreaseBanana() { return maxDecreaseBanana; }
double GameController::getLastSpawnTime() { return lastSpawnTime; }
float GameController::getSpawnRate() { return spawnRate; }
vector<SlowingApple*> GameController::getSlowApples() { return slowApples; }
vector<IncreaseLengthApple*> GameController::getLengthApples() { return lengthApples; }
vector<DecreaseLengthBanana*> GameController::getDecreaseBananas() { return DecreaseBananas; }

// Setters
void GameController::setScore(int score) {
  this->score = score;
  return;
}
void GameController::setCellSize(int size) {
  this->cellSize = size;
  return;
}
void GameController::setCellNum(int num) {
  this->cellNum = num;
  return;
}
void GameController::setInputCooldown(float coolDown) {
  this->inputCooldown = coolDown;
  return;
}
void GameController::setLastInputTime(double input) {
  this->lastInputTime = input;
  return;
}
void GameController::setisRunning(bool isRunning) {
  this->isRunning = isRunning;
}
void GameController::setSnake(Snake snake) {
  this->snake = snake;
  return;
}

// Setters for SpawnRate
void GameController::setLengthApples(
    vector<IncreaseLengthApple*> lengthApples) {
  this->lengthApples = lengthApples;
  return;
}
void GameController::setSlowApples(vector<SlowingApple*> SlowApples) {
  this->slowApples = slowApples;
  return;
}
 void GameController::setDecreaseBananas(vector<DecreaseLengthBanana*> DecreaseBananas){
  this->DecreaseBananas = DecreaseBananas;
 }

void GameController::setLastSpawnTime(double lastSpawnTime) {
  this->lastSpawnTime = lastSpawnTime;
  return;
}
void GameController::setSpawnRate(float spawnRate) {
  this->spawnRate = spawnRate;
  return;
}
void GameController::setMaxLengthApples(int maxLengthApples) {
  this->maxLengthApples = maxLengthApples;
  return;
}
void GameController::setMaxSlowApples(int maxSlowApples) {
  this->maxSlowApples = maxSlowApples;
  return;
}

// Managing Inputs and General Game Properties
void GameController::HandleInput(Vector2& direction) {
  double currentTime = GetTime();  // stores last time a key was pressed
  // Only accept input if cooldown time has passed
  if (currentTime - lastInputTime >= inputCooldown) {
    if (IsKeyPressed(KEY_UP) && direction.y != 1) {
      direction = {0, -1};
      snake.setDirection(direction);
      lastInputTime = currentTime;  // reset cooldown timer
      isRunning = true;
    } else if (IsKeyPressed(KEY_DOWN) && direction.y != -1) {
      direction = {0, 1};
      snake.setDirection(direction);
      lastInputTime = currentTime;
      isRunning = true;
    } else if (IsKeyPressed(KEY_LEFT) && direction.x != 1) {
      direction = {-1, 0};
      snake.setDirection(direction);
      lastInputTime = currentTime;
      isRunning = true;
    } else if (IsKeyPressed(KEY_RIGHT) && direction.x != -1) {
      direction = {1, 0};
      snake.setDirection(direction);
      lastInputTime = currentTime;
      isRunning = true;
    }
  }
}

void GameController::draw(int cellSize) {
  snake.draw(cellSize);
  for (int i = 0; i < lengthApples.size(); i++) {
    lengthApples[i]->draw(cellSize);
  }
  for (int i = 0; i < slowApples.size(); i++) {
    slowApples[i]->draw(cellSize);
  }
  for(int i=0; i < DecreaseBananas.size(); i++){
    DecreaseBananas[i]->draw(cellSize);
  }
}

void GameController::Update() {
  if (isRunning == true) {
    snake.Update();
    snake.updateSlowApple();
    checkCollisionWithLengthApple();
    checkCollisionWithSlowApple();
    checkCollisionWithDecreaseBanana();
    checkCollisionWithHead();
    checkCollisionWithEdges(cellNum);
  }
}

void GameController::GameOver(int cellNum) {
  snake.Reset();
  removeApples();
  // Spawn Apples
  spawnLengthApple();
  spawnSlowApple();
  spawnDecreaseBanana();

  isRunning = false;
  lastSpawnTime = GetTime();  // Resets spawn timer
}

// Managing Collisions
void GameController::checkCollisionWithLengthApple() {
  for (int i = 0; i < lengthApples.size(); i++) {
    if ((snake.getBody()[0].x == lengthApples[i]->getPosition().x) &&
        (snake.getBody()[0].y == lengthApples[i]->getPosition().y)) {
      lengthApples[i]->setPosition(
          lengthApples[i]->GenerateRandomPos(cellNum, snake));
      snake.setAddSegment(true);
      score = score + 1;
    }
  }
}
void GameController::checkCollisionWithSlowApple() {
  for (int i = 0; i < slowApples.size(); i++) {
    if ((snake.getBody()[0].x == slowApples[i]->getPosition().x) &&
        (snake.getBody()[0].y == slowApples[i]->getPosition().y)) {
      slowApples[i]->setPosition(
          slowApples[i]->GenerateRandomPos(cellNum, snake));
      snake.applySlowEffect(3.0f);  // Changes length of effect

      // Delete slowApple
      delete slowApples[i];
      // removes pointer and shifts remaining elements to fill the gap
      slowApples.erase(slowApples.begin() + i);

      // Spawn a new apple
      spawnSlowApple();
      break;
    }
  }
}
  void GameController::checkCollisionWithDecreaseBanana() {
     for (int i = 0; i < DecreaseBananas.size(); i++) {
    if ((snake.getBody()[0].x == DecreaseBananas[i]->getPosition().x) &&
        (snake.getBody()[0].y == DecreaseBananas[i]->getPosition().y)) {
      DecreaseBananas[i]->setPosition(
          DecreaseBananas[i]->GenerateRandomPos(cellNum, snake));
        snake.setSubtractSegment(true);
        score = score - 1;
      

      // Delete DecreaseBananas
      delete DecreaseBananas[i];
      // removes pointer and shifts remaining elements to fill the gap
      DecreaseBananas.erase(DecreaseBananas.begin() + i);

      // Spawn a new Banana
      spawnDecreaseBanana();
      break;
    }
  }
}
void GameController::checkCollisionWithHead() {
  for (int i = 1; i < snake.getBody().size(); i++) {
    if ((snake.getBody()[0].x == snake.getBody()[i].x) &&
        (snake.getBody()[0].y == snake.getBody()[i].y)) {
      GameOver(cellNum);
      return;
    }
  }
  return;
}
void GameController::checkCollisionWithEdges(int cellNum) {
  if (snake.getBody()[0].x == cellNum || snake.getBody()[0].x == -1) {
    GameOver(cellNum);
  }
  if (snake.getBody()[0].y == cellNum || snake.getBody()[0].y == -1) {
    GameOver(cellNum);
  }
}

// Spawning & Removing  Apples
void GameController::spawnLengthApple() {
  if (lengthApples.size() >= maxLengthApples) {
    return;  // Already at max amount
  } else {
    IncreaseLengthApple* newApple =
        new IncreaseLengthApple();  // Dynamically allocates
    Vector2 newApplePosition = newApple->GenerateRandomPos(cellNum, snake);
    bool validPosition = false;
    while (!validPosition) {
      validPosition = true;
      for (int i = 0; i < lengthApples.size(); i++) { 
         // Check valid spawn position against other length apples
        if ((newApplePosition.x == lengthApples[i]->getPosition().x) &&
            (newApplePosition.y == lengthApples[i]->getPosition().y)) {
          validPosition = false;
          newApplePosition = newApple->GenerateRandomPos(cellNum, snake);
          break;
        }
      }
      for (int i = 0; i < slowApples.size();
           i++) {  // Check valid spawn position against other slow apples
        if ((newApplePosition.x == slowApples[i]->getPosition().x) &&
            (newApplePosition.y == slowApples[i]->getPosition().y)) {
          validPosition = false;
          newApplePosition = newApple->GenerateRandomPos(cellNum, snake);
          break;
        }
      }
       //check spawn aganist other Bananas
      for(int i = 0; i < DecreaseBananas.size(); i++){
        if((newApplePosition.x == DecreaseBananas[i]->getPosition().x) &&
          (newApplePosition.y == DecreaseBananas[i]->getPosition().y)){
            validPosition = false;
          newApplePosition = newApple->GenerateRandomPos(cellNum, snake);
          break;
          }
      }
    }
    newApple->setPosition(newApplePosition);
    lengthApples.push_back(newApple);  // Adds new apple to lengthApples vector
  }
  return;
}
void GameController::spawnSlowApple() {
  if (slowApples.size() >= maxSlowApples) {
    return;  // Already at max amount
  } else {
    SlowingApple* newApple = new SlowingApple();
    Vector2 newApplePosition = newApple->GenerateRandomPos(cellNum, snake);
    bool validPosition = false;
    int index = 0;  // Prevents infinite loop

    while (!validPosition && index < 100) {
      validPosition = true;

      // Check valid spawn position against other length apples
      for (int i = 0; i < lengthApples.size(); i++) {
        if ((newApplePosition.x == lengthApples[i]->getPosition().x) &&
            (newApplePosition.y == lengthApples[i]->getPosition().y)) {
          validPosition = false;
          newApplePosition = newApple->GenerateRandomPos(cellNum, snake);
          break;
        }
      }
      // Check valid spawn position against other slow apples
      for (int i = 0; i < slowApples.size(); i++) {
        if ((newApplePosition.x == slowApples[i]->getPosition().x) &&
            (newApplePosition.y == slowApples[i]->getPosition().y)) {
          validPosition = false;
          newApplePosition = newApple->GenerateRandomPos(cellNum, snake);
          break;
        }
      }
      //check spawn aganist other Bananas
      for(int i = 0; i < DecreaseBananas.size(); i++){
        if((newApplePosition.x == DecreaseBananas[i]->getPosition().x) &&
          (newApplePosition.y == DecreaseBananas[i]->getPosition().y)){
            validPosition = false;
          newApplePosition = newApple->GenerateRandomPos(cellNum, snake);
          break;
          }
      }
      index = index + 1;
    }
    newApple->setPosition(newApplePosition);
    slowApples.push_back(newApple);  // Adds new apple to lengthApples vector
  }
  return;
}

void GameController::spawnDecreaseBanana() {
  if (DecreaseBananas.size() >= maxDecreaseBanana) {
    return;  // Already at max amount
  } else {
    DecreaseLengthBanana* newBanana = new DecreaseLengthBanana();
    Vector2 newBananaPosition = newBanana->GenerateRandomPos(cellNum, snake);
    bool validPosition = false;
    int index = 0;  // Prevents infinite loop

    while (!validPosition && index < 100) {
      validPosition = true;

      // Check valid spawn position against other length apples
      for (int i = 0; i < lengthApples.size(); i++) { // loop only checks through once no?
        if ((newBananaPosition.x == lengthApples[i]->getPosition().x) &&
            (newBananaPosition.y == lengthApples[i]->getPosition().y)) {
          validPosition = false;
          newBananaPosition = newBanana->GenerateRandomPos(cellNum, snake);
          break;
        }
      }
      // Check valid spawn position against other slow apples
      for (int i = 0; i < slowApples.size(); i++) { 
        if ((newBananaPosition.x == slowApples[i]->getPosition().x) &&
            (newBananaPosition.y == slowApples[i]->getPosition().y)) {
          validPosition = false;
          newBananaPosition = newBanana->GenerateRandomPos(cellNum, snake);
          break;
        }
      }
       //check spawn aganist other Bananas
      for(int i = 0; i < DecreaseBananas.size(); i++){
        if((newBananaPosition.x == DecreaseBananas[i]->getPosition().x) &&
          (newBananaPosition.y == DecreaseBananas[i]->getPosition().y)){
            validPosition = false;
          newBananaPosition = newBanana->GenerateRandomPos(cellNum, snake);
          break;
          }
      }
      index = index + 1;
    }
    newBanana->setPosition(newBananaPosition);
    DecreaseBananas.push_back(newBanana);  // Adds new apple to lengthApples vector
    std::cout << "Spawned banana at: " 
          << newBananaPosition.x << ", " << newBananaPosition.y << std::endl;
  }
  
  return;
}

void GameController::removeApples() {
  // Delete LengthApples
  for (int i = 0; i < lengthApples.size(); i++) {
    delete lengthApples[i];

    lengthApples.clear();  // clears vector/ empties container
  }
  // Delete SlowingApples
  for (int i = 0; i < slowApples.size(); i++) {
    delete slowApples[i];
    slowApples.clear();
  }
}
void GameController::removeBanana(){
  // Delete LengthBanana
  for (int i = 0; i < DecreaseBananas.size(); i++) {
    delete DecreaseBananas[i];

    DecreaseBananas.clear();  // clears vector/ empties container
  }
}

// Destructor--------------------------------------------------------------------------------------------------------
GameController::~GameController() { removeApples(); removeBanana();} 