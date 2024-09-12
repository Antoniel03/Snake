#include <iostream>
#ifndef DIRECTION
#define DIRECTION

enum direction { LEFT, RIGHT, UP, DOWN };

std::string code_to_str(int ch);
std::string direction_to_str(direction d);

#endif
