#include "display.hpp"

#include <FastLED.h>

#define FASTLED_ESP8266_RAW_PIN_ORDER
#define LED_SERPENTINE
#define LED_DATA_PIN 0
#define LED(x, y) leds[HEIGHT - (x & 1 ? HEIGHT - y - 1 : y) - 1 + HEIGHT * x]

CRGB leds [SIZE];
boolean open;

void setupDisplay() {
    FastLED.addLeds<WS2812B, LED_DATA_PIN, GRB>(leds, SIZE);
}

void openDisplay() {
  if (!open) {
    LEDS.clear();
    LEDS.setBrightness(127);
    open = true;
  }
}

void displayPoint(int x, int y, int red, int green, int blue) {
  if (open) {
    LED(x, y) = CRGB(red, green, blue);
  }
}

void displayHorLine(int fromX, int fromY, int x, int red, int green, int blue) {
  if (open) {
    for (int dx = 0; dx < x; dx++) {
      displayPoint(fromX + dx, fromY, red, green, blue);
    }
  }
}

void displayVerLine(int fromX, int fromY, int y, int red, int green, int blue) {
  if (open) {
    for (int dy = 0; dy < y; dy++) {
      displayPoint(fromX, fromY + dy, red, green, blue);
    }
  }
}

void displayRectangle(int fromX, int fromY, int toX, int toY, int red, int green, int blue) {
  if (open) {
    for (int dy = 0; dy <= toY - fromY; dy++) {
      for (int dx = 0; dx <= toX - fromX; dx++) {
        displayPoint(fromX + dx, fromY + dy, red, green, blue);
      }
    }
  }
}

void displayImage(int x, int y, int width, int height, const unsigned int pixels []) {
  if (open) {
    for (int dy = 0; dy < height; dy++) {
      for (int dx = 0; dx < width; dx++) {
        unsigned int pixel = pixels[(height - 1 - dy) * width + dx];
        int alpha = (pixel >> 24) & 1;
        int red = (pixel >> 16) & 255;
        int green = (pixel >> 8) & 255;
        int blue = (pixel >> 0) & 255;
        if (alpha) displayPoint(x + dx, y + dy, red, green, blue);
      }
    }
  }
}

void displayNumber(int x, int y, int red, int green, int blue, int number) {
  if (open) {
    const unsigned int * numberAlphas;
    if (number == 0) numberAlphas = NUMBER_0_ALPHAS;
    else if (number == 1) numberAlphas = NUMBER_1_ALPHAS;
    else if (number == 2) numberAlphas = NUMBER_2_ALPHAS;
    else if (number == 3) numberAlphas = NUMBER_3_ALPHAS;
    else if (number == 4) numberAlphas = NUMBER_4_ALPHAS;
    else if (number == 5) numberAlphas = NUMBER_5_ALPHAS;
    else if (number == 6) numberAlphas = NUMBER_6_ALPHAS;
    else if (number == 7) numberAlphas = NUMBER_7_ALPHAS;
    else if (number == 8) numberAlphas = NUMBER_8_ALPHAS;
    else if (number == 9) numberAlphas = NUMBER_9_ALPHAS;
    for (int dy = 0; dy < NUMBER_HEIGHT; dy++) {
      for (int dx = 0; dx < NUMBER_WIDTH; dx++) {
        unsigned int alpha = numberAlphas[(NUMBER_HEIGHT - 1 - dy) * NUMBER_WIDTH + dx];
        if (alpha) displayPoint(x + dx, y + dy, red, green, blue);
      }
    }
  }
}

void closeDisplay() {
  if (open) {
    LEDS.show();
    open = false;
  }
}
