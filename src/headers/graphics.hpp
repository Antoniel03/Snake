
#include "coordinate.hpp"
#include "utils.hpp"
#include <iostream>
#include <list>
#include <ncurses.h>

using std::cout;
using std::endl;
using std::list;

#ifndef GRAPHICS
#define GRAPHICS

class Graphics {
private:
  WINDOW *game_screen;
  WINDOW *data_screen;
  WINDOW *game_over_screen;
  int key;

public:
  Graphics();
  void update_screen(int screen[30][100], coordinate xy, coordinate food);
  void init_graphics();
  void init_game_screen();
  void init_player_input();
  void init_data_screen(coordinate xy, coordinate food);
  void set_key(int k);
  int get_last_pressed_key();
  WINDOW *get_game_window();
  void init_game_over_screen();
};
#endif
