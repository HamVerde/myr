#include "map.hpp"

const char Map::FIELDS [Map::HEIGHT * Map::WIDTH + 1] =
  "      +++      "\
  "      +s+      "\
  "    +++ +++    "\
  "    +g   k+    "\
  "    +++ +++    "\
  "      + +      "\
  "    +++ +++    "\
  "    +g   g+    "\
  "    +++ +++    "\
  "      +p+      "\
  "      +1+      "\
  "      + +      "\
  "      + +      "\
  "      +++      ";

const unsigned int Map::EASY_BATTLES [15] = { 3, 4, 4, 5, 4, 5, 4, 5, 2, 0, 0, 0, 0, 0, 0 };

const unsigned int Map::NORMAL_BATTLES [15] = { 0, 0, 0, 0, 1, 1, 2, 2, 4, 5, 4, 3, 2, 1, 0 };

const unsigned int Map::HARD_BATTLES [15] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5 };
