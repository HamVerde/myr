#include "gold-screen.hpp"

#include "display.hpp"
#include "map-screen.hpp"

GoldScreen::GoldScreen(State * state): Screen(state) {
  this->loops = 0;
}

bool GoldScreen::Display() {
  const unsigned int * goldPixels;
  if (this->loops >= 2 * FRAMES) goldPixels = GOLD_3_PIXELS;
  else if (this->loops >= 1 * FRAMES) goldPixels = GOLD_2_PIXELS;
  else if (this->loops >= 0 * FRAMES) goldPixels = GOLD_1_PIXELS;
  displayImage(0, 3, GOLD_WIDTH, GOLD_HEIGHT, goldPixels);

  if (this->loops < 3 * FRAMES) {
    this->loops = this->loops + 1;
    return false;
  } else {
    return true;
  }
}

Screen * GoldScreen::Handle(Button button) {
  this->state->AddGold();
  return new MapScreen(this->state);
}
