#include "headers/screen.hpp"
#include "headers/coordinate.hpp"

Screen::Screen() {
  for (int i = 0; i < 30; i++) {
    for (int j = 0; j < 100; j++) {
      screen[i][j] = EMPTY;
    }
  }
}

void Screen::reset() {
  for (int i = 0; i < 30; i++) {
    for (int j = 0; j < 100; j++) {
      screen[i][j] = EMPTY;
    }
  }
  screen[food.x][food.y] = food.state;
}

void Screen::set_cell_state(coordinate position) {
  screen[position.x][position.y] = position.state;
}

int (*(Screen::get_screen)())[100] { return screen; }

cell_state Screen::get_cell_state(int x, int y) {
  if (screen[x][y] == 0)
    return EMPTY;
  else if (screen[y][x] == 1)
    return OCCUPIED;
  else if (screen[y][x] == 2)
    return FOOD;
  return UNKNOWN;
}

coordinate Screen::get_food() { return food; }
void Screen::set_food(coordinate f) { food = f; }
