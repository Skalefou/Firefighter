/*
file: map.hpp
author: Skalefou
description: Header managing the Map class that configures the game map as well as its modifications during the game.
*/

#ifndef MAP_HPP
#define MAP_HPP

#include <array>

enum {ALL_DIRECTION_MAP, UP_DOWN_MAP, LEFT_RIGHT_MAP, LEFT_MAP, UP_MAP, RIGHT_MAP, DOWN_MAP, RIGHT_LEFT_DOWN_MAP, RIGHT_LEFT_UP_MAP, DOWN_UP_RIGHT_MAP, DOWN_UP_LEFT_MAP, LEFT_UP_MAP, RIGHT_UP_MAP, DOWN_RIGHT_MAP, DOWN_LEFT_MAP};

class Map
{
public:
    Map();
    void reset();
private:
    std::array<std::array<int, 6>, 6> m_mapCurrent;
};

#endif