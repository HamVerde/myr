#include "item-bar.hpp"

#include "display.hpp"

void displayPotion(int x) {
  displayPoint(x - 1, 0, 50, 0, 50);
  displayPoint(x, 0, 50, 0, 50);
  displayPoint(x + 1, 0, 50, 0, 50);
  displayPoint(x - 1, 1, 50, 0, 50);
  displayPoint(x, 1, 255, 0, 255);
  displayPoint(x + 1, 1, 50, 0, 50);
  displayPoint(x, 2, 255, 0, 255);
}

void displayGold(int x) {
  displayPoint(x, 0, 50, 50, 0);
  displayPoint(x - 1, 1, 50, 50, 0);
  displayPoint(x, 1, 255, 255, 100);
  displayPoint(x + 1, 1, 50, 50, 0);
  displayPoint(x, 2, 50, 50, 0);
}

void displayKey(int x) {
  displayPoint(x, 0, 200, 200, 200);
  displayPoint(x, 1, 200, 200, 200);
  displayPoint(x, 2, 200, 200, 200);
  displayPoint(x + 1, 2, 200, 200, 200);
}

void displayItemBar(bool potion, int gold, bool key) {
  displayRectangle(0, 0, 14, 2, 0, 0, 5);

  if (potion) displayPotion(1);

  if (gold >= 1) displayGold(4);
  if (gold >= 2) displayGold(7);
  if (gold >= 3) displayGold(10);

  if (key) displayKey(13);
}
