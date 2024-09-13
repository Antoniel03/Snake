
#include "coordinate.hpp"
#include "state.hpp"
#ifndef GAME_SCREEN
#define GAME_SCREEN

class Screen {
private:
  int screen[30][100];
  coordinate food{0, 0, EMPTY};

public:
  Screen();
  void reset();
  void set_cell_state(
      coordinate position,
      cell_state state); // It doesn't really need the cell_state parameter
  cell_state get_cell_state(int x, int y);
  int (*(get_screen)())[100];
  coordinate get_food();
  void set_food(coordinate f);
};

#endif
