#include "direction.hpp"
#include "screen.hpp"
#include "snake.hpp"

#ifndef GAME
#define GAME
enum game_state { NOT_STARTED, PLAYING, GAME_OVER, PAUSED };

class Game {
private:
  game_state state = NOT_STARTED;
  coordinate snake_head; // X Remove when not using the game data screen

public:
  Game();
  void init_player(Snake &player); // X Not being used
  void place_snake(Snake snake, Screen &screen);
  void start_game(Screen &screen, Snake &player); // Not being used
  void update_screen(Screen &screen, Snake &player);
  void update_snake_position(Snake &player, int key);
  bool validate_direction(); // Not being used
  void generate_food();
  bool check_game_over(std::list<coordinate> snake_body);

  bool taking_buff(coordinate snake_head, coordinate food);
  void apply_buff(Snake &player, Screen &s);
  void generate_buff(Screen &s);

  void set_state(game_state s);
  void terminate();
  void set_snake_head_position(coordinate xy);
  void set_game_state(game_state s);
  game_state get_game_state();
  coordinate get_snake_head_position();
  bool snake_overlap(std::list<coordinate> snake_body);
};

#endif
