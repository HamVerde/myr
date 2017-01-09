#include "key-screen.hpp"

#include "display.hpp"
#include "map-screen.hpp"

KeyScreen::KeyScreen(State * state): Screen(state) {
  this->loops = 0;
}

bool KeyScreen::Display() {
  const unsigned int * keyPixels;
  if (this->loops >= 2 * FRAMES) keyPixels = KEY_3_PIXELS;
  else if (this->loops >= 1 * FRAMES) keyPixels = KEY_2_PIXELS;
  else if (this->loops >= 0 * FRAMES) keyPixels = KEY_1_PIXELS;
  displayImage(0, 3, KEY_WIDTH, KEY_HEIGHT, keyPixels);

  if (this->loops < 3 * FRAMES) {
    this->loops = this->loops + 1;
    return false;
  } else {
    return true;
  }
}

Screen * KeyScreen::Handle(Button button) {
  this->state->AddKey();
  return new MapScreen(this->state);
}
