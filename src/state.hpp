#ifndef STATE_HEADER
#define STATE_HEADER

#include "map.hpp"

class State {

  public:

    int score;

    int health;

    Map map;

    int x;

    int y;

    bool potion;

    int gold;

    bool key;

    void ResetState() {
      this->score = 0;
      this->health = 5;
      this->map.ResetMap();
      this->x = this->map.x;
      this->y = this->map.y;
      this->potion = false;
      this->gold = 0;
      this->key = false;
    }

    void AdjustScore() {
      this->score = this->score +
          (this->gold == 3 ? 100 : (this->gold == 2 ? 40 : (this->gold == 1 ? 10 : 0)));
      this->gold = 0;
    }

    void ChangeHealth(int health) {
      this->health = this->health + health;
      this->health = this->health < 0 ? 0 : this->health > 15 ? 15 : this->health;
    }

    void ChangeMap() {
      this->score = this->score +
          (this->gold == 3 ? 10 : (this->gold == 2 ? 4 : (this->gold == 1 ? 1 : 0)));
      this->map.ChangeMap();
      this->x = this->map.x;
      this->y = this->map.y;
      this->gold = 0;
      this->key = false;
    }

    Field ChangePosition(int dx, int dy) {
      Field field = this->map.GetField(this->x + dx, this->y + dy);
      switch (field) {
        case NULL_FIELD:
          this->x = this->x + dx;
          this->y = this->y + dy;
          return NULL_FIELD;
        case WALL_FIELD:
          return WALL_FIELD;
        case GOLD_FIELD:
          this->map.SetField(this->x + dx, this->y + dy, NULL_FIELD);
          this->x = this->x + dx;
          this->y = this->y + dy;
          return GOLD_FIELD;
        case KEY_FIELD:
          this->map.SetField(this->x + dx, this->y + dy, NULL_FIELD);
          this->x = this->x + dx;
          this->y = this->y + dy;
          return KEY_FIELD;
        case STAIRS_FIELD:
          this->x = this->x + dx;
          this->y = this->y + dy;
          return STAIRS_FIELD;
        case POTION_FIELD:
          if (!this->potion) {
            this->map.SetField(this->x + dx, this->y + dy, NULL_FIELD);
          }
          this->x = this->x + dx;
          this->y = this->y + dy;
          return this->potion ? NULL_FIELD : POTION_FIELD;
        case EASY_BATTLE_FIELD:
          this->map.SetField(this->x + dx, this->y + dy, NULL_FIELD);
          this->x = this->x + dx;
          this->y = this->y + dy;
          return EASY_BATTLE_FIELD;
        case NORMAL_BATTLE_FIELD:
          this->map.SetField(this->x + dx, this->y + dy, NULL_FIELD);
          this->x = this->x + dx;
          this->y = this->y + dy;
          return NORMAL_BATTLE_FIELD;
        case HARD_BATTLE_FIELD:
          this->map.SetField(this->x + dx, this->y + dy, NULL_FIELD);
          this->x = this->x + dx;
          this->y = this->y + dy;
          return HARD_BATTLE_FIELD;
      }
    }

    void AddPotion() {
      this->potion = true;
    }

    void RemovePotion() {
        this->potion = false;
    }

    void AddGold() {
      this->gold = this->gold + 1;
      this->gold = this->gold > 3 ? 3 : this->gold;
    }

    bool AddKey() {
      this->key = true;
    }

};

#endif
