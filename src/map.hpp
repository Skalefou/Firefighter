/*
file: map.hpp
author: Skalefou
description: Header managing the Map class that configures the game map as well as its modifications during the game.
*/

#ifndef MAP_HPP
#define MAP_HPP

#include <array>
#include <SFML/Graphics.hpp>
#include "sprite.hpp"

#define FIRE_HEIGHT 16

enum {ALL_DIRECTION_MAP, UP_DOWN_MAP, LEFT_RIGHT_MAP, LEFT_MAP, UP_MAP, RIGHT_MAP, DOWN_MAP, RIGHT_LEFT_DOWN_MAP, RIGHT_LEFT_UP_MAP, DOWN_UP_RIGHT_MAP, DOWN_UP_LEFT_MAP, UP_LEFT_MAP, UP_RIGHT_MAP, DOWN_RIGHT_MAP, DOWN_LEFT_MAP};
enum {UP_PLAYER_MOVE, RIGHT_PLAYER_MOVE, DOWN_PLAYER_MOVE, LEFT_PLAYER_MOVE};

struct FirePosition
{
    sf::Vector2f pos;
    bool rotation = false;
};

class Map
{
public:
    Map();
    void reset();
    int moveKey() const;
    void MovePositionPlayer(Sprite &sprite, const int move);
    void changePositionPlayer(Sprite &sprite, const int move);
    FirePosition setFirePosition(sf::Vector2f pos, bool rotation) const;
    void refreshFireDisplay();
    void display(sf::RenderWindow &window, Sprite &sprite);
private:
    std::array<std::array<int, 16>, 16> m_mapCurrent;
    std::vector<FirePosition> m_firePosition;
    sf::Vector2f m_positionPlayerMap {7.f, 7.f};
};

#endif