#include "coordinate.hpp"
#include "direction.hpp"
#include <list>

#pragma once

class Snake {
private:
  int length;
  std::list<coordinate> body;
  direction current_movement;

  void movement_handler(coordinate direction_change);

public:
  Snake();
  Snake(int _length, direction _current_movement);

  void set_body(std::list<coordinate> new_body);
  void set_direction(direction somewhere);
  void set_length(int n);

  std::list<coordinate> get_body();
  direction get_direction();
  int get_length();

  void increase_length();
  void move();
};
