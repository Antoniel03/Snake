#include "direction.hpp"
#include "screen.hpp"
#include "snake.hpp"

#ifndef GAME
#define GAME
enum game_state { NOT_STARTED, PLAYING, GAME_OVER, PAUSED };

class Game {
private:
  game_state state = NOT_STARTED;

public:
  Game();
  void set_game_state(game_state _state);
  game_state get_game_state();

  void place_snake(Snake snake, Screen &screen);
  void update_snake_position(Snake &player, int key);
  bool check_game_over(std::list<coordinate> snake_body);
  bool snake_overlap(std::list<coordinate> snake_body);

  void generate_food(Screen &screen);
  bool taking_food(coordinate snake_head, coordinate food);
  void apply_buff(Snake &player, Screen &screen);
};

#endif
