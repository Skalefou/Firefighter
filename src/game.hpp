/*
file: game.hpp
author: Skalefou
description: Header managing the "Game" class that manipulates the whole game.
*/

#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "option.hpp"
#include "sprite.hpp"
#include "map.hpp"

class Game 
{
public:
    void init(sf::Font &font);
    void keyEnter(int &stategame, Sound &sound);
    void run(sf::RenderWindow &window, int &stategame, Sound &sound, Sprite &sprite);
    void draw(sf::RenderWindow &window, int &stategame);
private:
    Option m_option;
    Map m_map;
    bool m_activeKey = true, m_optionOn = false;
};

#endif