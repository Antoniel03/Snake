#include "headers/game.hpp"
#include "headers/coordinate.hpp"
#include "headers/state.hpp"
#include "headers/utils.hpp"
#include <ncurses.h>
using std::list;

Game::Game() {}

void Game::place_snake(Snake snake, Screen &screen) {
  list<coordinate> body = snake.get_body();
  for (auto i : body) {
    screen.set_cell_state(i);
  }
}

void Game::update_snake_position(Snake &player, int key) {
  switch (key) {
  case KEY_UP:
    if (player.get_direction() != DOWN)
      player.set_direction(UP);
    break;

  case KEY_DOWN:
    if (player.get_direction() != UP)
      player.set_direction(DOWN);
    break;

  case KEY_LEFT:
    if (player.get_direction() != RIGHT)
      player.set_direction(LEFT);
    break;

  case KEY_RIGHT:
    if (player.get_direction() != LEFT)
      player.set_direction(RIGHT);
    break;

  default:
    player.set_direction(player.get_direction());
    break;
  }
}

bool Game::check_game_over(list<coordinate> snake_body) {
  if ((snake_body.back().x <= 0) || (snake_body.back().y <= 0))
    return true;

  else if ((snake_body.back().x >= 29) || (snake_body.back().y > 99))
    return true;

  if (snake_overlap(snake_body))
    return true;

  return false;
}

bool Game::snake_overlap(list<coordinate> snake_body) {
  list<coordinate>::iterator limit = snake_body.end();
  limit--;
  for (list<coordinate>::iterator body_part = snake_body.begin();
       body_part != limit; body_part++) {

    if (same_coordinates(*body_part, snake_body.back()))
      return true;
  }
  return false;
}

void Game::set_game_state(game_state _state) { state = _state; }

game_state Game::get_game_state() { return state; }

void Game::generate_food(Screen &screen) {
  if (screen.get_food().state == EMPTY) {
    coordinate food_position{random_int(1, 28), random_int(1, 98), FOOD};
    screen.set_cell_state(food_position);
    screen.set_food(food_position);
  }
}

bool Game::taking_food(coordinate snake_head, coordinate food) {
  if (same_coordinates(snake_head, food))
    return true;
  return false;
}

void Game::apply_buff(Snake &player, Screen &screen) {
  list<coordinate> player_body = player.get_body();
  coordinate player_tail = player_body.front();
  player_body.push_front(player_tail);
  player.set_body(player_body);
  player.increase_length();

  coordinate food = screen.get_food();
  screen.set_food({0, 0, EMPTY});
}
