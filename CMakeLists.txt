cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(snake)

add_executable(snake_game src/main.cpp src/screen.cpp src/snake.cpp src/game_io.cpp src/game.cpp src/utils.cpp)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})

target_include_directories(snake_game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/headers)
target_link_libraries(snake_game ${CURSES_LIBRARIES})
