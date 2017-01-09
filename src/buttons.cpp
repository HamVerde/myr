#include "buttons.hpp"

Button byte2button(char byte) {
  switch (byte) {
    case 1:
      return DOWN_BUTTON;
    case 2:
      return LEFT_BUTTON;
    case 3:
      return UP_BUTTON;
    case 4:
      return RIGHT_BUTTON;
    case 5:
      return X_BUTTON;
    case 6:
      return Y_BUTTON;
    default:
      return NULL_BUTTON;
  }
}
