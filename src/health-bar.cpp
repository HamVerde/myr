#include "health-bar.hpp"

#include "display.hpp"

void displayOuterLeftHealthBar(int x) {
  displayPoint(x, 19, 5, 0, 0);
  displayPoint(x, 18, 50, 0, 0);
}

void displayInnerLeftHealthBar(int x) {
  displayPoint(x, 19, 255, 0, 0);
  displayPoint(x, 18, 255, 0, 0);
  displayPoint(x, 17, 20, 0, 0);
}

void displayCenterHealthBar(int x) {
  displayPoint(x, 19, 20, 0, 0);
  displayPoint(x, 18, 255, 0, 0);
  displayPoint(x, 17, 255, 0, 0);
}

void displayInnerRightHealthBar(int x) {
  displayPoint(x, 19, 255, 0, 0);
  displayPoint(x, 18, 255, 0, 0);
  displayPoint(x, 17, 20, 0, 0);
}

void displayOuterRightHealthBar(int x) {
  displayPoint(x, 19, 5, 0, 0);
  displayPoint(x, 18, 50, 0, 0);
}

void displayHealthBar(int health) {
  displayRectangle(0, 17, 14, 19, 0, 0, 5);

  if (health >= 1) displayOuterLeftHealthBar(0);
  if (health >= 2) displayInnerLeftHealthBar(1);
  if (health >= 3) displayCenterHealthBar(2);
  if (health >= 4) displayInnerRightHealthBar(3);
  if (health >= 5) displayOuterRightHealthBar(4);
  if (health >= 6) displayOuterLeftHealthBar(5);
  if (health >= 7) displayInnerLeftHealthBar(6);
  if (health >= 8) displayCenterHealthBar(7);
  if (health >= 9) displayInnerRightHealthBar(8);
  if (health >= 10) displayOuterRightHealthBar(9);
  if (health >= 11) displayOuterLeftHealthBar(10);
  if (health >= 12) displayInnerLeftHealthBar(11);
  if (health >= 13) displayCenterHealthBar(12);
  if (health >= 14) displayInnerRightHealthBar(13);
  if (health >= 15) displayOuterRightHealthBar(14);
}
