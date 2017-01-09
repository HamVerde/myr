#ifndef MAP_SCREEN_HEADER
#define MAP_SCREEN_HEADER

#include "screen.hpp"

class MapScreen: public Screen {

  private:

    unsigned int loops;

  public:

    MapScreen(State * state);

    bool Display();

    Screen * Handle(Button button);

};

#endif
