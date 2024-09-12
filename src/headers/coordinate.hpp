#ifndef COORDINATE
#define COORDINATE

#include "state.hpp"

struct coordinate {
  int x;
  int y;
  cell_state state;
};

bool same_coordinates(coordinate a, coordinate b);
coordinate sum_coordinates(coordinate a, coordinate b);
coordinate operator+(coordinate const &a, coordinate const &b);
bool operator<(const coordinate &a, const coordinate &b);
#endif
