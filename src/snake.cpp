#include "headers/snake.hpp"
#include "headers/utils.hpp"
#include <iostream>

using std::list;

Snake::Snake() {}

Snake::Snake(int _length, direction _current_movement) {
  current_movement = _current_movement;
  length = _length;
  for (int i = 0; i < _length; i++) {
    body.push_back(coordinate{1, i + 1, OCCUPIED});
  }
}

void Snake::set_body(list<coordinate> new_body) { body = new_body; }

void Snake::set_direction(direction somewhere) { current_movement = somewhere; }

void Snake::set_length(int n) { length = n; }

list<coordinate> Snake::get_body() { return body; }

direction Snake::get_direction() { return current_movement; }

int Snake::get_length() { return length; }

void Snake::move() {
  coordinate direction_change;
  switch (current_movement) {
  case UP: {
    direction_change.x = -1;
    direction_change.y = 0;
    break;
  }
  case DOWN: {
    direction_change.x = 1;
    direction_change.y = 0;
    break;
  }
  case LEFT: {
    direction_change.x = 0;
    direction_change.y = -1;
    break;
  }
  case RIGHT: {
    direction_change.x = 0;
    direction_change.y = 1;
    break;
  }
  }

  for (list<coordinate>::iterator body_part = body.begin();
       body_part != body.end(); body_part++) {
    auto aux = body_part;
    aux++;
    if (aux == body.end())
      break;
    *body_part = *aux;
  }

  coordinate new_head = body.back() + direction_change;
  body.pop_back();
  body.push_back(new_head);
}

void Snake::movement_handler(coordinate change_point,
                             coordinate direction_change) {}

void Snake::increase_length() { length++; }
