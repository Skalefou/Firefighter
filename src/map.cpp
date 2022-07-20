/*
file: map.cpp
author: Skalefou
description: file managing the functions of the Game class that configures the game map as well as its modifications during the game.
*/

#include "map.hpp"

Map::Map()
{
    reset();
}

void Map::reset()
{
    for(int i = 0; i < std::size(m_mapCurrent); i++)
        m_mapCurrent[i].fill(ALL_DIRECTION_MAP);
}

int Map::moveKey() const
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        return RIGHT_PLAYER_MOVE;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        return LEFT_PLAYER_MOVE;
    else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)))
        return DOWN_PLAYER_MOVE;
    else
        return UP_PLAYER_MOVE;
}

void Map::MovePositionPlayer(Sprite &sprite, const int move)
{
    const int a = m_mapCurrent[m_positionPlayerMap.x][m_positionPlayerMap.y];
    if(move == RIGHT_PLAYER_MOVE && m_positionPlayerMap.x < 15 && (a == ALL_DIRECTION_MAP || a == LEFT_RIGHT_MAP || a == RIGHT_MAP || a == RIGHT_LEFT_DOWN_MAP || a == RIGHT_LEFT_UP_MAP || a == DOWN_UP_RIGHT_MAP || a == UP_RIGHT_MAP || a == DOWN_RIGHT_MAP))
        changePositionPlayer(sprite, move);
    else if (move == LEFT_PLAYER_MOVE && m_positionPlayerMap.x > 0 && (a == ALL_DIRECTION_MAP || a == LEFT_RIGHT_MAP || a == LEFT_MAP || a == RIGHT_LEFT_DOWN_MAP || a == RIGHT_LEFT_UP_MAP || a == DOWN_UP_LEFT_MAP || a == UP_LEFT_MAP || a == DOWN_LEFT_MAP))
        changePositionPlayer(sprite, move);
    else if (move == DOWN_PLAYER_MOVE && m_positionPlayerMap.y < 15 && (a == ALL_DIRECTION_MAP || a == UP_DOWN_MAP || a == DOWN_MAP || a == RIGHT_LEFT_DOWN_MAP || a == DOWN_UP_LEFT_MAP || a == DOWN_UP_RIGHT_MAP || a == DOWN_LEFT_MAP || a == DOWN_RIGHT_MAP))
        changePositionPlayer(sprite, move);
    else if (move == UP_PLAYER_MOVE && m_positionPlayerMap.y > 0 && (a == ALL_DIRECTION_MAP || a == UP_DOWN_MAP || a == UP_MAP || a == RIGHT_LEFT_UP_MAP || a == DOWN_UP_LEFT_MAP || a == DOWN_UP_RIGHT_MAP || a == UP_LEFT_MAP || a == UP_RIGHT_MAP))
        changePositionPlayer(sprite, move);
}

void Map::changePositionPlayer(Sprite &sprite, const int move)
{
    if(move == RIGHT_PLAYER_MOVE)
        m_positionPlayerMap.x++;
    else if (move == LEFT_PLAYER_MOVE)
        m_positionPlayerMap.x--;
    else if (move == DOWN_PLAYER_MOVE)
        m_positionPlayerMap.y++;
    else if (move == UP_PLAYER_MOVE)
        m_positionPlayerMap.y--;
    sprite.changePosition(PLAYER_SPRITE, sf::Vector2f(32*m_positionPlayerMap.x, 32*m_positionPlayerMap.y));
}