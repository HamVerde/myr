#ifndef TYPES_HEADER
#define TYPES_HEADER

typedef enum Button {
  NULL_BUTTON,
  DOWN_BUTTON,
  LEFT_BUTTON,
  UP_BUTTON,
  RIGHT_BUTTON,
  X_BUTTON,
  Y_BUTTON
} Button;

typedef enum Field {
  NULL_FIELD = ' ',
  WALL_FIELD = '+',
  GOLD_FIELD = 'g',
  KEY_FIELD = 'k',
  STAIRS_FIELD = 's',
  POTION_FIELD = 'p',
  EASY_BATTLE_FIELD = '1',
  NORMAL_BATTLE_FIELD = '2',
  HARD_BATTLE_FIELD = '3'
} Field;

#endif
