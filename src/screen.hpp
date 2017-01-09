#ifndef SCREEN_HEADER
#define SCREEN_HEADER

#include "state.hpp"

class Screen {

  protected:

    State * state;

    Screen(State * state) {
      this->state = state;
    }

  public:

    virtual bool Display() = 0;

    virtual Screen * Handle(Button button) = 0;

};

#endif
