#include "coordinate.hpp"
#include "direction.hpp"
#include <iostream>

#pragma once
std::string code_to_str(int ch);
std::string direction_to_str(direction d);

bool same_coordinates(coordinate a, coordinate b);
coordinate sum_coordinates(coordinate a, coordinate b);
coordinate operator+(coordinate const &a, coordinate const &b);
bool operator<(const coordinate &a, const coordinate &b);
