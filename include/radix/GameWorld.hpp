#ifndef RADIX_GAME_WORLD_HPP
#define RADIX_GAME_WORLD_HPP

#include <list>

namespace radix {

class InputSource;
struct Screen;

class GameWorld {
public:
  InputSource &input;
  GameWorld(InputSource &input);
  void addScreen(Screen& screen);
  std::list<Screen*>* getScreens();
private:
  std::list<Screen*> screens;
};

} /* namespace radix */

#endif /* RADIX_GAME_WORLD_HPP */
