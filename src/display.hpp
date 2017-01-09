#ifndef DISPLAY_HEADER
#define DISPLAY_HEADER

#include <FastLED.h>

const unsigned long FRAMES = 10;
const unsigned long DELAY = 1000 / FRAMES;

const int WIDTH = 15;
const int HEIGHT = 20;
const int SIZE = WIDTH * HEIGHT;

const int NUMBER_WIDTH = 3;
const int NUMBER_HEIGHT = 5;
const unsigned int NUMBER_0_ALPHAS [NUMBER_HEIGHT * NUMBER_WIDTH] = {
  1, 1, 1,
  1, 0, 1,
  1, 0, 1,
  1, 0, 1,
  1, 1, 1
};
const unsigned int NUMBER_1_ALPHAS [NUMBER_HEIGHT * NUMBER_WIDTH] = {
  0, 1, 0,
  0, 1, 0,
  0, 1, 0,
  0, 1, 0,
  0, 1, 0
};
const unsigned int NUMBER_2_ALPHAS [NUMBER_HEIGHT * NUMBER_WIDTH] = {
  1, 1, 1,
  0, 0, 1,
  1, 1, 1,
  1, 0, 0,
  1, 1, 1
};
const unsigned int NUMBER_3_ALPHAS [NUMBER_HEIGHT * NUMBER_WIDTH] = {
  1, 1, 1,
  0, 0, 1,
  1, 1, 1,
  0, 0, 1,
  1, 1, 1
};
const unsigned int NUMBER_4_ALPHAS [NUMBER_HEIGHT * NUMBER_WIDTH] = {
  1, 0, 1,
  1, 0, 1,
  1, 1, 1,
  0, 0, 1,
  0, 0, 1
};
const unsigned int NUMBER_5_ALPHAS [NUMBER_HEIGHT * NUMBER_WIDTH] = {
  1, 1, 1,
  1, 0, 0,
  1, 1, 1,
  0, 0, 1,
  1, 1, 1
};
const unsigned int NUMBER_6_ALPHAS [NUMBER_HEIGHT * NUMBER_WIDTH] = {
  1, 1, 1,
  1, 0, 0,
  1, 1, 1,
  1, 0, 1,
  1, 1, 1
};
const unsigned int NUMBER_7_ALPHAS [NUMBER_HEIGHT * NUMBER_WIDTH] = {
  1, 1, 1,
  0, 0, 1,
  0, 0, 1,
  0, 0, 1,
  0, 0, 1
};
const unsigned int NUMBER_8_ALPHAS [NUMBER_HEIGHT * NUMBER_WIDTH] = {
  1, 1, 1,
  1, 0, 1,
  1, 1, 1,
  1, 0, 1,
  1, 1, 1
};
const unsigned int NUMBER_9_ALPHAS [NUMBER_HEIGHT * NUMBER_WIDTH] = {
  1, 1, 1,
  1, 0, 1,
  1, 1, 1,
  0, 0, 1,
  1, 1, 1
};

void setupDisplay();

void openDisplay();

void displayPoint(int x, int y, int red, int green, int blue);

void displayHorLine(int fromX, int fromY, int x, int red, int green, int blue);

void displayVerLine(int fromX, int fromY, int y, int red, int green, int blue);

void displayRectangle(int fromX, int fromY, int toX, int toY, int red, int green, int blue);

void displayImage(int x, int y, int width, int height, const unsigned int pixels []);

void displayNumber(int x, int y, int red, int green, int blue, int number);

void closeDisplay();

#endif
