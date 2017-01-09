#include "take-potion-screen.hpp"

#include "display.hpp"
#include "map-screen.hpp"

TakePotionScreen::TakePotionScreen(State * state): Screen(state) {
  this->loops = 0;
}

bool TakePotionScreen::Display() {
  const unsigned int * takePotionPixels;
  if (this->loops >= 2 * FRAMES) takePotionPixels = TAKE_POTION_3_PIXELS;
  else if (this->loops >= 1 * FRAMES) takePotionPixels = TAKE_POTION_2_PIXELS;
  else if (this->loops >= 0 * FRAMES) takePotionPixels = TAKE_POTION_1_PIXELS;
  displayImage(0, 3, TAKE_POTION_WIDTH, TAKE_POTION_HEIGHT, takePotionPixels);

  if (this->loops < 3 * FRAMES) {
    this->loops = this->loops + 1;
    return false;
  } else {
    return true;
  }
}

Screen * TakePotionScreen::Handle(Button button) {
  this->state->AddPotion();
  return new MapScreen(this->state);
}
