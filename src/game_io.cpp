#include "headers/game_io.hpp"
#include "headers/coordinate.hpp"
#include "headers/direction.hpp"
#include "headers/state.hpp"
#include <ncurses.h>
#include <thread>
using std::string;

Game_IO::Game_IO() {}

void Game_IO::init_game_screen(int score) {
  move(0, 45);
  printw("Score: %d", score);
  game_screen = newwin(30, 100, 1, 0);
  box(game_screen, 0, 0);
}
// X call to data_screen and xy parameter
void Game_IO::update_screen(int screen[30][100], coordinate food, int score) {
  init_game_screen(score);
  for (int i = 1; i < 29; i++) {
    for (int j = 1; j < 99; j++) {
      if (screen[i][j] == OCCUPIED) {
        wmove(game_screen, i, j);
        waddch(game_screen, 'O');
      } else if (screen[i][j] == FOOD) {
        wmove(game_screen, i, j);
        waddch(game_screen, 'X');
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
void Game_IO::init_graphics() {
  initscr();
  raw();
  noecho();
  keypad(stdscr, true);
}

void Game_IO::init_player_input() {
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

int Game_IO::get_last_pressed_key() { return key; }

void Game_IO::set_key(int k) { key = k; }

void Game_IO::init_game_over_screen(int score) {
  game_over_screen = newwin(5, 20, 10, 40);
  box(game_over_screen, 0, 0);
  wmove(game_over_screen, 1, 1);
  wprintw(game_over_screen, "Game over");
  wmove(game_over_screen, 2, 1);
  wprintw(game_over_screen, "Score: %d", score);
  wmove(game_over_screen, 3, 1);
  wprintw(game_over_screen, "Press ESC to exit");
  wrefresh(game_over_screen);
}
