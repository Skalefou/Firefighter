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
        m_mapCurrent[i].fill(LEFT_MAP);
    refreshFireDisplay();
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

FirePosition Map::setFirePosition(sf::Vector2f pos, bool rotation) const
{
    FirePosition a;
    a.pos = pos;
    a.rotation = rotation;
    return a;
}

void Map::refreshFireDisplay()
{
    for (int y = 0; y < 16; y++)
    {
        for (int x = 0; x < 16; x++)
        {
            int a = m_mapCurrent[x][y];
            if(a == ALL_DIRECTION_MAP)
                continue;
            else if (a == UP_DOWN_MAP)
            {
                m_firePosition.push_back(setFirePosition(sf::Vector2f(x*32, y*32), true));
            }
            else if (a == LEFT_RIGHT_MAP)
                m_firePosition.push_back(setFirePosition(sf::Vector2f(x*32, (y*32)-16), false));
            else if (a == LEFT_MAP)
            {
                m_firePosition.push_back(setFirePosition(sf::Vector2f(x*32, (y*32)-16), false));
                m_firePosition.push_back(setFirePosition(sf::Vector2f(x*32, y*32), true));
            }

        }
    }
}

void Map::display(sf::RenderWindow &window, Sprite &sprite)
{
    static bool rotate = false;
    for(int i = 0; i < std::size(m_firePosition); i++)
    {
        if(m_firePosition[i].rotation != rotate && !m_firePosition[i].rotation)
            sprite.setRotate(FIRE1_SPRITE, 0.f);
        else if (m_firePosition[i].rotation != rotate && m_firePosition[i].rotation)
            sprite.setRotate(FIRE1_SPRITE, 90.f);
        rotate = m_firePosition[i].rotation;
        sprite.changePosition(FIRE1_SPRITE, m_firePosition[i].pos);
        sprite.draw(window, FIRE1_SPRITE);
    }
}