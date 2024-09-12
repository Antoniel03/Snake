#include "headers/game.hpp"
#include "headers/coordinate.hpp"
#include "headers/state.hpp"
#include <ncurses.h>
using std::list;

Game::Game() {}

void Game::init_player(Snake &player) {
  int i = 0;
  /*coordinate a{0, 0, OCCUPIED};*/
  /*coordinate b{0, 1, OCCUPIED};*/

  /*list<coordinate> player_body;*/
  /*player_body.push_front(a);*/
  /*player_body.push_front(b);*/

  /*player.set_body(player_body);*/
}

void Game::place_snake(Snake &snake, Screen &screen) {
  list<coordinate> body = snake.get_body();
  for (auto i : body) {
    screen.set_cell_state(i, OCCUPIED);
  }
}

void Game::start_game(Screen &screen, Snake &player) {}

void Game::update_screen(Screen &screen, Snake &player) {}

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
  if ((snake_head.x <= 0) || (snake_head.y <= 0)) {
    return true;
  }

  if ((snake_head.x >= 29) || (snake_head.y > 99)) {

    return true;
  }
  if (snake_overlap(snake_body))
    return true;
  return false;
}

bool Game::snake_overlap(list<coordinate> snake_body) {

  list<coordinate>::iterator limit = snake_body.end();
  limit--;
  for (list<coordinate>::iterator body_part = snake_body.begin();
       body_part != limit; body_part++) {

    if (same_coordinates(*body_part, snake_head))
      return true;
  }
  return false;
}

/*bool Game::apply_buff(Snake player) {}*/
/**/
/*void Game::generate_buff() {}*/

void Game::set_state(game_state s) { state = s; }

void Game::set_snake_head_position(coordinate xy) { snake_head = xy; }

coordinate Game::get_snake_head_position() { return snake_head; }

void Game::set_game_state(game_state s) { state = s; }

game_state Game::get_game_state() { return state; }
