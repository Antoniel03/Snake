#include "coordinate.hpp"
#include "direction.hpp"
#include <list>
#include <map>

#ifndef SNAKE
#define SNAKE

class Snake {
private:
  int length;
  std::list<coordinate> body;
  direction current_movement;
  std::map<coordinate, coordinate> movement;

public:
  Snake();
  Snake(int _length, direction _current_movement);

  void set_body(std::list<coordinate> new_body);
  void set_direction(direction somewhere);
  void set_length(int n);
  void increase_body(int n);
  void move();
  void movement_handler(coordinate change_point, coordinate direction_change);

  std::list<coordinate> get_body();
  direction get_direction();
  int get_length();
};

#endif
