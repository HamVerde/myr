#include "drink-potion-screen.hpp"

#include "display.hpp"
#include "map-screen.hpp"

DrinkPotionScreen::DrinkPotionScreen(State * state): Screen(state) {
  this->loops = 0;
}

bool DrinkPotionScreen::Display() {
  const unsigned int * drinkPotionPixels;
  if (this->loops >= 2 * FRAMES) drinkPotionPixels = DRINK_POTION_3_PIXELS;
  else if (this->loops >= 1 * FRAMES) drinkPotionPixels = DRINK_POTION_2_PIXELS;
  else if (this->loops >= 0 * FRAMES) drinkPotionPixels = DRINK_POTION_1_PIXELS;
  displayImage(0, 3, DRINK_POTION_WIDTH, DRINK_POTION_HEIGHT, drinkPotionPixels);

  if (this->loops < 3 * FRAMES) {
    this->loops = this->loops + 1;
    return false;
  } else {
    return true;
  }
}

Screen * DrinkPotionScreen::Handle(Button button) {
  this->state->RemovePotion();
  this->state->ChangeHealth(5);
  return new MapScreen(this->state);
}
