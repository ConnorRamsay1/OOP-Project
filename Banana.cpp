#include "Banana.h"

#include <cmath>

// Constructors---------------------------------------------------------------------
Banana::Banana() {}
Banana::Banana(Vector2 position, Color _bananaYellow, Color _bananaOutline) {
  this->position = position;
  this->_bananaYellow = _bananaYellow;
  this->_bananaOutline = _bananaOutline;
}

// Setters
void Banana::setOutsideColour(Color Outline) { this->_bananaOutline = Outline; }
void Banana::setInsideColour(Color Inside) { this->_bananaYellow = Inside; }
// getters
Color Banana::getOutsideColour() { return _bananaOutline; }
Color Banana::getInsideColour() { return _bananaYellow; }
// drawing Banana
void Banana::BananaDraw(int cellSize, int cellNum, Color _bananaYellow,
                        Color _bananaOutline, Vector2 position) {
  int segments = 6;
  float maxWidth = cellSize;          // max horizontal space
  float maxHeight = cellSize;         // max vertical space
  float width = maxWidth / segments;  // width per segment
  float height = maxHeight * 0.6f;    // slightly smaller than full height
  float spacing = width * 0.9f;       // space between segments
  float amplitude = height * 0.5f;    // vertical curve

  float startX = position.x + cellSize / 2.0f - (segments - 1) * spacing / 2.0f;
  float centerY = position.y + cellSize / 2.0f;  // center in grid cell

  for (int i = 0; i < segments; i++) {
    float offsetY = sinf((float)i / (segments - 1) * PI) * amplitude;
    DrawEllipse(startX + i * spacing, centerY - offsetY, width, height,
                _bananaYellow);
    DrawEllipseLines(startX + i * spacing, centerY - offsetY, width, height,
                     _bananaOutline);
  }
}
