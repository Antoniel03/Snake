
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

class Game_IO {
private:
  WINDOW *game_screen;
  WINDOW *data_screen;
  WINDOW *game_over_screen;
  int key;

public:
  Game_IO();
  void update_screen(int screen[30][100], coordinate food, int score);
  void init_graphics();
  void init_game_screen(int score);
  void init_player_input();
  void set_key(int k);
  int get_last_pressed_key();
  void init_game_over_screen(int score);
};
#endif
