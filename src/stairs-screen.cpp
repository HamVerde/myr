#include "stairs-screen.hpp"

#include "display.hpp"
#include "score-screen.hpp"
#include "map-screen.hpp"

StairsScreen::StairsScreen(State * state): Screen(state) {
  this->loops = 0;

  this->state->ChangeMap();
}

bool StairsScreen::Display() {
  if (this->state->map.level < 10) {
    displayNumber(6, 5, 255, 0, 0, this->state->map.level);
  } else if (this->state->map.level < 15) {
    displayNumber(4, 5, 255, 0, 0, this->state->map.level / 10);
    displayNumber(8, 5, 255, 0, 0, this->state->map.level % 10);
  }

  const unsigned int * stairsPixels;
  if (this->loops >= 2 * FRAMES) stairsPixels = STAIRS_3_PIXELS;
  else if (this->loops >= 1 * FRAMES) stairsPixels = STAIRS_2_PIXELS;
  else if (this->loops >= 0 * FRAMES) stairsPixels = STAIRS_1_PIXELS;
  displayImage(0, 3, STAIRS_WIDTH, STAIRS_HEIGHT, stairsPixels);

  if (this->loops < 3 * FRAMES) {
    this->loops = this->loops + 1;
    return false;
  } else {
    return true;
  }
}

Screen * StairsScreen::Handle(Button button) {
  if (this->state->map.level >= 15) {
    return new ScoreScreen(this->state);
  } else {
    return new MapScreen(this->state);
  }
}
