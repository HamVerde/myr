#include "battle-screen.hpp"

#include "display.hpp"
#include "map-screen.hpp"
#include "score-screen.hpp"

BattleScreen::BattleScreen(State * state, unsigned int difficulty): Screen(state) {
  this->difficulty = difficulty;
  this->loops = 0;

  this->state->ChangeHealth(-difficulty);
}

bool BattleScreen::Display() {
  const unsigned int * battlePixels;
  if (this->loops >= 2 * FRAMES && this->state->health) battlePixels = BATTLE_3_VICTORY_PIXELS;
  else if (this->loops >= 2 * FRAMES && !this->state->health) battlePixels = BATTLE_3_DEFEAT_PIXELS;
  else if (this->loops >= 1 * FRAMES) battlePixels = this->difficulty == 1 ? BATTLE_2_EASY_PIXELS : this->difficulty == 2 ? BATTLE_2_NORMAL_PIXELS : BATTLE_2_HARD_PIXELS;
  else if (this->loops >= 0 * FRAMES) battlePixels = this->difficulty == 1 ? BATTLE_1_EASY_PIXELS : this->difficulty == 2 ? BATTLE_1_NORMAL_PIXELS : BATTLE_1_HARD_PIXELS;
  displayImage(0, 3, BATTLE_WIDTH, BATTLE_HEIGHT, battlePixels);

  if (this->loops < 3 * FRAMES) {
    this->loops = this->loops + 1;
    return false;
  } else {
    return true;
  }
}

Screen * BattleScreen::Handle(Button button) {
  if (this->state->health) {
    return new MapScreen(this->state);
  } else {
    this->state->AdjustScore();
    return new ScoreScreen(this->state);
  }
}
