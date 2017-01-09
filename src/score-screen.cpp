#include "score-screen.hpp"

#include "display.hpp"
#include "title-screen.hpp"

ScoreScreen::ScoreScreen(State * state): Screen(state) {

}

bool ScoreScreen::Display() {
  displayImage(0, 0, SCORE_WIDTH, SCORE_HEIGHT, SCORE_PIXELS);
  if (this->state->score < 10) {
    displayNumber(6, 3, 255, 0, 0, this->state->score);
  } else if (this->state->score < 100) {
    displayNumber(4, 3, 255, 0, 0, this->state->score / 10);
    displayNumber(8, 3, 255, 0, 0, this->state->score % 10);
  } else if (this->state->score < 1000) {
    displayNumber(2, 3, 255, 0, 0, this->state->score / 100);
    displayNumber(6, 3, 255, 0, 0, this->state->score / 10 % 10);
    displayNumber(10, 3, 255, 0, 0, this->state->score % 10);
  } else if (this->state->score < 10000) {
    displayNumber(0, 3, 255, 0, 0, this->state->score / 1000);
    displayNumber(4, 3, 255, 0, 0, this->state->score / 100 % 10);
    displayNumber(8, 3, 255, 0, 0, this->state->score / 10 % 10);
    displayNumber(12, 3, 255, 0, 0, this->state->score % 10);
  }

  return false;
}

Screen * ScoreScreen::Handle(Button button) {
  return new TitleScreen(this->state);
}
