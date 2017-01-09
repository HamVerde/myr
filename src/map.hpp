#ifndef MAP_HEADER
#define MAP_HEADER

#include <algorithm>
#include <stack>
#include <vector>
#include <cstdlib>
#include "types.hpp"

class Map {

  private:

    static const unsigned int WIDTH = 15;

    static const unsigned int HEIGHT = 14;

    static const char FIELDS [HEIGHT * WIDTH + 1];

    static const unsigned int X = 7;

    static const unsigned int Y = 1;

    static Field GET_FIELD(unsigned int x, unsigned int y) {
      return (Field) FIELDS[(HEIGHT - 1 - y) * WIDTH + x];
    }

    static const unsigned int EASY_BATTLES [15];

    static const unsigned int NORMAL_BATTLES [15];

    static const unsigned int HARD_BATTLES [15];

    unsigned int width;

    unsigned int height;

    Field * fields = new Field [this->height * this->width];

    bool insideField(unsigned int x, unsigned int y) {
      return x > 0 && x < this->width - 1 && y > 0 && y < this->height - 1;
    }

    bool pillarField(unsigned int x, unsigned int y) {
      return x % 2 == 0 && y % 2 == 0;
    }

    bool solidField(unsigned int x, unsigned int y) {
      unsigned int fields = 0;
      if (this->GetField(x, y - 1) == WALL_FIELD) fields = fields + 1;
      if (this->GetField(x - 1, y) == WALL_FIELD) fields = fields + 1;
      if (this->GetField(x, y + 1) == WALL_FIELD) fields = fields + 1;
      if (this->GetField(x + 1, y) == WALL_FIELD) fields = fields + 1;
      return fields >= 3;
    }

    bool checkField(unsigned int x, unsigned int y) {
      return !this->pillarField(x, y) && this->solidField(x, y);
    }

    void ResetFields() {
      if (this->level == 0) {
        this->width = WIDTH;
        this->height = HEIGHT;
        delete this->fields;
        this->fields = new Field [this->height * this->width];

        for (unsigned int y = 0; y < this->height; y++) {
          for (unsigned int x = 0; x < this->width; x++) {
            this->SetField(x, y, Map::GET_FIELD(x, y));
          }
        }

        this->x = Map::X;
        this->y = Map::Y;
      } else {
        this->width = 15;
        this->height = 15;
        delete this->fields;
        this->fields = new Field [this->height * this->width];

        bool done = false;
        do {
          for (unsigned int y = 0; y < this->height; y++) {
            for (unsigned int x = 0; x < this->width; x++) {
              this->SetField(x, y, WALL_FIELD);
            }
          }

          bool positions [this->height * this->width];
          for (unsigned int y = 0; y < this->height; y++) {
            for (unsigned int x = 0; x < this->width; x++) {
              positions[y * this->width + x] = false;
            }
          }
          std::stack<unsigned int> currentXs ({1});
          std::stack<unsigned int> currentYs ({1});
          while (!currentXs.empty() && !currentYs.empty()) {
            unsigned int x = currentXs.top();
            unsigned int y = currentYs.top();

            this->SetField(x, y, NULL_FIELD);
            positions[y * this->width + x] = true;

            std::vector<unsigned int> nextXs;
            std::vector<unsigned int> nextYs;
            unsigned int size = 0;
            if (this->insideField(x, y - 1) && !positions[(y - 1) * this->width + x] && this->checkField(x, y - 1)) {
              nextXs.push_back(x);
              nextYs.push_back(y - 1);
              size = size + 1;
            }
            if (this->insideField(x - 1, y) && !positions[y * this->width + (x - 1)] && this->checkField(x - 1, y)) {
              nextXs.push_back(x - 1);
              nextYs.push_back(y);
              size = size + 1;
            }
            if (this->insideField(x, y + 1) && !positions[(y + 1) * this->width + x] && this->checkField(x, y + 1)) {
              nextXs.push_back(x);
              nextYs.push_back(y + 1);
              size = size + 1;
            }
            if (this->insideField(x + 1, y) && !positions[y * this->width + (x + 1)] && this->checkField(x + 1, y)) {
              nextXs.push_back(x + 1);
              nextYs.push_back(y);
              size = size + 1;
            }

            if (size) {
              unsigned int index = rand() % size;
              currentXs.push(nextXs.at(index));
              currentYs.push(nextYs.at(index));
            } else {
              currentXs.pop();
              currentYs.pop();
            }
          }

          std::vector<unsigned int> deadendXs;
          std::vector<unsigned int> deadendYs;
          std::vector<unsigned int> deadendIndexes;
          unsigned int size = 0;
          for (unsigned int y = 0; y < this->height; y++) {
            for (unsigned int x = 0; x < this->width; x++) {
              if (this->checkField(x, y)) {
                deadendXs.push_back(x);
                deadendYs.push_back(y);
                deadendIndexes.push_back(size);
                size = size + 1;
              }
            }
          }
          std::random_shuffle(deadendIndexes.begin(), deadendIndexes.end());
          if (size >= 7) {
            this->SetField(deadendXs[deadendIndexes[0]], deadendYs[deadendIndexes[0]], KEY_FIELD);
            this->SetField(deadendXs[deadendIndexes[1]], deadendYs[deadendIndexes[1]], STAIRS_FIELD);
            this->SetField(deadendXs[deadendIndexes[2]], deadendYs[deadendIndexes[2]], GOLD_FIELD);
            this->SetField(deadendXs[deadendIndexes[3]], deadendYs[deadendIndexes[3]], GOLD_FIELD);
            this->SetField(deadendXs[deadendIndexes[4]], deadendYs[deadendIndexes[4]], GOLD_FIELD);
            this->SetField(deadendXs[deadendIndexes[5]], deadendYs[deadendIndexes[5]], POTION_FIELD);

            this->x = deadendXs[deadendIndexes[6]];
            this->y = deadendYs[deadendIndexes[6]];

            unsigned int easyBattles = EASY_BATTLES[this->level];
            while (easyBattles) {
              while (true) {
                unsigned int x = rand() % 15;
                unsigned int y = rand() % 15;
                if (this->GetField(x, y) == NULL_FIELD) {
                  this->SetField(x, y, EASY_BATTLE_FIELD);
                  easyBattles = easyBattles - 1;
                  break;
                }
              }
            }

            unsigned int normalBattles = NORMAL_BATTLES[this->level];
            while (normalBattles) {
              while (true) {
                unsigned int x = rand() % 15;
                unsigned int y = rand() % 15;
                if (this->GetField(x, y) == NULL_FIELD) {
                  this->SetField(x, y, NORMAL_BATTLE_FIELD);
                  normalBattles = normalBattles - 1;
                  break;
                }
              }
            }

            unsigned int hardBattles = HARD_BATTLES[this->level];
            while (hardBattles) {
              while (true) {
                unsigned int x = rand() % 15;
                unsigned int y = rand() % 15;
                if (this->GetField(x, y) == NULL_FIELD) {
                  this->SetField(x, y, HARD_BATTLE_FIELD);
                  hardBattles = hardBattles - 1;
                  break;
                }
              }
            }

            done = true;
          }
        } while (!done);
      }
    }

  public:

    unsigned int level;

    unsigned int x;

    unsigned int y;

    void ResetMap() {
      this->level = -1;
    }

    void ChangeMap() {
      this->level = this->level + 1;

      this->ResetFields();
    }

    Field GetField(unsigned int x, unsigned int y) {
      if (x >= 0 && x < this->width && y >= 0 && y < this->height) {
        return this->fields[y * this->width + x];
      } else {
        return NULL_FIELD;
      }
    }

    void SetField(unsigned int x, unsigned int y, Field field) {
      this->fields[y * this->width + x] = field;
    }

};

#endif
