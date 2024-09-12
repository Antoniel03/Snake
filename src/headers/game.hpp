#include "direction.hpp"
#include "screen.hpp"
#include "snake.hpp"

#ifndef GAME
#define GAME
enum game_state { NOT_STARTED, PLAYING, GAME_OVER, PAUSED };

class Game {
private:
  game_state state = NOT_STARTED;
  coordinate snake_head;

public:
  Game();
  void init_player(Snake &player);
  void place_snake(Snake &snake, Screen &screen);
  void start_game(Screen &screen, Snake &player);
  void update_screen(Screen &screen, Snake &player);
  void update_snake_position(Snake &player, int key);
  bool validate_direction();
  void generate_food();
  bool check_game_over(std::list<coordinate> snake_body);

  bool apply_buff(Snake player);
  void generate_buff();

  void set_state(game_state s);
  void terminate();
  void set_snake_head_position(coordinate xy);
  void set_game_state(game_state s);
  game_state get_game_state();
  coordinate get_snake_head_position();
  bool snake_overlap(std::list<coordinate> snake_body);
};

#endif
