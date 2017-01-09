#include "title-screen.hpp"

#include "display.hpp"
#include "stairs-screen.hpp"

TitleScreen::TitleScreen(State * state): Screen(state) {

}

bool TitleScreen::Display() {
  displayImage(0, 0, TITLE_WIDTH, TITLE_HEIGHT, TITLE_PIXELS);

  return false;
}

Screen * TitleScreen::Handle(Button button) {
  this->state->ResetState();
  return new StairsScreen(this->state);
}
