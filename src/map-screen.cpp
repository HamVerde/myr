#include "map-screen.hpp"

#include "types.hpp"
#include "display.hpp"
#include "health-bar.hpp"
#include "item-bar.hpp"
#include "battle-screen.hpp"
#include "gold-screen.hpp"
#include "key-screen.hpp"
#include "stairs-screen.hpp"
#include "take-potion-screen.hpp"
#include "drink-potion-screen.hpp"

MapScreen::MapScreen(State * state): Screen(state) {
  this->loops = 0;
}

bool MapScreen::Display() {
  displayHealthBar(this->state->health);
  for (unsigned int dy = 0; dy < 14; dy++) {
    for (unsigned int dx = 0; dx < 15; dx++) {
      Field field = this->state->map.GetField(dx + this->state->x - 7, dy + this->state->y - 7);
      switch (field) {
        case NULL_FIELD:
          break;
        case WALL_FIELD:
          displayPoint(dx, 3 + dy, 20, 20, 20);
          break;
        case GOLD_FIELD:
          displayPoint(dx, 3 + dy, 255, 255, 0);
          break;
        case KEY_FIELD:
          displayPoint(dx, 3 + dy, 200, 200, 200);
          break;
        case STAIRS_FIELD:
          displayPoint(dx, 3 + dy, (int) (sin((this->loops % 50) / (50 / M_PI)) * 150), (int) (sin((this->loops % 50) / (50 / M_PI)) * 75), 0);
          break;
        case POTION_FIELD:
          displayPoint(dx, 3 + dy, 255, 0, 255);
          break;
        case EASY_BATTLE_FIELD:
          displayPoint(dx, 3 + dy, (int) (sin((this->loops % 30) / (30 / M_PI)) * 255), 0, 0);
          break;
        case NORMAL_BATTLE_FIELD:
          displayPoint(dx, 3 + dy, (int) (sin((this->loops % 20) / (20 / M_PI)) * 255), 0, 0);
          break;
        case HARD_BATTLE_FIELD:
          displayPoint(dx, 3 + dy, (int) (sin((this->loops % 10) / (10 / M_PI)) * 255), 0, 0);
          break;
      }
    }
  }
  displayPoint(7, 3 + 7, 0, 0, 200);
  displayItemBar(this->state->potion, this->state->gold, this->state->key);

  this->loops = (this->loops + 1) % 4294967296;

  return false;
}

Screen * MapScreen::Handle(Button button) {
  Field field = NULL_FIELD;
  switch (button) {
    case DOWN_BUTTON:
      field = this->state->ChangePosition(0, -1);
      break;
    case LEFT_BUTTON:
      field = this->state->ChangePosition(-1, 0);
      break;
    case UP_BUTTON:
      field = this->state->ChangePosition(0, 1);
      break;
    case RIGHT_BUTTON:
      field = this->state->ChangePosition(1, 0);
      break;
    case Y_BUTTON:
      field = this->state->potion ? POTION_FIELD : NULL_FIELD;
      break;
  }
  switch (field) {
    case GOLD_FIELD:
      return new GoldScreen(this->state);
    case KEY_FIELD:
      return new KeyScreen(this->state);
    case STAIRS_FIELD:
      if (this->state->key) {
        return new StairsScreen(this->state);
      } else {
        return this;
      }
    case POTION_FIELD:
      if (this->state->potion) {
        return new DrinkPotionScreen(this->state);
      } else {
        return new TakePotionScreen(this->state);
      }
    case EASY_BATTLE_FIELD:
      return new BattleScreen(this->state, 1);
    case NORMAL_BATTLE_FIELD:
      return new BattleScreen(this->state, 2);
    case HARD_BATTLE_FIELD:
      return new BattleScreen(this->state, 3);
    default:
      return this;
  }
}
