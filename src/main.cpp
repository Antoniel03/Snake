#include "headers/game.hpp"
#include "headers/game_io.hpp"
#include "headers/state.hpp"
#include <chrono>
#include <ncurses.h>
#include <thread>

using std::cout;
using std::endl;
using std::string;
void print_body(list<coordinate> b);

int main(int argc, char *arg[]) {
  Game_IO g;
  Screen s;
  Game ruler;
  Snake player{2, RIGHT};

  ruler.place_snake(player, s);

  g.init_graphics();
  std::thread t([&g] { g.init_player_input(); });
  g.init_game_screen(player.get_length() - 2);
  t.detach();

  while (g.get_last_pressed_key() != 27) {

    if (ruler.get_game_state() != GAME_OVER) {
      ruler.generate_food(s);
      g.update_screen(s.get_screen(), s.get_food(), player.get_length() - 2);

      std::this_thread::sleep_for(std::chrono::milliseconds(60));

      s.reset();
      //
      ruler.update_snake_position(player, g.get_last_pressed_key());
    }

    if (ruler.check_game_over(player.get_body())) {
      ruler.set_game_state(GAME_OVER);
      g.init_game_over_screen(player.get_length() - 2);
    } else {
      if (ruler.taking_food(player.get_body().back(), s.get_food()))
        ruler.apply_buff(player, s);
      player.move();
      ruler.place_snake(player, s);
    }
  }
  cout << "GAME OVER" << endl;
}

void print_body(list<coordinate> b) {
  for (auto i : b) {
    cout << "(" << i.x << "," << i.y << ")";
  }
  cout << endl;
}
