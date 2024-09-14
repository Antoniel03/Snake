#include "headers/game.hpp"
#include "headers/game_io.hpp"
#include "headers/state.hpp"
#include <chrono>
#include <ncurses.h>
#include <thread>

using std::cout;
using std::endl;
using std::string;
void game_loop();

int main(int argc, char *arg[]) { game_loop(); }

void game_loop() {
  Game_IO game_io;
  Screen screen;
  Game game_logic;
  Snake player{2, RIGHT};
  int score = 0;

  game_io.init_graphics();
  std::thread t([&game_io] { game_io.init_player_input(); });
  game_io.init_game_screen(score);
  t.detach();

  while (game_io.get_last_pressed_key() != 27) {
    if (game_logic.get_game_state() != GAME_OVER) {
      game_logic.generate_food(screen);
      game_io.update_screen(screen.get_screen(), screen.get_food(), score);

      std::this_thread::sleep_for(std::chrono::milliseconds(60));
      screen.reset();
      game_logic.update_snake_position(player, game_io.get_last_pressed_key());
    }

    if (game_logic.check_game_over(player.get_body())) {
      game_logic.set_game_state(GAME_OVER);
      game_io.init_game_over_screen(score);
    } else {
      if (game_logic.taking_food(player.get_body().back(), screen.get_food())) {
        game_logic.apply_buff(player, screen);
        score++;
      }
      player.move();
      game_logic.place_snake(player, screen);
    }
  }

  system("clear");
}
