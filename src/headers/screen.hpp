
#include "coordinate.hpp"
#ifndef GAME_SCREEN
#define GAME_SCREEN

class Screen {
private:
  int screen[30][100];

public:
  Screen();
  void reset();
  void set_cell_state(coordinate position, cell_state state);
  cell_state get_cell_state(int x, int y);
  int (*(get_screen)())[100];
};

#endif
