#include "headers/game.hpp"
#include "headers/graphics.hpp"
#include "headers/state.hpp"
#include <chrono>
#include <ncurses.h>
#include <thread>

using std::cout;
using std::endl;
using std::string;
void print_body(list<coordinate> b);

int main(int argc, char *arg[]) {
  Graphics g;
  Screen s;
  Game ruler;
  Snake player{60, RIGHT};

  ruler.place_snake(player, s);

  g.init_graphics();
  std::thread t([&g] { g.init_player_input(); });
  ruler.set_snake_head_position(player.get_body().back());
  g.init_game_screen();
  g.init_data_screen(ruler.get_snake_head_position());
  t.detach();

  while (g.get_last_pressed_key() != 27) {

    if (ruler.get_game_state() != GAME_OVER) {
      g.update_screen(s.get_screen(), ruler.get_snake_head_position());
      std::this_thread::sleep_for(std::chrono::milliseconds(60));
      s.reset();
      ruler.set_snake_head_position(player.get_body().back());
      ruler.update_snake_position(player, g.get_last_pressed_key());
    }

    if (ruler.check_game_over(player.get_body())) {
      ruler.set_game_state(GAME_OVER);
      g.init_game_over_screen();
    } else {
      player.move();
      ruler.place_snake(player, s);
    }
  }
  endwin();
  cout << "GAME OVER" << endl;
}

void print_body(list<coordinate> b) {
  for (auto i : b) {
    cout << "(" << i.x << "," << i.y << ")";
  }
  cout << endl;
}
