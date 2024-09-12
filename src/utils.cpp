#include "headers/utils.hpp"
#include <iostream>
#include <ncurses.h>

using std::string;

bool same_coordinates(coordinate a, coordinate b) {
  if ((a.x == b.x) && (b.y == a.y))
    return true;
  return false;
}

coordinate sum_coordinates(coordinate a, coordinate b) {
  a.x += b.x;
  a.y += b.y;
  return a;
}

coordinate operator+(const coordinate &a, const coordinate &b) {
  coordinate result;
  result.x = a.x + b.x;
  result.y = a.y + b.y;
  result.state = UNKNOWN;
  return result;
}

// I think this is not being used
bool operator<(const coordinate &a, const coordinate &b) {

  if (a.x == b.x) {
    return a.y < b.y;
  }
  return a.x < b.x;
}

string code_to_str(int ch) {
  switch (ch) {
  case KEY_UP:
    return "UP";
    break;
  case KEY_DOWN:
    return "DOWN";
    break;
  case KEY_LEFT:
    return "LEFT";
    break;
  case KEY_RIGHT:
    return "RIGHT";
    break;
  }
  return "";
}

direction code_to_direction(int code) {
  switch (code) {
  case KEY_UP:
    return UP;
    break;
  case KEY_DOWN:
    return DOWN;
    break;
  case KEY_LEFT:
    return LEFT;
    break;
  case KEY_RIGHT:
    return RIGHT;
    break;
  }
  return RIGHT;
}

std::string direction_to_str(direction d) {
  switch (d) {
  case UP:
    return "UP";
    break;
  case DOWN:
    return "DOWN";
    break;
  case LEFT:
    return "LEFT";
    break;
  case RIGHT:
    return "RIGHT";
    break;
  }
  return "";
}
