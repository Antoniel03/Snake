#include "headers/graphics.hpp"
#include "headers/coordinate.hpp"
#include "headers/direction.hpp"
#include <ncurses.h>
#include <thread>
using std::string;

Graphics::Graphics() {}

void Graphics::init_game_screen() {
  game_screen = newwin(30, 100, 0, 0);
  box(game_screen, 0, 0);
}

void Graphics::update_screen(int screen[30][100], coordinate xy) {
  init_game_screen();
  init_data_screen(xy);
  for (int i = 1; i < 29; i++) {
    for (int j = 1; j < 99; j++) {
      if (screen[i][j] == 1) {
        wmove(game_screen, i, j);
        wattron(game_screen, A_STANDOUT);
        waddch(game_screen, ' ');
        wattroff(game_screen, A_STANDOUT);
      } else {
        wmove(game_screen, i, j);
        waddch(game_screen, ' ');
      }
    }
  }

  wrefresh(data_screen);
  wrefresh(game_screen);
  refresh();
}
// BETTER AS INPUT/OUTPUT
void Graphics::init_graphics() {
  initscr();
  raw();
  noecho();
  keypad(stdscr, true);
}

void Graphics::init_player_input() {
  while (key != 27) {
    key = getch();
    switch (key) {
    case KEY_UP:
      break;
    case KEY_DOWN:
      break;
    case KEY_LEFT:
      break;
    case KEY_RIGHT:
      break;
    }
  }
  endwin();
}

int Graphics::get_last_pressed_key() { return key; }

WINDOW *Graphics::get_game_window() { return game_screen; }

void Graphics::init_data_screen(coordinate xy) {
  data_screen = newwin(5, 50, 30, 0);
  box(data_screen, 0, 0);
  wmove(data_screen, 1, 1);

  string direction_input = code_to_str(key);

  wprintw(data_screen, "Current direction: %s", direction_input.data());
  wmove(data_screen, 2, 1);
  wprintw(data_screen, "Current head position: %d,%d", xy.x, xy.y);
}
void Graphics::set_key(int k) { key = k; }

void Graphics::init_game_over_screen() {
  game_over_screen = newwin(10, 20, 10, 40);
  box(game_over_screen, 0, 0);
  wmove(game_over_screen, 1, 1);
  wprintw(game_over_screen, "Game over");
  wmove(game_over_screen, 2, 1);
  wprintw(game_over_screen, "Score: %d", 0);
  wmove(game_over_screen, 3, 1);
  wprintw(game_over_screen, "Press ESC to exit");
  wrefresh(game_over_screen);
}
