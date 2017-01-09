#include "types.hpp"
#include "state.hpp"
#include "display.hpp"
#include "network.hpp"
#include "buttons.hpp"
#include "title-screen.hpp"

Screen * screen;

void setup() {
  setupDisplay();
  setupNetwork();

  srand(analogRead(0));

  screen = new TitleScreen(new State());
}

void loop() {
  unsigned long startTime = millis();

  openDisplay();
  Button systemButton = screen->Display() ? X_BUTTON : NULL_BUTTON;
  closeDisplay();
  Button userButton = byte2button(readNetwork());

  Button button = userButton != NULL_BUTTON ? userButton : systemButton;
  if (button != NULL_BUTTON) {
    Screen * nextScreen = screen->Handle(userButton);
    if (screen != nextScreen) {
      delete screen;
    }
    screen = nextScreen;
  }

  unsigned long endTime = millis();
  delay(DELAY - (endTime - startTime));
}
